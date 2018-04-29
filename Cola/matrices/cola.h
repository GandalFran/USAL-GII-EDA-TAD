#ifndef __COLA_H
#define __COLA_H

typedef int tipoElemento;
#define MAX 100


typedef struct {
	int tamagno;
    int frente, fondo;
	tipoElemento elementos[MAX];
	} Cola;



int colaCreaVacia(Cola *c);

int colaVacia(Cola *c);

int colaInserta(Cola *c, tipoElemento elemento);

tipoElemento colaSuprime(Cola *c);

#endif