/*********************************************/
/* Cabecera: Definicion de la clase especiales

Descripción: Define la clase especiales, la cual calcula el area de figuras especiales

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

#ifndef ESPECIALES_H
#define ESPECIALES_H

#include <iostream>
#include <cmath>

class especiales
{
    float area;
    public:
        especiales();
        void intro_valores(float &lado1, float &lado2, float &angulo);//parametros paralelogramo
        void intro_valores(float &lado1, float &angulo);//parametros rombo
        void intro_valores(float &lado1, float &lado2, float &lado3, float &lado4);//parametros trapecio
        float calcular_area(float lado1, float lado2, float angulo);//area paralelogramo
        float calcular_area(float lado1, float angulo);//area rombo
        float calcular_area(float lado1, float lado2, float lado3, float lado4);
        void imprimir_area();
};

#endif // ESPECIALES_H
