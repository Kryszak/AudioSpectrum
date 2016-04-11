/* 
 * File:   MWindow.h
 * Author: kryszak
 *
 * Created on 1 kwietnia 2015, 20:53
 */

#ifndef _MWINDOW_H
#define	_MWINDOW_H

#include "ui_MWindow.h"
#include "Mp3Player.h"
#include<iostream>
#include<QObject>
#include<QFileDialog>
#include<QThread>
#include<QFileInfo>
#include<unistd.h>
#include<cmath>
#include<QGraphicsScene>
#include<QGraphicsRectItem>
#include<QBrush>
#include<QPen>
#include<QFont>

using namespace std;

class MWindow : public QDialog {
    Q_OBJECT
public:
    QFileDialog dialog; //okienkowy wybor pliku do odtwarzania
    Mp3Player *player; //odtwarzacz muzyki
    QThread playerThread; //watek odtwarzacza
    QString fileName; //przechowuje sciezke do pliku
    QGraphicsScene *scene; //do rysowania
    volatile bool playerPlaying = false; //flaga odtwarzania
    MWindow(); 
    virtual ~MWindow();
public slots:
    void findFile(); //wybiera plik do odtworzenia
    void play(); //odtwarza + fft mp3
    void pause(); //pauza odtwarzania
    void stop(); //zatrzymanie odtwarzania pliku
    void finishedPlaying(); //czysci zmienna playerPlaying po zakonczenu watku
    void drawSpectrum(); //rysowanie
private:
    Ui::MWindow widget;
};

#endif	/* _MWINDOW_H */