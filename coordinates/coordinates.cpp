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
#include <deque>
#include <cmath>

using namespace std;

class polygon {
	private:
		struct vertex {
			double x, y, angle, side_length;
			vertex(double _x, double _y) : x(_x), y(_y) {}
			vertex(double _x, double _y, double _angle, double _side_length) : x(_x), y(_y), angle(_angle), side_length(_side_length) {}
		};

		deque<vertex> vertices;
		const long double PI = 3.141592653589793115997963468544185161590576171875;
		bool regular;

		int validVertexID(int v);
		double round(double value, int dec);
		vertex nextXYByAngleAndSide(double angle, double side_length, int vertex);
		void setX(double value, int v);
		void setY(double value, int v);
		void setAngle(int v);
		void setAngle(double value, int v);
		void setSideLength(int v);
		void setSideLength(double value, int v);
		void setIsRegular(int v);
	public:
		polygon();
		polygon(double x, double y);
		polygon(double x, double y, double side_length, int sides);

		void newVertexByAxis(double x, double y);
		void newVertexByAngleAndSide(double v_angle, double side_length); /* Necesita al menos de un X e Y asignados */
		void close();

		int MaxVertexID();
		double X(int v);
		double Y(int v);
		double Angle(int v);
		double SideLength(int v);
		double Area();
		double Perimeter();
		bool isClosed();
		bool isRegular();
		string Name();
		string NameIsRegular();
};

int polygon::validVertexID(int v) {
	if(v < 0) {
		int c;
		c = abs(v / (MaxVertexID() + 1));
		v += (MaxVertexID() + 1) * (c + 1);
	}
	return v % (MaxVertexID() + 1);
}

double polygon::round(double value, int dec) {return ceil((value * pow(10, dec) - 0.5) / pow(10, dec));}

polygon::vertex polygon::nextXYByAngleAndSide(double angle, double side_length, int vertex) {
	double xy_common = vertex * PI * 2 / (360 / (180 - angle));
	polygon::vertex point = {cos(xy_common) * side_length + X(vertex), sin(xy_common) * side_length + Y(vertex)};
	return point;
}
	
void polygon::setX(double value, int v) {vertices[validVertexID(v)].x = value;}

void polygon::setY(double value, int v) {vertices[validVertexID(v)].y = value;}

void polygon::setAngle(int v) {
	double ax, ay, bx, by, cx, cy;
	ax = X(v);
	ay = Y(v);
	bx = X(v + 1);
	by = Y(v + 1);
	cx = X(v - 1);
	cy = Y(v - 1);
	setAngle(acos((((bx - ax) * (cx - ax)) + ((by - ay) * (cy - ay))) / (sqrt(pow(bx - ax, 2) + pow(by - ay, 2)) * sqrt(pow(cx - ax, 2) + pow(cy - ay, 2)))) * 180 / PI, v);
}

void polygon::setAngle(double value, int v) {vertices[validVertexID(v)].angle = value;}

void polygon::setSideLength(int v) {setSideLength(sqrt(pow(X(v + 1) - X(v), 2) + pow(Y(v + 1) - Y(v), 2)), v);}

void polygon::setSideLength(double value, int v) {vertices[validVertexID(v)].side_length = value;}

void polygon::setIsRegular(int v) {
	if(MaxVertexID() < 2 || regular == false) return;
	if(Angle(v) == Angle(v - 1) && SideLength(v) == SideLength(v - 1)) regular = true;
	else regular = false;
}

polygon::polygon() : regular(true) {}

polygon::polygon(double x, double y) : polygon() {newVertexByAxis(x, y);}

polygon::polygon(double x, double y, double side_length, int sides) : polygon() {
	double angle = 180 - (360 / sides);
	vertices.emplace_back(x, y, angle, side_length);
	for(int i = 0; i + 1 < sides; i++) {
		polygon::vertex point = nextXYByAngleAndSide(angle, side_length, i);
		vertices.emplace_back(point.x, point.y, angle, side_length);
	}
}

void polygon::newVertexByAxis(double x, double y) {
	if(MaxVertexID() >= 0 && x == X(0) && y == Y(0)) close();
	else {
		vertices.emplace_back(x, y);
		if(MaxVertexID() > 0) setSideLength(MaxVertexID() - 1);
		if(MaxVertexID() > 1) setAngle(MaxVertexID() - 1);
		if(MaxVertexID() > 2) setIsRegular(MaxVertexID() - 1);
	}
}

void polygon::newVertexByAngleAndSide(double angle, double side_length) {
	setAngle(angle, MaxVertexID());
	setSideLength(side_length, MaxVertexID());
	polygon::vertex point = nextXYByAngleAndSide(angle, side_length, MaxVertexID());
	if(MaxVertexID() < 3 || round(point.x, 4) != X(0) || round(point.y, 4) != Y(0)) vertices.emplace_back(point.x, point.y);
}

void polygon::close() {
	setSideLength(MaxVertexID());
	setAngle(0);
	setAngle(MaxVertexID());
	setIsRegular(0);
	setIsRegular(1);
	setIsRegular(MaxVertexID());
}

int polygon::MaxVertexID() {return vertices.size() - 1;}

double polygon::X(int v) {return vertices[validVertexID(v)].x;}

double polygon::Y(int v) {return vertices[validVertexID(v)].y;}

double polygon::Angle(int v) {return vertices[validVertexID(v)].angle;}

double polygon::SideLength(int v) {return vertices[validVertexID(v)].side_length;}

