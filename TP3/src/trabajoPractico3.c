/*
 ============================================================================
 Name        : trabajoPractico3.c
 Author      : juampi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "utn.h"
#include "Controller.h"
#include "Employee.h"
#define QTY_EMPLEADOS 100
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/


int main(void) {
    int option;
    LinkedList* listaEmpleados = ll_newLinkedList();


    //flags
    int cargoDeTexto = 0;
    int dioDeAlta = 0;
    int cargoDeBinario = 0;

    if(listaEmpleados != NULL){
	  do{
			if(!utn_getNumero(&option, "\nIngrese opcion:"
									   "\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)."
									   "\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)."
									   "\n3. Alta de empleado"
									   "\n4. Modificar datos de empleado"
									   "\n5. Baja de empleado"
									   "\n6. Listar empleados"
									   "\n7. Ordenar empleados"
									   "\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto)."
									   "\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario)."
									   "\n10. Salir", "\nError", 1, 10, 3)){
				switch(option){
					case 1:
						//Si se levanta el .csv, es la unica vez que se puede realizar
						//para que el usuario no duplique los datos erroneamente
						if(cargoDeTexto == 1){
							printf("\nNo puede cargar nuevamente");
						}else{
							if(!controller_loadFromText("data.csv",listaEmpleados)){
								cargoDeTexto = 1;
							}
						}
						break;
					case 2:
						//Si no levanto el csv, no se puede permitir que cargue de binario
						//Porque no va a tener que cargar
						if(!cargoDeTexto){
							printf("\nDebe cargar de texto");
						}else{
							if(!cargoDeBinario){
								controller_loadFromBinary("data.bin",listaEmpleados);
								cargoDeBinario = 1;
							}else{
								printf("\nNo puede cargar nuevamente");
							}
						}
						break;
					case 3:
						//Debe cargar de texto para agregar empleados, para evitar que
						//se pisen los IDS
						if(!cargoDeTexto){
							printf("\nDebe cargar del texto previo a agregar empleados");
						}else{
							if(!controller_addEmployee(listaEmpleados)){
								dioDeAlta = 1;
							}
						}
						break;
					case 4:
						//Debe cargar de texto para editar empleados
						if(!cargoDeTexto){
							printf("\nDebe cargar del texto");
						}else{
							controller_editEmployee(listaEmpleados);
						}
						break;
					case 5:
						//Debe cargar de texto para eliminar empleados
						if(!cargoDeTexto) {
							printf("\nDebe cargar del texto");
						} else {
							controller_removeEmployee(listaEmpleados);
						}
						break;
					case 6:
						//Debe cargar de texto para listar empleados
						if(!cargoDeTexto) {
							printf("\nDebe cargar del texto");
						} else {
							controller_ListEmployee(listaEmpleados);
						}
						break;
					case 7:
						if(!cargoDeTexto) {
							printf("\nDebe cargar del texto");
						} else {
						controller_sortEmployee(listaEmpleados);
						}
						break;
					case 8:
						if(!cargoDeTexto) {
							printf("\nDebe cargar del texto");
						} else {
							controller_saveAsText("data.csv", listaEmpleados);
						}
						break;
					case 9:
						if(!cargoDeTexto) {
							printf("\nDebe cargar del texto");
						} else {
							controller_saveAsBinary("data.bin", listaEmpleados);
						}
						break;
					default:
						if(!ll_deleteLinkedList(listaEmpleados)){
							printf("\nSaliendo...");
						}
						break;
				}
			}
		}while(option != 10);
    }


    return EXIT_SUCCESS;
}
