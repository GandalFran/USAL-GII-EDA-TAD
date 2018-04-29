/*
 * grafos.c
 *
 *  Created on: 21/04/2014
 *      Author: MJ Polo
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cola.h"
#include "pila.h"
#include "monticulo.h"
#include "monticuloKruskal.h"
#include "conjuntos.h"
#include "grafos.h"


/*
  typedef struct tagarco
  { int v;
    int peso;
    struct tagarco *sig;
  } arco;

  typedef arco *pArco;

  typedef struct
  { int alcanzado;
    int gradoEntrada;
    int ordenTop;
    int distancia;
    int peso;
    int anterior;
    pArco lista;
  } vertices;

  typedef struct {
	vertices directorio[N];
	int orden;
  }tipoGrafo;
*/


/****************************************************************************************************/
/* Recorrido en PROFUNDIDAD de un grafo. ¡CUIDADO! Depende del vertice inicial y del tipo de grafo */
/***************************************************************************************************/
void profundidad(int v_inicio,tipoGrafo * grafo){
	pArco p;

	printf(" %d", v_inicio);
	grafo->directorio[v_inicio].alcanzado = 1;
	p = grafo->directorio[v_inicio].lista;
	while(NULL != p){
			if(!grafo->directorio[p->v].alcanzado)
				profundidad(p->v,grafo);
			p = p->sig;
	}

}
/************************************************************************************************/
/* Recorrido en AMPLITUD de un grafo. ¡CUIDADO! Depende del vertice inicial y del tipo de grafo */
/************************************************************************************************/
void amplitud(int v_inicio,tipoGrafo *grafo){
	Cola c;
	int v;
	pArco p;

	colaCreaVacia(&c);
	colaInserta(&c,v_inicio);

	while(!colaVacia(&c)){
		v = colaSuprime(&c);
		if(!grafo->directorio[v].alcanzado){
			grafo->directorio[v].alcanzado = 1;
			printf(" %d",v);
			p = grafo->directorio[v].lista;
			while(NULL != p){
				colaInserta(&c,p->v);
				p = p->sig;
			}
		}
	}
}
/**********************************************************************************************/
/* Función auxiliar para ver el contenido de la estructura que representa un grafo en memoria */
/**********************************************************************************************/
void verGrafo(tipoGrafo *g)
{  int i;
   pArco p;

   printf("\nGrafo  (Orden %d)\n\n",g->orden);
   printf("       alc gEnt oTop dist peso ant \n");
   printf("     +----+----+----+----+----+----+\n");

   for(i=1;i<=g->orden;i++)
   {  printf("  %2d | %2d | %2d | %2d |", i, g->directorio[i].alcanzado,
                       g->directorio[i].gradoEntrada, g->directorio[i].ordenTop);
       if (g->directorio[i].distancia == INF) printf("  * |");
       else   printf(" %2d |", g->directorio[i].distancia);
       if (g->directorio[i].peso == INF) printf("  * |");
       else   printf(" %2d |", g->directorio[i].peso);
       printf(" %2d |",g->directorio[i].anterior);
       p = g->directorio[i].lista;
       while (p != NULL)
       {   printf(" ->%2d", p->v);	// Grafos no ponderados
           //printf(" ->%2d, %2d", p->v, p->peso); // Grafos ponderados
           p = p->sig;
       }
       printf("\n");
   }
   printf("     +----+----+----+----+----+----+\n\n");
}
/********************************************************************/
/* Amplitud y profundidad mejoradas para recorrer todos los vertices*/
/********************************************************************/
void profundidadMejorado(int v_inicio,tipoGrafo * grafo){
	int i;

	iniciar(grafo);

	profundidad(v_inicio,grafo);

	for(i=1; i<=grafo->orden; i++){
		if(!grafo->directorio[i].alcanzado)
			profundidad(i,grafo);
	}
}

