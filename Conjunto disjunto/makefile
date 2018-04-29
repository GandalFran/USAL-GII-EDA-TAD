# Ejercicio 1
cMatrices:prueba.c conjuntosM/conjuntos.o  
	gcc -g prueba.c -DMATRICES conjuntosM/conjuntos.o -o cMatrices
conjuntosM/conjuntos.o: conjuntosM/conjuntos.c conjuntosM/conjuntos.h
	gcc -c -g conjuntosM/conjuntos.c -o conjuntosM/conjuntos.o
# Ejercicio 2
cListas:prueba.c conjuntosL/conjuntos.o 
	gcc -g prueba.c -DLISTAS conjuntosL/conjuntos.o -o cListas
conjuntosL/conjuntos.o: conjuntosL/conjuntos.c conjuntosL/conjuntos.h
	gcc -c -g conjuntosL/conjuntos.c -o conjuntosL/conjuntos.o
# Ejercicio 3 
cArbolesArbitrario:prueba.c conjuntosA/conjuntosArbitrario.o 
	gcc -g prueba.c -DARBOLES conjuntosA/conjuntosArbitrario.o -o cArbolesArbitrario
conjuntosA/conjuntosArbitrario.o: conjuntosA/conjuntos.c conjuntosA/conjuntos.h
	gcc -c -g conjuntosA/conjuntos.c -DARBITRARIO -o conjuntosA/conjuntosArbitrario.o

cArbolesAltura:prueba.c conjuntosA/conjuntosAltura.o 
	gcc -g prueba.c -DARBOLES conjuntosA/conjuntosAltura.o -o cArbolesAltura
conjuntosA/conjuntosAltura.o: conjuntosA/conjuntos.c conjuntosA/conjuntos.h
	gcc -c -g conjuntosA/conjuntos.c -DALTURA -o conjuntosA/conjuntosAltura.o

cArbolesTamanno:prueba.c conjuntosA/conjuntosTamanno.o 
	gcc -g prueba.c -DARBOLES conjuntosA/conjuntosTamanno.o -o cArbolesTamanno
conjuntosA/conjuntosTamanno.o: conjuntosA/conjuntos.c conjuntosA/conjuntos.h
	gcc -c -g conjuntosA/conjuntos.c -DTAMANNO -o conjuntosA/conjuntosTamanno.o

