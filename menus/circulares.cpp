/*********************************************/
/* Programa: Menu figuras circulares

Descripción: Muestra el listado de figuras circulares (circulo y elipse) y permite calcular sus areas

Autor: Almudena Garcia Jurado-Centurion

Año 2011 2012 2013*/
/*********************************************/

/* Copyright 2011 2012 2013 Almudena García Jurado-Centurión
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

#include "circulares.h"

using namespace std;

circulares::circulares(){
    seleccion=0;
}

int circulares::menu(){
    cout<< "\n\n\t\t----------------------------------------------" << endl
        << "\t\t--------------  Figuras curvas  --------------" << endl
        << "\t\t----------------------------------------------" << endl
        << "\n\t\t\t 1.Circulo. " << endl
        << "\n\t\t\t 2.Elipse." << endl
        //<< "\n\t\t\t 3.Sector circular." << endl
        //<< "\n\t\t\t 4.Regresar al menu anterior." << endl
        //<< "\n\t\t\t 5.Salir del programa." << endl
        << "\n\t\t----------------------------------------------" << endl;
    seleccion=validar(2);
    return seleccion;
}

void circulares::operacion(){
    float semiejex=0, semiejey=0, radio=0;
    switch(seleccion){
        case 1:
            curvas.intro_valores(radio, 2);//paso por referencia
            curvas.calcular_area(radio, 2);
        break;

        case 2:
            curvas.intro_valores(semiejex, semiejey);//paso por referencia
            curvas.calcular_area(semiejex, semiejey);
        break;
    }
    curvas.imprimir_area();
}
