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
#include <math.h>
#include <iostream>
#include <string>
#define PI 3.14159265358979323846
#define SCR_X 1280
#define SCR_Y 800

using namespace std;

struct vertice {
	double x, y, angulo, arista_poste;
	struct vertice *siguiente;
} vertice;

struct vertice *poligono, *aux;
int regular;
int numero = 0;

void cabecera();
void resultados();
void mostrar_poligono(struct vertice *poligono, int numero, double x_max, double y_max, double x_min, double y_min);
string nombre_poligono(int lados, int reg);
int lados_angulos(struct vertice *poligono, int lados);
double mayorque(double x, double y);
double menorque(double x, double y);
double redondea(double r, int n_digit);

int main() {
	numero = 0;
	double angulo;
	char menu_resp, resp;
	cabecera();
	printf( "\n\tSeleccione una opción del menú.\n"
	        "\n\t\ta) Calcular el area de cualquier polígono a"
	        "\n\t\t partir de las coordenadas de los vértices."
	        "\n\t\tb) Calcular área de un polígono regular."
	        "\n\t\tc) Calcular área de un polígono cualquiera,"
	        "\n\t\t introduciendo lados y ángulos."
	        "\n\n\t\ts) Salir"
	        "\n\n\n\t\t\tRespuesta: ");
	scanf("%c", &menu_resp);
	while(getchar() != '\n');
	if(menu_resp >= 90) menu_resp = menu_resp - 32;
	switch(menu_resp) {
		case 'A': {
			aux = (struct vertice*) malloc(sizeof(struct vertice));
			poligono = aux;
			char resp;
			do {
				cabecera();
				printf("\n\tPor favor, introduzca las coordenadas de los vértices del "
				       "polí-\n\tgono en sentido horario.\n");
				for(int i = 0; i < numero; i++) {
					if(i % 4 == 0) printf("\n");
					printf("\t(%.2f, %.2f) ", poligono->x, poligono->y);
					poligono = poligono->siguiente;
				}
				printf("\n\n");

				if(resp == 'S') {
					aux->siguiente = (struct vertice*) malloc(sizeof(struct vertice));
				aux = aux->siguiente;
				}

				numero++;
				printf("\tVértice %d\n", numero);
				printf("\tx: ");
				scanf("%lf", &(aux->x));
				printf("\ty: ");
				scanf("%lf", &(aux->y));
				aux->siguiente = poligono;
				do {
					if(numero >= 3) {
						printf("\n\t\t¿Desea introducir otro vértice? (S/N) ");
						resp = getchar();
						while(getchar() != '\n');
						if(resp >= 90) resp = resp - 32;
					}
					else resp = 'S';
				} while(resp != 'N' && resp != 'S');
			} while(resp == 'S');
			regular = lados_angulos(poligono, numero);
			resultados();
			break;
		}
		case 'B':
			double lado;
			aux = (struct vertice*) malloc(sizeof(struct vertice));
			poligono = aux;
			do {
				cabecera();
				printf( "\n\tPor favor, introduzca el número de vértices del "
			        "polígono (no puede ser menor de 3).\n\n");
				printf( "\tNúmero: ");
				scanf("%d", &numero);
				while(getchar() != '\n');
			} while(numero < 3);
			angulo = 180 -(360 / numero);
			printf( "\n\tPor favor, introduzca la longitud de los lados del "
			        "polígono.\n\n");
			do {
				printf("\tLongitud: ");
				scanf("%lf", &lado);
				while(getchar() != '\n');
			} while(lado <= 0);
			printf("\n\tPor favor, introduzca las coordenadas del primer vértice"
			       " del\n\tpolígono.\n");
			printf("\tx: ");
			scanf("%lf", &(aux->x));
			while(getchar() != '\n');
			printf("\ty: ");
			scanf("%lf", &(aux->y));
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
			resultados();
			break;
		case 'C':
			double x, y;
			aux = (struct vertice*) malloc(sizeof(struct vertice));
			poligono = aux;
			cabecera();
			printf("\n\tPor favor, introduzca las coordenadas del primer vértice"
			       " del\n\tpolígono.\n");
			printf("\tx: ");
			scanf("%lf", &x);
			while(getchar() != '\n');
			printf("\ty: ");
			scanf("%lf", &y);
			while(getchar() != '\n');
			do {
				cabecera();
				for(int i = 0; i < numero; i++) {
					if(i % 4 == 0) printf("\n");
					printf("\t(%.2G, %.2G) ", poligono->x, poligono->y);
					poligono = poligono->siguiente;
				}
				if(numero >= 1) {
					aux->siguiente = (struct vertice*) malloc(sizeof(struct vertice));
					aux = aux->siguiente;
				}
				printf( "\n\tPor favor, introduzca la amplitud del %dº ángulo del "
				        "polígono.\n", numero + 1);
				printf( "\n\tAmplitud (en grados): ");
				scanf("%lf", &aux->angulo);
				while(getchar() != '\n');
				printf( "\n\tPor favor, introduzca la longitud del %dº lado del "
				        "polígono.\n", numero + 1);
				printf( "\n\tLongitud: ");
				scanf("%lf", &aux->arista_poste);
				while(getchar() != '\n');
				aux->x = x;
				aux->y = y;

				x = aux->x + (cos(numero * (PI * 2 / (360 / (180 - aux->angulo)))) * aux->arista_poste);
				y = aux->y + (sin(numero * (PI * 2 / (360 / (180 - aux->angulo)))) * aux->arista_poste);
				aux->siguiente = poligono;
				numero++;
			} while(((numero < 3)) || !(((redondea(x, 6)) == redondea(poligono->x, 6)) && ((redondea(y, 6)) == redondea(poligono->y, 6))));
			resultados();
			break;
		case 'S': return EXIT_SUCCESS;
		default:
			printf("\n\n\t\tOpción seleccionada incorrecta.\n"
			       "Presiona intro para continuar...");
			while(getchar() != '\n');
	}
	main();
	return EXIT_SUCCESS;
}

