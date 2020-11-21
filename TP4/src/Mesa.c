/*
 * mesa.c
 *
 *  Created on: Sep 12, 2020
 *      Author: juang
 */
#include "Mesa.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Pedido.h"
#include "validaciones.h"
#define NOMBRE_LEN 50

/*==========Setters y getters==========*/

/*
 *  - Mesa
    - int clientes
    - Pedido pedido
    - int idMesa
    - int idMozo
 */

int mesa_setDescuento(Mesa* this, int flagDescuento){
	int retorno = -1;
	if(this != NULL){
		this->tuvoDescuento = flagDescuento;
		retorno = 0;
	}
	return retorno;
}

int mesa_getDescuento(Mesa* this,  int *flagDescuento){
	int retorno = -1;
	if(this != NULL && flagDescuento != NULL){
		*flagDescuento = this->tuvoDescuento;
		retorno = 0;
	}
	return retorno;
}


int mesa_setPedido(Mesa* this, Pedido pedido){
	int retorno = -1;
	if(this != NULL){
		this->pedido = pedido;
		retorno = 0;
	}
	return retorno;
}


int mesa_getPedido(Mesa* this, Pedido* pedido){
	int retorno = -1;
	if(this != NULL && pedido != NULL){
		*pedido = this->pedido;
		retorno = 0;
	}
	return retorno;
}

int mesa_setIdMozoInt(Mesa* this, int idMozo){
	int retorno = -1;
	if(this != NULL && idMozo >= 0){
		this->idMozo = idMozo;
		retorno = 0;
	}
	return retorno;
}

int mesa_getIdMozoInt(Mesa* this, int* idMozo){
	int retorno = -1;
	if(this != NULL && idMozo != NULL){
		*idMozo = this->idMozo;
		retorno = 0;
	}
	return retorno;
}

int mesa_setIdTxt(Mesa* this, char* id){
	int retorno = -1;
	if(this != NULL && id != NULL && esNumerica(id,10)){
		if(atoi(id) >= 0){
			this->idMesa = atoi(id);
			retorno = 0;
		}

	}
	return retorno;
}

int mesa_setIdInt(Mesa* this, int id){
	int retorno = -1;
	if(this != NULL && id >= 0){
		this->idMesa = id;
		retorno = 0;
	}
	return retorno;
}

int mesa_getIdTxt(Mesa* this, char* id){
	int retorno = -1;
	if(this != NULL && id != NULL){
		sprintf(id, "%d", this->idMesa);
		retorno = 0;
	}
	return retorno;
}

int mesa_getIdInt(Mesa* this, int* id){
	int retorno = -1;
	if(this != NULL){
		*id = this->idMesa;
		retorno = 0;
	}
	return retorno;
}

int mesa_setClientes(Mesa* this,int clientes){
	int retorno = -1;
	if(this != NULL && clientes > 0){
		this->clientes = clientes;
		retorno = 0;
	}
	return retorno;
}

int mesa_setClientesTxt(Mesa* this,char* clientes){
	int retorno = -1;
	if(this != NULL && esNumerica(clientes, 10)){
		this->clientes = atoi(clientes);
		retorno = 0;
	}
	return retorno;
}

int mesa_getClientes(Mesa* this,int* clientes){
	int retorno = -1;
	if(this != NULL && clientes > 0){
		*clientes = this->clientes;
		retorno = 0;
	}
	return retorno;
}

/*==========Setters y getters==========*/

/*==========Funciones de memoria dinamica==========*/

void mesa_delete(Mesa* this){
	if(this != NULL){
		free(this);
	}
}

Mesa* mesa_new() {
	return (Mesa*)malloc(sizeof(Mesa));
}

Mesa* mesa_newParametros(int clientes, Pedido pedido, int idMozo, int id) {
	Mesa* this = NULL;
	this = mesa_new();
	if(this != NULL && clientes > 0 && id >= 0 && idMozo >= 0){
		if(mesa_setClientes(this, clientes) == -1 ||
			mesa_setPedido(this, pedido) == -1 ||
			mesa_setIdInt(this, id) == -1 ||
			mesa_setIdMozoInt(this, idMozo) == -1){

			mesa_delete(this);
			this = NULL;
		}
	}
	return this;
}

/*==========Funciones de memoria dinamica==========*/

