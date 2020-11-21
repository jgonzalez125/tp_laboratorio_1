#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Mozo.h"

int parser_mozoFromText(FILE* pFile , LinkedList* pArrayListMozo)
{
	int resultado;
	int retorno = -1;
	Mozo* fileMozo = NULL;
	char buffer[2][50];

	fscanf(pFile,"%[^,],%[^\n]\n",buffer[0],buffer[1]);
	if(pFile != NULL && pArrayListMozo != NULL){
		do{
			resultado = fscanf(pFile,"%[^,],%[^\n]\n",buffer[0],buffer[1]);
			if(resultado == 2){
				fileMozo = mozo_newParametrosTxt(buffer[1], buffer[0]);
				if(fileMozo != NULL){
					ll_add(pArrayListMozo, fileMozo);
					retorno = 0;
				}
			}
		}while(!feof(pFile));
		fclose(pFile);
	}
    return retorno;
}