void amplitudMejorado(int v_inicio,tipoGrafo * grafo){
	int i;

	iniciar(grafo);

	amplitud(v_inicio,grafo);

	for(i=1; i<=grafo->orden; i++){
		if(!grafo->directorio[i].alcanzado)
			amplitud(i,grafo);
	}
}



/* Ejercicio 1*/
void iniciar(tipoGrafo *g){
	int i;
	pArco p;

	for(i=1; i<=g->orden; i++){
		g->directorio[i].alcanzado = 0;
    	g->directorio[i].gradoEntrada = 0;
    	g->directorio[i].ordenTop = 0;
    	g->directorio[i].distancia = INF;
    	g->directorio[i].peso = INF;
    	g->directorio[i].anterior = 0;
	}

	for(i=1; i<=g->orden; i++){
		p = g->directorio[i].lista;
		while(NULL != p){
			g->directorio[p->v].gradoEntrada++;
			p = p->sig;
		}
	}
}

/* Ejercicio 2*/
int ordenTop1(tipoGrafo *grafo){
	int i, j, orden;
	pArco aux;

	iniciar(grafo);

	orden = 1;
	for(i=1; i<=grafo->orden; i++){
		j = 1;
		while(j<=grafo->orden && !(grafo->directorio[j].ordenTop==0 && grafo->directorio[j].gradoEntrada == 0)) j++;
		if(j>grafo->orden) return -1;

		grafo->directorio[j].ordenTop = orden++;
		aux = grafo->directorio[j].lista;
		while(NULL != aux){
			grafo->directorio[aux->v].gradoEntrada--;
			aux = aux->sig;
		}

	}

	return 0;
}
int ordenTop2(tipoGrafo *grafo){
	int i, v, orden;
	pArco p;
	Cola c;

	iniciar(grafo);

	colaCreaVacia(&c);

	for(i=1; i<=grafo->orden; i++){
		if(grafo->directorio[i].gradoEntrada == 0)
			colaInserta(&c,i);
	}

	orden = 1;
	while(!colaVacia(&c)){
		v = colaSuprime(&c);
		grafo->directorio[v].ordenTop = orden++;
		p = grafo->directorio[v].lista;
		while(NULL != p){
			grafo->directorio[p->v].gradoEntrada --;
			if(0 == grafo->directorio[p->v].gradoEntrada){
				colaInserta(&c,p->v);
			}
			p = p->sig;
		}
	}

	return (orden >= grafo->orden)? (0) : (-1);
}




/* Ejercicio 3: Caminos mínimos en grafos dirigidos */
/* a) NO Ponderados */
void caminos1(int vInicio, tipoGrafo *g){
	int v, d;
	pArco p;

	iniciar(g);
	g->directorio[vInicio].distancia = 0;

	for(d=0; d<g->orden-1; d++){
		for(v=1; v<=g->orden; v++){
			if(g->directorio[v].distancia == d && g->directorio[v].alcanzado == 0){
				g->directorio[v].alcanzado = 1;
				p = g->directorio[v].lista;
				while(NULL != p){
					if(g->directorio[p->v].distancia == INF){
						g->directorio[p->v].distancia = d + 1;
						g->directorio[p->v].anterior = v;
					}
					p = p->sig;
				}
			}
		}
	}
}
void caminos2(int vInicio, tipoGrafo *g){
	int v,d;
	Cola c;
	pArco p;

	iniciar(g);
	g->directorio[vInicio].distancia = 0;
	g->directorio[vInicio].anterior = 0;

	colaCreaVacia(&c);
	colaInserta(&c,vInicio);

	while(!colaVacia(&c)){
		v = colaSuprime(&c);
		p = g->directorio[v].lista;
		while(NULL != p){
			if(g->directorio[p->v].distancia == INF){
				g->directorio[p->v].anterior = v;
				g->directorio[p->v].distancia = g->directorio[v].distancia + 1;
				colaInserta(&c,p->v);
			}
			p = p->sig;
		}
	}
	
}

