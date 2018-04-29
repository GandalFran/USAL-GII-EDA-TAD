#include <stdlib.h>
#include <stdio.h>
#include "monticulo.h"


int main(void){
 
  Monticulo m;
  int i,n=10;
  tipoElemento elemento;

 iniciaMonticulo(&m);

 printf("\n");
 m.tamanno=n;
 for (i=1;i<=n;i++) printf("%d ", m.elemento[i].clave=rand()%100);

 heapsort(&m);
 printf("\n");
 for (i=1;i<=m.tamanno;i++)
   printf("%d ",m.elemento[i].clave);
 printf("\n");

 return 0;
}




