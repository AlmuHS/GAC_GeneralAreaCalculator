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

		int maxVertexID;
		double area, perimeter;
		const long double PI = 3.141592653589793115997963468544185161590576171875;

		void calcAristaPoste(int v);
	public:
		polygon();		

		int getMaxVertexID();
		double getX(int v);
		double getY(int v);
		double getAngle(int v);
		void calcAngles(); /* No calcula bien los ángulos */
		double getAristaPoste(int v); /* Buscar traducción al nombre */
		double getArea();
		double getPerimeter();
		void calcSize(); /* Evitar ejecutar los calc si ya están los valores calculados */
		void calcValues();
		string getName();
		string getNameIsRegular();
		void close();
		void setMaxVertexID(int n); /* Implementar la gestión del número de lados desde la clase */
		void setX(double value, int v);
		void setY(double value, int v);
		void setAngle(double value, int v);
		void setAristaPoste(double value, int v);
		void newVertex();
		bool isClosed();
		bool isRegular();

		void inputB(double x, double y, double side_length); /* Necesita revisión */
		void inputC(double v_angle, double side_length, int v_index); /* Necesita revisión */
};

void polygon::calcAristaPoste(int v) {
	setAristaPoste(sqrt(pow(getX(v + 1) - getX(v), 2) + pow(getY(v + 1) - getY(v), 2)), v);
}


polygon::polygon() {
	vert.emplace_back(vertex{});
	maxVertexID = 0;
}

int polygon::getMaxVertexID() {
	return maxVertexID;
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
	for(int i = 0; i <= getMaxVertexID(); i++) {
		ax = getX(i + 1);
		ay = getY(i + 1);
		bx = getX(i + 2);
		by = getY(i + 2);
		cx = getX(i);
		cy = getY(i);
		setAngle(acos((((bx - ax) * (cx - ax)) + ((by - ay) * (cy - ay))) / (sqrt(pow(bx - ax, 2) + pow(by - ay, 2)) * sqrt(pow(cx - ax, 2) + pow(cy - ay, 2)))) * 180 / PI, i);
	}
}

double polygon::getAristaPoste(int v) {
	return vert[v].arista_poste;
}

double polygon::getArea() {
	return area;
}

double polygon::getPerimeter() {
	return perimeter;
}

void polygon::calcSize() {
	double x, y;
	for(int i = 0; i <= getMaxVertexID(); i++) {
		calcAristaPoste(i);
		x += getX(i) * getY(i + 1);
		y += getY(i) * getX(i + 1);
		perimeter += getAristaPoste(i);
	}
	area = abs(x - y) / 2;
}

void polygon::calcValues() {
	close();
	calcSize();
	calcAngles();
}

string polygon::getName() {
	if(getMaxVertexID() < 3) return "";  /* Gestionar casos en los que haya menos de 3 lados */
	string pol_small[] = {"","", "", "triángulo", "cuadrado", "pentágono", "hexágono","heptágono", "octágono", "eneágono", "decágono", "endecágono", "dodecágono", "tridecágono", "tetradecágono", "pentadecágono", "hexadecágono", "heptadecágono", "octodecágono", "eneadecágono"};
	string pol_small2[] = {"á", "akaihená","akaidí", "akaitrí", "akaitetrá", "akaipentá", "akaihexá","akaiheptá", "akaioctá", "akaieneá"};
	string pol_big[] = {"", "","icos", "triacont", "tetracont", "pentacont", "hexacont","heptacont", "octacont", "eneacont"};
	
	if(getMaxVertexID() >= 100) return "";
	else if(getMaxVertexID() >= 20) return pol_big[getMaxVertexID() / 10] + pol_small2[getMaxVertexID() % 10] + "gono";
	else return pol_small[getMaxVertexID()];
}

string polygon::getNameIsRegular() {
	if(isRegular()) return "regular";
	else return "irregular";
}

void polygon::close() {
	vert.emplace_back(vertex{});
	vert.emplace_back(vertex{});
	vert[getMaxVertexID() + 1] = vert[0];
	vert[getMaxVertexID() + 2] = vert[1];
}

void polygon::setMaxVertexID(int n) {
	maxVertexID = n;
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
	setMaxVertexID(getMaxVertexID() + 1);
}

bool polygon::isClosed() {
	if(getMaxVertexID() >= 3 && getX(0) == getX(getMaxVertexID()) && getY(0) == getY(getMaxVertexID())) return true;
	else return false;
}

bool polygon::isRegular() {
	if(getMaxVertexID() < 3) return false;
	for(int i = 0; i < getMaxVertexID(); i++) if(getAngle(i) != getAngle(i + 1)) return false;
	return true;
}

