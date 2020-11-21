/*
 * Mozo.h
 *
 *  Created on: Nov 18, 2020
 *      Author: juang
 */

#ifndef MOZO_H_
#define MOZO_H_
#define NOMBRE_LEN 50

typedef struct {
	int id;
	char nombre[NOMBRE_LEN];
}Mozo;

/*
 * \brief Funcion que devuelve la cantidad de espacio en memoria
 *        necesario para una entidad Mozo
 *
 * \return retorna NULL if ERROR, Mozo* if OK
 */
Mozo* mozo_new();


/*
 * \brief Funcion que establece los parametros para cada Mozo nuevo
 *
 * \param char* nombre cadena de caracteres que seria el nombre ingresado
 * \param char* id numero a alojar el id del Mesa
 * \return retorna un puntero a un Mozo if OK, NULL if ERROR
 */
Mozo* mozo_newParametrosTxt(char* nombre, char* id);

/*
 * \brief Funcion que libera la memoria alocada para un Mozo*
 *
 * \param this puntero a la memoria de la entidad a ser liberada
 */
void mozo_delete(Mozo* this);

/**
 * Setters
 *
 * setean los campos indicados en el nombre de las funciones
 */
int mozo_setIdTxt(Mozo* this, char* id);
int mozo_setNombre(Mozo* this, char* nombre);

/*
 * \brief Funcion que imprime la entidad
 *
 * \param this puntero a la memoria de la entidad a ser impresa
 *
 * \return retorna 0 if OK, -1 if ERROR
 */
int mozo_imprimir(Mozo* this);
#endif /* MOZO_H_ */
