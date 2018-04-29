#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbolBB.h"

int main(int argc,char*argv[]){
	FILE*pf;
	char buffer[500];
	tipoClave palabra;
	int i,inicio;
	tipoArbolBB arbol = NULL;
	tipoNodo*buscado;

	if(NULL==(pf=fopen(argv[1],"r"))){
		printf("\nError: No se encontro %s\n",argv[1]);
		return 0;
	}

	while(!feof(pf)){
		memset(palabra,'\0',sizeof(palabra));
		fscanf(pf,"%s",palabra);
		insertar(&arbol,palabra);
	}

	fclose(pf);

	if(NULL==(pf=fopen(argv[1],"r"))){
		printf("\nError: No se encontro %s\n",argv[1]);
		return 0;
	}

	while(!feof(pf)){
		memset(palabra,'\0',sizeof(palabra));
		fscanf(pf,"%s",palabra);
		buscar(palabra,arbol,&buscado);
		printf("\n%s -- %d",buscado->clave,buscado->info);
	}

	fclose(pf);

	printf("\n");
	return 0;
}