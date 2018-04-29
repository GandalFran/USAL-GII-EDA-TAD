#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"
#include "pila.h"
#include "genArbol.h"

Arbol genArbol(char *exPostfija){
	Pila p;
	int i;
	Arbol a = NULL;
	pilaCreaVacia(&p);

	i = 0;
	while(exPostfija[i] != '\0'){
		a = creaNodo(exPostfija[i]);
		if(exPostfija[i] == '+' || exPostfija[i] == '-' || exPostfija[i] == '*' || exPostfija[i] == '/' || exPostfija[i] == '%'){
			a->der = pilaSuprime(&p);
			a->izq = pilaSuprime(&p);
		}
		pilaInserta(&p,a);
		i++;
	}

	return a;
}