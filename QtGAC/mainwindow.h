// Copyright (C) 2013 José Miguel Ruiz Torres <jmruizt.94@gmail.com>

/* This file is part of GAC.

GAC is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

GAC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with GAC. If not, see <http://www.gnu.org/licenses/>. */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QTabWidget>
#include <QMessageBox>
#include <QLabel>
#include <QDockWidget>
#include <QtWebKit/QWebView>
#include <QTextEdit>
#include <QLabel>
#include <QLineEdit>
#include <QGroupBox>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QImage>
#include <QPixmap>
#include <QIcon>
#include <QStatusBar>

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void createActions();
    void createMenu();
    void createDictionary();
    void createDock();
    void createStatusBar();

    QAction *exitAct;

    QMenu *figura, *ver, *ayuda;
    QMenu *plana, *tridimensional;
    QMenu *circular, *poligonal;
    QMenu *redonda;

    QTabWidget *tab;
    QDockWidget *dictionary, *dock;
    QWebView *browser;

    QTextEdit *terminal;
    QLabel *prompt;
    QLineEdit *command;
    QPushButton *send;
};

class TabOperations : public QWidget
{
    Q_OBJECT

public:
    TabOperations(QWidget *parent = 0);
};

class TabPlane : public QWidget
{
    Q_OBJECT

public:
    TabPlane(QWidget *parent = 0);

private:
    QGroupBox *cir();
    QGroupBox *pol();
    QGridLayout *grilla;

    QPushButton *cirButton, *eliButton;
    QPushButton *regButton, *recButton, *triButton, *romButton, *parButton, *traButton;
};

class TabThreeDimensional : public QWidget
{
    Q_OBJECT

public:
    TabThreeDimensional(QWidget *parent = 0);

private:
    QGroupBox *red();
    QGroupBox *res();
    QGridLayout *grilla;

    QPushButton *esfButton, *eliButton, *conButton, *cilButton;
    QPushButton *polButton, *priButton, *pirButton;
};

#endif // MAINWINDOW_H
