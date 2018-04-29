#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbol.h"
#include "pila.h"
#include "cola.h"

#define TAM 20

Arbol generarConExpresiones(char*preOrdena,int bp, int tp, char*orden, int bo, int to);

int main(void){
  Arbol arbol; 
  char preOrdena[TAM], orden[TAM];

/* Generación del árbol algebraico */
  strcpy(preOrdena,"ESTRUCTURAS\0");
  strcpy(orden,"RTUSECUTARS\0");

  arbol = generarConExpresiones(preOrdena,0,strlen(preOrdena)-1,orden,0,strlen(orden)-1);

/* Recorrido en amplitud o por niveles */
   amplitud(arbol);

/* Aplicación de algunas operaciones y recorridos al árbol ejemplo */

  printf("Recorrido en PRE_ORDEN: ");
  preOrden(arbol);
  printf("\n");
  printf("Recorrido en ORDEN: ");
  enOrden(arbol);
  printf("\n");
  printf("Recorrido en POST_ORDEN: ");
  postOrden(arbol);
  printf("\n");


  printf("El árbol tiene %d nodos \n", numNodos(arbol));
  printf("y altura: %d\n",altura(arbol));

  printf("El árbol tiene %d nodos\n", numNodos(arbol));
  arbol = anula(arbol);
  printf("Después de anula el arbol queda vacio, por tanto la altura será 0.\n");
  if (altura(arbol)!=-1)		// Cuidado con definición de altura
     printf("El árbol no se ha anulado correctamente\n");
  else
     printf("O.K. Parece que la operación anula funciona!!!\n");

  return 1;
}


Arbol generarConExpresiones(char*preOrdena,int bp, int tp, char*orden, int bo, int to){
	if(bp<=tp){
		Arbol a;
		int i;
		int posRaizOr, numElementosIzda, divisionPre;
		char raiz;

		raiz = preOrdena[bp];

		i=bo;
		while(orden[i]!=raiz) i++;
		
		posRaizOr = i;
		numElementosIzda = posRaizOr-bo;
		divisionPre = bp + numElementosIzda;

		a = creaNodo(raiz);
		a->izq = generarConExpresiones(preOrdena,bp+1,divisionPre,orden,bo,posRaizOr-1);
		a->der = generarConExpresiones(preOrdena,divisionPre+1,tp,orden,posRaizOr+1,to);

		return a;	
	}else
		return NULL;
}