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
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class polygon {
	private:
		struct vertex {
			double x, y, angle, arista_poste;
		};

		vector<vertex> vert;

		int sides;
		double area, perimeter;
		const long double PI = 3.141592653589793115997963468544185161590576171875;
	public:
		polygon();		

		int getSides();
		double getX(int v);
		double getY(int v);
		double getAngle(int v);
		void calcAngles(); /* No calcula bien los ángulos */
		double getAristaPoste(int v); /* Buscar traducción al nombre */
		void calcAristaPoste();
		double getArea();
		double getPerimeter();
		void calcSize(); /* Evitar ejecutar los calc si ya están los valores calculados */
		void calcValues();
		string getName();
		void setSides(int n); /* Implementar la gestión del número de lados desde la clase */
		void setX(double value, int v);
		void setY(double value, int v);
		void setAngle(double value, int v);
		void setAristaPoste(double value, int v);
		void newVertex();
		bool isClosed();
		bool isRegular();

		void inputB(); /* Necesita revisión */
		void inputC(); /* Necesita revisión */
};

polygon::polygon(){
	sides = 0;
}

int polygon::getSides() {
	return sides;
}

double polygon::getX(int v) {
	return vert[v].x;
}

double polygon::getY(int v) {
	return vert[v].y;
}

double polygon::getAngle(int v) {
	return vert[v].angle;
}

void polygon::calcAngles() {
	double ax, ay, bx, by, cx, cy;
	for(int i = 0; i < sides; i++) {
		ax = vert[i + 1].x;
		ay = vert[i + 1].y;
		bx = vert[i + 2].x;
		by = vert[i + 2].y;
		cx = vert[i].x;
		cy = vert[i].y;
		vert[i].angle = acos((((bx - ax) * (cx - ax)) + ((by - ay) * (cy - ay))) / (sqrt(pow((bx - ax), 2) + pow((by - ay), 2)) * (sqrt(pow((cx - ax), 2) + pow((cy - ay), 2))))) * 180 / PI;
	}
}

double polygon::getAristaPoste(int v) {
	return vert[v].arista_poste;
}

void polygon::calcAristaPoste() {
	for(int i = 0; i < sides; i++) {
		vert[i].arista_poste = sqrt((pow((vert[i + 1].x - vert[i].x), 2)) + (pow((vert[i + 1].y - vert[i].y), 2)));
	}
}

double polygon::getArea() {
	return area;
}

double polygon::getPerimeter() {
	return perimeter;
}

void polygon::calcSize() {
	double x, y;
	calcAristaPoste();
	for(int i = 0; i < sides; i++) {
		x += vert[i].x * vert[i + 1].y;
		y += vert[i].y * vert[i + 1].x;
		perimeter += vert[i].arista_poste;
	}
	area = abs(x - y) / 2;
}

void polygon::calcValues() {
	vert[sides] = vert[0]; /* Hay que prescindir de él */
	calcSize();
	calcAngles();
}

string polygon::getName() {
	if(sides < 3) return "";  /* Gestionar casos en los que haya menos de 3 lados */
	string pol_small[] = {"","", "", "triángulo", "cuadrado", "pentágono", "hexágono","heptágono", "octágono", "eneágono", "decágono", "endecágono", "dodecágono", "tridecágono", "tetradecágono", "pentadecágono", "hexadecágono", "heptadecágono", "octodecágono", "eneadecágono"};
	string pol_small2[] = {"á", "akaihená","akaidí", "akaitrí", "akaitetrá", "akaipentá", "akaihexá","akaiheptá", "akaioctá", "akaieneá"};
	string pol_big[] = {"", "","icos", "triacont", "tetracont", "pentacont", "hexacont","heptacont", "octacont", "eneacont"};

	if(sides >= 100) return "";
	else if(sides >= 20) return pol_big[sides / 10] + pol_small2[sides % 10] + "gono";
	return pol_small[sides];
}

