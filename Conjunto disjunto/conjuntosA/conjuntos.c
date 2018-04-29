#include "conjuntos.h"
#include <stdio.h>

/// Incluir aqui las funciones que implementan las tres operaciones básicas 
/// en la representación de CONJUNTOS DISJUNTOS mediante ÁRBOLES
/// ......................................................................
void crea(particion C){
#ifdef TAMANNO
	#undef ALTURA
	#undef ARBITRARIO
#endif
#ifdef ALTURA
	#undef TAMANNO
	#undef ARBITRARIO
#endif
#ifdef ARBITRARIO
	#undef TAMANNO
	#undef ALTURA
#endif

	int i;
	
#ifdef TAMANNO
	for(i=0; i<MAXIMO; i++)
		C[i] = -1;
#endif
#ifdef ALTURA
	for(i=0; i<MAXIMO; i++)
		C[i] = -1;
#endif
#ifdef ARBITRARIO
	for(i=0; i<MAXIMO; i++)
		C[i] = i;
#endif
	
}
tipoElemento buscar(tipoElemento x, particion C){
#ifdef TAMANNO
	if(C[x]<0)
		return x;
	else{
		C[x] = buscar(C[x],C);
		return C[x];
	}
#endif
#ifdef ALTURA
	if(C[x]<0)
		return x;
	else{
		C[x] = buscar(C[x],C);
		return C[x];
	}
#endif
#ifdef ARBITRARIO
	if(C[x] == x)
		return x;
	else{
		C[x] = buscar(C[x],C);
		return C[x];
	}
#endif
}


void unir(tipoElemento x, tipoElemento y, particion C){
	x = buscar(x,C);
	y = buscar(y,C);

#ifdef ARBITRARIO
	C[y] = x;
#endif
#ifdef ALTURA
	if(C[x] == C[y]){
		C[x]--;
		C[y] = x;
	}else{
		if(C[x] < C[y])
			C[y] = x;
		else
			C[x] = y;
	}
#endif
#ifdef TAMANNO
	if(C[x] <= C[y]){
		C[x] += C[y];
		C[y] = x;
	}else{
		C[y] += C[x];
		C[x] = y;
	}

#endif
}



//
// Función auxiliar para ver contenido de Partición 
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
