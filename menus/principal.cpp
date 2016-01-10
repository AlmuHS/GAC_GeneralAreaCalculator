/*********************************************/
/* Programa: Menu principal de GAC

Descripción: Muestra un menu con dos opciones: calcular area o salir del programa,
y ejecuta las acciones correspondientes a cada opcion

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

#include "principal.h"

using namespace std;

principal::principal(){
    seleccion=0;
    salir='n';
}

int principal::salida(){
    return 0;
}


int principal::menu(){
    cout<< "\n\n\t\t----------------------------------------------" << endl
        << "\t\t- Geometria: Areas, superficies o volumenes. -" << endl
        << "\t\t----------------------------------------------" << endl
        << "\n\t\t\t 1.Figuras planas y espaciales. " << endl
        << "\n\t\t\t 2.Figuras a partir de sus puntos." << endl
        << "\n\t\t\t 3.Salir." << endl
        << "\n\t\t----------------------------------------------" << endl;
    seleccion=validar(2);
    return seleccion;
}

void principal::operacion(){
    switch(seleccion){
        case 1:
            areas.menu();
            areas.operacion();
        break;

        case 2:
            do{
                cout<<"Desea salir del programa? (s/n): ";
                cin>>salir;
                if (salir=='s'||salir=='S') salida();
                else if (salir=='n'||salir=='N'){
                    menu();
                    operacion();
                }
                else cout<<"Opcion incorrecta\n";
            }while (salir!='n'&&salir!='N'&&salir!='s'&&salir!='S');
        break;
    }
}
