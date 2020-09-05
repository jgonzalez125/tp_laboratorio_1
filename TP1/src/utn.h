/*
 * utn.h
 *
 *  Created on: Jul 5, 2020
 *      Author: juang
 */

#ifndef UTN_H_
#define UTN_H_

/*
 * \brief Funcion para conseguir un numero int
 * \param  int* pResultado, puntero a direccion de memoria del numero
 * \param char* mensaje, puntero a direccion de memoria a ser alojado el mensaje de ingreso
 * \param char* mensajeError, puntero a direccion de memoria a ser alojado el mensaje de error en caso de haberse
 * \param int minimo, numero minimo que podria ingresarse
 * \param int maximo, numero maximo que podria ingresarse
 * \param int reintentos, cantidad de oportunidades
 *
 * retorna 0 if OK, -1 if ERROR
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

#endif /* UTN_H_ */
