// Copyright (C) 2013 José Miguel Ruiz Torres <jmruizt.94@gmail.com>

/* This file is part of GAC.

GAC is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

GAC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with GAC. If not, see <http://www.gnu.org/licenses/>. */

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createActions();
    createMenu();
    createDictionary();
    createDock();
    createStatusBar();

    tab = new QTabWidget;
    tab->addTab(new TabOperations, QIcon(":/images/menu/operaciones.png"), trUtf8("Operaciones"));
    tab->addTab(new TabPlane, QIcon(":/images/menu/plana.png"), trUtf8("Planas"));
    tab->addTab(new TabThreeDimensional, QIcon(":/images/menu/tridimensional.png"), trUtf8("Tridimensionales"));
    tab->setTabPosition(QTabWidget::West);

    setCentralWidget(tab);
}

void MainWindow::createActions(){
    exitAct = new QAction(QIcon(":/images/menu/exit.png"), trUtf8("&Salir"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    exitAct->setStatusTip(trUtf8("Salir del programa."));
    connect(exitAct, SIGNAL(triggered()), qApp, SLOT(quit()));
}

void MainWindow::createMenu(){
    figura = new QMenu;
    figura = menuBar()->addMenu(trUtf8("&Figura"));

    plana = new QMenu;
    plana = figura->addMenu(QIcon(":/images/menu/plana.png"), trUtf8("&Plana"));

    circular = new QMenu;
    circular = plana->addMenu(QIcon(":/images/menu/circular.png"), trUtf8("&Circular"));

    poligonal = new QMenu;
    poligonal = plana->addMenu(QIcon(":/images/menu/poligonal.png"), trUtf8("&Poligonal"));

    tridimensional = new QMenu;
    tridimensional = figura->addMenu(QIcon(":/images/menu/tridimensional.png"), trUtf8("&Tridimensional"));

    redonda = new QMenu;
    redonda = tridimensional->addMenu(QIcon(":/images/menu/redonda.png"), trUtf8("&Redonda"));

    figura->addSeparator();
    figura->addAction(exitAct);

    ver = new QMenu;
    ver = menuBar()->addMenu(trUtf8("&Ver"));

    ayuda = new QMenu;
    ayuda = menuBar()->addMenu(trUtf8("&Ayuda"));
}

void MainWindow::createDictionary(){
    dictionary = new QDockWidget(trUtf8("Diccionario"));
    dictionary->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

    browser = new QWebView(this);
    browser->load(QUrl("qrc:///diccionario/index.html"));

    dictionary->setWidget(browser);

    ver->addAction(dictionary->toggleViewAction());
    addDockWidget(Qt::RightDockWidgetArea, dictionary);
}

void MainWindow::createDock(){
    dock = new QDockWidget(trUtf8("Línea de órdenes"));
    dock->setAllowedAreas(Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea);
    dock->setFixedHeight(150);

    QWidget *dockWidget = new QWidget;

    QVBoxLayout *vLayout = new QVBoxLayout;
    QHBoxLayout *hLayout = new QHBoxLayout;

    terminal = new QTextEdit;
    terminal->setReadOnly(true);
    prompt = new QLabel(trUtf8("GAC-engine-v0.8~>"));
    command = new QLineEdit;
    send = new QPushButton(trUtf8("Enviar"));

    hLayout->addWidget(prompt);
    hLayout->addWidget(command);
    hLayout->addWidget(send);

    vLayout->addWidget(terminal);
    vLayout->addLayout(hLayout);

    dockWidget->setLayout(vLayout);

    dock->setWidget(dockWidget);

    ver->addAction(dock->toggleViewAction());
    addDockWidget(Qt::BottomDockWidgetArea, dock);
}

void MainWindow::createStatusBar(){
   statusBar()->showMessage(trUtf8("Listo."), 2000);
}

TabOperations::TabOperations(QWidget *parent)
    : QWidget(parent)
{

}

TabPlane::TabPlane(QWidget *parent)
    : QWidget(parent)
{
    grilla = new QGridLayout;
    grilla->addWidget(cir(), 0, 0);
    grilla->addWidget(pol(), 1, 0);

    setLayout(grilla);
}

QGroupBox *TabPlane::cir(){
    QGroupBox *groupBox = new QGroupBox(trUtf8("Circulares"));

    QGridLayout *grid = new QGridLayout;

    cirButton = new QPushButton(QIcon(":/images/planas/circulo.png"), trUtf8("Círculo"));
    eliButton = new QPushButton(QIcon(":/images/planas/elipse.png"), trUtf8("Elipse"));

    grid->addWidget(cirButton, 0, 0);
    grid->addWidget(eliButton, 0, 1);

    groupBox->setLayout(grid);
    return groupBox;
}

QGroupBox *TabPlane::pol(){
    QGroupBox *groupBox = new QGroupBox(trUtf8("Poligonales"));

    QGridLayout *grid = new QGridLayout;

    regButton = new QPushButton(QIcon(":/images/planas/regular.png"), trUtf8("Polígono regular"));
    recButton = new QPushButton(QIcon(":/images/planas/rectangulo.png"), trUtf8("Rectángulo"));
    triButton = new QPushButton(QIcon(":/images/planas/triangulo.png"), trUtf8("Triángulo"));
    romButton = new QPushButton(QIcon(":/images/planas/rombo.png"), trUtf8("Rombo"));
    parButton = new QPushButton(QIcon(":/images/planas/paralelogramo.png"), trUtf8("Paralelogramo"));
    traButton = new QPushButton(QIcon(":/images/planas/trapecio.png"), trUtf8("Trapecio"));

    grid->addWidget(regButton, 0, 0);
    grid->addWidget(recButton, 0, 1);
    grid->addWidget(triButton, 1, 0);
    grid->addWidget(romButton, 1, 1);
    grid->addWidget(parButton, 2, 0);
    grid->addWidget(traButton, 2, 1);

    groupBox->setLayout(grid);
    return groupBox;
}

TabThreeDimensional::TabThreeDimensional(QWidget *parent)
    : QWidget(parent)
{
    grilla = new QGridLayout;
    grilla->addWidget(red(), 0, 0);
    grilla->addWidget(res(), 1, 0);

    setLayout(grilla);
}

QGroupBox *TabThreeDimensional::red(){
    QGroupBox *groupBox = new QGroupBox(trUtf8("Redondas"));

    QGridLayout *grid = new QGridLayout;

    esfButton = new QPushButton(QIcon(":/images/tridimensionales/esfera.png"), trUtf8("Esfera"));
    eliButton = new QPushButton(QIcon(":/images/tridimensionales/elipsoide.png"), trUtf8("Elipsoide"));
    conButton = new QPushButton(QIcon(":/images/tridimensionales/cono.png"), trUtf8("Cono"));
    cilButton = new QPushButton(QIcon(":/images/tridimensionales/cilindro.png"), trUtf8("Cilindro"));

    grid->addWidget(esfButton, 0, 0);
    grid->addWidget(eliButton, 0, 1);
    grid->addWidget(conButton, 1, 0);
    grid->addWidget(cilButton, 1, 1);

    groupBox->setLayout(grid);
    return groupBox;
}

QGroupBox *TabThreeDimensional::res(){
    QGroupBox *groupBox = new QGroupBox;

    QGridLayout *grid = new QGridLayout;

    polButton = new QPushButton(QIcon(":/images/tridimensionales/poliedro.png"), trUtf8("Poliedro"));;
    priButton = new QPushButton(QIcon(":/images/tridimensionales/prisma.png"), trUtf8("Prisma"));;
    pirButton = new QPushButton(QIcon(":/images/tridimensionales/piramide.png"), trUtf8("Pirámide"));;

    grid->addWidget(polButton, 0, 0);
    grid->addWidget(priButton, 0, 1);
    grid->addWidget(pirButton, 1, 0);

    groupBox->setLayout(grid);
    return groupBox;
}

MainWindow::~MainWindow(){}
