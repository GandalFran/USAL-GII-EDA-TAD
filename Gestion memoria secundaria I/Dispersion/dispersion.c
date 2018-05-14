#include "dispersion.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MARCA fprintf(stderr,"\n[%s:%d]",__FUNCTION__,__LINE__);
#define HASH(elemento) ((elemento) % CUBOS)
#define TAM_CUBO (sizeof(tipoCubo))
#define TAM_ALUMNO (sizeof(tipoAlumno))
#define INICIO_DESBORDE (CUBOS*sizeof(tipoCubo))
#define DESPLAZA_HASH(elemento) (HASH(elemento)*TAM_CUBO)

// Crea un fichero hash inicialmente vacio seg�n los criterios especificados en la pr�ctica
// Primera tarea a realizar para  crear un fichero organizado mediante DISPERSI�N
void creaHvacio(char *fichHash){
  FILE *fHash;
  tipoCubo cubo;
  int j;
  int numCubos =CUBOS+CUBOSDESBORDE;

  memset(&cubo,0,sizeof(cubo));

  fHash = fopen(fichHash,"wb");
  for (j=0;j<numCubos;j++) fwrite(&cubo,sizeof(cubo),1,fHash);
  fclose(fHash);
}
// Lee el contenido del fichero hash organizado mediante el m�todo de DISPERSI�N seg�n los criterios
// especificados en la pr�ctica. Se leen todos los cubos completos tengan registros asignados o no. La
// salida que produce esta funci�n permite visualizar el m�todo de DISPERSI�N

int leeHash(char *fichHash){
  FILE *f;
  tipoCubo cubo;
  int j,i=0;
  size_t numLee;

   f = fopen(fichHash,"rb");
   rewind(f);
   fread(&cubo,sizeof(cubo),1,f);
   while (!feof(f)){
	for (j=0;j<C;j++) {
        if (j==0)    	printf("Cubo %2d (%2d reg. ASIGNADOS)",i,cubo.numRegAsignados);
        else  	printf("\t\t\t");
	if (j < cubo.numRegAsignados) 
		    printf("\t%s %s %s %s %s\n",
	    		cubo.reg[j].dni,
			cubo.reg[j].nombre,
			cubo.reg[j].ape1,
		  	cubo.reg[j].ape2,
  	                cubo.reg[j].provincia);
	else printf ("\n");
        }
       i++;
       fread(&cubo,sizeof(cubo),1,f);
   }
   fclose(f);
   return i;
}

// funciones a codificar
int creaHash(char *fichEntrada,char *fichHash){
	int nDesbord, i;
	tipoCubo c;
	tipoAlumno a;
	FILE *fEntrada,*fSalida;


	creaHvacio(fichHash);

	if(NULL == (fEntrada = fopen(fichEntrada,"rb"))){
		return -1;
	}
	if(NULL == (fSalida = fopen(fichHash,"r+b"))){
		fclose(fEntrada);		
		return -1;
	}
	


	nDesbord = 0;
	while(0 < fread(&a, TAM_ALUMNO, 1, fEntrada)){
		fseek(fSalida,DESPLAZA_HASH(atoi(a.dni)),SEEK_SET);
		fread(&c,TAM_CUBO,1,fSalida);
		
		if(c.numRegAsignados < C){
			c.reg[c.numRegAsignados] = a;	
		}
		c.numRegAsignados += 1;
		fseek(fSalida,-TAM_CUBO,SEEK_CUR);
		fwrite(&c,1,TAM_CUBO,fSalida);

		if(c.numRegAsignados > C){

			fseek(fSalida,INICIO_DESBORDE,SEEK_SET);
			i=0;
			while(i<CUBOSDESBORDE && c.numRegAsignados>=C){
				i++;
				fread(&c,TAM_CUBO,1,fSalida);
			}

			c.reg[c.numRegAsignados] = a;	
			c.numRegAsignados += 1;

			fseek(fSalida,-TAM_CUBO,SEEK_CUR);
			fwrite(&c,TAM_CUBO,1,fSalida);

			nDesbord += 1;
		}

	};


	fclose(fEntrada);
	fclose(fSalida);

	return nDesbord;
}

int buscaReg(FILE *fHash, tipoAlumno *reg,char *dni){
	int i;	
	tipoCubo c;


	fseek(fHash,DESPLAZA_HASH(atoi(dni)),SEEK_SET);
	fread(&c,TAM_CUBO,1,fHash);

	for(i=0; i<c.numRegAsignados && i<C; i++){
		if(!strcmp(c.reg[i].dni,dni)){
			*reg = c.reg[i];
			return HASH(atoi(dni));
		}
	}

	if(c.numRegAsignados < C || c.numRegAsignados == 0)
		return -1;

	fseek(fHash,INICIO_DESBORDE,SEEK_SET);
	while(0 < fread(&c,TAM_CUBO,1,fHash)){
		for(i=0; i<c.numRegAsignados && i<C; i++){
			if(!strcmp(c.reg[i].dni,dni)){
				*reg = c.reg[i];
				return i+CUBOS;
			}
		}
	}
}

int insertarReg(FILE*f,tipoAlumno*reg){
	int i;
	tipoCubo c;
	
	fseek(f,DESPLAZA_HASH(atoi(reg->dni)),SEEK_SET);
	fread(&c,TAM_CUBO,1,f);
	
	if(c.numRegAsignados < C){
		c.reg[c.numRegAsignados] = *reg;	

		c.numRegAsignados += 1;
		fseek(f,-TAM_CUBO,SEEK_CUR);
		fwrite(&c,1,TAM_CUBO,f);

		return HASH(atoi(reg->dni));
	}else{
		c.numRegAsignados += 1;
		fseek(f,-TAM_CUBO,SEEK_CUR);
		fwrite(&c,1,TAM_CUBO,f);

		fseek(f,INICIO_DESBORDE,SEEK_SET);
		i=0;
		while(i<CUBOSDESBORDE && c.numRegAsignados>=C){
			i++;
			fread(&c,TAM_CUBO,1,f);
		}
		if(i == CUBOSDESBORDE)
			return -1;

		c.reg[c.numRegAsignados] = *reg;	
		c.numRegAsignados += 1;

		fseek(f,-TAM_CUBO,SEEK_CUR);
		fwrite(&c,TAM_CUBO,1,f);

		return i + CUBOS;
	}

	return -1;
}

