/*********************************************/
/* Programa: Area de figuras curvas

Descripción: Calcula el area de figuras derivadas del circulo,
clasificandolas segun el numero de parametros que necesiten; mediante sobrecarga de los metodos intro_valores() y calcular_area()
Pide por teclado los parametros de la misma (radio o semiejes), y muestra por pantalla su area

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

#include "curvos.h"

using namespace std;

curvos::curvos()
{
    //ctor
    area=0;
}

//Pide el valor del radio para el circulo y la esfera, clasificandolos segun las dimensiones que tengan
void curvos::intro_valores(float &radio, int dimension){
    switch(dimension){
        case 2://radio circulo (como el circulo es una figura plana, tiene 2 dimensiones)
            do{
                cout<<"\nIntroduce el radio del circulo: ";
                cin>>radio;

                if (radio<=0) cout<<"Error: El radio debe ser mayor que cero";
            }while (radio<=0);
        break;

        case 3:
            do{//valores esfera (como la esfera es una figura espacial, tiene 3 dimensiones)
                cout<<"\nRadio del circulo central: ";
                cin>>radio;
                if (radio<=0) cout<<"Error: El radio debe ser mayor o igual que cero";
            }while (radio<=0);
        break;
    }
}

//Parametros elipse
void curvos::intro_valores(float &semiejex, float &semiejey){
    do{
        cout<<"Longitud semieje mayor: ";
        cin>>semiejex;
        cout<<"Longitud semieje menor: ";
        cin>>semiejey;
        if(semiejex<=0||semiejey<=0) cout<<"Error: Las longitudes de los semiejes deben ser mayores que cero";
    }while(semiejex<=0||semiejey<=0);
}

//Parametros elipsoide
void curvos::intro_valores(float &semiejex, float &semiejey, float &semiejez){
    do{
        cout<<"Longitud semieje x: ";
        cin>>semiejex;
        cout<<"\nLongitud semieje y: ";
        cin>>semiejey;
        cout<<"\nLongitud semieje z: ";
        cin>>semiejez;
        if (semiejex<=0||semiejey<=0||semiejez<=0) cout<<"Error: Las longitudes de los semiejes deben ser mayores que cero";
    }while (semiejex<=0||semiejey<=0||semiejez<=0);
}


//areas circulo y esfera
float curvos::calcular_area(float radio, int dimension){
    switch(dimension){
        case 2:
            area=M_PI*pow(radio,2);//area circulo
        break;

        case 3:
            area=4*M_PI*pow(radio,2);//area esfera
        break;
    }
    return area;
}

//area elipse
float curvos::calcular_area(float semiejex, float semiejey){
    area=M_PI*semiejex*semiejey;//area elipse
    return area;
}

//area elipsoide
float curvos::calcular_area(float semiejex, float semiejey, float semiejez){
    area=4*M_PI*pow((1/3*pow(semiejex*semiejey,1.6)+pow(semiejex*semiejez,1.6)+pow(semiejey*semiejez,1.6)),0.62);
    return area;
}

void curvos::imprimir_area(){
    if (area<=0) cout<<"Error: No existe ninguna figura con las medidas indicadas";
    cout<<"El area es "<<area;
}


