#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "secuencial.h"

/*typedef struct {
	char dni[9];
	char nombre[19];
	char ape1[19];
	char ape2[19];
	char provincia[11];
	} tipoAlumno;
*/

char* __alumnoToSting(tipoAlumno a){
	char*string;
	if(NULL == (string = calloc(73,sizeof(char))) )
		return NULL; 
	sprintf(string,"%12s%15s%15s%15s%15s",a.dni,a.nombre,a.ape1,a.ape2,a.provincia);
	return string;
}

int leeSecuencial(char *fichero){
	FILE*f;	
	int posRelativa;
	tipoAlumno a;

	if(NULL == (f = fopen(fichero,"r")) ){
		return -1;
	}
	
	posRelativa = -1;
	while(0 < fread(&a, sizeof(tipoAlumno), 1, f)){
		posRelativa++;
		printf("\n%3d%s",posRelativa,__alumnoToSting(a));
	};
	printf("\n");

	return posRelativa;
}
int buscaReg(FILE *fSecuencial, tipoAlumno *reg,char *dni){

}
int insertaReg(char *fSecuencial, tipoAlumno *reg){

}
