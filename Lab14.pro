#-------------------------------------------------
#
# Project created by QtCreator 2018-05-15T17:20:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Lab12
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    Movie.cpp \
    MovieValidator.cpp \
    AdminDatabase.cpp \
    Exception.cpp \
    Controller.cpp \
    WatchList.cpp \
    CSVWatchList.cpp \
    HTMLWatchList.cpp \
    MoviesTableModel.cpp \
    MoviesView.cpp

HEADERS += \
        mainwindow.h \
    Movie.h \
    MovieValidator.h \
    AdminDatabase.h \
    Exception.h \
    Controller.h \
    WatchList.h \
    FileWatchList.h \
    CSVWatchList.h \
    HTMLWatchList.h \
    UndoAction.h \
    UndoAdd.h \
    UndoDelete.h \
    UndoUpdate.h \
    MoviesTableModel.h \
    MoviesView.h \
    UndoAddWL.h \
    UndoDeleteWL.h

FORMS += \
        mainwindow.ui \
    secondwindow.ui

DISTFILES += \
    ../Lab8-9/cpp/cpp/testWatchList.csv \
    ../Lab8-9/cpp/cpp/WatchList.csv \
    ../Lab8-9/cpp/cpp/WatchList.html \
    ../Lab8-9/cpp/cpp/testmovies.txt \
    watchlist.csv
