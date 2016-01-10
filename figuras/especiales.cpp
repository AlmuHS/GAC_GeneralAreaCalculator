/*********************************************/
/* Programa: Area de figuras especiales

Descripción: Calcula el area de figuras planas que no entran en ninguna categoria,
clasificandolas segun sus parametros mediante sobrecarga de los metodos
Pide por teclado los parametros de la misma (longitudes de sus lados y angulo),
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

#include "especiales.h"

using namespace std;

especiales::especiales()
{
    //ctor
    area=0;
}

void especiales::intro_valores(float &lado1, float &lado2, float &angulo){//parametros paralelogramo
    do{
        cout<<"Longitud lado 1: ";
        cin>>lado1;
        cout<<"\nLongitud lado 2: ";
        cin>>lado2;
        if(lado1<=0||lado2<=0) cout<<"Error: Las longitudes de los lados deben ser mayores que cero";
    }while(lado1<=0||lado2<=0);
    cout<<"\nAngulo: ";
    cin>>angulo;
}

void especiales::intro_valores(float &lado1, float &angulo){//parametros rombo
    do{
        cout<<"\nLongitud de los lados: ";
        cin>>lado1;
        if(lado1<=0) cout<<"Error: La longitud de los lados debe ser superior a cero";
    }while(lado1<=0);
    cout<<"\nAngulo: ";
    cin>>angulo;
}

void especiales::intro_valores(float &lado1, float &lado2, float &lado3, float &lado4){//parametros trapecio
    do{
        cout<<"Longitud lado 1: ";
        cin>>lado1;
        cout<<"\nLongitud lado 2: ";
        cin>>lado2;
        cout<<"\nLongitud lado 3: ";
        cin>>lado3;
        cout<<"\nLongitud lado 4: ";
        cin>>lado4;
        if(lado1<=0||lado2<=0||lado3<=0||lado4<=0) cout<<"Error: Las longitudes de los lados deben ser mayores que cero";
    }while(lado1<=0||lado2<=0||lado3<=0||lado4<=0);
}

float especiales::calcular_area(float lado1, float lado2, float angulo){
    area=sin(angulo)*lado1*lado2;//area paralelogramo
    if (sin(angulo)<0) area=area*(-1);
    return area;
}

float especiales::calcular_area(float lado1, float angulo){//area rombo
    area=pow(lado1, 2)*sin(angulo);
    if (sin(angulo)<0) area=area*(-1);
    return area;
}

float especiales::calcular_area(float lado1, float lado2, float lado3, float lado4){//area trapecio
    float tmp=0, tmp2=0;
    tmp=(lado1+lado3)/(4*(lado1-lado3));
    tmp2=(lado2+lado3+lado4-lado1)*(lado1-lado2+lado3+lado4)*(lado1-lado2+lado3-lado4)*(lado1-lado2-lado3+lado4);
    if (tmp2<=0) area=-1;
    else area=(sqrt(tmp2))*tmp;
    return area;
}

void especiales::imprimir_area(){
    if (area<=0) cout<<"No existe ninguna figura con esas medidas";
    else cout<<"El area es "<<area;
}
