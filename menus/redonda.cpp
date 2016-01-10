/*********************************************/
/* Programa: Menu figuras redondas

Descripción: Muestra el listado de figuras redondas (esfera, elipsoide...)
y permite calcular sus areas

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


#include "redonda.h"

using namespace std;

redonda::redonda(){
    seleccion=0;
}

int redonda::menu(){
    cout<<setw(20)<<setfill('*')<<""<<endl;
    cout<<"\n1. Esfera"
        <<"\n2. Elipsoide"
        <<"\n3. Cono"
        <<"\n4. Cilindro"<<endl;
    seleccion=validar(4);
    return seleccion;
}

void redonda::operacion(){
    float semiejex, semiejey, semiejez, radio;
    float altura=0;
    switch (seleccion){
        case 1:
            //area esfera
            redondos.intro_valores(radio, 3);//paso por referencia
            redondos.calcular_area(radio, 3);//La esfera es una figura espacial, por lo que tiene 3 dimensiones
            redondos.imprimir_area();
        break;

        case 2:
            //area elipsoide
            redondos.intro_valores(semiejex, semiejey, semiejez);//paso por referencia
            redondos.calcular_area(semiejex, semiejey, semiejez);
            redondos.imprimir_area();
        break;

        case 3:
            //area cono
            cono.intro_valores(radio, altura); //paso por referencia
            cono.imprimir_area();
        break;

        case 4:
            //area cilindro
            float altura, radio;
            cilindro.intro_valores(radio, altura);//paso por referencia
            cilindro.calcular_area(radio, altura);
            cilindro.imprimir_area();
        break;
    }
}
