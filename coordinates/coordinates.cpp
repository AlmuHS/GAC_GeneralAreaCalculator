/*
Copyright 2011 2013 Angel Olivera Crego, Cristian Corado Cordero

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

#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct vertice {
	double x, y, angulo, arista_poste;
	struct vertice *siguiente;
} vertice;

struct vertice *poligono, *aux;

class Fig {
	private:
		double a, peri;
		int lados, r;
	public:
		double area() {
			return a;
		}
		double perimetro() {
			return peri;
		}
		string nombre() {
			string pol_peque[] = {"","henágono", "dígono", "triángulo", "cuadrángulo", "pentágono", "hexágono","heptágono", "octágono", "eneágono", "decágono", "endecágono", "dodecágono", "tridecágono", "tetradecágono", "pentadecágono", "hexadecágono", "heptadecágono", "octodecágono", "eneadecágono"};
			string pol_peque2[] = {"á", "akaihená","akaidí", "akaitrí", "akaitetrá", "akaipentá", "akaihexá","akaiheptá", "akaioctá", "akaieneá"};
			string pol_grande[] = {"", "","icos", "triacont", "tetracont", "pentacont", "hexacont","heptacont", "octacont", "eneacont"};
		
			if(lados >= 100) return "";
			if(lados >= 20) return pol_grande[lados / 10] + pol_peque2[lados % 10] + "gono";
			return pol_peque[lados];
		}
		string regular() {
			if(!r) return "irregular";
			return "regular";
		}
		Fig(int lados, int r) : lados(lados), r(r) {
			double x, y;
			for(int i = 0; i < lados; i++) {
				x += poligono->x * (poligono->siguiente)->y;
				y += poligono->y * (poligono->siguiente)->x;
				peri += poligono->arista_poste;
				poligono = poligono->siguiente;
			}
			a = abs(x - y) / 2;
		}
};

int numero, regular;
const long double PI = 3.141592653589793115997963468544185161590576171875;

void cabecera();
void resultados(int numero, int regular);
void free_dynmem(int numero);
int lados_angulos(struct vertice *poligono, int lados, int regular);
double redondea(double r, int n_digit);

int main() {
	cout << setprecision(2) << fixed;
	double angulo;
	char menu_resp;
	cabecera();
	cout << "\n\tSeleccione una opción del menú.\n"
	     << "\n\t\ta) Calcular el area de cualquier polígono a"
	     << "\n\t\t partir de las coordenadas de los vértices."
	     << "\n\t\tb) Calcular área de un polígono regular."
	     << "\n\t\tc) Calcular área de un polígono cualquiera,"
	     << "\n\t\t introduciendo lados y ángulos."
	     << "\n\n\t\ts) Salir" << endl;
	cout << "\n\n\t\t\tRespuesta: ";
	cin >> menu_resp;
	while(getchar() != '\n');
	if(menu_resp >= 90) menu_resp = menu_resp - 32;
	switch(menu_resp) {
		case 'A':
			char resp;
			aux = (struct vertice*) malloc(sizeof(struct vertice));
			poligono = aux;
			do {
				cabecera();
				cout << "\n\tPor favor, introduzca las coordenadas de los vértices del "
				     << "polí-\n\tgono en sentido horario.\n";
				for(int i = 0; i < numero; i++) {
					if(i % 4 == 0) cout << "\n";
					cout << "\t(" << poligono->x << ", " << poligono->y << ") ";
					poligono = poligono->siguiente;
				}
				cout << "\n\n";

				if(resp == 'S') {
					aux->siguiente = (struct vertice*) malloc(sizeof(struct vertice));
				aux = aux->siguiente;
				}

				numero++;
				cout << "\tVértice " << numero << "\n";
				cout << "\tx: ";
				cin >> aux->x;
				cout << "\ty: ";
				cin >> aux->y;
				aux->siguiente = poligono;
				if(numero >= 3) {
					do {
						cout << "\n\t\t¿Desea introducir otro vértice? (S/N) ";
						cin >> resp;
						while(getchar() != '\n');
						if(resp >= 90) resp = resp - 32;
					} while(resp != 'N' && resp != 'S');
				}
				else resp = 'S';
			} while(resp == 'S');
			regular = lados_angulos(poligono, numero, regular);
			resultados(numero, regular);
			break;
		case 'B':
			double lado;
			aux = (struct vertice*) malloc(sizeof(struct vertice));
			poligono = aux;
			do {
				cabecera();
				cout << "\n\tPor favor, introduzca el número de vértices del "
				     << "polígono (no puede ser menor de 3).\n\n"
				     << "\tNúmero: ";
				cin >> numero;
				while(getchar() != '\n');
			} while(numero < 3);
			angulo = 180 -(360 / numero);
			cout << "\n\tPor favor, introduzca la longitud de los lados del "
			     << "polígono.\n\n";
			do {
				cout << "\tLongitud: ";
				cin >> lado;
				while(getchar() != '\n');
			} while(lado <= 0);
			cout << "\n\tPor favor, introduzca las coordenadas del primer vértice"
			     << " del\n\tpolígono.\n";
			cout << "\tx: ";
			cin >> aux->x;
			while(getchar() != '\n');
			cout << "\ty: ";
			cin >> aux->y;
			while(getchar() != '\n');
			aux->angulo = angulo;
			aux->arista_poste = lado;
			for(int i = 0; i < numero - 1; i++) {
				aux->siguiente = (struct vertice*) malloc(sizeof(struct vertice));
				aux->siguiente->x = aux->x + (cos(((i * (PI * 2 / numero)))) * aux->arista_poste);
				aux->siguiente->y = aux->y + (sin(((i * (PI * 2 / numero)))) * aux->arista_poste);
				aux = aux->siguiente;
				aux->angulo = angulo;
				aux->arista_poste = lado;
			}
			aux->siguiente = poligono;
			resultados(numero, regular);
			break;
		case 'C':
			double x, y;
			aux = (struct vertice*) malloc(sizeof(struct vertice));
			poligono = aux;
			cabecera();
			cout << "\n\tPor favor, introduzca las coordenadas del primer vértice del"
			     << "\n\tpolígono.\n";
			cout << "\tx: ";
			cin >> x;
			while(getchar() != '\n');
			cout << "\ty: ";
			cin >> y;
			while(getchar() != '\n');
			do {
				cabecera();
				for(int i = 0; i < numero; i++) {
					if(i % 4 == 0) cout << "\n";
					cout << "\t(" << poligono->x << ", " << poligono->y << ") ";
					poligono = poligono->siguiente;
				}
				if(numero >= 1) {
					aux->siguiente = (struct vertice*) malloc(sizeof(struct vertice));
					aux = aux->siguiente;
				}
				cout << "\n\tPor favor, introduzca la amplitud del " << numero + 1 << "º ángulo del polígono.\n";
				cout << "\n\tAmplitud (en grados): ";
				cin >> aux->angulo;
				while(getchar() != '\n');
				cout << "\n\tPor favor, introduzca la longitud del " << numero + 1 << "º lado del polígono.\n";
				cout << "\n\tLongitud: ";
				cin >> aux->arista_poste;
				while(getchar() != '\n');
				aux->x = x;
				aux->y = y;

				x = aux->x + (cos(numero * (PI * 2 / (360 / (180 - aux->angulo)))) * aux->arista_poste);
				y = aux->y + (sin(numero * (PI * 2 / (360 / (180 - aux->angulo)))) * aux->arista_poste);
				aux->siguiente = poligono;
				numero++;
			} while(((numero < 3)) || !(((redondea(x, 6)) == redondea(poligono->x, 6)) && ((redondea(y, 6)) == redondea(poligono->y, 6))));
			resultados(numero, regular);
			break;
		case 'S': return EXIT_SUCCESS;
		default:
			cout << "\n\n\t\tOpción seleccionada incorrecta.\n"
			     << "Presiona intro para continuar...";
			while(getchar() != '\n');
	}
	main();
	return EXIT_SUCCESS;
}

void cabecera() {
	system("clear");
	int frame_length = 80;
	for(int i = 0; i < frame_length; i++) cout << "=";
	cout << "\n\t\tCALCULADORA DE ÁREAS\n";
	for(int i = 0; i < frame_length; i++) cout << "=";
	cout << endl;
	return;
}

void resultados(int numero, int regular) {
	Fig figura(numero, regular);
	cabecera();
	cout << "\n\t\t\t\tResultados:\n\n"
	     << "\tVértice A \tÁngulo\t\tVértice B\tÁngulo\t\tDist";
	for(int i = 1; i <= numero; i++) {
		cout << endl;
		cout << i << "\t(" << poligono->x << ", " << poligono->y << ") <) " << poligono->angulo << "º"
		     << " \t(" << poligono->siguiente->x << ", " << poligono->siguiente->y << ") <) " << poligono->siguiente->angulo << "º"
		     << " \t|" << poligono->arista_poste << "|";
		poligono = poligono->siguiente;
	}
	cout << "\n\n\tEs un polígono de " << numero <<" vértices." << endl;
	if(figura.nombre() == "") cout << "\tSe desconoce el nombre de la figura." << endl;
	else cout << "\tLa figura se trata de un " << figura.nombre() << " " << figura.regular() << "." << endl;

	cout << "\tÁrea: " << figura.area() << " u²" << endl
	     << "\tPerímetro: " << figura.perimetro() << " u" << endl;
	cout << "\n\n\t\tPresiona intro para continuar...";
	while(getchar() != '\n');
	free_dynmem(numero);
	return;
}

void free_dynmem(int numero) {	/* Liberamos la memoria dinámica */
	aux = poligono->siguiente;
	poligono->siguiente = nullptr;
	poligono = aux;
	for(int i = 0; i < numero; i++) {
		aux = poligono;
		poligono = poligono->siguiente;
		free(aux);
	}
	return;
}


