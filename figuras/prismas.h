/*********************************************/
/* Cabecera: Definicion de la clase prismas

Descripción: Define la clase prismas, la cual calcula el area de prismas

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

#ifndef PRISMAS_H
#define PRISMAS_H

#include <iostream>
#include "poligonos.h"

class prismas
{
    float area;
    int num_lado;
    poligonos polig;
    float lado;

    public:
        prismas();
        void intro_valores(float &radio, float &altura);//parametros cilindro
        void intro_valores(int &num_lado, float &altura);//parametros prisma
        float calcular_area(float radio, float altura);
        float calcular_area(int num_lado, float altura);
        void imprimir_area();
};

#endif // PRISMAS_H
