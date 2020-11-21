/*
 * Mozo.c
 *
 *  Created on: Nov 18, 2020
 *      Author: juang
 *
 *  3- Mozo (cargados desde data.csv)
    - char nombre[]
    - int id
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Mozo.h"
#include "Pedido.h"
#include "validaciones.h"


Mozo* mozo_new(){
	return (Mozo*)malloc(sizeof(Mozo));
}

void mozo_delete(Mozo* this){
	if(this != NULL){
		free(this);
	}
}

Mozo* mozo_newParametrosTxt(char* nombre, char* id) {
	Mozo* this = NULL;
	this = mozo_new();
	if(this != NULL && nombre != NULL && id != NULL){
		if(mozo_setNombre(this, nombre) == -1 ||
		   mozo_setIdTxt(this, id) == -1){
			mozo_delete(this);
			this = NULL;
		}
	}
	return this;
}

int mozo_setIdTxt(Mozo* this, char* id){
	int retorno = -1;
	if(this != NULL && id != NULL && esNumerica(id,10)){
		if(atoi(id) >= 0){
			this->id = atoi(id);
			retorno = 0;
		}

	}
	return retorno;
}

int mozo_imprimir(Mozo* this){
	int retorno = -1;
	if(this != NULL){
		printf("\nId: %d -- Nombre: %s", this->id, this->nombre);
		retorno = 0;
	}
	return retorno;
}

int mozo_setNombre(Mozo* this, char* nombre){
	int retorno = -1;
	if(this != NULL && nombre != NULL && esNombre(nombre, NOMBRE_LEN)){
		strncpy(this->nombre, nombre, NOMBRE_LEN);
		retorno = 0;
	}
	return retorno;
}