int lados_angulos(struct vertice *poligono, int lados, int regular) {
	double angulo_temp;
	double ax, ay, bx, by, cx, cy;
	for(int i = 0; i < lados; i++) {
		poligono->arista_poste = sqrt((pow(((poligono->siguiente)->x - poligono->x), 2.0)) + (pow(((poligono->siguiente)->y - poligono->y), 2.0)));
		ax = (poligono->siguiente)->x;
		ay = (poligono->siguiente)->y;
		bx = ((poligono->siguiente)->siguiente)->x;
		by = ((poligono->siguiente)->siguiente)->y;
		cx = poligono->x;
		cy = poligono->y;
		(poligono->siguiente)->angulo = acos((((bx - ax) * (cx - ax)) + ((by -ay) * (cy - ay))) / (sqrt(pow((bx - ax), 2) + pow((by - ay), 2)) * (sqrt(pow((cx - ax), 2) + pow((cy - ay), 2))))) * 180 / PI;

		poligono = poligono->siguiente;
		if(i == 0) angulo_temp = poligono->angulo;
		else if(angulo_temp != poligono->angulo) regular = 1;
	}
	return regular;
}

double redondea(double r, int n_digit) {
	int n = pow(10, n_digit);
	r = ((float)((int)(r * n + 0.5))) / n;
	return r;
}
