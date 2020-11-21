#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "Mesa.h"
#include "Mozo.h"
#include "utn.h"

#define CLIENTES_MIN 1
#define CLIENTES_MAX 15
#define REINTENTOS 3
#define ID_MIN 1
#define ID_MOZOS_MAX 5
#define PRECIO_MIN 100
#define PRECIO_MAX 10000

int controller_ListarMozos(LinkedList *pArrayListMozos) {
	int retorno = -1;
	Mozo *auxMesa;

	if (pArrayListMozos != NULL) {
		for (int i = 0; i < ll_len(pArrayListMozos); i++) {
			auxMesa = (Mozo*) ll_get(pArrayListMozos, i);
			if (auxMesa != NULL) {
				mozo_imprimir(auxMesa);
			}
		}
		retorno = 0;
	}
	return retorno;
}

int controller_ListarMesas(LinkedList *pArrayListMesas) {
	int retorno = -1;
	Mesa *auxMesa;

	if (pArrayListMesas != NULL) {
		for (int i = 0; i < ll_len(pArrayListMesas); i++) {
			auxMesa = (Mesa*) ll_get(pArrayListMesas, i);
			if (auxMesa != NULL) {
				mesa_imprimir(auxMesa);
			}
		}
		retorno = 0;
	}
	return retorno;
}

int controller_cargarDeTexto(char *path, LinkedList *pArrayListMozos) {
	int retorno = -1;
	FILE *pFile;

	if (path != NULL && pArrayListMozos != NULL) {
		pFile = fopen(path, "r");
		if (pFile != NULL) {
			if (!parser_mozoFromText(pFile, pArrayListMozos)) {
				printf("\nLeido exitosamente\n");
				retorno = 0;
			} else {
				printf("\nError, mal leido");
			}
		}
	}
	return retorno;
}

int controller_mostrarMesasFiltradas(int (*pFunc)(void*), LinkedList *pArrayListMesas) {
	int retorno = -1;
	LinkedList *auxListaFiltrada = NULL;
	if (pFunc != NULL && pArrayListMesas != NULL) {
		auxListaFiltrada = ll_filter(pArrayListMesas, pFunc);
		if (auxListaFiltrada != NULL) {
			controller_ListarMesas(auxListaFiltrada);
			retorno = 0;
		}
	}

	return retorno;
}

int controller_aplicarDescuento(void* (*pFunc)(void*),
		LinkedList *pArrayListMesas) {
	int retorno = -1;
	LinkedList *auxListaFiltrada = NULL;
	if (pFunc != NULL && pArrayListMesas != NULL) {
		auxListaFiltrada = ll_map(pArrayListMesas, pFunc);
		if (auxListaFiltrada != NULL) {
			retorno = 0;
		}
	}
	return retorno;
}

int controller_agregarMesa(LinkedList *pArrayListMesas) {
	int retorno = -1;

	//variables auxiliares
	int auxClientes;
	Pedido auxPedido;
	int auxIdMozo;
	int auxId;

	static Mesa *nuevaMesa = NULL;

	if (pArrayListMesas != NULL) {

		auxId = ll_incrementId(pArrayListMesas);
		if (!utn_getNumero(&auxIdMozo,
				"\nIngrese Id de mozo que lo va a atender: ",
				"\nError, reingrese", ID_MIN, ID_MOZOS_MAX, REINTENTOS)
				&& !utn_getNumero(&auxClientes,
						"\nIngrese cantidad de clientes: (1 - 15)",
						"\nError, reingrese", CLIENTES_MIN, CLIENTES_MAX,
						REINTENTOS)
				&& !utn_getDescripcion(auxPedido.descripcion, NOMBRE_LEN,
						"\nIngrese orden del cliente:", "\nError, reingrese",
						REINTENTOS)
				&& !utn_getNumeroFlotante(&auxPedido.precio,
						"\nIngrese precio del pedido: (100 - 10000)",
						"\nError, reingrese", PRECIO_MIN, PRECIO_MAX,
						REINTENTOS)) {
			nuevaMesa = mesa_newParametros(auxClientes, auxPedido, auxIdMozo,
					auxId);
			if (nuevaMesa != NULL) {
				if (!ll_add(pArrayListMesas, nuevaMesa)) {
					printf("\nCarga realizada correctamente");
					retorno = 0;
				}
			} else {
				printf("\nNo se pudo setear los datos");
			}
		}
	}
	return retorno;
}

