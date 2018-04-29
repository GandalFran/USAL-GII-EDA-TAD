#ifndef __ARBOLBB_H
#define __ARBOLBB_H 


	#ifdef EJERCICIO1
		typedef int tipoClave;
	#endif
	#ifdef EJERCICIO2
		typedef char tipoClave[20];
	#endif
	#ifdef EJERCICIO3
		typedef int tipoClave;
	#endif
	#ifdef EJERCICIO1
		typedef int tipoInfo;
	#endif
	#ifdef EJERCICIO2
		typedef int tipoInfo;
	#endif
	#ifdef EJERCICIO3
		typedef char tipoInfo[20];
	#endif

	typedef struct tipoNodo {
	        tipoClave clave;
	        tipoInfo info;
	        struct tipoNodo *izq,*der;
	} tipoNodo;

	typedef tipoNodo *tipoArbolBB;

	// Funciones proporcionadas en arbolBB.c

	tipoNodo *creaNodo(tipoClave clave,tipoInfo info);
	void enOrden(tipoArbolBB raiz);
	void preOrden(tipoArbolBB raiz);
	void posOrden(tipoArbolBB raiz);

	// Funciones a implementar por el alumno
	#ifdef EJERCICIO1
		int insertar(tipoArbolBB *raiz, tipoClave clave);
		int buscar(tipoClave clave,tipoArbolBB raiz, tipoNodo **nodo);
		int eliminar(tipoArbolBB *raiz, tipoClave clave);
	#endif
	#ifdef EJERCICIO2
		int insertar(tipoArbolBB *raiz, tipoClave clave);
		int buscar(tipoClave clave,tipoArbolBB raiz, tipoNodo **nodo);
	#endif
	#ifdef EJERCICIO3
		int insertar(tipoArbolBB *raiz,tipoClave clave, tipoInfo info);
		int eliminar(tipoArbolBB *raiz, tipoClave clave);
	#endif

#endif

