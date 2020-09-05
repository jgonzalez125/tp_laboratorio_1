/*
 * operaciones.c
 *
 *  Created on: Aug 7, 2020
 *      Author: juang
 */
#include <stdio.h>
#include <stdlib.h>

int suma(int a, int b){
	return a+b;
}

int resta(int a, int b){
	return a-b;
}

int multiplicacion(int a, int b){
	return a*b;

}

float division(int a, int b){
	float retorno = -1;
	if(b != 0){
		retorno = (float)a/b;
	}
	return retorno;
}

int factorial(int a){
	int retorno = -1;
	if(a >= 0){
		if (a < 2) {
			retorno = 1;
		} else {
			retorno = a * factorial(a - 1);
		}
	}
	return retorno;
}

