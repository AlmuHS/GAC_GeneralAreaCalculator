/*********************************************/
/* Cabecera: Definicion de la clase area

Descripción: Define la clase area, la cual muestra el menu de tipo de figura

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

#include <cstdlib>
#include <iostream>
#include "../validar.h"
#include "planas.h"
#include "tridimensional.h"


class area{
    int seleccion;
    planas fig_plana;
    tridimensional tres_d;
    public:
        area();
        int menu();
        void operacion();
};

