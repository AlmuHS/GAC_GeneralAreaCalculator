/*********************************************/
/* Programa: Area de prismas

Descripción: Calcula el area de los prismas (cilindro y prisma),
clasificandolas segun sus parametros mediante sobrecarga de metodos
Pide por teclado los parametros de la misma y muestra por pantalla su area

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

#include "prismas.h"

using namespace std;

prismas::prismas()
{
    //ctor
    area=0;
    lado=0;
}

//parametros prisma
void prismas::intro_valores(int &num_lado, float &altura){
    do{
        cout<<"Numero de lados del poligono: ";
        cin>>num_lado;
        if(num_lado<3) cout<<"Error: El numero de lados debe ser mayor que dos";
    }while(num_lado<3);
    polig.intro_valores(num_lado, lado);//parametros area poligono regular
    do{
        cout<<"\nAltura del prisma: ";
        cin>>altura;
        if (altura<=0) cout<<"Error: La altura del prisma debe ser mayor que cero";
    }while (altura<=0);
}

//parametros cilindro
void prismas::intro_valores(float &radio, float &altura){
    do{
        cout<<"Altura del cilindro: ";
        cin>>altura;
        cout<<"Radio de la base: ";
        cin>>radio;
        if(altura<=0||radio<=0) cout<<"Error: Las longitudes deben ser mayores que cero";
    }while (altura<=0||radio<=0);
}

float prismas::calcular_area(float radio, float altura){
    area=2*M_PI*radio*(altura+radio);//area cilindro
    return area;
}

float prismas::calcular_area(int num_lado, float altura){
    float area_pol=polig.calcular_area(num_lado, lado);
    float perimetro=polig.perimetro();
    area=perimetro*altura+2*area_pol;
    return area;
}

void prismas::imprimir_area(){
    cout<<"El area es "<<area;
}

