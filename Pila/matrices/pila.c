#include <stdio.h>
#include <stdlib.h>
#include "pila.h"


/*
typedef struct {
    int tope;
    tipoElemento elementos[MAX];
} Pila;
*/

int pilaCreaVacia(Pila *p){
	if( NULL == p) return -1;

	p->tope = -1;

	return 0;
}

int pilaVacia(Pila *p){
	if(NULL == p)	return -1;
	if(NULL == p->elementos) return -2;

	return (p->tope <= -1) ? (1) : (0);
}

int pilaInserta(Pila *p,tipoElemento elemento){
	if(NULL == p) return -1;
	if(NULL == p->elementos) return -2;
	if(p->tope >= (MAX-1)) return -3;

	p->tope++;
	p->elementos[p->tope] = elemento;

	return 0;
}

tipoElemento pilaSuprime(Pila *p){
	if(NULL == p) return -1;
	if(NULL == p->elementos) return -2;
	if(p->tope <= -1) return -4;


	tipoElemento valor = p->elementos[p->tope];
	p->tope--;

	return valor;
}
