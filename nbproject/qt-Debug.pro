# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Debug/GNU-Linux-x86
TARGET = Audio_Spectrum
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += debug 
PKGCONFIG +=
QT = core gui widgets
SOURCES += FrequencyBin.cpp MWindow.cpp Mp3Player.cpp kissfft/kiss_fft.c kissfft/kiss_fftr.c main.cpp
HEADERS += FrequencyBin.h MWindow.h Mp3Player.h kissfft/kiss_fft.h kissfft/kiss_fftr.h
FORMS += MWindow.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Debug/GNU-Linux-x86
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += 
INCLUDEPATH += 
LIBS += -lmpg123 -lao  
