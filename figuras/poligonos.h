/*********************************************/
/* Cabecera: Definicion de la clase poligonos

Descripción: Define la clase poligonos, la cual calcula el area de figuras poligonales

Autor: Almudena Garcia Jurado-Centurion

Año 2011 2012*/
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
#ifndef POLIGONOS_H
#define POLIGONOS_H

#include <iostream>
#include <iomanip>
#include <cmath>

class poligonos{
    float area;
    int num_lados;
    float lado1, lado2, lado3;
    public:
        poligonos();
        void intro_valores(float &base, float &altura);//parametros rectangulo
        void intro_valores(float &lado1, float &lado2, float &lado3);//parametros triangulo
        void intro_valores(int &num_lado, float &lado);//Parametros poligono regular
        float calcular_area(float base, float altura);//area rectangulo
        float calcular_area(float lado1, float lado2, float lado3);//area triangulo
        float calcular_area(int num_lado, float lado);//area poligono regular
        void imprimir_area();
        float perimetro();
};

#endif
