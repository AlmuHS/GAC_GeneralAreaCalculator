/*********************************************/
/* Programa: Area de poligonos

Descripción: Calcula el area de los poligonos, pidiendo y pasando por parametro el numero de lados
y las longitudes de los mismos
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

#include "poligonos.h"

using namespace std;

poligonos::poligonos(){
    area=0;
}

//parametros poligono regular
void poligonos::intro_valores(int &num_lado, float &lado){;
    num_lados=num_lado;
    do{
        cout<<"\nLongitud de los lados: ";
        cin>>lado;
        if(lado<=0) cout<<"Error: La longitud de los lados debe ser mayor que cero";
    }while(lado<=0);
}

//parametros rectangulo
void poligonos::intro_valores(float &base, float &altura){
    num_lados=2;
    do{
        cout<<"\nLongitud de la base: ";
        cin>>base;
        cout<<"\nAltura: ";
        cin>>altura;
        if(base<=0||altura<=0) cout<<"Error: Las longitudes de los lados deben ser mayores que cero";
    }while(base<=0||altura<=0);
}

//parametros triangulo
void poligonos::intro_valores(float &lado1, float &lado2, float &lado3){
   num_lados=3;
   do{
        cout<<"Longitud lado1: ";
        cin>>lado1;
        cout<<"Longitud lado2: ";
        cin>>lado2;
        cout<<"Longitud lado3: ";
        cin>>lado3;
        if(lado1<=0||lado2<=0||lado3<=0) cout<<"Error: Las longitudes de los lados deben ser mayores que cero";
    }while(lado1<=0||lado2<=0||lado3<=0);
}

//area poligono regular
float poligonos::calcular_area(int num_lado, float lado){
    float tmp=0, tmp2=0;
    tmp=(pow(num_lado,2)*num_lado)/4;
    tmp2=tan(M_PI_2*(num_lado-2)/num_lado);
    area=tmp*tmp2;
    return area;
}

//area rectangulo
float poligonos::calcular_area(float base, float altura){
    area=base*altura;
    return area;
}

//area triangulo
float poligonos::calcular_area(float lado1, float lado2, float lado3){
    float p=(lado1+lado2+lado3)/2;
    float tmp=p*(p-lado1)*(p-lado2)*(p-lado3);
    if(tmp<=0) area=-1;
    else area=sqrt(tmp);
    return area;
}

void poligonos::imprimir_area(){
    if(area<=0) cout<<"Error: No existe ninguna figura con esas medidas";
    else cout<<"El area es "<<area;
}

float poligonos::perimetro(){
    float perimetro=0;
    switch(num_lados){
        case 3:
            perimetro=lado1+lado2+lado3;
        break;

        case 4:
            perimetro=2*(lado1+lado2);
        break;

        default:
            perimetro=num_lados*lado1;
        break;
    }
    return perimetro;
}