int mesa_ordenarPorClientes(void* actual,void* siguiente){
  int retorno = -1;
  int clientesMesaUno;
  int clientesMesaDos;
  Mesa* mesaUno = NULL;
    Mesa* mesaDos = NULL;

  	if (actual != NULL && siguiente != NULL) {
  		mesaUno = (Mesa*) actual;
  		mesaDos = (Mesa*) siguiente;

  		mesa_getClientes(mesaUno, &clientesMesaUno);
  		mesa_getClientes(mesaDos, &clientesMesaDos);
  		if (clientesMesaUno > clientesMesaDos) {
  			retorno = 1;
  		} else {
  			retorno = 0;
  		}
  	}


  return retorno;
}

int mesa_ordenarPorPrecio(void* actual,void* siguiente){
  int retorno = -1;
  Pedido pedidoMesaUno;
  Pedido pedidoMesaDos;
  Mesa* mesaUno = NULL;
  Mesa* mesaDos = NULL;

	if (actual != NULL && siguiente != NULL) {
		mesaUno = (Mesa*) actual;
		mesaDos = (Mesa*) siguiente;

		mesa_getPedido(mesaUno, &pedidoMesaUno);
		mesa_getPedido(mesaDos, &pedidoMesaDos);
		if (pedidoMesaUno.precio > pedidoMesaDos.precio) {
			retorno = 1;
		} else {
			retorno = 0;
		}
	}

  return retorno;
}

int mesa_ordenarPorId(void* actual,void* siguiente){
  int retorno = -1;
  int idEmpleadoUno;
  int idEmpleadoDos;
  Mesa* empleadoUno= NULL;
  Mesa* empleadoDos= NULL;

	if (actual != NULL && siguiente != NULL) {
		empleadoUno = (Mesa*) actual;
		empleadoDos = (Mesa*) siguiente;

		mesa_getIdInt(empleadoUno, &idEmpleadoUno);
		mesa_getIdInt(empleadoDos, &idEmpleadoDos);
		if (idEmpleadoUno > idEmpleadoDos) {
			retorno = 1;
		} else {
			retorno = 0;
		}
	}

  return retorno;
}


void* mesa_aplicarDescuento(void* pElement){
	int clientes;
	int tuvoDescuento;
	float descuento;
	float precioFinal;
	Pedido pedido;
	Mesa* mesa = (Mesa*) pElement;
	if(pElement != NULL){
		if(!mesa_getClientes(mesa, &clientes) && !mesa_getDescuento(mesa, &tuvoDescuento)){
			if(clientes > 5 && !tuvoDescuento){
				if(!mesa_getPedido(mesa, &pedido)){
					descuento = pedido.precio*20/100;
					precioFinal = pedido.precio - descuento;
					pedido.precio = precioFinal;
					mesa_setPedido(mesa, pedido);
					mesa_setDescuento(mesa, 1);
				}
			}
		}
	}
	return mesa;
}

int mesa_buscarIdPunteros(Mesa** array, int longitud, int id){
	int retorno = -1;

	if(array != NULL && longitud > 0 && id >= 0){
		for(int i = 0; i < longitud; i++){
			retorno = -2;
			if(array[i] != NULL && array[i]->idMesa == id){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int mesa_imprimir(Mesa* mesa) {
	int retorno = -1;

	if (mesa != NULL) {
		printf("\nid: %d -- Id mozo: %d -- clientes: %d -- Pedido: %s - precio: %.2f",
				mesa->idMesa, mesa->idMozo, mesa->clientes, mesa->pedido.descripcion, mesa->pedido.precio);
		retorno = 0;
	}
	return retorno;
}

int mesa_filtrarMesasPorPrecio(void* pElement){
	int retorno = -1;
	Pedido pedido;
	Mesa* mesa = (Mesa*) pElement;
	if(mesa != NULL){
		if(!mesa_getPedido(mesa, &pedido)){
			if(pedido.precio > 1000){
				retorno = 1;
			}
		}
	}
	return retorno;
}

int mesa_filtrarMesasPorClientes(void* pElement){
	int retorno = -1;
	int clientes;
	int tuvoDescuento;
	Mesa* mesa = (Mesa*) pElement;
	if(mesa != NULL){
		if (!mesa_getClientes(mesa, &clientes) &&
			!mesa_getDescuento(mesa, &tuvoDescuento)) {
			if (clientes > 5 && tuvoDescuento) {
				retorno = 1;
			}
		}
	}

	return retorno;
}

