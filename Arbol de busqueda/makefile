# Sesión 10. Semana 2 de Mayo
pruebaEj1: pruebaEj1.c arbolBB1.o
	gcc -g -DEJERCICIO1 pruebaEj1.c arbolBB1.o -o pruebaEj1
arbolBB1.o: arbolBB.h arbolBB.c
	gcc -c -g -DEJERCICIO1 arbolBB.c -o arbolBB1.o

ejercicio2: ejercicio2.c arbolBB2.o
	gcc -g -DEJERCICIO2 ejercicio2.c arbolBB2.o -o ejercicio2
arbolBB2.o: arbolBB.h arbolBB.c
	gcc -c -g -DEJERCICIO2 arbolBB.c -o arbolBB2.o

# Sesión 11. Semana 9 Mayo
pruebaEj3: pruebaEj3.c arbolBB3.o
	gcc -g -DEJERCICIO3 pruebaEj3.c arbolBB3.o -o pruebaEj3
arbolBB3.o: arbolBB.c arbolBB.h
	gcc -c -g -DEJERCICIO3 arbolBB.c -o arbolBB3.o
clean:
	rm *.o
