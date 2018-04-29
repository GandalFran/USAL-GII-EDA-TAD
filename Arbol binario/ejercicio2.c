#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"
#include "genArbol.h"

int main(void){
	Arbol a=NULL, b=NULL;


	a = genArbol("AB+CDE+**\0");
	b = genArbol("AB+CDE+**\0");

	printf("\n");
	printf("\nPreOrden:  ");
	preOrden(a);
	printf("\nEnOrden:   ");
	enOrden(a);
	printf("\nPostOrden: ");
	postOrden(a);
	printf("\nAmplitud:  ");
	amplitud(a);


	printf("\n");
	printf("\nAltura:           %d",altura(a));
	printf("\nnumNodos:         %d",numNodos(a));
	printf("\nnumNodosHoja:     %d",numNodosHoja(a));
	printf("\nnumNodosInternos: %d",numNodosInternos(a));
	printf("\nnumHijoUnico:     %d",numHijoUnico(a));

	printf("\n");
	printf("\nbuscarMax: %c",buscarMax(a)->info);
	printf("\nbuscarMin: %c",buscarMin(a)->info);

	printf("\n");
	printf("\nsustituye: A --> Z: %d",sustituye(a,'A','Z'));
	printf("\n\t");
	preOrden(a);
	
	printf("\n");
	printf("\na y b similares:    (SI) %d",similares(a,b));
	printf("\na y NULL similares: (NO) %d",similares(a,NULL));
	printf("\na y a equivalentes: (SI) %d",equivalentes(a,a));
	printf("\na y b equivalentes: (NO) %d",equivalentes(a,b));
	anula(b);
	printf("\nb anulado");
	b = especular(a);
	printf("\nEspecular de a: ");
	printf("\n\ta:	\n\t\tpreOrden: ");
	preOrden(a);
	printf("\n\t\tenOrden:  ");	
	enOrden(a);
	printf("\n\tespecular:	\n\t\tpreOrden: ");
	preOrden(b);
	printf("\n\t\tenOrden:  ");	
	enOrden(b);


	printf("\n");
	anula(a);
	printf("\nA anulado");
	anula(b);
	printf("\nB anulado");
	printf("\n");

	return 0;
}
