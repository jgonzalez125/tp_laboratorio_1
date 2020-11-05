/*
 * empleado.c
 *
 *  Created on: Sep 12, 2020
 *      Author: juang
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "validaciones.h"
#include "Employee.h"
#define APELLIDO_LEN 50

/*==========Setters y getters==========*/


int empleado_setNombre(Employee* this, char* nombre){
	int retorno = -1;
	if(this != NULL && nombre != NULL && esNombre(nombre, NOMBRE_LEN)){
		strncpy(this->nombre, nombre, NOMBRE_LEN);
		retorno = 0;
	}
	return retorno;
}

int empleado_getNombre(Employee* this, char* nombre){
	int retorno = -1;
	if(this != NULL && nombre != NULL){
		strncpy(nombre, this->nombre, NOMBRE_LEN);
		retorno = 0;
	}
	return retorno;
}

int empleado_setSueldoTxt(Employee* this, char* sueldo){
	int retorno = -1;
	float bufferEstatura;
	if(this != NULL && sueldo != NULL && esNumericaFloat(sueldo, 10)){
		bufferEstatura = atoi(sueldo);
		if(bufferEstatura >= 0){
			this->sueldo = bufferEstatura;
			retorno = 0;
		}
	}
	return retorno;
}

int empleado_setSueldoFloat(Employee* this, float sueldo){
	int retorno = -1;
	if(this != NULL && sueldo > 0){
		this->sueldo = sueldo;
		retorno = 0;
	}
	return retorno;
}

int empleado_getSueldoTxt(Employee* this, char* sueldo){
	int retorno = -1;
	if(this != NULL && sueldo != NULL){
		sprintf(sueldo, "%.2f", this->sueldo);
		retorno = 0;
	}
	return retorno;
}

int empleado_getSueldoFloat(Employee* this, float* sueldo){
	int retorno = -1;
	if(this != NULL && sueldo >= 0){
		*sueldo = this->sueldo;
		retorno = 0;
	}
	return retorno;
}

int empleado_setIdTxt(Employee* this, char* id){
	int retorno = -1;
	if(this != NULL && id != NULL && esNumerica(id,10)){
		if(atoi(id) >= 0){
			this->id = atoi(id);
			retorno = 0;
		}

	}
	return retorno;
}

int empleado_setIdInt(Employee* this, int id){
	int retorno = -1;
	if(this != NULL && id >= 0){
		this->id = id;
		retorno = 0;
	}
	return retorno;
}

int empleado_getIdTxt(Employee* this, char* id){
	int retorno = -1;
	if(this != NULL && id != NULL){
		sprintf(id, "%d", this->id);
		retorno = 0;
	}
	return retorno;
}

