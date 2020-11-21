/*
 * Pedido.h
 *
 *  Created on: Nov 12, 2020
 *      Author: juang
 */

#ifndef PEDIDO_H_
#define PEDIDO_H_
#define DESCRIPCION_LEN 50

typedef struct {
    char descripcion[DESCRIPCION_LEN];
    float precio;
}Pedido;

#endif /* PEDIDO_H_ */
