#ifndef __PILA_H
#define __PILA_H

typedef int tipoElemento;

#ifndef TIPOCELDA__
#define TIPOCELDA__
typedef struct tipoCelda { 
	tipoElemento elemento; 
	struct tipoCelda * sig; 
	} tipoCelda;
#endif
	
typedef tipoCelda * Pila;

int pilaCreaVacia(Pila *p);

int pilaVacia(Pila *p);

int pilaInserta(Pila *p,tipoElemento elemento);

tipoElemento pilaSuprime(Pila *p);


#endif