void polygon::inputB(double x, double y, double side_length) {
	newVertex();
	setX(x, 0);
	setY(y, 0);
	setAristaPoste(side_length, 0);
	setAngle(180 - (360 / getMaxVertexID()), 0);
	for(int i = 0; i < getMaxVertexID() - 1; i++) {
		setX(cos(i * PI * 2 / getMaxVertexID()) * getAristaPoste(i) + getX(i), i + 1);
		setY(sin(i * PI * 2 / getMaxVertexID()) * getAristaPoste(i) + getY(i), i + 1);
		setAngle(getAngle(i), i + 1);
		setAristaPoste(getAristaPoste(i), i + 1);
	}
}

void polygon::inputC(double v_angle, double side_length, int v_index) {
	setAngle(v_angle, v_index);
	setAristaPoste(side_length, v_index);
	newVertex();
	setX(cos(v_index * PI * 2 / (360 / (180 - getAngle(v_index)))) * getAristaPoste(v_index) + getX(v_index), v_index + 1);
	setY(cos(v_index * PI * 2 / (360 / (180 - getAngle(v_index)))) * getAristaPoste(v_index) + getY(v_index), v_index + 1);
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
	for(int i = 0; i < P.getMaxVertexID(); i++) {
		if(i % 4 == 0) cout << "\n";
		cout << "\t(" << P.getX(i) << ", " << P.getY(i) << ") ";
	}
}

void resultados(polygon &P) {
	P.calcValues();
	header();
	cout << "\n\t\t\t\tResultados:\n\n"
	     << "\tVértice A \tÁngulo\t\tVértice B\tÁngulo\t\tDist";
	for(int i = 0; i <= P.getMaxVertexID(); i++) {
		cout << "\n" << i + 1 << "\t(" << P.getX(i) << ", " << P.getY(i) << ") <) " << P.getAngle(i) << "º"
		     << " \t(" << P.getX(i + 1) << ", " << P.getY(i + 1) << ") <) " << P.getAngle(i + 1) << "º"
		     << " \t|" << P.getAristaPoste(i) << "|";
	}
	cout << "\n\n\tEs un polígono de " << P.getMaxVertexID() + 1 <<" vértices.\n";
	if(P.getName() == "") cout << "\tSe desconoce el nombre de la figura.\n";
	else cout << "\tLa figura se trata de un " << P.getName() << " " << P.getNameIsRegular() << ".\n";
	cout << "\tÁrea: " << P.getArea() << " u²\n"
	     << "\tPerímetro: " << P.getPerimeter() << " u\n\n\n"
	     << "\t\tPresiona intro para continuar...";
	cin.get();
}

void menuA() {
	polygon P;
	double x, y;
	char resp;
	while(true) {
		header();
		cout << "\n\tPor favor, introduzca las coordenadas de los vértices del polí-\n"
		     << "\tgono en sentido horario.\n";
		coordinates_label(P);
		cout << "\n\n\tVértice " << P.getMaxVertexID() + 1 << "\n"
		     << "\tx: ";
		cin >> x;
		cin.get();
		cout << "\ty: ";
		cin >> y;
		cin.get();
		P.setX(x, P.getMaxVertexID());
		P.setY(y, P.getMaxVertexID());
		if(P.getMaxVertexID() >= 2) {
			do {
				cout << "\n\t\t¿Desea introducir otro vértice? (S/N) ";
				cin >> resp;
				cin.get();
				resp = toupper(resp);
			} while(resp != 'N' && resp != 'S');
		}
		if(resp == 'N') break;
		P.newVertex();
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
		int sides;
		cin >> sides;
		cin.get();
		P.setMaxVertexID(sides - 1);
	} while(P.getMaxVertexID() < 3);
	cout << "\n\tPor favor, introduzca la longitud de los lados del polígono.\n\n";
	do {
		cout << "\tLongitud: ";
		cin >> arista_poste;
		cin.get();
	} while(arista_poste <= 0);
	cout << "\n\tPor favor, introduzca las coordenadas del primer vértice del polígono.\n"
	     << "\tx: ";
	cin >> x;
	cin.get();
	cout << "\ty: ";
	cin >> y;
	cin.get();
	P.inputB(x, y, arista_poste);
	resultados(P);
}

void menuC() {
	polygon P;
	double x, y, angle, arista_poste;
	header();
	cout << "\n\tPor favor, introduzca las coordenadas del primer vértice del polígono.\n"
	     << "\tx: ";
	cin >> x;
	cin.get();
	cout << "\ty: ";
	cin >> y;
	cin.get();
	P.setX(x, 0);
	P.setY(y, 0);
	do {
		header();
		cout << "\n";
		coordinates_label(P);
		cout << "\n\tPor favor, introduzca la amplitud del " << P.getMaxVertexID() + 1 << "º ángulo del polígono.\n\n"
		     << "\tAmplitud (en grados): ";
		cin >> angle;
		cin.get();
		cout << "\n\tPor favor, introduzca la longitud del " << P.getMaxVertexID() + 1 << "º lado del polígono.\n\n"
		     << "\tLongitud: ";
		cin >> arista_poste;
		cin.get();
		P.inputC(angle, arista_poste, P.getMaxVertexID());                          /* incluye P.newVertex() */
	} while(!P.isClosed());
	resultados(P);
}
