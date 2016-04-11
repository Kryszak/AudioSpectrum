/* 
 * File:   Mp3Player.cpp
 * Author: kryszak
 * 
 * Created on 22 kwiecień 2015, 23:00
 */

#include "Mp3Player.h"
#include "ui_MWindow.h"

Mp3Player::Mp3Player() {
    //inicjalizacja biblioteki ao
    ao_initialize();
    driver = ao_default_driver_id();

    //inicjalizacja biblioteki mpg123
    mpg123_init();
    mh = mpg123_new(NULL, &err);

    //ustawienie rozmiarow buforow
    bufferSize = 2048;
    buffer = new unsigned char[bufferSize];
    magnitude = new float[bufferSize / 4]; //ZMIENIC DO /2
}

Mp3Player::~Mp3Player() {
    //usuniecie buforow
    delete buffer;
    delete magnitude;
    //zamkniecie uchwytow ao i mpg123
    ao_close(device);
    mpg123_close(mh);
    mpg123_delete(mh);
    //zamkniecie ao i mpg123
    mpg123_exit();
    ao_shutdown();
}

float Mp3Player::scale(kiss_fft_scalar val){
    int g = 0;
    return val < 0 ? val*(1/32768.0f ) : val*(1/32767.0f);
}

void Mp3Player::run() {
    int err;
    err = mpg123_open(mh, path); //otwarcie pliku; sprawdzic, co zwraca, zlapac wyjatek
    
    if (err == -1){
        cout << " Ulomnosc pliku readers.h nie pozwolila na otwarcie pliku, prosze sprobowac ponownie" << endl;
    }
    
    mpg123_getformat(mh, &rate, &channels, &encoding); //sprawdzenie formatu pliku
    
    
    //czary ustawiajace parametry do odtwarzania ao
    format.bits = mpg123_encsize(encoding) * BITS;
    format.rate = rate;
    format.channels = channels;
    format.byte_format = AO_FMT_NATIVE;
    format.matrix = 0;

    device = ao_open_live(driver, &format, NULL); //otwarcie odtwarzania
    
   
    int samples = bufferSize / 2; //bufor probek do fft
    
    //bufory do fft
    kiss_fft_cpx in[samples];
    kiss_fft_cpx out[samples];
    kiss_fft_cfg cfg;

    //zerowanie czesci urojonej buforow
    for (int i = 0; i < samples; i++) {
        in[i].i = 0;
    }

    cfg = kiss_fft_alloc(samples, 0, 0, 0); //alokacja pamieci buforow ff
    
    //glowna petla odtwarzajaca i przetwarzajaca dane
    while (mpg123_read(mh, buffer, bufferSize, &done) == MPG123_OK) {
        while (paused); //dopoki flaga pauzy jest aktywna, zapetlony

        int index = 0;

        if(channels == 2){
            for (int i = 0; i < bufferSize; i += 2 ) {
                in[index].r = (buffer[i] | buffer[i+1] << 8);
                cout <<  (buffer[i] | buffer[i+1] << 8) << endl;
                index++;
            }
        }

        kiss_fft(cfg, in, out); //wykonaj fft
        
        for (int i = 0; i < samples / 2; i++) {
            float real = scale(out[i].r);// * samples;
            float imaginary = scale(out[i].i);// * samples;
           /* float max;
            if(real > imaginary) max = real;
            else max = imaginary;
            real /= max;
            imaginary /= max;*/
            magnitude[i] = 10 * log10(real * real + imaginary * imaginary);  
        }

        emit spectrumReady(); //wyslij sygnal gotowosci danych
        ao_play(device, (char*) buffer, done); //odtworz pobrana probke
    }
    free(cfg); //usun niepotrzebne zmienne kiss_fft
}