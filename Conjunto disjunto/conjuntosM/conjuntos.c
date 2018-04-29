#include "conjuntos.h"
#include <stdio.h>

/// Incluir aqui las funciones que implementan las tres operaciones básicas 
/// en la representación de CONJUNTOS DISJUNTOS mediante MATRICES
/// ......................................................................
void crea(particion C){
	int i;
	for(i=0; i<MAXIMO; i++)
		C[i] = i;
}
tipoElemento buscar(tipoElemento x, particion C){
	return  (x>=0 && x<MAXIMO)? C[x]: -1;
}
void unir(tipoElemento x, tipoElemento y, particion C){
	int i;

	x = buscar(x,C);
	y = buscar(y,C);

	for(i=0; i<MAXIMO; i++){
		if(C[i] == y)
			C[i] = x;
	}
}




//
// Funciones auxiliares para ver contenido de Partición y Clase de Equivalencia
//
void verParticion(particion C)
{ int i;
    printf("\n");
    for (i =0;i<MAXIMO;i++) printf("|%2d",C[i]);
    printf("| contenido  vector\n");
    for (i =0;i<MAXIMO;i++) printf("---");
    printf("\n");
    for (i =0;i<MAXIMO;i++) printf(" %2d",i);
    printf("  índices vector\n\n");
}

void verClaseEquivalencia(tipoElemento x,particion C)
{ int representante,i;
  representante = buscar(x,C);
  printf("\n\nClase de Equivalencia de %d cuyo representante es %d: ", x,representante);
  for (i=0;i<MAXIMO;i++) if (C[i]==representante) printf("%d ",i);
  printf("\n");

}
