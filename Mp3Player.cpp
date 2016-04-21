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

/*
 *Zsumowanie lewego i prawego kanalu
 *Format PCM:
 * 2 kolejne bajty - lewy kanal, 2 nastepne - prawy kanal 
 * Zsumowanie obu kanalow
 */
void Mp3Player::demux(char* in, short out[]){
    short left[1024];
    short right[1024];
    int index = 0;
    
    for(int i=0; i < 4096; i+=4){
        left[index] = in[i] | (in[i+1] << 8);
        right[index] = in[i+2] | (in[i+3] << 8);
        index++;
    }
    
    for(int i = 0; i < 1024; i++){
        out[i] = left[i] + right[i];
    }
    
}

void Mp3Player::run() {
    int err;
    err = mpg123_open(mh, path); //otwarcie pliku; sprawdzic, co zwraca, zlapac wyjatek
    
    if (err == -1){
        QMessageBox box;
        box.critical(0, "Error", "Cannot find file(readers.h error)");
    }
    
    mpg123_getformat(mh, &rate, &channels, &encoding); //sprawdzenie formatu pliku
    
    
    //czary ustawiajace parametry do odtwarzania ao
    format.bits = mpg123_encsize(encoding) * BITS;
    format.rate = rate;
    format.channels = channels;
    format.byte_format = AO_FMT_NATIVE;
    format.matrix = 0;

    device = ao_open_live(driver, &format, NULL); //otwarcie odtwarzania
    
   
    int samples = bufferSize / 4; //ilosc probek przekazywanych do fft
    
    //bufory do fft
    kiss_fft_cpx in[samples];
    kiss_fft_cpx out[samples];
    kiss_fft_cfg cfg;
    
    short signal[samples];
    
    //zerowanie czesci urojonej buforow
    for (int i = 0; i < samples; i++) {
        in[i].i = 0;
    }

    cfg = kiss_fft_alloc(samples, 0, 0, 0); //alokacja pamieci buforow ff
    
    //glowna petla odtwarzajaca i przetwarzajaca dane
    while (mpg123_read(mh, buffer, bufferSize, &done) == MPG123_OK) {
        while (paused); //dopoki flaga pauzy jest aktywna, zapetlony
                       
        demux((char*)buffer, signal);
        
        for(int i = 0; i < samples; i++){
            in[i].r = signal[i];
        }
        
        kiss_fft(cfg, in, out); //wykonaj fft
        
        for (int i = 0; i < samples; i++) {
            float real = scale(out[i].r);
            float imaginary = scale(out[i].i);
            magnitude[i] = 10 * log10(real * real + imaginary * imaginary);  
        }

        emit spectrumReady(); //wyslij sygnal gotowosci danych
        ao_play(device, (char*) buffer, done); //odtworz pobrana probke
    }
    free(cfg); //usun niepotrzebne zmienne kiss_fft
}