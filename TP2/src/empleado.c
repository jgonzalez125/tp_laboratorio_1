/*
 * Empleado.c
 *
 *  Created on: Aug 2, 2020
 *      Author: juang
 */
#include "empleado.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utn.h"

int emp_imprimir(Empleado *array) {
	int retorno = -1;

	if (array != NULL) {
		printf(
				"\nid: %d) Nombre: %s -- Apellido: %s -- Salario: %.2f -- sector: %d",
				array->id, array->nombre, array->apellido, array->salario,
				array->sector);
		retorno = 0;
	}

	return retorno;
}

int emp_imprimirArray(Empleado *array, int longitud) {
	int retorno = -1;

	if (array != NULL && longitud > 0) {
		for (int i = 0; i < longitud; i++) {
			if (array[i].isEmpty != 1) {
				printf(
						"\nid: %d) Nombre: %s -- Apellido: %s -- Salario: %.2f -- sector: %d",
						array[i].id, array[i].nombre, array[i].apellido,
						array[i].salario, array[i].sector);
				retorno = 0;
			}
		}
	}
	return retorno;
}

int emp_initArray(Empleado *array, int longitud) {
	int retorno = -1;

	if (array != NULL && longitud > 0) {
		for (int i = 0; i < longitud; i++) {
			array[i].isEmpty = 1;
			retorno = 0;
		}
	}
	return retorno;
}

