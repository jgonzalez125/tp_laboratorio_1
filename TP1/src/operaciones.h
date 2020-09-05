/*
 * operaciones.h
 *
 *  Created on: Aug 7, 2020
 *      Author: juang
 */

#ifndef OPERACIONES_H_
#define OPERACIONES_H_

/*
 * Funciom que calcula el factorial de a
 * \param a int a ser factorizado
 * retorna el valor devuelto por la recursion, si el numero es menor a 2 y mayor o igual a 0, devuelve 1
 */
int factorial(int a);

/*
 * Funciom que calcula la suma de a y b
 * \param int a
 * \param int b
 * retorna el valor devuelto por la suma de a y b
 */
int suma(int a, int b);

/*
 * Funciom que calcula la resta entre a y b
 * \param int a
 * \param int b
 * retorna el valor devuelto por la resta de a y b
 */
int resta(int a, int b);

/*
 * Funciom que calcula la multiplicacion de a y b
 * \param int a
 * \param int b
 * retorna el valor devuelto por la multiplicacion de a y b
 */
int multiplicacion(int a, int b);

/*
 * Funciom que calcula la division de a y b
 * \param int a
 * \param int b
 * retorna el valor devuelto por la division de a y b
 */
float division(int a, int b);

#endif /* OPERACIONES_H_ */
