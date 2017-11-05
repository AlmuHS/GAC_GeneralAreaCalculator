/*
Copyright 2011 2013 Ángel Olivera Crego, Cristian Corado Cordero

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
#include <cmath>
#include <string>
#include <vector>

using namespace std;

class polygon {
	private:
		struct vertex {
			double x, y, angle, arista_poste;
		};

		vector<vertex> vert;

		int l = 0; /* No se inicializa solo correctamente, hay que indicar el valor inicial (inicializar mejor en 1?) */
		double a, per;
		const long double PI = 3.141592653589793115997963468544185161590576171875;
	public:
		int Sides();
		double X(int v);
		double Y(int v);
		double Angle(int v);
		double AristaPoste(int v); /* Buscar traducción al nombre */
		double Area();
		double Perimeter();
		string Name();
		bool isClosed();
		bool isRegular();
		void newVertex();
		void setSides(int n);
		void setX(double value, int v);
		void setY(double value, int v);
		void setAngle(double value, int v);
		void setAristaPoste(double value, int v);
		void calcSize(); /* Evitar ejecutar los calc si ya están los valores calculados */
		void calcAngles(); /* No calcula bien los ángulos */
		void calcAristaPoste();
		void calcValues();
		void inputB();
		void inputC();
};

int polygon::Sides() {
	return l;
}

double polygon::X(int v) {
	return vert[v].x;
}

double polygon::Y(int v) {
	return vert[v].y;
}

double polygon::Angle(int v) {
	return vert[v].angle;
}

double polygon::AristaPoste(int v) {
	return vert[v].arista_poste;
}

double polygon::Area() {
	return a;
}

double polygon::Perimeter() {
	return per;
}

string polygon::Name() {
	string pol_small[] = {"","henágono", "dígono", "triángulo", "cuadrado", "pentágono", "hexágono","heptágono", "octágono", "eneágono", "decágono", "endecágono", "dodecágono", "tridecágono", "tetradecágono", "pentadecágono", "hexadecágono", "heptadecágono", "octodecágono", "eneadecágono"};
	string pol_small2[] = {"á", "akaihená","akaidí", "akaitrí", "akaitetrá", "akaipentá", "akaihexá","akaiheptá", "akaioctá", "akaieneá"};
	string pol_big[] = {"", "","icos", "triacont", "tetracont", "pentacont", "hexacont","heptacont", "octacont", "eneacont"};

	if(l >= 100) return "";
	if(l >= 20) return pol_big[l / 10] + pol_small2[l % 10] + "gono";
	return pol_small[l];
}

bool polygon::isClosed() {
	if (l >= 3 || ((vert[0].x == vert[l].x) && (vert[0].y == vert[l].y))) return true;
	else return false;
}

bool polygon::isRegular() {
	if(l >= 3 && vert[l].angle != vert[l - 1].angle) return true; /* Solo compara los dos últimos vértices, corregir */
	else return false;
}

void polygon::newVertex() {
	vert.emplace_back(vertex{});
}

