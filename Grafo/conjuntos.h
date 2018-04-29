#ifndef __CONJUNTOS_A_H
#define __CONJUNTOS_A_H

#define MAXIMO_CONJ 100

typedef int particion[MAXIMO_CONJ];
typedef int tipoConjunto;
typedef int tipoElemento;

// Funciones a implementar

void crea(particion C);
tipoElemento buscar(tipoElemento x, particion C);
void unir(tipoElemento x, tipoElemento y, particion C);
// Función proporcionada
void verParticion(particion C);
#endif