double polygon::Area() {
	if(isClosed()) {
		double x, y;
		for(int i = 0; i <= MaxVertexID(); i++) {
			x += X(i) * Y(i + 1);
			y += Y(i) * X(i + 1);
		}
		return abs(x - y) / 2;
	}
}

double polygon::Perimeter() {
	if(isClosed()) {
		double perimeter;
		for(int i = 0; i <= MaxVertexID(); i++) {
			perimeter += SideLength(i);
		}
		return perimeter;
	}
}

bool polygon::isClosed() {
	if(Angle(MaxVertexID()) && SideLength(MaxVertexID())) return true;
	else return false;
}

bool polygon::isRegular() {
	if(!isClosed()) return false;
	return regular;
}

string polygon::Name() {
	int i = MaxVertexID() + 1;
	if(i < 3 || i >= 100) return "";
	string pol_small[] = {"","", "", "triángulo", "cuadrado", "pentágono", "hexágono","heptágono", "octágono", "eneágono", "decágono", "endecágono", "dodecágono", "tridecágono", "tetradecágono", "pentadecágono", "hexadecágono", "heptadecágono", "octodecágono", "eneadecágono"};
	string pol_small2[] = {"á", "akaihená","akaidí", "akaitrí", "akaitetrá", "akaipentá", "akaihexá","akaiheptá", "akaioctá", "akaieneá"};
	string pol_big[] = {"", "","icos", "triacont", "tetracont", "pentacont", "hexacont","heptacont", "octacont", "eneacont"};
	
	if(i >= 20) return pol_big[i / 10] + pol_small2[i % 10] + "gono";
	else return pol_small[i];
}

string polygon::NameIsRegular() {
	if(isRegular()) return "regular";
	else return "irregular";
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
	for(int i = 0; i < P.MaxVertexID() + 1; i++) {
		if(i % 4 == 0) cout << "\n";
		cout << "\t(" << P.X(i) << ", " << P.Y(i) << ") ";
	}
}

void resultados(polygon &P) {
	header();
	cout << "\n\t\t\t\tResultados:\n\n"
	     << "\tVértice A \tÁngulo\t\tVértice B\tÁngulo\t\tDist";
	for(int i = 0; i <= P.MaxVertexID(); i++) {
		cout << "\n" << i + 1 << "\t(" << P.X(i) << ", " << P.Y(i) << ") <) " << P.Angle(i) << "º"
		     << " \t(" << P.X(i + 1) << ", " << P.Y(i + 1) << ") <) " << P.Angle(i + 1) << "º"
		     << " \t|" << P.SideLength(i) << "|";
	}
	cout << "\n\n\tEs un polígono de " << P.MaxVertexID() + 1 <<" vértices.\n";
	if(P.Name() == "") cout << "\tSe desconoce el nombre de la figura.\n";
	else cout << "\tLa figura se trata de un " << P.Name() << " " << P.NameIsRegular() << ".\n";
	cout << "\tÁrea: " << P.Area() << " u²\n"
	     << "\tPerímetro: " << P.Perimeter() << " u\n\n\n"
	     << "\t\tPresiona intro para continuar...";
	cin.get();
}

void menuA() {
	polygon P;
	double x, y;
	char resp = 'S';
	do {
		header();
		cout << "\n\tPor favor, introduzca las coordenadas de los vértices del polí-\n"
		     << "\tgono en sentido horario.\n";
		coordinates_label(P);
		cout << "\n\n\tVértice " << P.MaxVertexID() + 2 << "\n"
		     << "\tx: ";
		cin >> x;
		cin.get();
		cout << "\ty: ";
		cin >> y;
		cin.get();
		P.newVertexByAxis(x, y);
		if(P.MaxVertexID() > 1) {
			do {
				cout << "\n\t\t¿Desea introducir otro vértice? (S/N) ";
				cin >> resp;
				cin.get();
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
		cout << "\n\tPor favor, introduzca el número de vértices del polígono (no puede ser menor de 3).\n\n"
		     << "\tNúmero: ";
		cin >> sides;
		cin.get();
	} while(sides < 3);
	cout << "\n\tPor favor, introduzca la longitud de los lados del polígono.\n\n";
	do {
		cout << "\tLongitud: ";
		cin >> sides_length;
		cin.get();
	} while(sides_length <= 0);
	cout << "\n\tPor favor, introduzca las coordenadas del primer vértice del polígono.\n"
	     << "\tx: ";
	cin >> x;
	cin.get();
	cout << "\ty: ";
	cin >> y;
	cin.get();
	polygon P(x, y, sides_length, sides);
	resultados(P);
}

void menuC() {
	double x, y, angle, side_length;
	header();
	cout << "\n\tPor favor, introduzca las coordenadas del primer vértice del polígono.\n"
	     << "\tx: ";
	cin >> x;
	cin.get();
	cout << "\ty: ";
	cin >> y;
	cin.get();
	polygon P(x, y);
	do {
		header();
		cout << "\n";
		coordinates_label(P);
		cout << "\n\tPor favor, introduzca la amplitud del " << P.MaxVertexID() + 1 << "º ángulo del polígono.\n\n"
		     << "\tAmplitud (en grados): ";
		cin >> angle;
		cin.get();
		cout << "\n\tPor favor, introduzca la longitud del " << P.MaxVertexID() + 1 << "º lado del polígono.\n\n"
		     << "\tLongitud: ";
		cin >> side_length;
		cin.get();
		P.newVertexByAngleAndSide(angle, side_length);
	} while(!P.isClosed());
	resultados(P);
}
