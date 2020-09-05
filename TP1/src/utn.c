#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * \brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena un
 * 		  maximo de 'n - 1' caracteres (n siendo la longitud del string).
 * \param cadena: Puntero al espaciode memoria donde se copia el string obtenido
 * \param longitud: Define el tamanio de la cadena
 * \n return: retorna 0 if OK y -1 if ERROR
 */
static int myGets(char* cadena, int longitud);

/**
 * \brief Lee la cadena para chequear que el caracter no sea mayor a '9' y menor a '0'
 * \param cadena: cadena de caracteres a confirmar si es una cadena solo numerica
 * \n return: retorna 0 if OK y -1 if ERROR
 */
static int esNumerica(char cadena[]);

/**
 * \brief Obtiene el numero int
 * \param pResultado puntero a la direccion de memoria a ser almacenado el numero obtenido
 * \n return: retorna 0 if OK y -1 if ERROR
 */
static int getInt(int* pResultado);


static int myGets(char* cadena, int longitud){
	int retorno = -1;
	if(cadena != NULL && longitud > 0 && fgets(cadena, longitud, stdin) == cadena){
		fpurge(stdin);
		if(cadena[strlen(cadena) - 1] == '\n'){
			cadena[strlen(cadena) -1] = '\0';
		}
		retorno = 0;
	}
	return retorno;
}

/* =============== FUNCIONES NECESARIAS PARA utn_getNumero() =============== */

static int getInt(int* pResultado){
	char buffer[64];
	int retorno = -1;
	myGets(buffer, sizeof(buffer));

	if(esNumerica(buffer)){
		*pResultado = atoi(buffer);
		retorno = 1;
	}
	return retorno;
}

static int esNumerica(char cadena[]){
	int i;
	int retorno = 1;
	if(cadena != NULL && strlen(cadena) > 0){
		for(i = 0;cadena[i] != '\0'; i++){
			if((cadena[i] < '0' || cadena[i] > '9') && cadena[0] != '-'){
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos){
	int retorno = -1;
	int bufferInt;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0){
		while(reintentos > 0){
			printf("%s", mensaje);
			if(getInt(&bufferInt) == 1){
				if(bufferInt <= maximo && bufferInt >= minimo){
					break;
				}
				fpurge(stdin);
				reintentos--;
				printf("%s", mensajeError);
			}
		}
		if(reintentos == 0){
			retorno = -1;
		}else{
			retorno = 0;
			*pResultado = bufferInt;
		}
	}
	return retorno;
}