void cabecera() {
	system("clear");
	int frame_length = 80;
	for(int i = 0; i < frame_length; i++) printf("=");
	printf("\n\t\t\t CALCULADORA DE ÁREAS\n");
	for(int i = 0; i < frame_length; i++) printf("=");
	printf("\n");
	return;
}

void resultados() {
	/* Hallamos el área */
	double area, x, y;
	for(int i = 0; i < numero; i++) {
		x = x + (poligono->x * (poligono->siguiente)->y);
		y = y + (poligono->y * (poligono->siguiente)->x);
		poligono = poligono->siguiente;
	}
	area = fabsf(x - y) / 2;
	/* Calculamos el perímetro */
	double peri = 0;
	double x_max = poligono->x;
	double x_min = poligono->x;
	double y_max = poligono->y;
	double y_min = poligono->y;
	for(int i = 0; i < numero; i++) {
		x_max = mayorque(poligono->x, x_max);
		x_min = menorque(poligono->x, x_min);
		y_max = mayorque(poligono->y, y_max);
		y_min = menorque(poligono->y, y_min);
		peri = peri + poligono->arista_poste;
		poligono = poligono->siguiente;
	}

	/* Interfaz */
	cabecera();
	printf("\n\t\t\t\tResultados:\n\n"
	       "\tVértice A \tÁngulo\t\tVértice B\tÁngulo\t\tDist");
	for(int i = 0; i < numero; i++) {
		if(i % 1 == 0) printf("\n");
		printf("%d\t(%.2f, %.2f) <) %.2fº", i + 1, poligono->x, poligono->y, poligono->angulo);
		printf(" \t(%.2f, %.2f) <) %.2fº", poligono->siguiente->x, poligono->siguiente->y, poligono->siguiente->angulo);
		printf(" \t|%.2f|", poligono->arista_poste);
		poligono = poligono->siguiente;
	}
	//nombre_poligono(numero, regular); /* Reconocemos de qué polígono se trata */
	printf("\n\n\tEs un polígono de %d vértices.\n", numero);
	if(numero >= 100) printf("\tSe desconoce el nombre de la figura.\n");
	else cout << "\tLa figura se trata de un " << nombre_poligono(numero, regular) << "." << endl;
	
	printf("\tÁrea: %G u²\n", area);
	printf("\tPerímetro: %G u\n", peri);
	mostrar_poligono(poligono, numero, x_max, y_max, x_min, y_min);
	printf("\n\n\t\tPresiona intro para continuar...");
	while(getchar() != '\n');

	/* Liberamos la memoria dinámica */
	aux = poligono->siguiente;
	poligono->siguiente = NULL;
	poligono = aux;
	for(int i = 0; i < numero; i++) {
		aux = poligono;
		poligono = poligono->siguiente;
		free(aux);
	}

	return;
}

