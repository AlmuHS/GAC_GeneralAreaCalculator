/*********************************************/
/* Cabecera: Definicion de la clase curvos

Descripción: Define la clase curvos, la cual permite calcular el area de figuras derivadas del circulo

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

#ifndef CURVOS_H
#define CURVOS_H

#include <iostream>
#include <cmath>

class curvos
{
    float area;
    public:
        curvos();
        void intro_valores(float &radio, int dimension);
        void intro_valores (float &semiejex, float &semiejey);
        void intro_valores(float &semiejex, float &semiejey, float &semiejez);
        float calcular_area (float radio, int dimension);
        float calcular_area (float semiejex, float semiejey);
        float calcular_area(float semiejex, float semiejey, float semiejez);
        void imprimir_area();
};

#endif // CURVOS_H
