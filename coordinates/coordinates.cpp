/*
Copyright 2011 Ángel Olivera Crego
Copyright 2013 Cristian Corado Cordero
Copyright 2017 Alejandro Domínguez Muñoz

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <iostream>
#include <iomanip>
#include "coordinates.hpp"

void header();
void coordinates_label(polygon &P);
void resultados(polygon &P);
void menuA();
void menuB();
void menuC();

int main() {
	std::cout << std::setprecision(2) << std::fixed;
	while(true) {
		char menu_resp;
		header();
		std::cout << "\n\tSeleccione una opción del menú.\n\n"
		     << "\t\ta) Calcular el área de cualquier polígono a\n"
		     << "\t\t partir de las coordenadas de los vértices.\n"
		     << "\t\tb) Calcular área de un polígono regular.\n"
		     << "\t\tc) Calcular área de un polígono cualquiera,\n"
		     << "\t\t introduciendo lados y ángulos.\n"
		     << "\n\t\ts) Salir\n"
		     << "\n\n\t\t\tRespuesta: ";
		std::cin >> menu_resp;
		std::cin.get();
		menu_resp = toupper(menu_resp);
		switch(menu_resp) {
			case 'A': menuA(); break;
			case 'B': menuB(); break;
			case 'C': menuC(); break;
			case 'S': return EXIT_SUCCESS;
			default:
				std::cout << "\n\n\t\tOpción seleccionada incorrecta.\n"
				     << "Presiona intro para continuar...";
				std::cin.get();
		}
	}
	return EXIT_FAILURE;
}

void header() {
	system("clear");
	std::cout << std::setw(80) << std::setfill('=') << "\n"
	     << "\t\t\tCALCULADORA DE ÁREAS\n"
	     << std::setw(80) << std::setfill('=') << "\n";
}

void coordinates_label(polygon &P) {
	for(int i = 0; i < P.MaxVertexID() + 1; i++) {
		if(i % 4 == 0) std::cout << "\n";
		std::cout << "\t(" << P.X(i) << ", " << P.Y(i) << ") ";
	}
}

void resultados(polygon &P) {
	header();
	std::cout << "\n\t\t\t\tResultados:\n\n"
	     << "\tVértice A \tÁngulo\t\tVértice B\tÁngulo\t\tDist";
	for(int i = 0; i <= P.MaxVertexID(); i++) {
		std::cout << "\n" << i + 1 << "\t(" << P.X(i) << ", " << P.Y(i) << ") <) " << P.Angle(i) << "º"
		     << " \t(" << P.X(i + 1) << ", " << P.Y(i + 1) << ") <) " << P.Angle(i + 1) << "º"
		     << " \t|" << P.SideLength(i) << "|";
	}
	std::cout << "\n\n\tEs un polígono de " << P.MaxVertexID() + 1 <<" vértices.\n";
	if(P.Name() == "") std::cout << "\tSe desconoce el nombre de la figura.\n";
	else std::cout << "\tLa figura se trata de un " << P.Name() << " " << P.NameIsRegular() << ".\n";
	std::cout << "\tÁrea: " << P.Area() << " u²\n"
	     << "\tPerímetro: " << P.Perimeter() << " u\n\n\n"
	     << "\t\tPresiona intro para continuar...";
	std::cin.get();
}

void menuA() {
	polygon P;
	double x, y;
	char resp = 'S';
	do {
		header();
		std::cout << "\n\tPor favor, introduzca las coordenadas de los vértices del polí-\n"
		     << "\tgono en sentido horario.\n";
		coordinates_label(P);
		std::cout << "\n\n\tVértice " << P.MaxVertexID() + 2 << "\n"
		     << "\tx: ";
		std::cin >> x;
		std::cin.get();
		std::cout << "\ty: ";
		std::cin >> y;
		std::cin.get();
		P.newVertexByAxis(x, y);
		if(P.MaxVertexID() > 1) {
			do {
				std::cout << "\n\t\t¿Desea introducir otro vértice? (S/N) ";
				std::cin >> resp;
				std::cin.get();
				resp = toupper(resp);
			} while(resp != 'N' && resp != 'S');
		}
	} while(resp == 'S');
	P.close();
	resultados(P);
}

void menuB() {
	double x, y, sides_length;
	int sides;
	do {
		header();
		std::cout << "\n\tPor favor, introduzca el número de vértices del polígono (no puede ser menor de 3).\n\n"
		     << "\tNúmero: ";
		std::cin >> sides;
		std::cin.get();
	} while(sides < 3);
	std::cout << "\n\tPor favor, introduzca la longitud de los lados del polígono.\n\n";
	do {
		std::cout << "\tLongitud: ";
		std::cin >> sides_length;
		std::cin.get();
	} while(sides_length <= 0);
	std::cout << "\n\tPor favor, introduzca las coordenadas del primer vértice del polígono.\n"
	     << "\tx: ";
	std::cin >> x;
	std::cin.get();
	std::cout << "\ty: ";
	std::cin >> y;
	std::cin.get();
	polygon P(x, y, sides_length, sides);
	resultados(P);
}

void menuC() {
	double x, y, angle, side_length;
	header();
	std::cout << "\n\tPor favor, introduzca las coordenadas del primer vértice del polígono.\n"
	     << "\tx: ";
	std::cin >> x;
	std::cin.get();
	std::cout << "\ty: ";
	std::cin >> y;
	std::cin.get();
	polygon P(x, y);
	do {
		header();
		std::cout << "\n";
		coordinates_label(P);
		std::cout << "\n\tPor favor, introduzca la amplitud del " << P.MaxVertexID() + 1 << "º ángulo del polígono.\n\n"
		     << "\tAmplitud (en grados): ";
		std::cin >> angle;
		std::cin.get();
		std::cout << "\n\tPor favor, introduzca la longitud del " << P.MaxVertexID() + 1 << "º lado del polígono.\n\n"
		     << "\tLongitud: ";
		std::cin >> side_length;
		std::cin.get();
		P.newVertexByAngleAndSide(angle, side_length);
	} while(!P.isClosed());
	resultados(P);
}
