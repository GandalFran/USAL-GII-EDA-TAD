#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbolBB.h"


#ifdef EJERCICIO1
/******************************************************************
* Árboles Binarios de Búsqueda SIN CLAVES REPETIDAS
* Se incluye un poco de código para mostrar la diferencia entre   *
* insertar (paso por referencia) y buscar                         * 
*******************************************************************/

int insertar(tipoArbolBB *raiz,tipoClave clave){
  if(NULL == (*raiz)){
  	*raiz = creaNodo(clave,1);
  	return 0;
  }else if((*raiz)->clave == clave){
  	(*raiz)->info += 1;
  	return 0;
  }else if((*raiz)->clave > clave){
  	return insertar(&(*raiz)->izq,clave);
  }else{
  	return insertar(&(*raiz)->der,clave);
  }
}

int buscar(tipoClave clave,tipoArbolBB raiz, tipoNodo **nodo){
  if(NULL == raiz){
  	*nodo = NULL;
  	return 0;
  }else if(raiz->clave == clave){
  	*nodo = raiz;
  	return 1;
  }else if(raiz->clave > clave){
  	return buscar(clave,raiz->izq,nodo);
  }else{
  	return buscar(clave,raiz->der,nodo);
  }
}

int eliminar(tipoArbolBB *raiz, tipoClave clave){
  tipoNodo*aBorrar;
  int nNodos;
  if(NULL == (*raiz)){
  	return -1;
  }else if((*raiz)->clave > clave){
  	return eliminar(&(*raiz)->izq,clave);
  }else if((*raiz)->clave < clave){
  	return eliminar(&(*raiz)->der,clave);
  }else{
	nNodos = (*raiz)->info;
  	if((*raiz)->izq == NULL && (*raiz)->der == NULL){
  		free(*raiz);
  		*raiz = NULL;
  	}else if((*raiz)->izq == NULL){
  		aBorrar = *raiz;
  		(*raiz) = (*raiz)->der;
  		free(aBorrar);
  	}else if((*raiz)->der == NULL){
  		aBorrar = *raiz;
  		(*raiz) = (*raiz)->izq;
  		free(aBorrar);
  	}else{
  		tipoNodo*aux,*ant;

  		ant = (*raiz);
  		aux = ant->izq;
  		while(NULL != aux->der){
  			ant = aux;
  			aux = aux->der;
  		}

  		(*raiz)->clave = aux->clave;
  		(*raiz)->info = aux->info;

  		if(*raiz == ant){
  			ant->izq = aux->izq;
  		}else{
  			ant->der = aux->izq;
  		}

  		free(aux);
  	}
  	return nNodos;
  }
}

#endif

#ifdef EJERCICIO2

int insertar(tipoArbolBB *raiz,tipoClave clave){
  if(NULL == (*raiz)){
  	*raiz = creaNodo(clave,1);
  	return 0;
  }else if(0 == strcmp((*raiz)->clave,clave)){
  	(*raiz)->info += 1;
  	return 0;
  }else if(0 > strcmp(clave,(*raiz)->clave)){
  	return insertar(&(*raiz)->izq,clave);
  }else{
  	return insertar(&(*raiz)->der,clave);
  }
}

int buscar(tipoClave clave,tipoArbolBB raiz, tipoNodo **nodo){
  if(NULL == raiz){
  	*nodo = NULL;
  	return 0;
  }else if(0 == strcmp(raiz->clave,clave)){
  	*nodo = raiz;
  	return 1;
  }else if(0 > strcmp(clave,raiz->clave)){
  	return buscar(clave,raiz->izq,nodo);
  }else{
  	return buscar(clave,raiz->der,nodo);
  }
}

#endif

#ifdef EJERCICIO3
/******************************************************
* Árboles Binarios de Búsqueda CON CLAVES REPETIDAS   *
******************************************************/
int insertar(tipoArbolBB *raiz,tipoClave clave, tipoInfo info){ 
	tipoNodo*nuevo,*aux;
  if(NULL == (*raiz)){
  	*raiz = creaNodo(clave,info);
  	return -1;
  }else if((*raiz)->clave == clave){
	nuevo = creaNodo(clave,info);
   	if(NULL != (*raiz)->izq){
   		nuevo->izq = (*raiz)->izq;
   	}
   	(*raiz)->izq = nuevo;
  	return 0;
  }else if((*raiz)->clave > clave){
  	return insertar(&(*raiz)->izq,clave,info);
  }else{
  	return insertar(&(*raiz)->der,clave,info);
  }
}

