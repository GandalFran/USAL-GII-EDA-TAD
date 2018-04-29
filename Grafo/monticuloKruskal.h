

#include "grafos.h"

#define MAXK 100

typedef int tipoClave ;
typedef struct {int u, v;} tipoInfoKruskal;

typedef struct
{ tipoClave clave;
   tipoInfoKruskal  informacion;
} tipoElementoMonticuloKruskal;

typedef struct
{ tipoElementoMonticuloKruskal elemento[MAXK];
    int tamanno;
} MonticuloKruskal;


/* Ejercicio 1 */

void iniciaMonticuloKruskal(MonticuloKruskal *m);
int vacioMonticuloKruskal(MonticuloKruskal m);
int insertarKruskal(tipoElementoMonticuloKruskal x, MonticuloKruskal *m);
int eliminarMinimoKruskal(MonticuloKruskal *m, tipoElementoMonticuloKruskal *minimo);
void decrementarClaveKruskal(int pos, int cantidad, MonticuloKruskal *m);
void incrementarClaveKruskal(int pos, int cantidad, MonticuloKruskal *m);
int esMonticuloKruskal(MonticuloKruskal m);

/* Funciones auxiliares que conviene implementar: las dos estrategias de filtrado en las 
   que se basan todos los algoritmos que manejan montículos */

  void filtradoDescendenteKruskal(MonticuloKruskal *m, int i);
  void filtradoAscendenteKruskal(MonticuloKruskal *m, int i);

/* Operación crearMonticuloKruskal la utilizaremos en ejercicio 2 y en tema de grafos */ 

  void crearMonticuloKruskal(MonticuloKruskal *m);

  void heapsortKruskal(MonticuloKruskal *m);


