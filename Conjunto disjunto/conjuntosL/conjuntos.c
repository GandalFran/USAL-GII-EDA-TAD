#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conjuntos.h"


tipoCelda*creaNodo(tipoElemento x){
    tipoCelda*n;

    if(NULL == (n = malloc(sizeof(tipoCelda))))
        return NULL;

    n->elemento = x;
    n->sig = NULL;

    return n;
}   


tipoCelda* localiza(tipoElemento x, tipoLista l){ 
    tipoCelda* p;
    
    p = l.primero;
    while(p != NULL && p->elemento!=x) p = p->sig;

    return p;
}

/// Incluir aqui las funciones que implementan las tres operaciones básicas 
/// en la representación de CONJUNTOS DISJUNTOS mediante LISTAS
/// ......................................................................

void crea(particion C){
	int i;
	for(i=0; i<MAXIMO; i++)
		C[i].primero = C[i].ultimo = creaNodo(i);

}
tipoElemento buscar(tipoElemento x, particion C){
	int i;
	
	for(i=0; i<MAXIMO; i++){
		if(NULL != localiza(x,C[i]))
			return i;
	}
	return -1;
}
void unir(tipoElemento x, tipoElemento y, particion C){
	x = buscar(x,C);
	y = buscar(y,C);

	if(x<0 || x>=MAXIMO || y<0 || y>=MAXIMO) return;
	
	C[x].ultimo->sig = C[y].primero;
	C[x].ultimo = C[y].ultimo;
	C[y].primero = C[y].ultimo = NULL;
}



//
// Funciones auxiliares para ver contenido de Partición y Clase de Equivalencia
//


void verParticion(particion C)
{ int i;
   tipoCelda *aux;
    for (i =0;i<MAXIMO;i++) {
         aux = C[i].primero;
         if (aux!=NULL)  printf("\n\nClase equivalencia representante %d: ",i);
        while (aux!=NULL)
        { printf("%d ",aux->elemento);
         aux=aux->sig;
        }
    }
}

void verClaseEquivalencia(tipoElemento x,particion C)
{ int representante;
  tipoCelda *aux;
  
    representante = buscar(x,C);
    printf("\n\nClase de Equivalencia de %d cuyo representante es %d: ", x,representante);
    aux = C[representante].primero;
    while (aux)
        { printf(" %d ",aux->elemento);
          aux=aux->sig;
        }
    printf("\n\n");
}




