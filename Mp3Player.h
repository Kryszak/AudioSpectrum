/* 
 * File:   Mp3Player.h
 * Author: kryszak
 *
 * Created on 22 kwiecień 2015, 23:00
 */

#ifndef MP3PLAYER_H
#define	MP3PLAYER_H

#include<iostream>
#include<mpg123.h>
#include<ao/ao.h>
#include<QObject>
#include<QThread>
#include"kissfft/kiss_fft.h"
#include"kissfft/kiss_fftr.h"
#include<math.h>
#include<QMessageBox>

#define BITS 8

using namespace std;

class Mp3Player : public QThread {
    Q_OBJECT
public:
    const char* path = NULL; //sciezka do pliku
    volatile bool paused = false; //flaga pauzy odtwarzacza
    float *magnitude; //bufer danych przetworzonych fft
    size_t bufferSize; //rozmiar bufora
    
    Mp3Player();
    virtual ~Mp3Player();
    void run() Q_DECL_OVERRIDE; //przetwarzanie mp3
    float scale(kiss_fft_scalar);
    void demux(char*, short[]);
signals:
    void spectrumReady(); //sygnal gotowosci danych
private:
    //zmienne mpg123 
    mpg123_handle *mh;
    size_t done;
    int err;
    unsigned char *buffer;
    //zmienne audio info ao
    int driver;
    int channels;
    int encoding;
    long rate;
    //zmienne libao
    ao_device *device;
    ao_sample_format format;

};

#endif	/* MP3PLAYER_H */

