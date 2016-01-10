#include <iostream>
#include <cstdio>
#include <string>
#include "curvos.h"
#include "especiales.h"
#include "piramidales.h"
#include "poliedro.h"
#include "poligonos.h"
#include "prismas.h"

typedef char cadena[20];

struct figuras{
	curvos redondas;
	poligonos poligonal;
	especiales poli_especial;
	piramidales piramides;
	poliedro poliedricas;
	prismas prisma;
}

void parser(string comando){
	figuras fig;	
	int arg_inicio=comando.find("(")+1;
	int arg_fin=comando.find(")");
	string orden=comando.substr(0, arg_inicio-2);
	int fin_arg1=orden.find(", ")-1;
	int fin_arg2=orden.find(", ", fin_arg1)-1;
	string arg1=orden.substr(arg_inicio, fin_arg1);
	string arg2=orden.substr(fin_arg1+2, fin_arg2);
	
	//float par1=atof(arg1);
	//float par2=atof(arg2);

	if(strcmp("circulo", orden)==0){
		float radio=atof(arg1);
		//int dimension=atoi(arg2);		
		fig.redondas.calcular_area(radio, 2);
	}
	else if(strcmp("elipse", orden)==0){
		float semiejex=atof(arg1);
		float semiejey=atof(arg2);
		fig.redondas.calcular_area(semiejex, semiejey);	
	}

}
		