int emp_encontrarIndiceVacio(Empleado *array, int longitud) {
	int retorno = -1;

	if (array != NULL && longitud > 0) {
		for (int i = 0; i < longitud; i++) {
			if (array[i].isEmpty == 1) {
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int emp_cargarArray(Empleado *array, int longitud, int indice, int *id) {
	int retorno = -1;
	Empleado variableProducto;

	if (longitud > 0 && array != NULL && indice < longitud) {
		if (utn_getNombre(variableProducto.nombre, NOMBRE_LEN,
				"\nIngrese nombre del empleado:", "\nError", 3) == 0
				&& utn_getNombre(variableProducto.apellido, NOMBRE_LEN,
						"\nIngrese apellido del empleado: ",
						"\nError, reingrese", 3) == 0
				&& utn_getNumeroFlotante(&variableProducto.salario,
						"\nIngrese salario del empleado:", "\nError", 10000,
						100000, 3) == 0
				&& utn_getNumero(&variableProducto.sector,
						"\nIngrese sector del empleado", "\nError, reingrese",
						1, 10, 3) == 0) {

			variableProducto.isEmpty = 0;
			array[indice] = variableProducto;
			array[indice].id = *id;
			(*id)++;
			retorno = 0;
		}

	}
	return retorno;
}

int emp_altaForzada(Empleado *array, int longitud, int indice, char* nombre, char* apellido, float salario, int sector, int* id){
	int retorno = -1;
	Empleado auxiliarEmpleado;
	if(array != NULL && nombre != NULL && apellido != NULL && salario > 0 && sector > 0 && id != NULL){
		strncpy(auxiliarEmpleado.nombre, nombre, NOMBRE_LEN);
		strncpy(auxiliarEmpleado.apellido, apellido, NOMBRE_LEN);
		auxiliarEmpleado.salario = salario;
		auxiliarEmpleado.id = *id;
		auxiliarEmpleado.sector = sector;
		auxiliarEmpleado.isEmpty = 0;
		array[indice] = auxiliarEmpleado;
		(*id)++;
		retorno = 0;
	}

	return retorno;
}

int emp_bajaArray(Empleado *array, int longitud, int indice) {
	int retorno = -1;

	if (array != NULL && longitud > 0 && indice < longitud
			&& array[indice].isEmpty == 0 && indice >= 0) {
		printf("\nEmpleado a ser eliminado:");
		emp_imprimir(&array[indice]);
		array[indice].isEmpty = 1;
		retorno = 0;
	}
	return retorno;
}

int emp_modificarArray(Empleado *array, int longitud, int indice) {
	int retorno = -1;
	int opcion;
	Empleado auxCliente;

	if (array != NULL && longitud > 0 && indice < longitud
			&& array[indice].isEmpty == 0 && indice >= 0) {
		do {
			printf("\nCliente a ser modificado: ");
			emp_imprimir(&array[indice]);
			if (!utn_getNumero(&opcion,
					"\nQue campo desea modificar? \n1)Nombre\n2)Salario\n3)Apellido\n4)Sector\n5)No modificar",
					"\nError, reingrese", 1, 5, 3)) {
				switch (opcion) {
				case 1:
					if (!utn_getNombre(auxCliente.nombre, NOMBRE_LEN,
							"\nModifique nombre del empleado:", "\nError", 3)) {
						printf("Nombre modificado exitosamente");
						strncpy(array[indice].nombre, auxCliente.nombre,
								NOMBRE_LEN);
					}
					break;
				case 2:
					if (!utn_getNombre(auxCliente.apellido, NOMBRE_LEN,
							"\nModifique apellido del empleado:", "\nError",
							3)) {
						printf("Apellido modificado exitosamente");
						strncpy(array[indice].apellido, auxCliente.apellido,
								NOMBRE_LEN);
					}
					break;
				case 3:
					if (!utn_getNumeroFlotante(&auxCliente.salario,
							"\nModifique salario del empleado:", "\nError",
							10000, 1000000, 3)) {
						printf("Salario modificado exitosamente");
						array[indice].salario = auxCliente.salario;
					}
					break;
				case 4:
					if (!utn_getNumero(&auxCliente.sector,
							"\nModifique sector del empleado:", "\nError", 1,
							10, 3)) {
						printf("Sector modificado exitosamente");
						array[indice].sector = auxCliente.sector;
					}
					break;
				default:
					printf("\nSaliendo de la modificacion");
				}
				retorno = 0;
			}
		} while (opcion != 5);
	}
	return retorno;
}

int emp_ordenarPorApellidoSector(Empleado *array, int limite) {
	int retorno = -1;
	int i;
	int j;
	Empleado auxCliente;

	if (array != NULL && limite > 0) {
		for (i = 0; i < limite - 1; i++) {
			for (j = i + 1; j < limite; j++) {
				int auxCmp = strncmp(array[i].apellido, array[j].apellido,
						NOMBRE_LEN);
				if (array[i].isEmpty == 1 || array[i + 1].isEmpty == 1) {
					continue;
				}
				if (auxCmp < 0
						|| (auxCmp == 0 && array[i].sector < array[j].sector)) {
					auxCliente = array[i];
					array[i] = array[j];
					array[j] = auxCliente;
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}

int emp_buscarId(Empleado *array, int limite, int idBuscado) {
	int retorno = -1;

	if (array != NULL && limite > 0) {
		for (int i = 0; i < limite; i++) {
			if (array[i].id == idBuscado) {
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

float emp_calcularPromedio(Empleado *array, int limite, int contadorEmpleados) {
	float retorno = -1;
	int acumulador = 0;
	if (array != NULL && limite > 0) {
		for (int i = 0; i < limite; i++) {
			if (array[i].isEmpty && array[i + 1].isEmpty)
				continue;
			acumulador = acumulador + array[i].salario;
		}
		retorno = (float) acumulador / contadorEmpleados;
	}
	return retorno;
}

int emp_superaPromedio(Empleado *array, int limite, int contadorEmpleados) {
	int retorno = -1;
	int respuesta;
	int contador = 0;
	if (array != NULL && limite > 0) {
		respuesta = emp_calcularPromedio(array, limite, contadorEmpleados);
		for (int i = 0; i < limite; i++) {
			if (array[i].isEmpty && array[i + 1].isEmpty)
				continue;
			if (array[i].salario > respuesta) {
				contador++;
			}
		}
		retorno = contador;
	}
	return retorno;
}
