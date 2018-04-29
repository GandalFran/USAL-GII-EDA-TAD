#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/*typedef struct tipoCelda { 
	tipoElemento elemento; 
	struct tipoCelda * sig; 
	} tipoCelda;
	
typedef tipoCelda * Pila;*/

tipoElemento ERROR_X_ = -1;

int pilaCreaVacia(Pila *p){
	if(NULL == p) return -1;

	*p = NULL;
	return 0;
}

int pilaVacia(Pila *p){
	if(NULL == p) return -1;

	return (NULL == *p);
}

int pilaInserta(Pila *p,tipoElemento elemento){
	if(NULL == p) return -1;

	tipoCelda*c;
	if(NULL == (c = malloc(sizeof(tipoCelda))) ) return -5;
	c->elemento = elemento;
	c->sig = NULL;

	if(NULL == *p) *p = c;
	else{
		c->sig = *p;
		*p = c;
	}
	return 0;
}

tipoElemento pilaSuprime(Pila *p){
	if(NULL == p) return ERROR_X_;
	if(NULL == *p) return ERROR_X_;
	
	tipoCelda *aBorrar = *p;
	tipoElemento c = aBorrar->elemento;

	*p = (*p)->sig;
	free(aBorrar);

	return c;
}
