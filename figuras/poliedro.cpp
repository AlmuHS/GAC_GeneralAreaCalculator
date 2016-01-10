/*********************************************/
/* Programa: Area del poliedro

Descripción: Calcula el area del poliedro
Pide por teclado los parametros de la misma
(numero de caras, numero de lados del poligono, y longitudes de los mismos)
y muestra por pantalla su area

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

#include "poliedro.h"

using namespace std;

poliedro::poliedro(){
    num_cara=0;
    area=0;
}

void poliedro::intro_valores(){
    do{
        cout<<"\nNumero de caras del poliedro: ";
        cin>>num_cara;
        if (num_cara<=0) cout<<"Error: El numero de caras debe ser mayor que cero";
    }while (num_cara<=0);
    do{
        cout<<"\nNumero de lados del poligono base: ";
        cin>>num_lado;
        if(num_lado<3) cout<<"Error: el numero de lados debe ser mayor que dos";
    }while(num_lado<3);
    poligono.intro_valores(num_lado, lado);
}

float poliedro::calcular_area(){
    float area_poligono=poligono.calcular_area(num_lado, lado);
    area=area_poligono*num_cara;
    return area;
}

void poliedro::imprimir_area(){
    if(area<=0) cout<<"No existe ninguna figura con esas medidas";
    else cout<<"El area es "<<area;
}
