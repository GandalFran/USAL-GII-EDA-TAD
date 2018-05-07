#ifndef __SECUENCIAL_H
#define __SECUENCIAL_H

typedef struct {
	char dni[9];
	char nombre[19];
	char ape1[19];
	char ape2[19];
	char provincia[11];
	} tipoAlumno;


int leeSecuencial(char *fichero);
int buscaReg(FILE *fSecuencial, tipoAlumno *reg,char *dni);
int insertaReg(char *fSecuencial, tipoAlumno *reg);


#endif
