QT       += core gui
QT       += webkit

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GAC
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

RESOURCES += \
    resource.qrc
