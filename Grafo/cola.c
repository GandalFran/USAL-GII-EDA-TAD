#include <stdio.h>
#include <stdlib.h>
#include "cola.h"


/*
typedef struct tipoCelda { 
	tipoElemento elemento; 
	struct tipoCelda * sig; 
	} tipoCelda;

typedef struct {
        tipoCelda *frente, *fondo;
} Cola;
*/

tipoElemento ERROR = -1;

int colaCreaVacia(Cola *c){
	if(NULL == c) return -1;

	c->frente = c->fondo = NULL;
	return 0;
}

int colaVacia(Cola *c){
	if(NULL == c) return -1;

	return (c->frente == NULL && c->fondo == NULL);
}

int colaInserta(Cola *c, tipoElemento elemento){
	if(NULL == c) return -1;

	tipoCelda*celda;
	if(NULL == (celda = malloc(sizeof(tipoCelda))) ) return -5;
	celda->elemento = elemento;
	celda->sig = NULL;

	if(NULL == c->fondo)
		c->frente = c->fondo = celda;
	else
		c->fondo = c->fondo->sig = celda;
	
	return 0;
}

tipoElemento colaSuprime(Cola *c){
	if(NULL == c) return ERROR;
	if(NULL==c->frente) return ERROR;

	tipoCelda*aBorrar = c->frente;
	tipoElemento valor = aBorrar->elemento;

	c->frente = aBorrar->sig;
	if(aBorrar == c->fondo)
		c->fondo = c->frente;
	free(aBorrar);

	return valor;
}
