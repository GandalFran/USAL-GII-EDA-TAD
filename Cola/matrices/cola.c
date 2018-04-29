#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

/*
typedef struct {
	int tamagno;
    int frente, fondo;
	tipoElemento elementos[MAX];
	} Cola;
*/


int colaCreaVacia(Cola *c){
	if( NULL == c) return -1;

	c->tamagno = 0;
	c->frente = 0;
	c->fondo = MAX-1;

	return 0;
}

int colaVacia(Cola *c){
	if(NULL == c) return -1;
	if(NULL == c->elementos) return -2;

	return !c->tamagno;
}

void incrementarIndice(int *i){
	*i = ( (*i+1)>=(MAX) ) ? (0) : (*i+1);
}

int colaInserta(Cola *c, tipoElemento elemento){
	if(NULL == c) return -1;
	if(NULL == c->elementos) return -2;
	if(c->tamagno >= MAX-1) return -3;

	
	incrementarIndice(&c->fondo);
	c->elementos[c->fondo] = elemento;
	c->tamagno++;

	return 0;
}

tipoElemento colaSuprime(Cola *c){
	if(NULL == c) return -1;
	if(NULL == c->elementos) return -2;
	if(!c->tamagno) return -4;


	tipoElemento valor = c->elementos[c->frente];
	incrementarIndice(&c->frente);
	c->tamagno--;

	return valor;
}


