#include <stdio.h>
#include <stdlib.h>
#include "arbolBB.h"

int calcularfe(Arbol raiz);

int main(void){
	tipoArbolBB raiz;
	calcularfe(raiz);
	
}

int calcularfe(Arbol raiz,int*h){
	if(NULL == raiz){
		*h = -1;
		return 1;
	}else{
		int hizq, hder;
		if(!calcularfe(raiz->izq,&hizq) || !calcularfe(raiz->der,&hder))
			return 0;
		
		*h = 1 + ((hizq > hder) ? (hizq) : (hder));
		
		raiz->fe = hder - hizq;
		return (raiz->fe < -1 || raiz->fe > 1) ? (0) : (1);
	}
}