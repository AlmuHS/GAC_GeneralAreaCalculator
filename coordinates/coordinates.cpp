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

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <string>

using namespace std;

struct vertice {
	double x, y, angulo, arista_poste;
	struct vertice *siguiente;
} vertice;

const long double PI = 3.141592653589793115997963468544185161590576171875;

class Fig {
	private:
		int l = 0; /* No se inicializa solo correctamente, hay que indicar el valor inicial */
		double a, peri;
		string reg = "irregular";
	public:
		int Lados();
		double Area();
		double Perimetro();
		string Nombre();
		string Regular();
		void setLados(int n);
		void setSize(struct vertice *poligono);
		void setRegular(struct vertice *poligono);
		void setValues(struct vertice *poligono);
};

int Fig::Lados() {
	return l;
}

double Fig::Area() {
	return a;
}

double Fig::Perimetro() {
	return peri;
}

string Fig::Nombre() {
	string pol_peque[] = {"","henágono", "dígono", "triángulo", "cuadrado", "pentágono", "hexágono","heptágono", "octágono", "eneágono", "decágono", "endecágono", "dodecágono", "tridecágono", "tetradecágono", "pentadecágono", "hexadecágono", "heptadecágono", "octodecágono", "eneadecágono"};
	string pol_peque2[] = {"á", "akaihená","akaidí", "akaitrí", "akaitetrá", "akaipentá", "akaihexá","akaiheptá", "akaioctá", "akaieneá"};
	string pol_grande[] = {"", "","icos", "triacont", "tetracont", "pentacont", "hexacont","heptacont", "octacont", "eneacont"};

	if(l >= 100) return "";
	if(l >= 20) return pol_grande[l / 10] + pol_peque2[l % 10] + "gono";
	return pol_peque[l];
}

string Fig::Regular() {
	return reg;
}

void Fig::setLados(int n) {
	l = n;
}

void Fig::setSize(struct vertice *poligono) {
	double x, y;
	for(int i = 0; i < l; i++) {
		x += poligono->x * (poligono->siguiente)->y;
		y += poligono->y * (poligono->siguiente)->x;
		peri += poligono->arista_poste;
		poligono = poligono->siguiente;
	}
	a = abs(x - y) / 2;
}

void Fig::setRegular(struct vertice *poligono) {
	double angulo_temp, ax, ay, bx, by, cx, cy;
	for(int i = 0; i < l; i++) {
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
		else if(angulo_temp != poligono->angulo) reg = "regular";
	}
}

void Fig::setValues(struct vertice *poligono) {
	setRegular(poligono); /* Si invierto el orden la primera vez que ejecuto a) el perímetro me sale a 0 */
	setSize(poligono);
}

void cabecera();
void free_dynmem(int numero, struct vertice *poligono, struct vertice *aux);
double redondea(double r, int n_digit);

