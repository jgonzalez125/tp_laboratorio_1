/*
 * menu.c
 *
 *  Created on: Aug 7, 2020
 *      Author: juang
 */
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "empleado.h"
#define CANTIDAD_EMPLEADOS 1000

void menu() {
	Empleado arrayEmpleado[CANTIDAD_EMPLEADOS];
	int opcion;
	int dioDeAlta = 0;
	int contadorIds = 0;
	int auxiliarId;
	int auxiliarIndice;
	float respuestaPromedios;
	int respuestaSuperaPromedio;

	if (emp_initArray(arrayEmpleado, CANTIDAD_EMPLEADOS) == 0) {
		printf("\nArray inicializado ok");
	}

	/*
	 * ================================== Funciones de prueba =========================================
	 * emp_altaForzada(arrayEmpleado, CANTIDAD_EMPLEADOS, 0, "JUAN", "GONZALEZ", 30000, 1, &contadorIds);
	 * emp_altaForzada(arrayEmpleado, CANTIDAD_EMPLEADOS, 1, "PEDRO", "LOPEZ", 20000, 2, &contadorIds);
	 * emp_altaForzada(arrayEmpleado, CANTIDAD_EMPLEADOS, 2, "LAURA", "ALVAREZ", 25Å000, 3, &contadorIds);
	 * dioDeAlta = 1;
	 */
	do {
		setbuf(stdout, NULL);
		if (!utn_getNumero(&opcion,
				"\n1)ALTA"
				"\n2)MODIFICAR"
				"\n3)BAJA"
				"\n4)INFORMAR"
				"\n  1. Listado de los empleados ordenados alfabeticamente por apellido y sector"
				"\n  2. Total y promedio de los salarios, y cuantos empleados superan el salario promedio"
				"\n5)Salir\n", "\nError", 1, 5, 3)) {
			switch (opcion) {
			case 1:
				//opcion 1
				auxiliarId = emp_encontrarIndiceVacio(arrayEmpleado,CANTIDAD_EMPLEADOS);
				if (auxiliarId >= 0) {
					if (emp_cargarArray(arrayEmpleado, CANTIDAD_EMPLEADOS, auxiliarId, &contadorIds) == 0) {
						printf("\nCarga realizada exitosamente");
					}
					dioDeAlta = 1;
				} else {
					printf("\nSe quedo sin espacios");
				}
				break;
			case 2:
				//opcion 2
				if(dioDeAlta != 1){
					printf("\nDebe ingresar al menos un empleado para modificar");
					continue;
				}
				emp_imprimirArray(arrayEmpleado, CANTIDAD_EMPLEADOS);
				if (!utn_getNumero(&auxiliarId,
						"\nIngrese id de empleado a ser modificado:", "\nError",
						0, CANTIDAD_EMPLEADOS - 1, 3)) {
					auxiliarIndice = emp_buscarId(arrayEmpleado, CANTIDAD_EMPLEADOS, auxiliarId);
					if (!emp_modificarArray(arrayEmpleado, CANTIDAD_EMPLEADOS, auxiliarIndice)) {
						printf("\nModificacion realizada exitosamente");
					} else {
						printf("\nId %d no es valido", auxiliarId);
					}
				}
				break;
			case 3:
				//opcion 3
				if(dioDeAlta != 1){
					printf("\nDebe ingresar al menos un empleado para dar de baja");
					continue;
				}
				emp_imprimirArray(arrayEmpleado, CANTIDAD_EMPLEADOS);
				if (!utn_getNumero(&auxiliarId,
						"\nIngrese id de empleado a ser eliminado:", "\nError",
						0, CANTIDAD_EMPLEADOS - 1, 3)) {
					auxiliarIndice = emp_buscarId(arrayEmpleado, CANTIDAD_EMPLEADOS, auxiliarId);
					if (!emp_bajaArray(arrayEmpleado, CANTIDAD_EMPLEADOS, auxiliarIndice)) {
						printf("\nBaja realizada exitosamente");
					} else {
						printf("\nId %d no es valido", auxiliarId);
					}
				}
				break;
				//opcion 4
			case 4:
				if(dioDeAlta != 1){
					printf("\nDebe ingresar al menos un empleado para informar");
					continue;
				}
				if (!utn_getNumero(&opcion,
						"\n1.Listado de los empleados ordenados por apellido y sector"
						"\n2.Total y promedio de salarios, y cuantos superan el promedio",
						"\nError, reingrese", 1, 2, 3)) {
					switch (opcion) {
					case 1:
						//opcion 1
						emp_ordenarPorApellidoSectorMenorAmayor(arrayEmpleado,CANTIDAD_EMPLEADOS);
						emp_imprimirArray(arrayEmpleado, CANTIDAD_EMPLEADOS);
						break;
					case 2:
						//opcion 2
						respuestaPromedios = emp_calcularPromedio(arrayEmpleado, CANTIDAD_EMPLEADOS);
						respuestaSuperaPromedio = emp_superaPromedio( arrayEmpleado, CANTIDAD_EMPLEADOS);
						if (respuestaPromedios > 0
								&& respuestaSuperaPromedio != -1) {
							printf(
									"\nPromedio de salarios: %.2f"
									"\nCantidad de empleados que superan el promedio: %d",
									respuestaPromedios,
									respuestaSuperaPromedio);
						}
						break;
					}
				}
				break;
			default:
				printf("\nSaliendo...");
				break;
			}
		}
	} while (opcion != 5);
}
