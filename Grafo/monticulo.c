#include <stdio.h>
#include <stdlib.h>
#include "monticulo.h"

/*
typedef int tipoClave ;
typedef int tipoInfo ;
º
typedef struct
{ tipoClave clave;
   tipoInfo  informacion;
} tipoElementoMonticulo;

typedef struct
{ tipoElementoMonticulo elemento[MAXIMO];
    int tamanno;
} Monticulo;
*/

/* Ejercicio 1 */

void iniciaMonticulo(Monticulo *m){
	m->tamanno = 0;
}

int vacioMonticulo(Monticulo m){
	return (m.tamanno == 0);
}

int insertar(tipoElementoMonticulo x, Monticulo *m){
	if(m->tamanno >= MAXIMO) return -1;

	m->tamanno++;
	m->elemento[m->tamanno] = x;
	filtradoAscendente(m,m->tamanno);

	return 0;
}

int eliminarMinimo(Monticulo *m, tipoElementoMonticulo *minimo){
	if(m->tamanno <= 0) return -1;

    m->tamanno--;
	*minimo = m->elemento[1];
	m->elemento[1] = m->elemento[m->tamanno];
	
	filtradoDescendente(m,1);

	return 0;
}

void decrementarClave(int pos, int cantidad, Monticulo *m){
	if(pos <= 0 || pos > m->tamanno) return;

	m->elemento[pos].clave -= cantidad;
	filtradoAscendente(m,pos);
}

void incrementarClave(int pos, int cantidad, Monticulo *m){
	if(pos <= 0 || pos > m->tamanno) return;

	m->elemento[pos].clave += cantidad;
	filtradoDescendente(m,pos);
}

int esMonticulo(Monticulo m){
	int i;

	for(i=m.tamanno; i>1; i--){
		if(m.elemento[i/2].clave > m.elemento[i].clave)
			return 0;
	}

	return 1;
}


/* Funciones auxiliares que conviene implementar: las dos estrategias de filtrado en las 
   que se basan todos los algoritmos que manejan montículos */

  void filtradoDescendente(Monticulo *m, int i){
  	int hijo, finFiltrado;
  	tipoElementoMonticulo e = m->elemento[i];

  	
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

  void filtradoAscendente(Monticulo *m, int i){
  	tipoElementoMonticulo e = m->elemento[i];

   	while(i>1 && e.clave < m->elemento[i/2].clave){
  		m->elemento[i] = m->elemento[i/2];
  		i/=2;
  	}

  	m->elemento[i] = e;
  }


/* Operación crearMonticulo la utilizaremos en ejercicio 2 y en tema de grafos */ 

  void crearMonticulo(Monticulo *m){
  	int i;

  	for(i=m->tamanno/2;i>=1; i--)
  		filtradoDescendente(m,i);
  }


  void heapsort(Monticulo *m){
  	int tam, i;
  	tipoElementoMonticulo e;

  	tam = m->tamanno;

  	crearMonticulo(m);

  
  	for(i=1; i<=tam; i++){
  		eliminarMinimo(m, &e);
  		m->elemento[m->tamanno+1] = e; 
  	}

  	m->tamanno = tam;
  }


