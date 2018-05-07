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
		printf("\n%3d%s",posRelativa,alumnoToSting(a));
	};
	printf("\n");

	fclose(f);

	return posRelativa;
}
int buscaReg(FILE *fSecuencial, tipoAlumno *reg,char *dni){
	int posRelativa;
	tipoAlumno a;
	
	posRelativa = -1;
	while(0 < fread(reg, sizeof(tipoAlumno), 1, fSecuencial)){
		posRelativa++;
		if(!strcmp(dni,reg->dni))
			return posRelativa;		
	};

	memset(reg,0,sizeof(tipoAlumno));
	return -1;
}
int insertaReg(char *fSecuencial, tipoAlumno *reg){
	FILE*f;	
	int posRelativa;

	if(NULL == (f = fopen(fSecuencial,"a+b")) )
		return -1;
	if(0 >= fwrite(reg,1, sizeof(tipoAlumno), f))
		return -2;
	if(0 >= (posRelativa = ftell(f))){
		return -3;
	}

	posRelativa /=  sizeof(tipoAlumno); 

	fclose(f);

	printf("\nPOSICION RELATIVA: %d",posRelativa);
	return posRelativa;
}

char* alumnoToSting(tipoAlumno a){
	char*string;
	if(NULL == (string = calloc(73,sizeof(char))) )
		return NULL; 
	sprintf(string,"%12s%15s%15s%15s%15s",a.dni,a.nombre,a.ape1,a.ape2,a.provincia);
	return string;
}