int controller_editarMesa(LinkedList *pArrayListMesas) {
	int retorno = -1;
	int opcion;

	//auxiliares
	int auxiliarId;
	int auxClientes;
	Mesa *auxMesa;
	Pedido auxPedido;

	// variables buffers
	int bufferId;
	int ll_len = ll_incrementId(pArrayListMesas);

	controller_ListarMesas(pArrayListMesas);
	if (pArrayListMesas != NULL) {
		if (!utn_getNumero(&auxiliarId, "\nIngrese id de mesa a modificar",
				"\nError, reingrese", 1, 100000, 3)) {
			for (int i = 0; i < ll_len; i++) {
				auxMesa = (Mesa*) ll_get(pArrayListMesas, i);
				mesa_getIdInt(auxMesa, &bufferId);

				if (auxiliarId == bufferId) {
					do {
						if (!mesa_imprimir(auxMesa)
								&& !utn_getNumero(&opcion,
										"\nModifique: \n1- Cantidad de Clientes\n2-Pedido\n3- Precio",
										"\nError", 1, 4, 3)) {
							switch (opcion) {
							case 1:
								if (!utn_getNumero(&auxClientes,
										"\nModifique cantidad de clientes:",
										"\nError, reingrese", CLIENTES_MIN,
										CLIENTES_MAX, REINTENTOS)) {
									if (!mesa_setClientes(auxMesa,
											auxClientes)) {
										printf(
												"\nCantidad de clientes modificado exitosamente");
									}
								}
								break;
							case 2:
								if (!utn_getDescripcion(auxPedido.descripcion,
										DESCRIPCION_LEN, "\nModifique pedido: ",
										"\nError, reingrese", REINTENTOS)) {
									if (!mesa_setPedido(auxMesa, auxPedido)) {
										printf(
												"\nPedido modificado exitosamente");
									}
								}
								break;
							case 3:
								if (!utn_getNumeroFlotante(&auxPedido.precio,
										"\nIngrese nuevo precio: ",
										"\nError, reingrese", PRECIO_MIN,
										PRECIO_MAX, REINTENTOS)) {
									if (!mesa_setPedido(auxMesa, auxPedido)) {
										printf(
												"\nPrecio modificado exitosamente");
									}
								}
								break;
							default:
								printf("\nSaliendo de menu de modificacion...");
								break;
							}
						}
					} while (opcion != 4);
				}
				retorno = 0;
			}
		}
	}
	return retorno;
}


int controller_borrarMesa(LinkedList *pArrayListMesas) {
	int retorno = -1;
	int auxiliarId;
	int bufferId;
	Mesa *auxMesa;
	int ll_len = ll_incrementId(pArrayListMesas);

	controller_ListarMesas(pArrayListMesas);
	if (pArrayListMesas != NULL) {
		if (!utn_getNumero(&auxiliarId, "\nIngrese id de la mesa a dar de baja",
				"\nError, reingrese", ID_MIN, ll_len - 1, REINTENTOS)) {
			for (int i = 0; i < ll_len; i++) {
				auxMesa = (Mesa*) ll_get(pArrayListMesas, i);
				mesa_getIdInt(auxMesa, &bufferId);

				if (bufferId == auxiliarId) {
					printf("\nMesa a ser eliminada: ");
					mesa_imprimir(auxMesa);
					if (!ll_remove(pArrayListMesas, i)) {
						printf("\nMesa eliminada exitosamente");
						retorno = 0;
						break;
					}
				}
			}
		}
	}
	return retorno;
}

int controller_ordenarMesas(LinkedList *pArrayListMesas) {
	int retorno = -1;
	int opcion;
	int criterio;
	if (pArrayListMesas != NULL) {
		do {
			if (!utn_getNumero(&opcion, "\nIngrese un opcion:"
					"\n1.Ordenar por cantidad de clientes."
					"\n2.Ordenar por precio de pedidos."
					"\n3.Ordenar por id de mesa."
					"\n4.Salir ", "Opcion invalida", 1, 4, 3)) {
				if (opcion != 4) {
					utn_getNumero(&criterio,
							"\nDe manera ascendente (1) o descendente (0)",
							"\nError, reingrese", 0, 1, 3);
				}
				switch (opcion) {
				case 1:
					ll_sort(pArrayListMesas, mesa_ordenarPorClientes, criterio);
					break;
				case 2:
					ll_sort(pArrayListMesas, mesa_ordenarPorPrecio, criterio);
					break;
				case 3:
					ll_sort(pArrayListMesas, mesa_ordenarPorId, criterio);
					break;
				}
			}

		} while (opcion != 4);
	}
	return retorno;
}

int controller_guardarComoTexto(char *path, LinkedList *pArrayListMesas) {
	int retorno = -1;
	int i;

	//Variables buffer
	int bufferClientes;
	Pedido bufferPedido;
	int bufferIdMozo;
	int bufferId;

	//Aux variables
	Mesa *auxMesa;
	FILE *fpArchivo;

	if (pArrayListMesas != NULL && path != NULL) {
		fpArchivo = fopen(path, "aw");
		if (fpArchivo != NULL) {
			for (i = 0; i < ll_len(pArrayListMesas); i++) {
				auxMesa = ll_get(pArrayListMesas, i);
				if (pArrayListMesas != NULL) {
					if (!mesa_getClientes(auxMesa, &bufferClientes)
							&& !mesa_getPedido(auxMesa, &bufferPedido)
							&& !mesa_getIdMozoInt(auxMesa, &bufferIdMozo)
							&& !mesa_getIdInt(auxMesa, &bufferId)) {
						fprintf(fpArchivo, "%d,%d,%s,%.2f,%d\n", bufferId,
								bufferClientes, bufferPedido.descripcion,
								bufferPedido.precio, bufferIdMozo);
					} else {
						printf("\nError al guardar");
					}
				}
			}
			printf("\nGuardado exitosamente");
			retorno = 0;
			fclose(fpArchivo);
		}
	}
	return retorno;
}
