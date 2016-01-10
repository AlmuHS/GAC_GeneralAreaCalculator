/*********************************************/
/* Programa: Area de figuras piramidales

Descripción: Calcula el area de figuras piramidales (cono y piramide),
clasificandolas segun sus parametros mediante sobrecarga de metodos
Pide por teclado los parametros de la misma y muestra por pantalla su area

Autor: Almudena Garcia Jurado-Centurion

Año 2011 2012 2013*/
/*********************************************/

/* Copyright 2011 2012 2013Almudena García Jurado-Centurión
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

#include "piramidales.h"

using namespace std;

piramidales::piramidales()
{
    //ctor
    lado1=0;
    lado2=0;
    lado3=0;
    num_lado=0;
    area=0;
}

void piramidales::intro_valores(float &radio, float &altura){
    do{
        cout<<"\nRadio de la base: ";
        cin>>radio;
        cout<<"Altura del cono: ";
        cin>>altura;
        if (radio<=0||altura<=0) cout<<"Error: Las longitudes deben ser mayores que cero";
    }while (radio<=0||altura<=0);
}

void piramidales::intro_valores(int &num_lado){
    cout<<"Parametros del triangulo: \n";
    tri.intro_valores(lado1, lado2, lado3);
    cout<<"Parametros del poligono base: \n";
    do{
        cout<<"\nNumero de lados de la base: ";
        cin>>num_lado;
        if (num_lado<3) cout<<"Error: El numero de lados debe ser mayor que dos";
    }while (num_lado<3);
    poli.intro_valores(num_lado, lado1);
}

float piramidales::calcular_area(float radio, float altura){//area cono
    float tmp=0, tmp2=0, tmp3=0;
    tmp=pow(radio,2);
    tmp2=pow(altura,2);
    if((tmp+tmp2)<=0) area=-1;
    else{
        tmp3=sqrt(tmp+tmp2);
        area=M_PI*radio*(radio+tmp3);
    }
    return area;
}

float piramidales::calcular_area(int num_lado){
    float area_t=tri.calcular_area(lado1, lado2, lado3);
    float area_p=poli.calcular_area(num_lado, lado1);
    if(area_t<=0 || area_p<=0) area=-1;
    else area=(area_t*num_lado)+area_p;
    return area;
}

void piramidales::imprimir_area(){
    if(area<=0) cout<<"Error: No existe ninguna figura con esas medidas";
    else cout<<"El area es "<<area;
}
