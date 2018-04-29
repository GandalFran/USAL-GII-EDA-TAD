#include "conjuntos.h"
#include <stdio.h>

/// Incluir aqui las funciones que implementan las tres operaciones básicas 
/// en la representación de CONJUNTOS DISJUNTOS mediante ÁRBOLES
/// ......................................................................
void crea(particion C){
	int i;
	
	for(i=0; i<MAXIMO_CONJ; i++)
		C[i] = -1;
	C[i] = i;
}
tipoElemento buscar(tipoElemento x, particion C){
	if(C[x]<0)
		return x;
	else{
		C[x] = buscar(C[x],C);
		return C[x];
	}
}


void unir(tipoElemento x, tipoElemento y, particion C){
	x = buscar(x,C);
	y = buscar(y,C);

	if(C[x] == C[y]){
		C[x]--;
		C[y] = x;
	}else{
		if(C[x] < C[y])
			C[y] = x;
		else
			C[x] = y;
	}
}



//
// Función auxiliar para ver contenido de Partición 
//
void verParticion(particion C)
{ int i;
    printf("\n");
    for (i =0;i<MAXIMO_CONJ;i++) printf("|%2d",C[i]);
    printf("| contenido  vector\n");
    for (i =0;i<MAXIMO_CONJ;i++) printf("---");
    printf("\n");
    for (i =0;i<MAXIMO_CONJ;i++) printf(" %2d",i);
    printf("  índices vector\n\n");
}