int empleado_getIdInt(Employee* this, int* id){
	int retorno = -1;
	if(this != NULL && id >= 0){
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

int empleado_setHorasTrabajadas(Employee* this,int horasTrabajadas){
	int retorno = -1;
	if(this != NULL && horasTrabajadas >= 0){
		this->horasTrabajadas = horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}

int empleado_setHorasTrabajadasTxt(Employee* this,char* horasTrabajadas){
	int retorno = -1;
	if(this != NULL && esNumerica(horasTrabajadas, 10)){
		this->horasTrabajadas = atoi(horasTrabajadas);
		retorno = 0;
	}
	return retorno;
}

int empleado_getHorasTrabajadas(Employee* this,int* horasTrabajadas){
	int retorno = -1;
	if(this != NULL && horasTrabajadas >= 0){
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}

/*==========Setters y getters==========*/

/*==========Funciones de memoria dinamica==========*/

void empleado_delete(Employee* this){
	if(this != NULL){
		free(this);
	}
}

Employee* empleado_new() {
	Employee* this = (Employee*)malloc(sizeof(Employee));

	if (this != NULL) {
		empleado_setIdInt(this, 0);
		empleado_setNombre(this, " ");
		empleado_setSueldoFloat(this, 0);
		empleado_setHorasTrabajadas(this, 0);
	}
	  return (Employee*)malloc(sizeof(Employee));
}

Employee* empleado_newParametros(char* nombre, float sueldo, int horasTrabajadas, int id) {
	Employee* this = NULL;
	this = empleado_new();
	if(this != NULL && nombre != NULL && sueldo >= 0 && id >= 0){
		if(empleado_setNombre(this, nombre) == -1 ||
			empleado_setSueldoFloat(this, sueldo) == -1 ||
			empleado_setIdInt(this, id) == -1 ||
			empleado_setHorasTrabajadas(this, horasTrabajadas)){

			empleado_delete(this);
			this = NULL;
		}
	}
	return this;
}

Employee* empleado_newParametrosTxt(char* nombre, char* sueldo, char* horasTrabajadas, char* id) {
	Employee* this = NULL;
	this = empleado_new();
	if(this != NULL && nombre != NULL && sueldo != NULL && id != NULL){
		if(empleado_setNombre(this, nombre) == -1 ||
			empleado_setSueldoTxt(this, sueldo) == -1 ||
			empleado_setHorasTrabajadasTxt(this, horasTrabajadas) == -1 ||
			empleado_setIdTxt(this, id) == -1){
			empleado_delete(this);
			this = NULL;
		}
	}
	return this;
}

/*==========Funciones de memoria dinamica==========*/

int empleado_ordenarPorSueldo(void* actual,void* siguiente){
  int retorno = -1;
  float sueldoEmpleadoUno;
  float sueldoEmpleadoDos;
  Employee* empleadoUno= NULL;
  Employee* empleadoDos= NULL;

	if (actual != NULL && siguiente != NULL) {
		empleadoUno = (Employee*) actual;
		empleadoDos = (Employee*) siguiente;

		empleado_getSueldoFloat(empleadoUno, &sueldoEmpleadoUno);
		empleado_getSueldoFloat(empleadoDos, &sueldoEmpleadoDos);
		if (sueldoEmpleadoUno > sueldoEmpleadoDos) {
			retorno = 1;
		} else {
			retorno = 0;
		}
	}

  return retorno;
}

int empleado_ordenarPorHorasTrabajadas(void* actual,void* siguiente){
  int retorno = -1;
  int horasTrabajadasEmpleadoUno;
  int horasTrabajadasEmpleadoDos;
  Employee* empleadoUno= NULL;
  Employee* empleadoDos= NULL;

	if (actual != NULL && siguiente != NULL) {
		empleadoUno = (Employee*) actual;
		empleadoDos = (Employee*) siguiente;

		empleado_getHorasTrabajadas(empleadoUno, &horasTrabajadasEmpleadoUno);
		empleado_getHorasTrabajadas(empleadoDos, &horasTrabajadasEmpleadoDos);
		if (horasTrabajadasEmpleadoUno > horasTrabajadasEmpleadoDos) {
			retorno = 1;
		} else {
			retorno = 0;
		}
	}

  return retorno;
}

int empleado_ordenarPorId(void* actual,void* siguiente){
  int retorno = -1;
  int idEmpleadoUno;
  int idEmpleadoDos;
  Employee* empleadoUno= NULL;
  Employee* empleadoDos= NULL;

	if (actual != NULL && siguiente != NULL) {
		empleadoUno = (Employee*) actual;
		empleadoDos = (Employee*) siguiente;

		empleado_getIdInt(empleadoUno, &idEmpleadoUno);
		empleado_getIdInt(empleadoDos, &idEmpleadoDos);
		if (idEmpleadoUno > idEmpleadoDos) {
			retorno = 1;
		} else {
			retorno = 0;
		}
	}

  return retorno;
}

int empleado_ordenarPorNombre(void* actual,void* siguiente){
  int retorno = -1;
  char nombreEmpleadoUno[NOMBRE_LEN];
  char nombreEmpleadoDos[NOMBRE_LEN];
  Employee* empleadoUno= NULL;
  Employee* empleadoDos= NULL;

	if (actual != NULL && siguiente != NULL) {
		empleadoUno = (Employee*) actual;
		empleadoDos = (Employee*) siguiente;

		empleado_getNombre(empleadoUno, nombreEmpleadoUno);
		empleado_getNombre(empleadoDos, nombreEmpleadoDos);

		if (strncmp(nombreEmpleadoUno, nombreEmpleadoDos, NOMBRE_LEN) < 0) {
			retorno = 1;
		} else {
			retorno = 0;
		}
	}

  return retorno;
}


/*===============Funciones de arrays================*/

int empleado_agregarEmpleadoPunteros(Employee** array, int longitud, int indice, char* nombre, int sueldo, int horasTrabajadas, int id){
	int retorno = -1;

	if(array != NULL && longitud > 0 && indice >= 0 && indice < longitud && id >= 0 && nombre != NULL  && sueldo > 0){
			array[indice] = empleado_newParametros(nombre, sueldo, horasTrabajadas, id);
			retorno = 0;
	}
	return retorno;
}

int empleado_agregarEmpleadoPunterosTxt(Employee** array, int longitud, char* nombre, char* altura, char* horasTrabajadas, char* id){
	int retorno = -1;
	int indiceLibre;
	Employee* pAuxiliarempleado;
	if(array != NULL && longitud > 0 && id != NULL && nombre != NULL  && altura != NULL){
		indiceLibre = empleado_getEmptyIndexPunteros(array, longitud);
		if(indiceLibre >= 0){
			pAuxiliarempleado = empleado_newParametrosTxt(nombre, altura, horasTrabajadas, id);
			if(pAuxiliarempleado != NULL){
				retorno = indiceLibre;
				array[indiceLibre] = pAuxiliarempleado;
			}
		}
	}
	return retorno;
}


int empleado_buscarIdPunteros(Employee** array, int longitud, int id){
	int retorno = -1;

	if(array != NULL && longitud > 0 && id >= 0){
		for(int i = 0; i < longitud; i++){
			retorno = -2;
			if(array[i] != NULL && array[i]->id == id){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int empleado_borrarEmpleadoPunteros(Employee** array, int longitud, int id){
	int retorno = -1;
	int indiceBorrar;

	if(array != NULL && longitud > 0 && id >= 0){
		indiceBorrar = empleado_buscarIdPunteros(array, longitud, id);
		if (indiceBorrar >= 0) {
			if(!empleado_deleteIndexArrayPunteros(array, longitud, indiceBorrar)){
				retorno = 0;
			}
		}
	}
	return retorno;
}


int empleado_initArrayPunteros(Employee **array, int longitud) {
	int retorno = -1;
	if (array != NULL && longitud > 0) {
		for (int i = 0; i < longitud; i++) {
			array[i] = NULL;
		}
		retorno = 0;
	}
	return retorno;
}

int empleado_deleteIndexArrayPunteros(Employee **array, int limite, int indice) {
	int retorno = -1;
	if (array != NULL && indice >= 0 && indice < limite && array[indice] != NULL) {
		empleado_delete(array[indice]);
		array[indice] = NULL;
		retorno = 0;
	}
	return retorno;
}

int empleado_getEmptyIndexPunteros(Employee** array, int longitud){
	int retorno = -1;

	if(array != NULL && longitud > 0){
		for(int i = 0; i < longitud; i++){
			retorno = -2;
			if(array[i] == NULL){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int empleado_imprimirArray(Employee **array, int longitud) {
	int retorno = -1;

	if (array != NULL && longitud > 0) {
		printf("\n======================= LISTA empleadoS =======================\n");
		for (int i = 0; i < longitud; i++) {
			if (array[i] != NULL) {
				printf("\nNombre: %s -- id: %d -- sueldo: %.2f",
						array[i]->nombre,
						array[i]->id, array[i]->sueldo);
			}
		}
	}
	return retorno;
}

int empleado_imprimir(Employee* empleado) {
	int retorno = -1;

	if (empleado != NULL) {
		printf("\nid: %d -- Nombre: %s -- sueldo: %.2f -- horas trabajadas: %d ",
				empleado->id, empleado->nombre, empleado->sueldo, empleado->horasTrabajadas);
		retorno = 0;
	}
	return retorno;
}



int empleado_cargarArrayPunteros(Employee** array, int longitud, int indice, int* id){
	int retorno = -1;
	char bufferNombre[NOMBRE_LEN];
	int sueldoEmpleado;
	int horasTrabajadas;
	int bufferId;

	if(longitud > 0 && array != NULL && id != NULL && indice >= 0 && indice < longitud){
		if(!utn_getNombre(bufferNombre, NOMBRE_LEN, "\nIngrese nombre del empleado:", "\nError", 3) &&
			!utn_getNumero(&sueldoEmpleado, "\nIngrese sueldo de empleado:", "\nError", 10000,100000, 3) &&
			!utn_getNumero(&horasTrabajadas, "\nIngrese sueldo de empleado:", "\nError", 10000,100000, 3)){

			bufferId = *id;
			if(!empleado_agregarEmpleadoPunteros(array, longitud, indice, bufferNombre, sueldoEmpleado, horasTrabajadas, bufferId)){
				(*id)++;
				retorno = 0;
			}

		}

	}
	return retorno;
}

int empleado_modificarArrayPunteros(Employee** array, int longitud, int indice){
	int retorno = -1;
	char bufferNombre[NOMBRE_LEN];
	float bufferSueldo;
	int opcion;

	if(longitud > 0 && array != NULL && indice >= 0){
		do{
			if(!utn_getNumero(&opcion, "\nModifique: \n1-Nombre \n2-Altura \n3-Salir", "\nError", 1, 3, 3)){
				switch(opcion){
				case 1:
					if(!utn_getNombre(bufferNombre, NOMBRE_LEN, "\nIngrese nombre:", "\nError", 3)){
						empleado_setNombre(array[indice],bufferNombre);
					}
					break;
				case 2:
					if(!utn_getNumeroFlotante(&bufferSueldo, "\nIngrese sueldo:", "\nError", 10000, 100000, 3)){
						empleado_setSueldoFloat(array[indice],bufferSueldo);
					}
					break;
				default:
					printf("\nSaliendo de modificacion");
					break;
				}
			}
		}while(opcion != 3);

	}
	return retorno;
}

int empleado_ordenarPorNombreSueldo(Employee** array, int limite){
	int retorno = -1;
	int i;
	int j;
	Employee* auxempleado;

	if(array != NULL && limite > 0){
		retorno = 0;
		for(i = 0; i < limite - 1; i++){
			for(j = i+1; j < limite; j++){
			if(array[i] == NULL || array[j] == NULL) continue;
			int auxCmp = strncmp(array[i]->nombre, array[j]->nombre, NOMBRE_LEN);
				if(auxCmp > 0 || (auxCmp == 0 && array[i]->sueldo > array[j]->sueldo)){
					auxempleado = array[i];
					array[i] = array[j];
					array[j] = auxempleado;
				}
			}
		}
	}
	return retorno;
}

int empleado_imprimirEmpleadoMayorSueldo(Employee** array, int limite){
	int retorno = -1;
	int i;
	Employee* empleadoMasAlto;
	if(array != NULL && limite > 0){
		for(i = 0; i < limite; i++){
			if(array[i] != NULL && (i == 0 || array[i]->sueldo > empleadoMasAlto->sueldo)){
				empleadoMasAlto = array[i];
				retorno = 0;
			}
		}
		printf("\nempleado con mayor sueldo: %s -- %.2f", empleadoMasAlto->nombre, empleadoMasAlto->sueldo);
	}

	return retorno;
}

int empleado_imprimirPromedioDeSueldos(Employee** array, int limite){
	int retorno = -1;
	int i;
	float acumuladorSueldos = 0;
	float promedioSueldos;
	int contadorempleados = 0;
	if(array != NULL && limite > 0){
		for(i = 0; i < limite; i++){
			if(array[i] != NULL){
				acumuladorSueldos = acumuladorSueldos + array[i]->sueldo;
				contadorempleados++;
			}
		}
		retorno = 0;
		promedioSueldos = acumuladorSueldos/contadorempleados;
		printf("\nPromedio de sueldos: %.2f", promedioSueldos);
	}

	return retorno;
}

int empleado_guardarArrayEnArchivo(Employee** array, int limite, char* pathArchivo){
	int retorno = -1;
	int i;
	float bufferAltura;
	char bufferNombre[NOMBRE_LEN];
	int bufferId;

	FILE* fpArchivo;
	if(array != NULL && limite > 0 && pathArchivo != NULL){
		fpArchivo = fopen(pathArchivo, "w");
		if(fpArchivo != NULL){
			retorno = 0;

			for(i = 0; i < limite; i++){
				if(array[i] != NULL){
					if(!empleado_getSueldoFloat(array[i], &bufferAltura) &&
					   !empleado_getIdInt(array[i], &bufferId) &&
					   !empleado_getNombre(array[i], bufferNombre)){
						fprintf(fpArchivo, "%d, %s, %.2f\n", bufferId, bufferNombre, bufferAltura);
					}
				}
			}
			fclose(fpArchivo);
		}
	}
	return retorno;
}

int empleado_leerArrayEnArchivo(Employee** array, int limite, char* pathArchivo, int* id){
	int retorno = -1;
	char bufferSueldo[4096];
	char bufferNombre[4096];
	char bufferHorasTrabajadas[4096];
	char bufferId[4096];

	FILE* fpArchivo;
	if(array != NULL && limite > 0 && pathArchivo != NULL){
		fpArchivo = fopen(pathArchivo, "r");
		if(fpArchivo != NULL){
			do{
				if(fscanf(fpArchivo,"%[^,], %[^,], %[^\n]\n",bufferId, bufferNombre, bufferSueldo) == 3){
					if(empleado_agregarEmpleadoPunterosTxt(array, limite, bufferNombre, bufferSueldo, bufferHorasTrabajadas, bufferId) >= 0){
						retorno = 0;
						printf("\nAlta ok");
						if(atoi(bufferId) > *id){
							*id = atoi(bufferId) + 1;
						}
					}
				}
			}while(!feof(fpArchivo));
			fclose(fpArchivo);
		}
	}
	return retorno;
}



