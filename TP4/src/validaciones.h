/*
 * validaciones.h
 *
 *  Created on: Sep 12, 2020
 *      Author: juang
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

/**
 * \brief Lee la cadena para chequear que los caracteres sean alfabeticos
 * \param cadena: cadena de caracteres a confirmar si es una cadena solo numerica
 * \param longitud tamanio del string a ser obtenido
 * \n return: retorna 0 if OK y -1 if ERROR
 */
int esNombre(char* cadena, int longitud);

/**
 * \brief Lee la cadena para chequear que el caracter no sea mayor a '9' y menor a '0' y que contenga un solo '.'
 * \param cadena: cadena de caracteres a confirmar si es una cadena solo numerica decimal
 * \n return: retorna 0 if OK y -1 if ERROR
 */
int esNumericaFloat(char cadena[], int longitud);

/**
 * \brief Lee la cadena para chequear que el caracter no sea mayor a '9' y menor a '0'
 * \param cadena: cadena de caracteres a confirmar si es una cadena solo numerica
 * \n return: retorna 0 if OK y -1 if ERROR
 */
int esNumerica(char cadena[], int longitud);

#endif /* VALIDACIONES_H_ */
