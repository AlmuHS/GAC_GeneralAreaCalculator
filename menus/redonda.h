/*********************************************/
/* Cabecera: Definicion de la clase redonda

Descripción: Define la clase redonda, la cual calcula el muestra el menu de figuras redondas

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
#include "../figuras/curvos.h"
#include "../figuras/piramidales.h"
#include "../figuras/prismas.h"

class redonda{
    int seleccion;
    curvos redondos;
    piramidales cono;
    prismas cilindro;
    public:
        redonda();
        int menu();
        void operacion();
};

