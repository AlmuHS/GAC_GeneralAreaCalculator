/*********************************************/
/* Cabecera: Definicion de la clase tridimensional

Descripción: Define la clase tridimensional, la cual muestra el menu de figuras tridimensionales

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

#include <iostream>
#include "../validar.h"
#include "redonda.h"
#include "../figuras/poliedro.h"
#include "../figuras/prismas.h"
#include "../figuras/piramidales.h"

class tridimensional{
    int seleccion;
    redonda redondo;
    piramidales piramide;
    prismas prisma;
    poliedro poli;
    public:
        tridimensional();
        int menu();
        void operacion();
};
