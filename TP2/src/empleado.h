/*
 * empleado.h
 *
 *  Created on: Aug 8, 2020
 *      Author: juang
 */

#ifndef EMPLEADO_H_
#define EMPLEADO_H_
#define NOMBRE_LEN 100

typedef struct {
	int id;
	char nombre[NOMBRE_LEN];
	char apellido[NOMBRE_LEN];
	float salario;
	int sector;
	int isEmpty;
}Empleado;


int emp_altaForzada(Empleado *array, int longitud, int indice, char* nombre, char* apellido, float salario, int sector, int* id);
/*
 * \brief Funcion para cargar un array de empleados
 *
 * \param pProducto puntero a la direccion de memoria del empleado a ser cargado
 * \param longitud tamanio del array de Producto
 * \param indice indice a ser cargado
 * \param id puntero a la direccion de memoria del id a ser autoincrementado
 */
int emp_cargarArray(Empleado* array, int longitud, int indice, int* id);

/*
 * \brief Funcion para imprimir un empleado
 *
 * \param pProducto puntero a la direccion de memoria del empleado a ser impreso
 */
int emp_imprimir(Empleado* array);

/*
 * \brief Funcion para imprimir un array
 *
 * \param pProducto puntero a la direccion de memoria del array cliente a ser impreso
 * \param longitud longitud del array a ser impreso
 */
int emp_imprimirArray(Empleado* array, int longitud);


/*
 * \brief Funcion para eliminar un indice seteando el campo isEmpty en 1 (TRUE)
 *
 * \param pProducto puntero a la direccion de memoria del indice de empleado a ser eliminado
 * \param longitud tamanio del array de Empleado
 * \param indice indice a ser buscado
 */
int emp_bajaArray(Empleado* array, int longitud, int indice);

/*
 * \brief Funcion para encontrar un cliente por id
 *
 * \param array puntero a la direccion de memoria del array
 * \param longitud tamanio del array de Empleado
 * \param idBuscado id del cliente a ser buscado
 */
int emp_buscarId(Empleado* array, int limite, int idBuscado);

/*
 * \brief Funcion para modificar un campo del cliente
 *
 * \param pProducto puntero a la direccion de memoria del cliente a ser modificado
 * \param longitud tamanio del array de Empleado
 * \param indice indice a ser buscado
 */
int emp_modificarArray(Empleado* array, int longitud, int indice);

/*
 * \brief Funcion para ordenar por nombre y/o altura de menor a mayor
 *
 * \param array puntero a la direccion de memoria del cliente a ser inicializado
 * \param longitud tamanio del array de Empleado
 */
int emp_ordenarPorApellidoSector(Empleado* array, int limite);

/*
 * \brief Funcion para inicializar un array Empleado poniendo el campo isEmpty en TRUE (1)
 *
 * \param array puntero a la direccion de memoria del cliente a ser inicializado
 * \param longitud tamanio del array de Empleado
 */
int emp_initArray(Empleado* array, int longitud);

/*
 * \brief Funcion para chequear el primer indice que se encuentre vacio
 *
 * \param array puntero a la direccion de memoria del empleado
 * \param longitud tamanio del array de Empleado
 *
 * \return retorna el indice vacio, -1 if ERROR
 */
int emp_encontrarIndiceVacio(Empleado* array, int longitud);

/*
 * \brief Funcion para calcular el salario promedio entre todos los empleados
 *
 * \param array puntero a la direccion de memoria del array de empleados
 * \param longitud tamanio del array de Empleado
 * \param contadorEmpleados cantidad de empleados cargados
 *
 * \return retorna el indice vacio, -1 if ERROR
 */
float emp_calcularPromedio(Empleado* array, int limite, int contadorEmpleados);

/*
 * \brief Funcion para calcular cuantos empleados superan el salario promedio
 * \param array puntero a la direccion de memoria del array de empleados
 * \param longitud tamanio del array de Empleado
 * \param contadorEmpleados cantidad de empleados cargados
 * \return retorna el indice vacio, -1 if ERROR
 */
int emp_superaPromedio(Empleado* array, int limite, int contadorEmpleados);

#endif /* EMPLEADO_H_ */