int eliminar(tipoArbolBB *raiz, tipoClave clave){
 tipoNodo*aBorrar;
  if(NULL == (*raiz)){
  	return 0;
  }else if((*raiz)->clave > clave){
  	return eliminar(&(*raiz)->izq,clave);
  }else if((*raiz)->clave < clave){
  	return eliminar(&(*raiz)->der,clave);
  }else{
  	if((*raiz)->izq == NULL && (*raiz)->der == NULL){
  		free(*raiz);
  		*raiz = NULL;
  		return 1;
  	}else if((*raiz)->izq == NULL){
  		aBorrar = *raiz;
  		(*raiz) = (*raiz)->der;
  		free(aBorrar);
  		return 1;
  	}else if((*raiz)->der == NULL){
  		aBorrar = *raiz;
  		(*raiz) = (*raiz)->izq;
  		free(aBorrar);
  		if((*raiz)->clave == clave)
  			return 1 + eliminar(raiz,clave);
		else
			return 1;
  	}else{
  		tipoNodo*aux,*ant;

  		ant = (*raiz);
  		aux = ant->izq;
  		while(NULL != aux->der){
  			ant = aux;
  			aux = aux->der;
  		}

  		(*raiz)->clave = aux->clave;
  		strcpy((*raiz)->info,aux->info);

  		if(*raiz == ant){
  			ant->izq = aux->izq;
  		}else{
  			ant->der = aux->izq;
  		}

  		free(aux);

		if(NULL != (*raiz)->izq && (*raiz)->izq->clave == clave)
  			return 2 + eliminar(&(*raiz)->izq,clave);
  		else
  			return 1;
  	}
  }
}

#endif
/*****************************************************************************************
* Funciones GENERALES adaptadas a los dos ejercicios mediante DIRECTIVAS DE COMPILACIÓN  *
/*****************************************************************************************/

tipoNodo *creaNodo(tipoClave clave, tipoInfo info)
{ tipoNodo * nuevo;
  
  //   nuevo =(tipoNodo *)calloc(1, sizeof(tipoNodo));
  if ((nuevo =(tipoNodo *)malloc(sizeof(tipoNodo)))==NULL)
	return NULL;
  else 
  {	
  	#ifdef EJERCICIO1
  	nuevo->clave = clave;
	nuevo->info=info;
  	#endif
  	#ifdef EJERCICIO2
	nuevo->info=info;
	strcpy(nuevo->clave,clave);
  	#endif
  	#ifdef EJERCICIO3
  	nuevo->clave = clave;
	strcpy(nuevo->info,info);
  	#endif
  	nuevo->izq=NULL;
  	nuevo->der=NULL;
  return nuevo;
  }
}

void preOrden(tipoArbolBB a)
{ if (a) { 
  	#ifdef EJERCICIO1
	printf("%d %d \n", a->clave,a->info);
	#endif
  	#ifdef EJERCICIO2
	printf("%s %d \n", a->clave,a->info);
	#endif
  	#ifdef EJERCICIO3
	printf("%d %s \n", a->clave,a->info);
  	#endif
  	preOrden(a->izq);
  	preOrden(a->der);
  }
} 

void enOrden(tipoArbolBB a)
{ if (a) { 
	enOrden(a->izq);
  	#ifdef EJERCICIO1
	printf("%d %d \n", a->clave,a->info);
	#endif
  	#ifdef EJERCICIO2
	printf("%s %d \n", a->clave,a->info);
	#endif
  	#ifdef EJERCICIO3
	printf("%d %s \n", a->clave,a->info);
  	#endif
    	enOrden(a->der);
  }
} 

void posOrden(tipoArbolBB a)
{ if (a) {
  	posOrden(a->izq);
  	posOrden(a->der);
  	#ifdef EJERCICIO1
	printf("%d %d \n", a->clave,a->info);
	#endif
  	#ifdef EJERCICIO2
	printf("%s %d \n", a->clave,a->info);
	#endif
  	#ifdef EJERCICIO3
	printf("%d %s \n", a->clave,a->info);
  	#endif
  }
} 

