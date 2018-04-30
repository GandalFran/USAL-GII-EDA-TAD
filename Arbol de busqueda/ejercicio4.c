#include <stdio.h>
#include <stdlib.h>
#include "arbolBB.h"

int calcularfe(Arbol raiz);

int main(void){
	tipoArbolBB raiz;
	calcularfe(raiz);
	
}

int calcularfe(Arbol raiz){
	if(NULL == raiz)
		return -1;
	else{
		int izq, der;
		izq = calcularfe(raiz->izq);
		der = calcularfe(raiz->der);
		raiz->fe = der - izq;
		return 1 + ((izq>der)? izq : der);
	}
}