void polygon::setSides(int n) {
	l = n;
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

void polygon::calcSize() {
	double x, y;
	calcAristaPoste();
	for(int i = 0; i < l; i++) {
		x += vert[i].x * vert[i + 1].y;
		y += vert[i].y * vert[i + 1].x;
		per += vert[i].arista_poste;
	}
	a = abs(x - y) / 2;
}

void polygon::calcAristaPoste() {
	for(int i = 0; i < l; i++) {
		vert[i].arista_poste = sqrt((pow((vert[i + 1].x - vert[i].x), 2)) + (pow((vert[i + 1].y - vert[i].y), 2)));
	}
}

void polygon::calcAngles() {
	double ax, ay, bx, by, cx, cy;
	for(int i = 0; i < l; i++) {
		ax = vert[i + 1].x;
		ay = vert[i + 1].y;
		bx = vert[i + 2].x;
		by = vert[i + 2].y;
		cx = vert[i].x;
		cy = vert[i].y;
		vert[i].angle = acos((((bx - ax) * (cx - ax)) + ((by -ay) * (cy - ay))) / (sqrt(pow((bx - ax), 2) + pow((by - ay), 2)) * (sqrt(pow((cx - ax), 2) + pow((cy - ay), 2))))) * 180 / PI;
	}
}

void polygon::calcValues() {
	vert[l] = vert[0]; /* Hay que prescindir de él */
	calcSize();
	calcAngles();
}

void polygon::inputB() {
	for(int i = 0; i < l - 1; i++) {
		vert[i + 1].x = vert[i].x + (cos(((i * (PI * 2 / l)))) * vert[i].arista_poste);
		vert[i + 1].y = vert[i].y + (sin(((i * (PI * 2 / l)))) * vert[i].arista_poste);
		vert[i + 1].angle = vert[i].angle;
		vert[i + 1].arista_poste = vert[i].arista_poste;
	}
}

void polygon::inputC() {
	newVertex();
	vert[l + 1].x = vert[l].x + (cos(l * (PI * 2 / (360 / (180 - vert[l].angle)))) * vert[l].arista_poste);
	vert[l + 1].y = vert[l].y + (cos(l * (PI * 2 / (360 / (180 - vert[l].angle)))) * vert[l].arista_poste);
}

void header();
void coordinates_label(polygon* P);

int main() {
	cout << setprecision(2) << fixed;
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
	polygon P;
	double x, y, angle, arista_poste;
	switch(menu_resp) {
		case 'A':
			char resp;
			do {
				P.newVertex();
				header();
				cout << "\n\tPor favor, introduzca las coordenadas de los vértices del polí-\n"
				     << "\tgono en sentido horario.\n";
				coordinates_label(&P);
				cout << "\n\n\tVértice " << P.Sides() + 1 << "\n"
				     << "\tx: ";
				cin >> x;
				P.setX(x, P.Sides());
				cout << "\ty: ";
				cin >> y;
				P.setY(y, P.Sides());
				P.setSides(P.Sides() + 1);
				if(P.Sides() >= 3) {
					do {
						cout << "\n\t\t¿Desea introducir otro vértice? (S/N) ";
						cin >> resp;
						cin.get();
						resp = toupper(resp);
					} while(resp != 'N' && resp != 'S');
				}
				else resp = 'S';
			} while(resp == 'S');
			break;
		case 'B':
			do {
				header();
				cout << "\n\tPor favor, introduzca el número de vértices del polígono (no puede ser menor de 3).\n\n"
				     << "\tNúmero: ";
				int intSides;
				cin >> intSides;
				P.setSides(intSides);
				cin.get();
			} while(P.Sides() < 3);
			P.newVertex();
			cout << "\n\tPor favor, introduzca la longitud de los lados del polígono.\n\n";
			do {
				cout << "\tLongitud: ";
				cin >> arista_poste;
				P.setAristaPoste(arista_poste, 0);
				cin.get();
			} while(P.AristaPoste(0) <= 0);
			cout << "\n\tPor favor, introduzca las coordenadas del primer vértice del polígono.\n"
			     << "\tx: ";
			cin >> x;
			P.setX(x, 0);
			cin.get();
			cout << "\ty: ";
			cin >> y;
			P.setY(y, 0);
			cin.get();
			P.setAngle(180 - (360 / P.Sides()), 0);
			P.inputB();
			break;
		case 'C':
			P.newVertex();
			header();
			cout << "\n\tPor favor, introduzca las coordenadas del primer vértice del polígono.\n"
			     << "\tx: ";
			cin >> x;
			P.setX(x, 0);
			cin.get();
			cout << "\ty: ";
			cin >> y;
			P.setY(y, 0);
			cin.get();
			do {
				header();
				cout << "\n";
				coordinates_label(&P);
				cout << "\n\tPor favor, introduzca la amplitud del " << P.Sides() + 1 << "º ángulo del polígono.\n\n"
				     << "\tAmplitud (en grados): ";
				cin >> angle;
				P.setAngle(angle, P.Sides());
				cin.get();
				cout << "\n\tPor favor, introduzca la longitud del " << P.Sides() + 1 << "º lado del polígono.\n\n"
				     << "\tLongitud: ";
				cin >> arista_poste;
				P.setAristaPoste(arista_poste, P.Sides());
				cin.get();
				P.inputC();                          /* incluye P.newVertex() */
				P.setSides(P.Sides() + 1);
			} while(!P.isClosed());
			break;
		case 'S': return EXIT_SUCCESS;
		default:
			cout << "\n\n\t\tOpción seleccionada incorrecta.\n"
			     << "Presiona intro para continuar...";
			cin.get();
			main();
			return EXIT_SUCCESS;
	}
	P.calcValues();
	header();
	cout << "\n\t\t\t\tResultados:\n\n"
	     << "\tVértice A \tÁngulo\t\tVértice B\tÁngulo\t\tDist";
	for(int i = 0; i < P.Sides(); i++) {
		cout << "\n";
		cout << i + 1 << "\t(" << P.X(i) << ", " << P.Y(i) << ") <) " << P.Angle(i) << "º"
		     << " \t(" << P.X(i + 1) << ", " << P.Y(i + 1) << ") <) " << P.Angle(i + 1) << "º"
		     << " \t|" << P.AristaPoste(i) << "|";
	}
	cout << "\n\n\tEs un polígono de " << P.Sides() <<" vértices.\n";
	if(P.Name() == "") cout << "\tSe desconoce el nombre de la figura.\n";
	else if(P.isRegular()) cout << "\tLa figura se trata de un " << P.Name() << " regular.\n";
	else cout << "\tLa figura se trata de un " << P.Name() << " irregular.\n";
	cout << "\tÁrea: " << P.Area() << " u²\n"
	     << "\tPerímetro: " << P.Perimeter() << " u\n\n\n";
	cout << "\t\tPresiona intro para continuar...";
	cin.get();
	main();
	return EXIT_SUCCESS;
}

void header() {
	system("clear");
	int frame_length = 80;
	for(int i = 0; i < frame_length; i++) cout << "=";
	cout << "\n\t\t\tCALCULADORA DE ÁREAS\n";
	for(int i = 0; i < frame_length; i++) cout << "=";
	cout << "\n";
}

void coordinates_label(polygon* P) {
	for(int i = 0; i < P->Sides(); i++) {
		if(i % 4 == 0) cout << "\n";
		cout << "\t(" << P->X(i) << ", " << P->Y(i) << ") ";
	}
}
