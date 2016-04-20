/*
 * File:   MWindow.cpp
 * Author: kryszak
 *
 * Created on 1 kwietnia 2015, 20:53
 */

#include "MWindow.h"

MWindow::MWindow() {
    widget.setupUi(this); //ustawienie UI z creatora
    this->setWindowTitle("Audio Spectrum v0.1"); //tytul okienka
    this->player = NULL; 

    widget.fileNameLabel->setText("No file selected"); //startowy napis w polu nazwy pliku
    
    //ustawianie okienka rysujacego
    scene = new QGraphicsScene;
    scene->setSceneRect(0, 0, widget.graphicsView->width() - 3, widget.graphicsView->height() - 3); //wielkosc okienka do rysowania
    widget.graphicsView->setScene(scene); 

    connect(widget.LoadButton, SIGNAL(clicked()), this, SLOT(findFile())); //wybor pliku
    connect(widget.PlayButton, SIGNAL(clicked()), this, SLOT(play())); //sygnal play
    connect(widget.PauseButton, SIGNAL(clicked()), this, SLOT(pause())); //sygnal pauza
    connect(widget.StopButton, SIGNAL(clicked()), this, SLOT(stop())); //sygnal stop

}

MWindow::~MWindow() {
}

//otwiera okienko wyboru pliku, po czym laduje go do playera

void MWindow::findFile() {
    if(!this->playerPlaying){
        fileName = dialog.getOpenFileName(this, tr("Open file"), "/home/kryszak", tr("Music files(*.mp3)")); //okienko wyboru pliku
        QFileInfo f(fileName);
        widget.fileNameLabel->setText(f.fileName()); //ustawienie nazwy pliku w pasku
    }
}

void MWindow::drawSpectrum() {


    scene->clear(); //wyczysc scene
    int j = 20; //startowy X pierwszego slupka
    //ustawianie koloru rysujacego dlugopisu
    float r = 255, g = 0, b = 0;
    QColor color(r, g, b);
    QPen pen(color);
    int band_width = widget.graphicsView->width()/8;
    pen.setWidth(band_width);
    int bands = 8; //ilosc slupkow
    double spectrum[bands]; //tablica danych do rysowania
    int bandLimit[] = {                     //tablica logarytmicznych odstepow do sumowania WYWALIC PRAZEK 0
       1, 2, 5, 10, 23, 49, 108, 235, 512
    };
    
    //sumuj czestotliwosci, skaluj
    for (int i = 0; i < bands; i++) {
        
        for (int q = bandLimit[i]; q < bandLimit[i+1]; q++) {
            spectrum[i] += player->magnitude[q];
        }
         
        spectrum[i] = spectrum[i]/(bandLimit[i+1] - bandLimit[i]); //skalowanie SPRAWDZIC
    }
   
    //rysowanie slupkow
    for (int i = 0; i < bands; i++) {
        scene->addLine(j, 211, j, 211 - spectrum[i], pen);
        j += band_width;
        r += 60;
        color.setHsv(r, 255, 255);
        pen.setColor(color);
    }
    r = 255;
}

//rozpoczyna/kontynuuje odtwarzanie
void MWindow::play() {
    if (!playerPlaying) {
        cout << "Playing!" << endl;
        this->player = new Mp3Player(); //stworz nowy odtwarzacz
        player->path = fileName.toUtf8().constData(); //konwersja nazwy pliku do formatu mpg123

        connect(player, &Mp3Player::finished, player, &QObject::deleteLater); //sygnal zakonczenia odtwarzania
        connect(player, &Mp3Player::finished, this, &MWindow::finishedPlaying);
        connect(player, SIGNAL(spectrumReady()), this, SLOT(drawSpectrum())); //sygnal gotowosci danych ze slotem rysowania
        playerPlaying = true; //ustaw flage odtwarzania
        player->start(); //rozpocznij watek odtwarzacza
    }
    player->paused = false; //wyczysc flage odtwarzania
}

//pauzuje odtwarzanie
void MWindow::pause() {
    cout << "Pause!" << endl;
    player->paused = true; //ustawienie flagi pauzy
}

//zatrzymuje odtwarzanie
void MWindow::stop() {
    //jezeli player odtwarza, zatrzymaj
    if (playerPlaying) {
        cout << "Stop!" << endl;
        this->player->terminate(); //zabicie watku playera
        playerPlaying = false; //wyczyszczenie flagi odtwarzania
    }
}

//czysci zmienne boolowskie kontrolujace odtwarzacz
void MWindow::finishedPlaying() {
    playerPlaying = false; //flaga odtwarzania
    scene->clear(); //wyczyszczenie sceny
}
