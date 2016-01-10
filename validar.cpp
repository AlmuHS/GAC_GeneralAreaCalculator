/*********************************************/
/* Programa: Validador de caracteres

Descripción: Analiza el valor introducido por teclado, guardando los enteros entre 0 y 9,
y rechazando todo lo demas.


Autor: Cristian Corado Cordero

Año 2011 2012*/
/*********************************************/

/* Copyright 2012 Cristian Corado Cordero
    This file is part of GAC.

    GAC is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    GAC is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with GAC.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "validar.h"

using namespace std;

int validar(int num_opciones){
    bool pasar;
    int opcion=0;
    string ingreso;
    do{
        cout << "\t\tSeleccione una opcion: ";
        cin>>ingreso;

        istringstream convert(ingreso);

        if(ingreso=="1"){convert>>opcion; pasar=1;}
        if(ingreso=="2"){convert>>opcion; pasar=1;}
        if(ingreso=="3"){convert>>opcion; pasar=1;}
        if(ingreso=="4"){convert>>opcion; pasar=1;}
        if(ingreso=="5"){convert>>opcion; pasar=1;}
        if(ingreso=="6"){convert>>opcion; pasar=1;}
        if(ingreso=="7"){convert>>opcion; pasar=1;}
        if(ingreso=="8"){convert>>opcion; pasar=1;}
        if(ingreso=="9"){convert>>opcion; pasar=1;}
        if(ingreso=="0"){convert>>opcion; pasar=1;}
        if(opcion>num_opciones||opcion==0){
            pasar=0;
        };
    }
    while(!pasar);
    return opcion;
}