void polygon::setSides(int n) {
	sides = n;
}

void polygon::setX(double value, int v) {
	vert[v].x = value;
}

void polygon::setY(double value, int v) {
	vert[v].y = value;
}

void polygon::setAngle(double value, int v) {
	vert[v].angle = value;
}

void polygon::setAristaPoste(double value, int v) {
	vert[v].arista_poste = value;
}

void polygon::newVertex() {
	vert.emplace_back(vertex{});
}

bool polygon::isClosed() {
	if (sides >= 3 && vert[0].x == vert[sides].x && vert[0].y == vert[sides].y) return true;
	else return false;
}

bool polygon::isRegular() {
	if(l >= 3 && vert[sides].angle != vert[sides - 1].angle) return true; /* Solo compara los dos últimos vértices, corregir */
	else return false;
}

void polygon::inputB() {
	for(int i = 0; i < sides - 1; i++) {
		vert[i + 1].x = vert[i].x + (cos(((i * (PI * 2 / sides)))) * vert[i].arista_poste);
		vert[i + 1].y = vert[i].y + (sin(((i * (PI * 2 / sides)))) * vert[i].arista_poste);
		vert[i + 1].angle = vert[i].angle;
		vert[i + 1].arista_poste = vert[i].arista_poste;
	}
}

void polygon::inputC() {
	newVertex();
	vert[sides + 1].x = vert[sides].x + (cos(sides * (PI * 2 / (360 / (180 - vert[sides].angsidese)))) * vert[sides].arista_poste);
	vert[sides + 1].y = vert[sides].y + (cos(sides * (PI * 2 / (360 / (180 - vert[sides].angsidese)))) * vert[sides].arista_poste);
}

void header();
void coordinates_label(polygon &P);
void resultados(polygon &P);
void menuA();
void menuB();
void menuC();

int main() {
	cout.precision(2);
	cout << fixed;
	while(true) {
		char menu_resp;
		header();
		cout << "\n\tSeleccione una opción del menú.\n\n"
		     << "\t\ta) Calcular el área de cualquier polígono a\n"
		     << "\t\t partir de las coordenadas de los vértices.\n"
		     << "\t\tb) Calcular área de un polígono regular.\n"
		     << "\t\tc) Calcular área de un polígono cualquiera,\n"
		     << "\t\t introduciendo lados y ángulos.\n"
		     << "\n\t\ts) Salir\n"
		     << "\n\n\t\t\tRespuesta: ";
		cin >> menu_resp;
		cin.get();
		menu_resp = toupper(menu_resp);
		switch(menu_resp) {
			case 'A': menuA(); break;
			case 'B': menuB(); break;
			case 'C': menuC(); break;
			case 'S': return EXIT_SUCCESS;
			default:
				cout << "\n\n\t\tOpción seleccionada incorrecta.\n"
				     << "Presiona intro para continuar...";
				cin.get();
		}
	}
	return EXIT_FAILURE;
}

void header() {
	system("clear");
	cout << setw(80) << setfill('=') << "\n"
	     << "\t\t\tCALCULADORA DE ÁREAS\n"
	     << setw(80) << setfill('=') << "\n";
}

void coordinates_label(polygon &P) {
	for(int i = 0; i < P.getSides(); i++) {
		if(i % 4 == 0) cout << "\n";
		cout << "\t(" << P.getX(i) << ", " << P.getY(i) << ") ";
	}
}

