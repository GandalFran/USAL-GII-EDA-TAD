#include <stdio.h>
#include <string.h>
#include "arbol.h"
#include "genArbol.h"

int evalua(Arbol a);

int main(void)
{ Arbol arbol; 
  char ex_postfija[10];

/* Generación del árbol algebraico */
  strcpy(ex_postfija,"AB+CDE+**\0");

  arbol = genArbol(ex_postfija);

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
  printf("Debe coinicidir con la expresión postfija inicial\n");

  printf("El árbol tiene %d nodos \n", numNodos(arbol));
  printf("y altura: %d\n",altura(arbol));

  printf("El árbol tiene %d nodos\n", numNodos(arbol));
  arbol = anula(arbol);
  printf("Después de anula el arbol queda vacio, por tanto la altura será 0.\n");
  if (altura(arbol)!=-1)		// Cuidado con definición de altura
     printf("El árbol no se ha anulado correctamente\n");
  else
     printf("O.K. Parece que la operación anula funciona!!!\n");


/* Evaluación de un árbol algebraico: operandos entre '0' y '9'*/

  strcpy(ex_postfija,"23+713+**\0");
  arbol = genArbol(ex_postfija);
  printf("evalua: %d\n", evalua(arbol));
  printf("Recorrido en PRE_ORDEN (prefija): ");
  preOrden(arbol);
  printf("\n");
  printf("Recorrido en ORDEN(infija): ");
  enOrden(arbol);
  printf("\n");
  printf("Recorrido en POST_ORDEN(postfija): ");
  postOrden(arbol);
  printf("\n");

/* Aplicar a este arbol las funciones del ejercicio 2 */

  return 1;
}

int evalua(Arbol a){
	if(NULL != a){
		if(a->info>='0' && a->info<='9')
			return (a->info - '0');
		else{
			switch(a->info){
				case '+': return evalua(a->izq) + evalua(a->der); break;
				case '-': return evalua(a->izq) - evalua(a->der); break;
				case '*': return evalua(a->izq) * evalua(a->der); break;
				case '/': return evalua(a->izq) / evalua(a->der); break;
				case '%': return evalua(a->izq) % evalua(a->der); break;
			}
		}
	}
}