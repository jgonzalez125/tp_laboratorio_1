/*
 * operaciones.c
 *
 *  Created on: Aug 7, 2020
 *      Author: juang
 */
#include <stdio.h>
#include <stdlib.h>

int suma(int a, int b, int* resultado){
	*resultado = a+b;
	return *resultado;
}

int resta(int a, int b, int* resultado){
	*resultado = a-b;
	return *resultado;
}

int multiplicacion(int a, int b, int* resultado){
	*resultado = a*b;
	return a*b;

}

float division(int a, int b, float* resultado){
	if(b != 0){
		*resultado = (float)a/b;
	}
	return *resultado;
}

int factorial(int a, int* resultado){
	*resultado = -1;
	if(a >= 0){
		if (a < 2) {
			*resultado = 1;
		} else {
			*resultado = a * factorial(a - 1, resultado);
		}
	}
	return *resultado;
}

