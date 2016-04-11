/*
 * File:   main.cpp
 * Author: kryszak
 *
 * Created on 1 kwietnia 2015, 20:43
 */
#include<iostream>
#include<QApplication>
#include"MWindow.h"

using namespace std;

int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);

    QApplication app(argc, argv);
    
    //utworzenie i pokazanie okna aplikacji
    
    MWindow w;
    w.show();
    // create and show your widgets here
    
    return app.exec();
}