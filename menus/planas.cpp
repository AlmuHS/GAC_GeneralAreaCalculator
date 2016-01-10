/*********************************************/
/* Programa: Menu de figuras planas

Descripción: Muestra un menu con el listado de figuras planas,
y permite acceder a una subcategoria o calcular un area

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

#include "planas.h"

using namespace std;

planas::planas(){
    seleccion=0;
}


int planas::menu(){
    cout<< "\n\n\t\t----------------------------------------------" << endl
        << "\t\t--------------  Figuras planas  --------------" << endl
        << "\t\t----------------------------------------------" << endl
        << "\n\t\t\t 1.Figuras curvas " << endl
        << "\n\t\t\t 2.Poligonos regulares." << endl
        << "\n\t\t\t 3.Poligonos especiales." << endl
        //<< "\n\t\t\t 4.Regresar al menu anterior." << endl;
        //<< "\n\t\t\t 5.Salir del programa." << endl;
        << "\n\t\t----------------------------------------------" << endl;
    seleccion=validar(3);
    return seleccion;
}

void planas::operacion(){
    switch(seleccion){
        case 1:
            //menu figuras circulares
            circular.menu();
            circular.operacion();
        break;

        case 2:
            //area poligonos
            int num_lado;
            float lado, lado1, lado2, lado3;
            do{
                cout<<"\nNumero de lados: ";
                cin>>num_lado;
                if(num_lado<3) cout<<"Error: el numero de lados debe ser mayor que dos";
            }while(num_lado<3);

            if (num_lado==3){//area triangulo
                poli.intro_valores(lado1, lado2, lado3);//paso por referencia
                poli.calcular_area(lado1, lado2, lado3);
            }
            else if(num_lado==4){//area rectangulo
                poli.intro_valores(lado1, lado2);//paso por referencia
                poli.calcular_area(lado1, lado2);
            }
            else{//area poligonos regulares
                poli.intro_valores(num_lado, lado);//paso por referencia
                poli.calcular_area(num_lado, lado);
            }
            poli.imprimir_area();

        break;

        case 3:
            //menu poligonos especiales
            especial.menu();
            especial.operacion();
        break;
    }
}


