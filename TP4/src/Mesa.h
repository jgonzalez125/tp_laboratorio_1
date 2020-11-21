#ifndef mesa_H_INCLUDED
#define mesa_H_INCLUDED
#define DESCRIPCION_LEN 50
#include "Pedido.h"


typedef struct {
    int clientes;
    Pedido pedido;
    int idMesa;
    int idMozo;
    int tuvoDescuento;
}Mesa;

/*
 * \brief Funcion que aloca el espacio de memoria para una Mesa
 *
 * \return retorna un puntero a void con el espacio suficiente para alojar a una Mesa, sino NULL
 */
Mesa* mesa_new();

/*
 * \brief Funcion que establece los parametros para cada Mesa nueva
 *
 * \param char* nombre cadena de caracteres que seria el nombre ingresado
 * \param float sueldo numero flotante a alojar la sueldo ingresada
 * \param int horasTrabajadas numero int a alojar las horas trabajadas
 * \param int id numero a alojar el id del Mesa
 * \return retorna un puntero a un Mesa en caso de haberse podido alocar la memoria, sino NULL
 */
Mesa* mesa_newParametros(int clientes, Pedido pedido, int idMozo, int id);

/*
 * \brief Funcion que establece los parametros para cada Mesa nueva
 *
 * \param char* nombre cadena de caracteres que seria el nombre ingresado
 * \param char* sueldo numero flotante a alojar la sueldo ingresada
 * \param char* id numero a alojar el id del Mesa
 * \return retorna un puntero a un Mesa en caso de haberse podido alocar la memoria, sino NULL
 */
Mesa* mesa_newParametrosTxt(char* nombre, char* sueldo, char* horasTrabajadas, char* id);

/*
 * \brief Funcion que elimina una Mesa y libera ese espacio de memoria
 *
 * \param Mesa* this puntero a la direccion de memoria a ser liberada
 */
void mesa_delete(Mesa* this);

/*
 * \brief Funcion que imprime la mesa pasada por parametros
 *
 * \param mesa this puntero a la direccion de memoria de la entidad a ser mostrada
 */
int mesa_imprimir(Mesa* mesa);

/*
 * \brief Funciones que filtran cada elemento por el criterio indicado
 *        en el nombre de la funcion
 *
 * \param pElement puntero a void a ser casteado como Mesa*
 *
 * \return retorna 0 if no se filtro, 1 si se filtro
 */
int mesa_filtrarMesasPorPrecio(void* pElement);
int mesa_filtrarMesasPorClientes(void* pElement);

/*
 * \brief Funcion que aplica el descuento del 20% a las mesas con mas
 *        de 10 clientes
 *
 * \param pElement puntero a void a ser casteado como Mesa*
 *
 * \return retorna el puntero a Mesa if OK, NULL if ERROR
 */
void* mesa_aplicarDescuento(void* pElement);


/*
 * \brief Funciones de ordenamiento por criterio indicado
 *        en el nombre de la funcion
 *
 * \param actual puntero a void que indica la posicion a comparar
 * \param siguiente puntero a void que indica la posicion a comparar
 * \return retorna 0 if actual > siguiente, 1 if actual < siguiente, -1 if error
 */
int mesa_ordenarPorId(void* actual,void* siguiente);
int mesa_ordenarPorPrecio(void* actual,void* siguiente);
int mesa_ordenarPorClientes(void* actual,void* siguiente);

/*
 * Setters y getters
 *
 * Modifican y obtienen (respectivamente) los datos indicados en el nombre de cada funcion
 *
 * \return retornan 0 IF OK, -1 if ERROR
 */

/*
 * funciones de pedido
 */
int mesa_setPedido(Mesa* this, Pedido pedido);
int mesa_getPedido(Mesa* this, Pedido* pedido);

/*
 * funciones de idMozo
 */
int mesa_setIdMozoInt(Mesa* this, int idMozo);
int mesa_getIdMozoInt(Mesa* this, int* idMozo);

/*
 * funciones de id
 */
int mesa_setIdTxt(Mesa* this, char* id);
int mesa_setIdInt(Mesa* this, int id);
int mesa_getIdTxt(Mesa* this, char* id);
int mesa_getIdInt(Mesa* this, int* id);

/*
 * funciones de clientes
 */
int mesa_setClientes(Mesa* this,int clientes);
int mesa_setClientesTxt(Mesa* this,char* clientes);
int mesa_getClientes(Mesa* this,int* clientes);



#endif // mesa_H_INCLUDED
