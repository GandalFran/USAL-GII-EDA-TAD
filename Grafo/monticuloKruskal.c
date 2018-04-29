#include <stdio.h>
#include <stdlib.h>
#include "monticuloKruskal.h"

/*
typedef int tipoClave ;
typedef int tipoInfoKruskal ;
º
typedef struct
{ tipoClave clave;
   tipoInfoKruskal  informacion;
} tipoElementoMonticuloKruskal;

typedef struct
{ tipoElementoMonticuloKruskal elemento[MAXK];
    int tamanno;
} MonticuloKruskal;
*/

/* Ejercicio 1 */

void iniciaMonticuloKruskal(MonticuloKruskal *m){
	m->tamanno = 0;
}

int vacioMonticuloKruskal(MonticuloKruskal m){
	return (m.tamanno == 0);
}

int insertarKruskal(tipoElementoMonticuloKruskal x, MonticuloKruskal *m){
	if(m->tamanno >= MAXK) return -1;

	m->tamanno++;
	m->elemento[m->tamanno] = x;
	filtradoAscendenteKruskal(m,m->tamanno);

	return 0;
}

int eliminarMinimoKruskal(MonticuloKruskal *m, tipoElementoMonticuloKruskal *minimo){
	if(m->tamanno <= 0) return -1;

    m->tamanno--;
	*minimo = m->elemento[1];
	m->elemento[1] = m->elemento[m->tamanno];
	
	filtradoDescendenteKruskal(m,1);

	return 0;
}

void decrementarClaveKruskal(int pos, int cantidad, MonticuloKruskal *m){
	if(pos <= 0 || pos > m->tamanno) return;

	m->elemento[pos].clave -= cantidad;
	filtradoAscendenteKruskal(m,pos);
}

void incrementarClaveKruskal(int pos, int cantidad, MonticuloKruskal *m){
	if(pos <= 0 || pos > m->tamanno) return;

	m->elemento[pos].clave += cantidad;
	filtradoDescendenteKruskal(m,pos);
}

int esMonticuloKruskal(MonticuloKruskal m){
	int i;

	for(i=m.tamanno; i>1; i--){
		if(m.elemento[i/2].clave > m.elemento[i].clave)
			return 0;
	}

	return 1;
}


/* Funciones auxiliares que conviene implementar: las dos estrategias de filtrado en las 
   que se basan todos los algoritmos que manejan montículos */

  void filtradoDescendenteKruskal(MonticuloKruskal *m, int i){
  	int hijo, finFiltrado;
  	tipoElementoMonticuloKruskal e = m->elemento[i];

  	
  	finFiltrado = 0;
  	while(2*i <= m->tamanno && !finFiltrado){
  		hijo = 2*i;
  		if(hijo+1 <=m->tamanno && m->elemento[hijo+1].clave<m->elemento[hijo].clave)
  			hijo++;

  		if(e.clave > m->elemento[hijo].clave){
  			m->elemento[i] = m->elemento[hijo];
  			i = hijo;
  		}else
  			finFiltrado = 1;
  	}

  	m->elemento[i] = e;
  }

  void filtradoAscendenteKruskal(MonticuloKruskal *m, int i){
  	tipoElementoMonticuloKruskal e = m->elemento[i];

   	while(i>1 && e.clave < m->elemento[i/2].clave){
  		m->elemento[i] = m->elemento[i/2];
  		i/=2;
  	}

  	m->elemento[i] = e;
  }


/* Operación crearMonticuloKruskal la utilizaremos en ejercicio 2 y en tema de grafos */ 

  void crearMonticuloKruskal(MonticuloKruskal *m){
  	int i;

  	for(i=m->tamanno/2;i>=1; i--)
  		filtradoDescendenteKruskal(m,i);
  }


  void heapsortKruskal(MonticuloKruskal *m){
  	int tam, i;
  	tipoElementoMonticuloKruskal e;

  	tam = m->tamanno;

  	crearMonticuloKruskal(m);

  
  	for(i=1; i<=tam; i++){
  		eliminarMinimoKruskal(m, &e);
  		m->elemento[m->tamanno+1] = e; 
  	}

  	m->tamanno = tam;
  }


