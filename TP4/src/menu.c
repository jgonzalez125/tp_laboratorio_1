/*
 * menu.c
 *
 *  Created on: Nov 19, 2020
 *      Author: juang
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Mesa.h"
#include "Controller.h"
#include "LinkedList.h"

void menu() {
	int opcion = 0;
	LinkedList* listaMozos = ll_newLinkedList();
	LinkedList* listaMesas = ll_newLinkedList();

	//flags
	int cargoMozos = 0;
	int cargoMesa = 0;
	int cerroSistema = 0;

	 if(listaMozos != NULL && listaMesas != NULL && !cerroSistema){
		  do{
				if(!utn_getNumero(&opcion, "\nIngrese opcion:"
										   "\n1. Cargar los datos de los mozos desde el archivo mozo.csv."
										   "\n2. Alta de Mesa."
										   "\n3. Modificar datos de la mesa"
										   "\n4. Baja de mesa"
										   "\n5. Listar mesas ocupadas"
										   "\n6. Ordenar mesas"
										   "\n7. Guardar los datos de las mesas en el archivo mesa.csv (modo texto)."
										   "\n8. Aplicar descuentos del 20% a las mesas con mas de 5 clientes"
										   "\n9. Informes: (Cierre de sistema)"
										   "\n     - Mesas con pedidos mayores a $1000"
										   "\n     - Mesas a las que se aplico descuento"
										   "\n10. Salir", "\nError", 1, 10, 3)){
					switch(opcion){
						case 1:
							//Si se levanta el .csv, es la unica vez que se puede realizar
							//para que el usuario no duplique los datos erroneamente
							if(!cargoMozos){
								controller_cargarDeTexto("mozo.csv", listaMozos);
								cargoMozos = 1;
							}else{
								printf("\nYa cargo los mozos");
							}
							break;
						case 2:
							//Si no levanto el csv, no se puede permitir que cargue de binario
							//Porque no va a tener que cargar
							if(cargoMozos && !controller_ListarMozos(listaMozos)){
								controller_agregarMesa(listaMesas);
								cargoMesa++;
							}else{
								printf("\nDebe cargar los mozos previo a dar de alta una mesa");
							}
							break;
						case 3:
							if(cargoMesa){
								controller_editarMesa(listaMesas);
							}else{
								printf("\nDebe cargar una mesa previo a editar");
							}
							//Debe cargar
							break;
						case 4:
							//Debe cargar de texto para dar de baja
							if(cargoMesa){
								controller_borrarMesa(listaMesas);
								cargoMesa--;
							}else{
								printf("\nDebe cargar una mesa previo a eliminar");
							}
							break;
						case 5:
							if(cargoMesa){
								controller_ListarMesas(listaMesas);
							}else{
								printf("\nNo hay mesas para listar");
							}
							break;
						case 6:
							if(cargoMesa){
								controller_ordenarMesas(listaMesas);
							}else{
								printf("\nNo hay mesas para ordenar");
							}
							break;
						case 7:
							if(cargoMesa){
								controller_guardarComoTexto("mesa.csv", listaMesas);
							}else{
								printf("\nNo hay mesas para guardar");
							}
							break;
						case 8:
							if(cargoMesa){
								// El descuento se aplica una sola vez a las mesas
								if(!controller_aplicarDescuento(mesa_aplicarDescuento, listaMesas)){
									printf("\nDescuento aplicado exitosmanete");
								}
							}else{
								printf("\nDebe cargar mesas");
							}
							break;
						case 9:
							// Si no cargo mozos, no puede entrar a esta opcion
							// pero si puede entrar aunque no haya cargado mesas
							if(cargoMozos){
								printf("\n============  Mesas con pedidos mayores a $1000  ============");
								if(controller_mostrarMesasFiltradas(mesa_filtrarMesasPorPrecio, listaMesas)){
									printf("\nNo hubo mesas con pedidos mayores a $1000");
								}
								printf("\n============  Mesas con descuento aplicado  ============");
								if(controller_mostrarMesasFiltradas(mesa_filtrarMesasPorClientes, listaMesas)){
									printf("\nNo hubo mesas con mas de 5 clientes");
								}
								cerroSistema = 1;
							}else{
								printf("\nNo se puede cerrar sistema si no cargo mozos");
							}
							break;
						default:
							printf("\nSaliendo...");
							break;
					}
				}
			}while(opcion != 10);
	    }
}

