#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#define NOMBRE_LEN 50
typedef struct
{
    int id;
    int horasTrabajadas;
    float sueldo;
    char nombre[NOMBRE_LEN];
}Employee;

/*
 * \brief Funcion que aloca el espacio de memoria para un Employee
 *
 * \return retorna un puntero a void con el espacio suficiente para alojar a un Employee, sino NULL
 */
Employee* empleado_new();

/*
 * \brief Funcion que establece los parametros para cada Employee nuevo
 *
 * \param char* nombre cadena de caracteres que seria el nombre ingresado
 * \param float sueldo numero flotante a alojar la sueldo ingresada
 * \param int horasTrabajadas numero int a alojar las horas trabajadas
 * \param int id numero a alojar el id del Employee
 * \return retorna un puntero a un Employee en caso de haberse podido alocar la memoria, sino NULL
 */
Employee* empleado_newParametros(char* nombre, float sueldo, int horasTrabajadas, int id);

/*
 * \brief Funcion que establece los parametros para cada Employee nuevo
 *
 * \param char* nombre cadena de caracteres que seria el nombre ingresado
 * \param char* sueldo numero flotante a alojar la sueldo ingresada
 * \param char* id numero a alojar el id del Employee
 * \return retorna un puntero a un Employee en caso de haberse podido alocar la memoria, sino NULL
 */
Employee* empleado_newParametrosTxt(char* nombre, char* sueldo, char* horasTrabajadas, char* id);
/*
 * \brief Funcion que elimina un Employee y libera ese espacio de memoria
 *
 * \param Employee* this puntero a la direccion de memoria a ser liberada
 */
void empleado_delete(Employee* this);

int empleado_imprimir(Employee* empleado);

int empleado_initArrayPunteros(Employee **array, int longitud);

/*
 * \brief Funcion que imprime el promedio de sueldos
 *
 * \param empleado** array puntero al array de punteros
 * \param int limite tamanio del array de punteros
 * \return retorna 0 if OK -1 if ERROR
 */
int empleado_imprimirPromedioDesueldos(Employee** array, int limite);

/*
 * \brief Funcion que imprime al Employee mas alto
 *
 * \param Employee** array puntero al array de punteros
 * \param int limite tamanio del array de punteros
 * \return retorna 0 if OK -1 if ERROR
 */
int empleado_imprimirEmpleadoMasAlto(Employee** array, int limite);


int empleado_ordenarPorNombre(void* actual,void* siguiente);
int empleado_ordenarPorId(void* actual,void* siguiente);
int empleado_ordenarPorHorasTrabajadas(void* actual,void* siguiente);
int empleado_ordenarPorSueldo(void* actual,void* siguiente);

/*
 * \brief Funcion que modifica un Employee especifico
 *
 * \param Employee** array puntero al array de punteros
 * \param int limite tamanio del array de punteros
 * \param int indice indice del puntero a ser modificado
 * \return retorna 0 if OK -1 if ERROR
 */
int empleado_modificarArrayPunteros(Employee** array, int longitud, int indice);

/*
 * \brief Funcion que agrega un Employee al array
 *
 * \param Employee** array puntero al array de punteros
 * \param int limite tamanio del array de punteros
 * \param int indice indice del array de punteros donde va a ser ingresado
 * \param char* nombre cadena de caracteres que seria el nombre ingresado
 * \param int sueldo numero flotante a alojar la sueldo ingresada
 * \param int id numero a alojar el id del Employee
 * \return retorna 0 if OK -1 if ERROR
 */
int empleado_agregarEmpleadoPunteros(Employee** array, int longitud, int indice, char* nombre, int sueldo, int horasTrabajadas, int id);
/*
 * \brief Funcion que elimina a un Employee por id
 *
 * \param Employee** array puntero al array de punteros
 * \param int limite tamanio del array de punteros
 * \param int id indice del puntero a ser modificado
 * \return retorna 0 if OK -1 if ERROR
 */
int empleado_borrarEmpleadoPunteros(Employee** array, int longitud, int id);

/*
 * \brief Funcion que busca el id de un Employee
 *
 * \param Employee** array puntero al array de punteros
 * \param int limite tamanio del array de punteros
 * \param int id indice del puntero a ser modificado
 * \return retorna el indice donde se encuentra el id
 */
int empleado_buscarIdPunteros(Employee** array, int longitud, int id);

/*
 * \brief Funcion que elimina el indice donde se almacena el Employee
 *
 * \param Employee** array puntero al array de punteros
 * \param int limite tamanio del array de punteros
 * \param int indice indice del puntero a ser eliminado
 * \return retorna 0 if OK -1 if ERROR
 */
int empleado_deleteIndexArrayPunteros(Employee **array, int limite, int indice);

/*
 * \brief Funcion que imprime el array
 *
 * \param Employee** array puntero al array de punteros
 * \param int limite tamanio del array de punteros
 * \return retorna 0 if OK -1 if ERROR
 */
int empleado_imprimirArray(Employee **array, int longitud);

/*
 * \brief Funcion que inicializa el array
 *
 * \param Employee** array puntero al array de punteros
 * \param int limite tamanio del array de punteros
 * \return retorna 0 if OK -1 if ERROR
 */
int Eempleado_initArrayPunteros(Employee **array, int longitud);

/*
 * \brief Funcion que obtiene el primer indice vacio que encuentre el array
 *
 * \param Employee** array puntero al array de punteros
 * \param int limite tamanio del array de punteros
 * \return retorna el valor del indice vacio
 */
int empleado_getEmptyIndexPunteros(Employee** array, int longitud);

/*
 * \brief Funcion que para cargar los datos del Employee
 *
 * \param Employee** array puntero al array de punteros
 * \param int longitud tamanio del array de punteros
 * \param int indice indice donde se va a guardar el Employee
 * \param int* id puntero a la direccion de memoria del id correspondiente
 * \return retorna 0 if OK -1 if ERROR
 */
int empleado_cargarArrayPunteros(Employee** array, int longitud, int indice, int* id);

/*
 * Setters y getters
 *
 * Modifican y obtienen (respectivamente) los datos indicados en el nombre de cada funcion
 */

int empleado_setIdTxt(Employee* this,char* id);
int empleado_setIdInt(Employee* this,int id);
int empleado_getIdInt(Employee* this,int* id);

int empleado_setNombre(Employee* this,char* nombre);
int empleado_getNombre(Employee* this,char* nombre);

int empleado_setHorasTrabajadasTxt(Employee* this,char* horasTrabajadas);
int empleado_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int empleado_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int empleado_setSueldoFloat(Employee* this,float sueldo);
int empleado_setSueldoTxt(Employee* this,char* sueldo);
int empleado_getSueldoFloat(Employee* this,float* sueldo);
int empleado_getSueldoTxt(Employee* this,char* sueldo);

#endif // employee_H_INCLUDED
