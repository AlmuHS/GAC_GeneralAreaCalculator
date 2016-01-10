/*********************************************/
/* Programa: Menu figuras especiales

Descripción: Muestra un listado con aquellas figuras planas que no entran en el resto de categorias,
tales como rombo y trapecio; y permite calcular sus areas

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

#include "poli_especial.h"

using namespace std;

poli_especial::poli_especial(){
    seleccion=0;
}

int poli_especial::menu(){
    cout<<setw(20)<<setfill('*')<<""<<endl;
    cout<<"1. Rombo"
        <<"\n2. Paralelogramo"
        <<"\n3. Trapecio"<<endl;
    seleccion=validar(3);
    return seleccion;
}

void poli_especial::operacion(){
    float lado1=0, lado2=0, lado3=0, lado4=0, angulo=0;
    switch (seleccion){
        case 1:
            //area rombo
            especial.intro_valores(lado1, angulo);//paso por referencia
            especial.calcular_area(lado1, angulo);
        break;

        case 2:
            //area paralelogramo
            especial.intro_valores(lado1, lado2, angulo);//paso por referencia
            especial.calcular_area(lado1, lado2, angulo);
        break;

        case 3:
            //area trapecio
            especial.intro_valores(lado1, lado2, lado3, lado4);//paso por referencia
            especial.calcular_area(lado1, lado2, lado3, lado4);
        break;
    }
    especial.imprimir_area();
}
