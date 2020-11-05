#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "Employee.h"
#include "utn.h"
#define NOMBRE_TAM 25



/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee* auxEmpleado;

	if(pArrayListEmployee != NULL){
		for(int i = 0; i < ll_len(pArrayListEmployee); i++){
			auxEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
			if(auxEmpleado != NULL){
				empleado_imprimir(auxEmpleado);
			}
		}
		retorno = 0;
	}
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE *pFile;

	if (path != NULL && pArrayListEmployee != NULL) {
		pFile = fopen(path, "r");
		if (pFile != NULL) {
			if (!parser_EmployeeFromText(pFile, pArrayListEmployee)) {
				printf("\nLeido exitosamente\n");
				retorno = 0;
			} else {
				printf("\nError, mal leido");
			}
		}
	}
	return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE *pFile;

	if (path != NULL && pArrayListEmployee != NULL) {
		pFile = fopen(path, "rb");
		if (pFile != NULL) {
			if (!parser_EmployeeFromBinary(pFile, pArrayListEmployee)) {
				printf("\nLeido exitosamente\n");
				fclose(pFile);
				retorno = 0;
			} else {
				printf("\nError, no se pudo cargar");
			}
		}
	}
	return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;

	//variables auxiliares
	float sueldoAux;
	int auxId;
	char nombreAux[NOMBRE_TAM];
	int horasTrabajadasAux;

	static Employee* nuevoEmpleado = NULL;

	if(pArrayListEmployee != NULL){

		auxId = ll_incrementId(pArrayListEmployee);
			if(!utn_getNombre(nombreAux, NOMBRE_TAM, "\nIngrese nombre:", "\nError", 3) &&
				!utn_getNumeroFlotante(&sueldoAux, "\nIngrese sueldo: (10000 - 100000)", "\nError, reingrese", 10000, 100000, 3) &&
				!utn_getNumero(&horasTrabajadasAux, "\nIngrese horas trabajadas (mensuales)", "\nError, reingrese", 1, 1000, 3)){
				nuevoEmpleado = empleado_newParametros(nombreAux, sueldoAux, horasTrabajadasAux, auxId);
				if(nuevoEmpleado != NULL){
					if(!ll_add(pArrayListEmployee, nuevoEmpleado)){
						printf("\nCarga realizada correctamente");
						retorno = 0;
					}
				}else{
					printf("\nNo se pudo setear los datos");
				}
			}
	}
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int opcion;

	//auxiliares
	int auxiliarId;
	Employee* auxEmpleado;

	// variables buffers
	int bufferId;
	char bufferNombre[NOMBRE_TAM];
	float bufferSueldo;
	int bufferHorasTrabajadas;
	int ll_len = ll_incrementId(pArrayListEmployee);

	controller_ListEmployee(pArrayListEmployee);
	if(pArrayListEmployee != NULL){
		if(!utn_getNumero(&auxiliarId, "\nIngrese id de empleado a modificar", "\nError, reingrese", 1, 100000, 3)){
			for(int i = 0; i < ll_len; i++){
				auxEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
				empleado_getIdInt(auxEmpleado, &bufferId);

				if(auxiliarId == bufferId){
					do{
						if(!empleado_imprimir(auxEmpleado) && !utn_getNumero(&opcion, "\nModifique: \n1-Nombre \n2-Sueldo\n3-Horas trabajadas \n4-Salir", "\nError", 1, 4, 3)){
							switch(opcion){
							case 1:
								if(!utn_getNombre(bufferNombre, NOMBRE_TAM, "\nIngrese nombre:", "\nError", 3)){
									if(!empleado_setNombre(auxEmpleado, bufferNombre)){
										printf("\nNombre modificado exitosamente");
									}
								}
								break;
							case 2:
								if(!utn_getNumeroFlotante(&bufferSueldo, "\nIngrese sueldo: (10000 - 100000)", "\nError", 10000, 100000, 3)){
									if(!empleado_setSueldoFloat(auxEmpleado, bufferSueldo)){
										printf("\nSueldo modificado exitosamente");
									}
								}
								break;
							case 3:
								if(!utn_getNumero(&bufferHorasTrabajadas, "\nIngrese horas trabajadas:", "\nError", 1, 1000, 3)){
									if(!empleado_setHorasTrabajadas(auxEmpleado, bufferHorasTrabajadas)){
										printf("\nHoras trabajadas modificadas exitosamente");
									}
								}
								break;
							case 4:
								printf("\nSaliendo de modificacion");
								break;
							}
						}
					}while(opcion != 4);
				}
				retorno = 0;
			}
		}
	}
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int auxiliarId;
	int bufferId;
	Employee* auxEmpleado;
	int ll_len = ll_incrementId(pArrayListEmployee);

	controller_ListEmployee(pArrayListEmployee);
	if(pArrayListEmployee != NULL){
		if(!utn_getNumero(&auxiliarId, "\nIngrese id de empleado a dar de baja", "\nError, reingrese", 1, ll_len - 1, 3)){
			for(int i = 0; i < ll_len; i++){
				auxEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
				empleado_getIdInt(auxEmpleado, &bufferId);

				if(bufferId == auxiliarId){
					printf("\nEmpleado a ser eliminado: ");
					empleado_imprimir(auxEmpleado);
					if(!ll_remove(pArrayListEmployee, i)){
						printf("\nEmpleado eliminado exitosamente");
						retorno = 0;
						break;
					}
				}
			}
		}
	}
    return retorno;
}
/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int opcion;
	int criterio;
	if(pArrayListEmployee != NULL){
		do{
			if (!utn_getNumero(&opcion, "\nIngrese un opcion:"
					"\n1.Ordenar por Nombre."
					"\n2.Ordenar por horas trabajadas."
					"\n3.Ordenar por sueldo."
					"\n4.Ordenar por Id"
					"\n5.Salir ", "Opcion invalida", 1, 5, 3)) {
				if(opcion != 5){
					utn_getNumero(&criterio,
							"\nDe manera ascendente (1) o descendente (0)",
							"\nError, reingrese", 0, 1, 3);
				}
					switch (opcion) {
					case 1:
						ll_sort(pArrayListEmployee, empleado_ordenarPorNombre,
								criterio);
						break;
					case 2:
						ll_sort(pArrayListEmployee,
								empleado_ordenarPorHorasTrabajadas, criterio);
						break;
					case 3:
						ll_sort(pArrayListEmployee, empleado_ordenarPorSueldo,
								criterio);
						break;
					case 4:
						ll_sort(pArrayListEmployee, empleado_ordenarPorId,
								criterio);
						break;
					case 5:
						printf("\nSaliendo de menu de ordenamiento...");
						break;
					}
			}

		} while (opcion != 5);
	}
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int i;

	//Variables buffer
	float bufferSueldo;
	int bufferHorasTrabajadas;
	char bufferNombre[NOMBRE_LEN];
	int bufferId;

	//Aux variables
	Employee* auxEmployee;
	FILE* fpArchivo;

	if(pArrayListEmployee != NULL && path != NULL){
		fpArchivo = fopen(path, "w");
		if(fpArchivo != NULL){
			fprintf(fpArchivo, "id,nombre,horasTrabajadas,sueldo\n");
			for(i = 0; i < ll_len(pArrayListEmployee); i++){
				auxEmployee = ll_get(pArrayListEmployee, i);
				if(pArrayListEmployee != NULL){
					if(!empleado_getSueldoFloat(auxEmployee, &bufferSueldo) &&
					   !empleado_getIdInt(auxEmployee, &bufferId) &&
					   !empleado_getNombre(auxEmployee, bufferNombre) &&
					   !empleado_getHorasTrabajadas(auxEmployee, &bufferHorasTrabajadas)){
						fprintf(fpArchivo, "%d,%s,%d,%.2f\n", bufferId, bufferNombre, bufferHorasTrabajadas, bufferSueldo);
					}else{
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

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char *path, LinkedList *pArrayListEmployee) {
	int retorno = -1;
	FILE *pFile;
	Employee *binaryEmployee;
	int i;

	if (path != NULL && pArrayListEmployee != NULL && ll_len(pArrayListEmployee)) {
			if ((pFile = fopen(path, "wb")) != NULL) {
				printf("\nAbierto Exitosamente");
				for (i = 0; i < ll_len(pArrayListEmployee); i++) {
					binaryEmployee = ll_get(pArrayListEmployee, i);
					if (binaryEmployee != NULL) {
						fwrite(binaryEmployee, sizeof(Employee), 1, pFile);
						retorno = 0;
					}
				}
				fclose(pFile);
			}
		printf("\nDatos .bin guardados");
	} else {
		printf("\nNo se pudo guardar");
	}
	return retorno;
}