/* b) PONDERADOS */
void dijkstra1(int vInicio, tipoGrafo *g){
	int i,j,v;
	pArco p;

	iniciar(g);
	g->directorio[vInicio].distancia = 0;
	g->directorio[vInicio].anterior = 0;

	for(i=0; i<g->orden; i++){
		v = -1;
		for(j=1;j<=g->orden; j++){
			if((v==-1 ||g->directorio[j].distancia < g->directorio[v].distancia) && g->directorio[j].alcanzado==0)
				v = j;
		}
		if(-1 != v){
			g->directorio[v].alcanzado = 1;
			p = g->directorio[v].lista;
			while(NULL != p){
				if(g->directorio[p->v].alcanzado == 0 && g->directorio[p->v].distancia > (g->directorio[v].distancia + p->peso)){
					g->directorio[p->v].anterior = v;
					g->directorio[p->v].distancia = g->directorio[v].distancia + p->peso;
				}
				p = p->sig;
			}
		}

	}
}
void dijkstra2(int vInicio, tipoGrafo *g){
	int v;
	Monticulo m;
	tipoElementoMonticulo e = {0,0};
	pArco p;
	
	iniciar(g);
	iniciaMonticulo(&m);

	g->directorio[vInicio].distancia = 0;
	g->directorio[vInicio].anterior = 0;

	e.clave = 0;
	e.informacion = vInicio;
	insertar(e,&m);

	while(!vacioMonticulo(m)){
		eliminarMinimo(&m,&e);
		v = e.informacion;

		g->directorio[v].alcanzado = 1;

		p = g->directorio[v].lista;
		while(NULL != p){
			if(g->directorio[p->v].alcanzado == 0 && g->directorio[p->v].distancia > g->directorio[v].distancia + p->peso){
				g->directorio[p->v].anterior = v;
				g->directorio[p->v].distancia = g->directorio[v].distancia + p->peso;
					e.informacion = p->v;
					e.clave = g->directorio[p->v].distancia; 
				insertar(e,&m);
			}
			p = p->sig;
		}
	}
}

/* Interpretación de los algoritmos ¡Secuencia de vértices en caminos mínimos y distancias !!! */
int costeyTrayectoria(int vIni, int vFin, tipoGrafo *g){// Un camino!!
	int v,i,coste;
	Pila p;
	char string[100];
	memset(string,'\0',sizeof(string));

	v = vFin;
	pilaCreaVacia(&p);
	while(v != vIni && v != 0){
		pilaInserta(&p,v);
		v = g->directorio[v].anterior;
	}
	pilaInserta(&p,vIni);

	coste = 0;
	if(v == 0){
		printf("No hay");
		return -1;
	}else{
		i=0;
		while(!pilaVacia(&p)){
			v = pilaSuprime(&p);
			string[i++] = 'v';
			string[i++] = v+'0';
			string[i++] = ',';
			string[i] = ' ';
		}
		string[i] = string[i-1] = '\0';
		coste = g->directorio[vFin].distancia-g->directorio[vIni].distancia;
		printf("%-10s\tCoste:%d",string,coste);
		return coste;
	}
	
} 
void todosCaminosMin(int vIni, tipoGrafo *g){// Todos!!
	int i;

	for(i=1; i<=g->orden; i++){
		printf("\nv%d: ",i);
		costeyTrayectoria(vIni,i,g);
	}
	printf("\n");
}		 



/* Ejercicio 4: Árbol de Expansión en grafos NO dirigidos */
void crearArista(int u, int v, int peso, tipoGrafo*g){
	int i;
	pArco p, nArista;

	nArista = calloc(1,sizeof(arco));			
	nArista->peso = peso;
	nArista->v = v;
	if(NULL == g->directorio[u].lista)
			g->directorio[u].lista = nArista;	
	else{
		p = g->directorio[u].lista;
		while(p->sig != NULL)	p = p->sig;
		p->sig = nArista;
	}

	nArista = calloc(1,sizeof(arco));			
	nArista->peso = peso;
	nArista->v = u;
	if(NULL == g->directorio[v].lista)
			g->directorio[v].lista = nArista;	
	else{
		p = g->directorio[v].lista;
		while(p->sig != NULL)	p = p->sig;
		p->sig = nArista;
	}

}

