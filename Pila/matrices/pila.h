#ifndef __PILA_H
#define __PILA_H

typedef int tipoElemento;
#define MAX 100

typedef struct {
    int tope;
    tipoElemento elementos[MAX];
} Pila;
	


int pilaCreaVacia(Pila *p);

int pilaVacia(Pila *p);

int pilaInserta(Pila *p,tipoElemento elemento);

tipoElemento pilaSuprime(Pila *p);


#endif
