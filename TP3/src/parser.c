#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int resultado;
	int retorno = -1;
	Employee* fileEmployee = NULL;
	char buffer[4][20];
	pFile = fopen("data.csv","r");

	fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
	if(pFile != NULL && pArrayListEmployee != NULL){
		do{
			resultado = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
			if(resultado == 4){
				fileEmployee = empleado_newParametrosTxt(buffer[1], buffer[3], buffer[2], buffer[0]);
				if(fileEmployee != NULL){
					ll_add(pArrayListEmployee, fileEmployee);
					retorno = 0;
				}
			}
		}while(!feof(pFile));
	}
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int resultado;
	Employee* auxEmployee;
	if(pArrayListEmployee != NULL){
		while(!feof(pFile)){
			resultado = fread(auxEmployee, sizeof(auxEmployee), 1, pFile);
			auxEmployee = empleado_new();
			if (resultado < 1) {
				if (feof(pFile)) {
					break;
				} else {
					retorno = -1;
					break;
				}
			}
			if(auxEmployee != NULL){
				ll_add(pArrayListEmployee, auxEmployee);
				retorno = 0;
			}else{
				empleado_delete(auxEmployee);
			}

		}
	}
    return retorno;
}
