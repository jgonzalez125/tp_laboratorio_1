/*
 * menu.c
 *
 *  Created on: Aug 7, 2020
 *      Author: juang
 */
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "operaciones.h"

void menu(){
	int opcion;
	int num1;
	int num2;
	int resultadoSuma;
	int resultadoResta;
	int resultadoMultiplicacion;
	int resultadoFactorialUno;
	int resultadoFactorialDos;
	float resultadoDiv;
	int resultadoUno;
	int resultadoDos;
	int valorOpcion;


	do{
		setbuf(stdout, NULL);
		if(!utn_getNumero(&opcion, "\n1)Ingresar 1er operando (A=x)"
									"\n2)Ingresar 2do operando (B=y)"
									"\n3)Calcular todas las operaciones (+, -, *, /, !)"
									"\n4)Informar resultados"
									"\n5)Salir\n", "\nError", 1, 5, 3)){
			switch(opcion){
			case 1:
				resultadoUno = utn_getNumero(&num1, "\nIngrese operador:", "\nIngrese operando:", -1000, 1000000, 3);
				valorOpcion = opcion;
				//opcion 1
				break;
			case 2:
				if(valorOpcion != 1){
					printf("\nDebe ingresar el primer operando");
				}else{
					resultadoDos = utn_getNumero(&num2, "\nIngrese operador:", "\nIngrese operando:", -1000, 1000000, 3);
					valorOpcion = opcion;
				}
				//opcion 2
				break;
			case 3:
				if(valorOpcion != 2){
					printf("\nDebe ingresar los dos operandos");
				}else{
					printf("\nCalculando...");
					valorOpcion = opcion;
					resultadoSuma = suma(num1, num2);
					resultadoResta = resta(num1, num2);
					resultadoMultiplicacion = multiplicacion(num1, num2);
					resultadoFactorialUno = factorial(num1);
					resultadoFactorialDos = factorial(num2);
					if(num2 != 0){
						resultadoDiv = division(num1, num2);
					}else{
						printf("\nNo se puede dividir por 0");
					}
					if(resultadoFactorialUno == -1){
						printf("\nEl numero %d es menor a 0, no se puede hacer factorial, resultado por defecto -1", num1);
					}
					if(resultadoFactorialDos == -1){
						printf("\nEl numero %d es menor a 0, no se puede hacer factorial, resultado por defecto -1", num2);
					}
				}
				//opcion 3
				break;
			case 4:
				if(valorOpcion != 3 && valorOpcion != 4){
					printf("\nDebe calcular previo a mostrar los resultados");
				}else{
					valorOpcion = opcion;
					if(num2 == 0){
						printf("\nSuma: %d"
								"\nResta: %d"
								"\nMultiplicacion: %d"
								"\nDivision: SYNTAX ERROR"
								"\nFactorial %d: %d"
								"\nFactorial %d: %d\n", resultadoSuma, resultadoResta, resultadoMultiplicacion, num1, resultadoFactorialUno, num2, resultadoFactorialDos);
						//opcion 4
					}else{

						printf("\nSuma: %d"
								"\nResta: %d"
								"\nMultiplicacion: %d"
								"\nDivision: %.2f"
								"\nFactorial %d: %d"
								"\nFactorial %d: %d\n", resultadoSuma, resultadoResta, resultadoMultiplicacion, resultadoDiv, num1, resultadoFactorialUno, num2, resultadoFactorialDos);
						//opcion 4
					}
				}
				break;
			}
		}
	}while(opcion != 5);
}
