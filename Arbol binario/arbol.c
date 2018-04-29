#include <stdlib.h>
#include <stdio.h>
#include "arbol.h"
#include "cola.h"

/*
typedef struct tipoNodo {
        tipoInfo info;
        struct tipoNodo *izq,*der;
        } tipoNodo;

typedef tipoNodo * Arbol;
*/

Arbol creaNodo(tipoInfo info){
	Arbol a;

	if(NULL == (a = malloc(sizeof(Arbol))))
		return NULL;

	a->info = info;
	a->izq = a->der = NULL;

	return a;
}

void preOrden(Arbol raiz){
	if(NULL != raiz){
		printf("%c",raiz->info);
		preOrden(raiz->izq);
		preOrden(raiz->der);
	}
}

void enOrden(Arbol raiz){
	if(NULL != raiz){
		enOrden(raiz->izq);
		printf("%c",raiz->info);
		enOrden(raiz->der);
	}
}

void postOrden(Arbol raiz){
	if(NULL != raiz){
		postOrden(raiz->izq);
		postOrden(raiz->der);
		printf("%c",raiz->info);
	}
}

void amplitud(Arbol raiz){
	Cola c;
	Arbol a;

	colaCreaVacia(&c);

	if(raiz!=NULL)
		colaInserta(&c,raiz);
	while(!colaVacia(&c)){
		a = colaSuprime(&c);
		printf("%c",a->info);
		if(NULL != a->izq)
			colaInserta(&c,a->izq);
		if(NULL != a->der)
			colaInserta(&c,a->der);
	}
}

int altura(Arbol raiz){
	if(NULL == raiz)
		return -1;
	else{
		int izq, der;
		izq = altura(raiz->izq);
		der = altura(raiz->der);
		return 1 + ((izq>der)? izq : der);
	}
}

int numNodos(Arbol raiz){
	if(NULL == raiz)
		return 0;
	else
		return 1 + numNodos(raiz->izq) + numNodos(raiz->der);
}

Arbol anula(Arbol raiz){
	if(NULL != raiz){
		raiz->izq = anula(raiz->izq);
		raiz->der = anula(raiz->der);
		free(raiz);
		return NULL;
	}
}

int sustituye(Arbol raiz, tipoInfo x, tipoInfo y){
	if(NULL == raiz)
		return 0;
	else{
		int izq,der;
		izq = sustituye(raiz->izq,x,y);
		der = sustituye(raiz->der,x,y);
		if(raiz->info == x){
			raiz->info = y;
			return izq + der + 1;		
		}
		return izq + der;
	}
}

int numNodosHoja(Arbol raiz){
	if(NULL == raiz)
		return 0;
	else{
		if(NULL == raiz->izq && NULL== raiz->der)
			return 1;
		else
			return numNodosHoja(raiz->izq) + numNodosHoja(raiz->der);
	}
}

int numNodosInternos(Arbol raiz){
	if(NULL == raiz)
		return 0;
	else{
		if(NULL!=raiz->izq || NULL!=raiz->der)
			return 1 + numNodosInternos(raiz->izq) + numNodosInternos(raiz->der);
	}
}

int numHijoUnico(Arbol raiz){
	if(NULL == raiz)
		return 0;
	else{
		if((NULL!=raiz->izq && NULL==raiz->der) || (NULL==raiz->izq && NULL!=raiz->der))
			return 1 + numHijoUnico(raiz->der) + numHijoUnico(raiz->izq);
		else
			return numHijoUnico(raiz->der) + numHijoUnico(raiz->izq);
	}
}

Arbol buscarMax(Arbol raiz){
	if(NULL == raiz)
		return NULL;
	else{
		Arbol izq, der, max;
		izq = buscarMax(raiz->izq);
		der = buscarMax(raiz->der);
		

		if(NULL == izq && NULL == der)
			return raiz;
		else if(NULL == der)
			return (raiz->info > izq->info) ? raiz : izq;
		else if(NULL == izq)
			return (raiz->info > der->info) ? raiz : der;
		else{
			max = raiz;
			if(max->info < der->info)
				max = der;
			else if(max->info < izq->info)
				max = izq;
			return max;
		}
	}
}

Arbol buscarMin(Arbol raiz){
	if(NULL == raiz)
		return NULL;
	else{
		Arbol izq, der, max;
		izq = buscarMax(raiz->izq);
		der = buscarMax(raiz->der);
		

		if(NULL == izq && NULL == der)
			return raiz;
		else if(NULL == der)
			return (raiz->info < izq->info) ? raiz : izq;
		else if(NULL == izq)
			return (raiz->info < der->info) ? raiz : der;
		else{
			max = raiz;
			if(max->info > der->info)
				max = der;
			else if(max->info > izq->info)
				max = izq;
			return max;
		}
	}
}

int similares(Arbol r1,Arbol r2){
	if(r1 == NULL && r2 == NULL)
		return 1;
	else if((NULL == r1 && NULL!=r2) || (NULL!=r1 && NULL==r2))
		return 0;
	else //if(NULL != r1 && NULL != r2)
		return similares(r1->izq,r2->izq) * similares(r1->der,r2->der);
}

int equivalentes(Arbol r1,Arbol r2){
	if(r1 == NULL && r2 == NULL)
		return 1;
	else if((NULL == r1 && NULL!=r2) || (NULL!=r1 && NULL==r2))
		return 0;
	else{ //if(NULL != r1 && NULL != r2)
		if(r1->info == r2->info)
			return equivalentes(r1->izq,r2->izq) * equivalentes(r1->der,r2->der);
		else
			return 0;
	}
}

Arbol especular(Arbol raiz){
	if(NULL == raiz)
		return NULL;
	else{
		Arbol a = creaNodo(raiz->info);
		a->izq = especular(raiz->der);
		a->der = especular(raiz->izq);
		return a;
	}
}