int main() {
	cout << setprecision(2) << fixed;
	char menu_resp;
	cabecera();
	cout << "\n\tSeleccione una opción del menú.\n"
	     << "\n\t\ta) Calcular el área de cualquier polígono a"
	     << "\n\t\t partir de las coordenadas de los vértices."
	     << "\n\t\tb) Calcular área de un polígono regular."
	     << "\n\t\tc) Calcular área de un polígono cualquiera,"
	     << "\n\t\t introduciendo lados y ángulos."
	     << "\n\n\t\ts) Salir" << endl;
	cout << "\n\n\t\t\tRespuesta: ";
	cin >> menu_resp;
	while(getchar() != '\n');
	if(menu_resp >= 90) menu_resp = menu_resp - 32;
	struct vertice *poligono, *aux;
	Fig figura;
	switch(menu_resp) {
		case 'A':
			aux = (struct vertice*) malloc(sizeof(struct vertice));
			poligono = aux;

			char resp;
			do {
				cabecera();
				cout << "\n\tPor favor, introduzca las coordenadas de los vértices del polí-"
				     << "\n\tgono en sentido horario.\n";

				/* Repetido en case 'C' */
				for(int i = 0; i < figura.Lados(); i++) {
					if(i % 4 == 0) cout << "\n";
					cout << "\t(" << poligono->x << ", " << poligono->y << ") ";
					poligono = poligono->siguiente;
				}
				if(figura.Lados() >= 1) {
					aux->siguiente = (struct vertice*) malloc(sizeof(struct vertice));
					aux = aux->siguiente;
				}



				cout << "\n\n";
				figura.setLados(figura.Lados() + 1);
				cout << "\tVértice " << figura.Lados() << "\n";
				cout << "\tx: ";
				cin >> aux->x;
				cout << "\ty: ";
				cin >> aux->y;
				aux->siguiente = poligono;
				if(figura.Lados() >= 3) {
					do {
						cout << "\n\t\t¿Desea introducir otro vértice? (S/N) ";
						cin >> resp;
						while(getchar() != '\n');
						if(resp >= 90) resp = resp - 32;
					} while(resp != 'N' && resp != 'S');
				}
				else resp = 'S';
			} while(resp == 'S');
			break;
		case 'B':
			aux = (struct vertice*) malloc(sizeof(struct vertice));
			poligono = aux;

			double angulo, lado;
			do {
				cabecera();
				cout << "\n\tPor favor, introduzca el número de vértices del "
				     << "polígono (no puede ser menor de 3).\n\n"
				     << "\tNúmero: ";
				int intLados;
				cin >> intLados;
				figura.setLados(intLados);
				while(getchar() != '\n');
			} while(figura.Lados() < 3);
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
			aux->angulo = angulo = 180 - (360 / figura.Lados());
			aux->arista_poste = lado;
			for(int i = 1; i < figura.Lados(); i++) {
				aux->siguiente = (struct vertice*) malloc(sizeof(struct vertice));
				aux->siguiente->x = aux->x + (cos(((i * (PI * 2 / figura.Lados())))) * aux->arista_poste);
				aux->siguiente->y = aux->y + (sin(((i * (PI * 2 / figura.Lados())))) * aux->arista_poste);
				aux = aux->siguiente;
				aux->angulo = angulo;
				aux->arista_poste = lado;
			}
			aux->siguiente = poligono;
			break;
		case 'C':
			aux = (struct vertice*) malloc(sizeof(struct vertice));
			poligono = aux;

			double x, y;
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

				/* Repetido en case 'A' */
				for(int i = 0; i < figura.Lados(); i++) {
					if(i % 4 == 0) cout << "\n";
					cout << "\t(" << poligono->x << ", " << poligono->y << ") ";
					poligono = poligono->siguiente;
				}
				if(figura.Lados() >= 1) {
					aux->siguiente = (struct vertice*) malloc(sizeof(struct vertice));
					aux = aux->siguiente;
				}



				cout << "\n\tPor favor, introduzca la amplitud del " << figura.Lados() + 1 << "º ángulo del polígono.\n";
				cout << "\n\tAmplitud (en grados): ";
				cin >> aux->angulo;
				while(getchar() != '\n');
				cout << "\n\tPor favor, introduzca la longitud del " << figura.Lados() + 1 << "º lado del polígono.\n";
				cout << "\n\tLongitud: ";
				cin >> aux->arista_poste;
				while(getchar() != '\n');
				aux->x = x;
				aux->y = y;

				x = aux->x + (cos(figura.Lados() * (PI * 2 / (360 / (180 - aux->angulo)))) * aux->arista_poste);
				y = aux->y + (sin(figura.Lados() * (PI * 2 / (360 / (180 - aux->angulo)))) * aux->arista_poste);
				aux->siguiente = poligono;
				figura.setLados(figura.Lados() + 1);
			} while(((figura.Lados() < 3)) || !(((redondea(x, 6)) == redondea(poligono->x, 6)) && ((redondea(y, 6)) == redondea(poligono->y, 6))));
			break;
		case 'S': return EXIT_SUCCESS;
		default:
			cout << "\n\n\t\tOpción seleccionada incorrecta.\n"
			     << "Presiona intro para continuar...";
			while(getchar() != '\n');
			main();
			return EXIT_SUCCESS;
	}
	figura.setValues(poligono);
	cabecera();
	cout << "\n\t\t\t\tResultados:\n\n"
	     << "\tVértice A \tÁngulo\t\tVértice B\tÁngulo\t\tDist";
	for(int i = 1; i <= figura.Lados(); i++) {
		cout << "\n";
		cout << i << "\t(" << poligono->x << ", " << poligono->y << ") <) " << poligono->angulo << "º"
		     << " \t(" << poligono->siguiente->x << ", " << poligono->siguiente->y << ") <) " << poligono->siguiente->angulo << "º"
		     << " \t|" << poligono->arista_poste << "|";
		poligono = poligono->siguiente;
	}
	cout << "\n\n\tEs un polígono de " << figura.Lados() <<" vértices.\n";
	if(figura.Nombre() == "") cout << "\tSe desconoce el nombre de la figura.\n";
	else cout << "\tLa figura se trata de un " << figura.Nombre() << " " << figura.Regular() << ".\n";
	cout << "\tÁrea: " << figura.Area() << " u²\n"
	     << "\tPerímetro: " << figura.Perimetro() << " u" << endl;
	cout << "\n\n\t\tPresiona intro para continuar...";
	while(getchar() != '\n');
	free_dynmem(figura.Lados(), poligono, aux);
	main();
	return EXIT_SUCCESS;
}

void cabecera() {
	system("clear");
	int frame_length = 80;
	for(int i = 0; i < frame_length; i++) cout << "=";
	cout << "\n\t\t\tCALCULADORA DE ÁREAS\n";
	for(int i = 0; i < frame_length; i++) cout << "=";
	cout << endl;
	return;
}

void free_dynmem(int numero, struct vertice *poligono, struct vertice *aux) {
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

double redondea(double r, int n_digit) {
	int n = pow(10, n_digit);
	r = ((float)((int)(r * n + 0.5))) / n;
	return r;
}
