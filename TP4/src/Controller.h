/*
 * Controller.h
 *
 *  Created on: Oct 28, 2020
 *      Author: juang
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "LinkedList.h"


/**
 * \brief Funcion que aplica los descuentos a las mesas que cumplan con la condicion brindada
 * 		  en el puntero a funcion pasado por parametro
 *
 * \param pFunc puntero a funcion que indica la condicion a cumplirse para aplicar el desc
 * \param pArrayListMesas puntero a lista vinculada a ser mapeada
 *
 * \return retorna 0 if ok, -1 if ERROR
 */
int controller_aplicarDescuento(void* (*pFunc)(void*), LinkedList* pArrayListMesas);

/**
 * \brief Funcion que muestra las mesas filtradas
 *
 * \param pFunc puntero a funcion que indica la condicion a cumplirse para filtrar en la lista
 * \param pArrayListMesas lista vinculada a ser filtrada
 */
int controller_mostrarMesasFiltradas(int (*pFunc)(void*), LinkedList* pArrayListMesas);

/** \brief Carga los datos de las mesas desde el archivo mozo.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListMesas LinkedList*
 * \return retorna 0 if ok, -1 if ERROR
 *
 */
int controller_cargarDeTexto(char* path , LinkedList* pArrayListMesas);

/** \brief Alta de mesa
 *
 * \param pArrayListMesas LinkedList*
 *
 * \return retorna 0 if OK, -1 if ERROR
 */
int controller_agregarMesa(LinkedList* pArrayListMesas);

/** \brief Modificar datos de mesas
 *
 * \param pArrayListMesas LinkedList*
 * \return retorna 0 if OK, -1 if ERROR
 *
 */
int controller_editarMesa(LinkedList* pArrayListMesas);

/** \brief Baja de mesa
 *
 * \param pArrayListMesas LinkedList*
 * \return retorna 0 if OK, -1 if ERROR
 *
 */
int controller_borrarMesa(LinkedList* pArrayListMesas);

/** \brief Listar mesas
 *
 * \param path char*
 * \param pArrayListMesas LinkedList*
 * \return int
 *
 */
int controller_ListarMesas(LinkedList* pArrayListMesas);

/** \brief Listar mozos
 *
 * \param path char*
 * \param pArrayListMesas LinkedList*
 * \return int
 *
 */
int controller_ListarMozos(LinkedList* pArrayListMozos);

/** \brief Ordenar mesas
 *
 * \param path char*
 * \param pArrayListMesas LinkedList*
 * \return int
 *
 */
int controller_ordenarMesas(LinkedList* pArrayListMesas);

/** \brief Guarda los datos de las mesas en el archivo mesa.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListMesas LinkedList*
 * \return int
 */
int controller_guardarComoTexto(char* path , LinkedList* pArrayListMesas);



#endif /* CONTROLLER_H_ */