void mostrar_poligono(struct vertice *poligono, int numero, double x_max, double y_max, double x_min, double y_min) {
	double x, x2, y, y2;
	double factor = menorque((SCR_X - 40) / (x_max - x_min), (SCR_Y - 40) / (y_max - y_min));
	double diferenciax = ((SCR_X - 40) - ((x_max - x_min) * factor)) / 2;
	double diferenciay = ((SCR_Y - 40) - ((y_max - y_min) * factor)) / 2;
	for(int i = 0; i < numero; i++) {
		x = (20 + diferenciax) + (poligono->x - x_min) * (factor);
		y = (SCR_Y-(20 + diferenciay)) - (poligono->y - y_min) * (factor);
		x2 = (20 + diferenciax) + (poligono->siguiente->x - x_min) * (factor);
		y2 = (SCR_Y - (20 + diferenciay)) - (poligono->siguiente->y - y_min) * (factor);
		//textprintf_ex(screen, font, x, y, makecol(255, 255, 255),-1, "(%.2f,%.2f)",poligono->x,poligono->y);
		poligono = poligono->siguiente;
	}
	x = (20 + diferenciax) + (x_max - x_min) * (factor) / 2;
	y = (SCR_Y - (20 + diferenciay)) - (y_max - y_min) * (factor) / 2;
	return;
}

string nombre_poligono(int lados, int reg) {
	string pol_peque[] = {"","henágono", "dígono", "triángulo", "cuadrángulo", "pentágono", "hexágono","heptágono", "octágono", "eneágono", "decágono", "endecágono", "dodecágono", "tridecágono", "tetradecágono", "pentadecágono", "hexadecágono", "heptadecágono", "octodecágono", "eneadecágono"};
	string pol_peque2[] = {"á", "akaihená","akaidí", "akaitrí", "akaitetrá", "akaipentá", "akaihexá","akaiheptá", "akaioctá", "akaieneá"};
	string pol_grande[] = {"", "","icos", "triacont", "tetracont", "pentacont", "hexacont","heptacont", "octacont", "eneacont"};
	string nombre;

	if(lados >= 100) return "";
	if(lados >= 20) nombre = pol_grande[lados / 10] + pol_peque2[lados % 10] + "gono";
	else nombre = pol_peque[lados];
	if(!reg) nombre += " irregular";
	else nombre += " regular";
	return nombre;
}

int lados_angulos(struct vertice *poligono, int lados) {
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
		else if(angulo_temp != poligono->angulo) regular = 0;
	}
	return regular;
}

double mayorque(double x, double y) {
	if(x > y) return x;
	else return y;
}

double menorque(double x, double y) {
	if(x < y) return x;
	else return y;
}

double redondea(double r, int n_digit) {
	int n = pow(10, n_digit);
	r = ((float)((int)(r * n + 0.5))) / n;
	return r;
}
