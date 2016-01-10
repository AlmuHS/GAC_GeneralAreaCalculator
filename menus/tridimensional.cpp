/*********************************************/
/* Programa: Menu de figuras tridimensionales

Descripción: Muestra un menu con el listado de figuras tridimensionales,
y permite acceder a una subcategoria o calcular un area

Autor: Almudena Garcia Jurado-Centurion

Año 2011 2012*/
/*********************************************/

/* Copyright 2011 2012 Almudena García Jurado-Centurión
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

#include "tridimensional.h"

using namespace std;

tridimensional::tridimensional(){
    seleccion=0;
}

int tridimensional::menu(){
    cout<< "\n\n\t\t----------------------------------------------" << endl
        << "\t\t------------  Figuras espaciales  ------------" << endl
        << "\t\t----------------------------------------------" << endl
        << "\n\t\t\t 1.Redonda." << endl
        << "\n\t\t\t 2.Poliedrica." << endl
        << "\n\t\t\t 3.Prisma." << endl
        << "\n\t\t\t 4.Piramidal."<<endl
        //<< "\n\t\t\t 5.Regresar al menu anterior." << endl;
        //<< "\n\t\t\t 6.Salir del programa." << endl;
        << "\n\t\t----------------------------------------------" << endl;
    seleccion=validar(4);
    return seleccion;
}

void tridimensional::operacion(){
    int num_lado=0;
    float altura=0;
    switch(seleccion){
        case 1:
            //menu redonda
            redondo.menu();
            redondo.operacion();
        break;

        case 2:
            //area poliedros
            poli.intro_valores();
            poli.calcular_area();
            poli.imprimir_area();
        break;

        case 3:
            //area prisma
            prisma.intro_valores(num_lado, altura);//paso por referencia
            prisma.calcular_area(num_lado, altura);
            prisma.imprimir_area();
        break;

        case 4:
            //area piramide
            piramide.intro_valores(num_lado);//paso por referencia
            piramide.calcular_area(num_lado);
            piramide.imprimir_area();
        break;
    }
}
