/*
 ============================================================================
 Name        : trabajoPractico4.c
 Author      : Gonzalez Conti Juan Pablo
 Version     :
 Copyright   : Your copyright notice
 Description : Sistema ABM de mesas de restaurante


 Entidades:
 1- Mesa
    - int clientes
    - Pedido pedido
    - int idMesa
    - int idMozo

2- Pedido
    - char descripcion[]
    - float precio

3- Mozo (cargados desde mozo.csv)
    - char nombre[]
    - int id


*************************************************************************************
 * Este programa tiene como objetivo emular un sistema de mesas de restaurante
 * contando con un archivo previamente cargado de mozos en su sistema
 * y la posibilidad de agregar, modificar y eliminar mesas de su sistema, para luego
 * guardarlas en su archivo correspondiente.
 *
 *
 * NOTAS:
 * - Una vez cerrado el sistema, el usuario no podra volver a ingresar datos
 * - Puede cerrar el sistema si no ingreso mesas
    Menu:
     1. Cargar los datos de los mozos desde el archivo mozo.csv. (apertura)
     2. Alta de Mesa
     3. Modificar datos de la mesa
     4. Baja de mesa
     5. Listar mesas ocupadas
     6. Ordenar mesas por criterio (cant clientes, importe, id)
     7. Guardar los datos de las mesas de cada dia en el archivo mesas<fecha>.csv.
	 8. Aplicar descuentos del 20% a las mesas con mas de 5 clientes
	 9. Informes: (Cierre de sistema)
        - Informa mesas con pedidos mayores a $1000
        - Mesas a las que se aplico descuento
     10. Salir
*************************************************************************************
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int main(void) {
	menu();

	return 0;
}
