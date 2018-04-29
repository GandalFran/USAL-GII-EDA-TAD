# Sesión 7 :

ejercicio1: ejercicio1.c grafos.h grafos.o cola.o
	gcc -g ejercicio1.c grafos.o cola.o -o ejercicio1
ejercicio1y2: ejercicio1y2.c grafos.h grafos.o cola.o
	gcc -g ejercicio1y2.c grafos.o cola.o -o ejercicio1y2
ejercicio3: ejercicio3.c grafos.h grafos.o cola.o monticulo.o pila.o
	gcc -g ejercicio3.c grafos.o cola.o pila.o monticulo.o -o ejercicio3
ejercicio4: ejercicio4.c grafos.h grafos.o cola.o monticulo.o conjuntos.o monticuloKruskal.o
	gcc -g ejercicio4.c grafos.o cola.o pila.o monticulo.o conjuntos.o monticuloKruskal.o -o ejercicio4

grafos.o: grafos.c grafos.h
	gcc -g -c grafos.c -o grafos.o
cola.o: cola.c cola.h
	gcc -g -c cola.c
pila.o: pila.c pila.h
	gcc -g -c pila.c
monticulo.o: monticulo.c monticulo.h
	gcc -g -c monticulo.c
conjuntos.o: conjuntos.c conjuntos.h
	gcc -g -c conjuntos.c
monticuloKruskal.o: monticuloKruskal.c monticuloKruskal.h
	gcc -g -c monticuloKruskal.c