/* a) Prim  ¡ Algoritmo e interpretación del resultado!!! */
tipoGrafo*creaInterpretacionGrafo(tipoGrafo*grafo){
	int i;
	pArco p, nArista;

	tipoGrafo* g = calloc(1,sizeof(tipoGrafo));
	g->orden = grafo->orden;	
	iniciar(g);

	for(i=1; i<=grafo->orden; i++){
		if(0 != grafo->directorio[i].anterior){
			crearArista(i, grafo->directorio[i].anterior, grafo->directorio[i].peso, g);
		}
	}

	return g;
}
tipoGrafo * prim1(tipoGrafo *grafo){
	int i,j,v;
	pArco p;

	iniciar(grafo);
	grafo->directorio[1].peso = 0;
	grafo->directorio[1].anterior = 0;

	for(i=0; i<grafo->orden; i++){
		v = -1;
		for(j=1;j<=grafo->orden; j++){
			if((v==-1 || grafo->directorio[j].peso < grafo->directorio[v].peso) && grafo->directorio[j].alcanzado==0)
				v = j;
		}
		grafo->directorio[v].alcanzado = 1;
		p = grafo->directorio[v].lista;
		while(NULL != p){
			if(grafo->directorio[p->v].alcanzado == 0 && grafo->directorio[p->v].peso > p->peso){
				grafo->directorio[p->v].anterior = v;
				grafo->directorio[p->v].peso = p->peso;
			}
			p = p->sig;
		}
	}

	return creaInterpretacionGrafo(grafo);
}
tipoGrafo * prim2(tipoGrafo *grafo){
	int v;
	Monticulo m;
	tipoElementoMonticulo e;
	pArco p;
	
	iniciar(grafo);
	iniciaMonticulo(&m);

	grafo->directorio[1].peso = 0;
	grafo->directorio[1].anterior = 0;

	e.clave = 0;
	e.informacion = 1;
	insertar(e,&m);

	while(!vacioMonticulo(m)){
		eliminarMinimo(&m,&e);
		v = e.informacion;

		grafo->directorio[v].alcanzado = 1;

		p = grafo->directorio[v].lista;
		while(NULL != p){
			if(grafo->directorio[p->v].alcanzado == 0 && grafo->directorio[p->v].peso > p->peso){
				grafo->directorio[p->v].anterior = v;
				grafo->directorio[p->v].peso = p->peso;
					e.informacion = p->v;
					e.clave = p->peso;
				insertar(e,&m);
			}
			p = p->sig;
		}
	}

	return creaInterpretacionGrafo(grafo);
}

/* c) Kruskal*/
tipoGrafo * kruskal(tipoGrafo *grafo){
	int i,j,numAristas;
	pArco p;
	particion C;
	MonticuloKruskal m;
	tipoInfoKruskal arista;
	tipoElementoMonticuloKruskal e;

	tipoGrafo* g = calloc(1,sizeof(tipoGrafo));
	g->orden = grafo->orden;	
	iniciar(g);

	j = 0;
	for(i=1; i<=grafo->orden; i++){
		p = grafo->directorio[i].lista;
		while(NULL != p){
			arista.u = i;
			arista.v = p->v;
			e.informacion = arista;
			e.clave = p->peso;
			m.elemento[++j] = e;
			p = p->sig;
		}
	}
	m.tamanno = j;
	crearMonticuloKruskal(&m);
	crea(C);

	numAristas = 0;
	while(numAristas < grafo->orden-1){
		eliminarMinimoKruskal(&m,&e);
		arista = e.informacion;

		i = buscar(arista.u,C);
		j = buscar(arista.v,C);

		if(i != j){
			numAristas++;
			unir(i,j,C);
			crearArista(arista.u,arista.v,e.clave,g);
		}
	}

	return g;
}





























