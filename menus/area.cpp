/*********************************************/
/* Programa: Menu areas

Descripción: Muestra un menu preguntando por el tipo de figura: plana o tridimensional,
y muestra el listado de subcategorias correspondientes a cada caso

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

#include "area.h"

using namespace std;

area::area(){
    seleccion=0;
}

int area::menu(){
    cout<< "\n\n\t\t----------------------------------------------" << endl
        << "\t\t-- Geometria:  Figuras planas y espaciales. --" << endl
        << "\t\t----------------------------------------------" << endl
        << "\n\t\t\t 1.Figuras planas " << endl
        << "\n\t\t\t 2.Figuras espaciales." << endl
        //<< "\n\t\t\t 3.Regresar al menu anterior." << endl
        //<< "\n\t\t\t 4.Salir del programa." << endl
        << "\n\t\t----------------------------------------------" << endl;
        //<< "\t\tSeleccione una opcion: ";
    seleccion=validar(2);//recoge el caracter introducido y lo evalua
return seleccion;
}


void area::operacion(){
    char opcion='n';
        switch(seleccion){
            case 1:
                fig_plana.menu();
                fig_plana.operacion();
            break;

            case 2:
                //figuras espaciales
                tres_d.menu();
                tres_d.operacion();
            break;
        }
        do{
            cout<<"\n¿Desea hacer otra operacion? (s/n): ";
            cin>>opcion;
            if(opcion!='s'&&opcion!='n') cout<<"\nError: Las opciones permitidas son 's' o 'n' ";
        }while(opcion!='s'&&opcion!='n');
        if(opcion=='s'){
            system("clear");
            menu();
            operacion();
        }
}