void resultados(polygon &P) {
	P.calcValues();
	header();
	cout << "\n\t\t\t\tResultados:\n\n"
	     << "\tVértice A \tÁngulo\t\tVértice B\tÁngulo\t\tDist";
	for(int i = 0; i < P.getSides(); i++) {
		cout << "\n" << i + 1 << "\t(" << P.getX(i) << ", " << P.getY(i) << ") <) " << P.getAngle(i) << "º"
		     << " \t(" << P.getX(i + 1) << ", " << P.getY(i + 1) << ") <) " << P.getAngle(i + 1) << "º"
		     << " \t|" << P.getAristaPoste(i) << "|";
	}
	cout << "\n\n\tEs un polígono de " << P.getSides() <<" vértices.\n";
	if(P.getName() == "") cout << "\tSe desconoce el nombre de la figura.\n";
	else if(P.isRegular()) cout << "\tLa figura se trata de un " << P.getName() << " regular.\n";
	else cout << "\tLa figura se trata de un " << P.getName() << " irregular.\n";
	cout << "\tÁrea: " << P.getArea() << " u²\n"
	     << "\tPerímetro: " << P.getPerimeter() << " u\n\n\n"
	     << "\t\tPresiona intro para continuar...";
	cin.get();
}

void menuA() {
	polygon P;
	double x, y;
	char resp = 'S';
	while(resp == 'S') {
		P.newVertex();
		header();
		cout << "\n\tPor favor, introduzca las coordenadas de los vértices del polí-\n"
		     << "\tgono en sentido horario.\n";
		coordinates_label(P);
		cout << "\n\n\tVértice " << P.getSides() + 1 << "\n"
		     << "\tx: ";
		cin >> x;
		cin.get();
		P.setX(x, P.getSides());
		cout << "\ty: ";
		cin >> y;
		cin.get();
		P.setY(y, P.getSides());
		P.setSides(P.getSides() + 1);
		if(P.getSides() >= 3) {
			do {
				cout << "\n\t\t¿Desea introducir otro vértice? (S/N) ";
				cin >> resp;
				cin.get();
				resp = toupper(resp);
			} while(resp != 'N' && resp != 'S');
		} else resp = 'S';
	}
	resultados(P);
}

void menuB() {
	polygon P;
	double x, y, arista_poste;
	do {
		header();
		cout << "\n\tPor favor, introduzca el número de vértices del polígono (no puede ser menor de 3).\n\n"
		     << "\tNúmero: ";
		int Sides;
		cin >> Sides;
		cin.get();
		P.setSides(Sides);
	} while(P.getSides() < 3);
	P.newVertex();
	cout << "\n\tPor favor, introduzca la longitud de los lados del polígono.\n\n";
	do {
		cout << "\tLongitud: ";
		cin >> arista_poste;
		cin.get();
		P.setAristaPoste(arista_poste, 0);
	} while(P.getAristaPoste(0) <= 0);
	cout << "\n\tPor favor, introduzca las coordenadas del primer vértice del polígono.\n"
	     << "\tx: ";
	cin >> x;
	cin.get();
	P.setX(x, 0);
	cout << "\ty: ";
	cin >> y;
	cin.get();
	P.setY(y, 0);
	P.setAngle(180 - (360 / P.getSides()), 0);
	P.inputB();
	resultados(P);
}

void menuC() {
	polygon P;
	double x, y, angle, arista_poste;
	P.newVertex();
	header();
	cout << "\n\tPor favor, introduzca las coordenadas del primer vértice del polígono.\n"
	     << "\tx: ";
	cin >> x;
	cin.get();
	P.setX(x, 0);
	cout << "\ty: ";
	cin >> y;
	cin.get();
	P.setY(y, 0);
	do {
		header();
		cout << "\n";
		coordinates_label(P);
		cout << "\n\tPor favor, introduzca la amplitud del " << P.getSides() + 1 << "º ángulo del polígono.\n\n"
		     << "\tAmplitud (en grados): ";
		cin >> angle;
		cin.get();
		P.setAngle(angle, P.getSides());
		cout << "\n\tPor favor, introduzca la longitud del " << P.getSides() + 1 << "º lado del polígono.\n\n"
		     << "\tLongitud: ";
		cin >> arista_poste;
		cin.get();
		P.setAristaPoste(arista_poste, P.getSides());
		P.inputC();                          /* incluye P.newVertex() */
		P.setSides(P.getSides() + 1);
	} while(!P.isClosed());
	resultados(P);
}
