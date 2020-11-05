/*
 * validaciones.c
 *
 *  Created on: Sep 12, 2020
 *      Author: juang
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int esNombre(char* cadena, int longitud){
	int retorno = -1;
	int i;

	if(cadena != NULL && longitud > 0){
		for(i = 0; cadena[i] != '\0' && i < longitud; i++){
			if((cadena[i] < 'A' || cadena[i] > 'Z') && (cadena[i] < 'a' || cadena[i] > 'z') && cadena[i] != ' '){
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int esNumericaFloat(char cadena[], int longitud){
	int retorno = -1;
	int i;
	int contadorPuntos = 0;
	if(cadena != NULL && strnlen(cadena, longitud) > 0){
			for(i = 0; cadena[i] != '\0'; i++){
				if(cadena[i] == '.') contadorPuntos++;
				if(((cadena[i] < '0' || cadena[i] > '9') && cadena[0] != '-') && contadorPuntos > 1){
					retorno = 0;
					break;
				}
			}
		}
	return retorno;
}

int esNumerica(char cadena[], int longitud){
	int i;
	int retorno = 1;
	if(cadena != NULL && strnlen(cadena, longitud) > 0){
		for(i = 0; cadena[i] != '\0'; i++){
			if((cadena[i] < '0' || cadena[i] > '9') && cadena[0] != '-'){
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
