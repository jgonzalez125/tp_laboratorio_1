/*
 * LinkedList.c
 *
 *  Created on: Oct 3, 2020
 *      Author: juang
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Mesa.h"

/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex);

/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

LinkedList* ll_newLinkedList(void)
{
    LinkedList* this = NULL;
    this = (LinkedList*) malloc(sizeof(LinkedList));
    if(this != NULL){
    	this->size = 0;
    	this->pFirstNode = NULL;
    }
    return this;
}

int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL){
    	returnAux = this->size;
    }
    return returnAux;
}

static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNode = NULL;
	int i;
	if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this)){
		pNode = this->pFirstNode;
		for (i = 0; i < nodeIndex; i++) {
			pNode = pNode->pNextNode;
		}
	}
    return pNode;
}

Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* newNode = (Node*)malloc(sizeof(Node));
    Node* prevNode = NULL;

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this) && newNode != NULL){
    	newNode->pElement = pElement;
    	newNode->pNextNode = NULL;

    	if(!nodeIndex){
    		newNode->pNextNode = this->pFirstNode;
    		this->pFirstNode = newNode;
    	}else{
			prevNode = getNode(this, nodeIndex - 1);
			newNode->pNextNode = prevNode->pNextNode;
			prevNode->pNextNode = newNode;
    	}
    	this->size++;
    	returnAux = 0;
    }
    return returnAux;
}

int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}

int ll_add(LinkedList* this, void* pElement)
{
    return addNode(this, ll_len(this), pElement);
}

void* ll_get(LinkedList* this, int index)
{
	void *returnAux = NULL;
	Node *auxNode = NULL;

	auxNode = getNode(this, index);
	if(auxNode != NULL){
		returnAux =  auxNode->pElement;
	}

	return returnAux;
}

int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* auxNode = NULL;

	auxNode = getNode(this, index);
	if(auxNode != NULL){
		auxNode->pElement = pElement;
	}

    return returnAux;
}

int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* actualNode = NULL;
    Node* prevNode;

    actualNode = getNode(this, index);

    if(actualNode != NULL) {
		if (!index) {
			this->pFirstNode = actualNode->pNextNode;
			this->size--;
			free(actualNode);
			returnAux = 0;
		} else {
			prevNode = getNode(this, index - 1);
			if(prevNode != NULL){
				prevNode->pNextNode = actualNode->pNextNode;
				this->size--;
				free(actualNode);
				returnAux = 0;
			}

		}

    }
    return returnAux;
}

int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL && ll_len(this) > 0){
    	for(int i = 0; i < ll_len(this); i++){
    		free(getNode(this, i));
    		if(this->size == 0){
    			returnAux = 0;
    			break;
    		}
    	}
    }
    return returnAux;
}

int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

	if(this != NULL){
		ll_clear(this);
		free(this);
		returnAux = 0;
	}
    return returnAux;
}

int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    //valido en ll_len que this != NULL
    if(this != NULL && ll_len(this) > 0){
    	for(int i = 0; i < ll_len(this); i++){
    		if(getNode(this, i)->pElement == pElement){
    			returnAux = i;
    			break;
    		}
    	}
    }
    return returnAux;
}

int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

	if (!ll_len(this)) {
		returnAux = 1;
	} else {
		returnAux = 0;
	}

    return returnAux;
}

int ll_push(LinkedList* this, int index, void* pElement)
{
    return addNode(this, index, pElement);;
}

void* ll_pop(LinkedList* this,int index)
{
    //valido en getNode que this != NULL
    void* returnAux = NULL;

	returnAux = ll_get(this, index);
	ll_remove(this, index);

    return returnAux;
}

int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    //valido en ll_indexOf que this != NULL
	if(ll_indexOf(this, pElement) >= 0){
		returnAux = 1;
	}else{
		returnAux = 0;
	}

    return returnAux;
}

int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int contadorElementos = 0;

	for (int i = 0; i <= this2->size; i++) {
		if (ll_contains(this, ll_get(this2, i))) {
			contadorElementos++;
		}
	}
	if (contadorElementos == this->size) {
		returnAux = 1;
	} else {
		returnAux = 0;
	}

    return returnAux;
}

LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    Node* auxNode = NULL;
    int i;

	if (from >= 0 && from < ll_len(this) && to > from && to <= ll_len(this)) {
		cloneArray = ll_newLinkedList();
		if (cloneArray != NULL) {
			for (i = 0; i < to; i++) {
				auxNode = getNode(this, i);
				addNode(cloneArray, i, auxNode->pElement);
			}
		}
	}
    return cloneArray;
}

LinkedList* ll_clone(LinkedList* this)
{
	return ll_subList(this, 0, ll_len(this));
}

int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    void* entidadAuxiliar;
    void* entidadAuxiliarDos;
    void* entidadAuxiliarTres;
    if(this != NULL && pFunc != NULL && (!order || order == 1)){
    	for(int i = 0; i < ll_len(this) - 1; i++){
    		for(int j = i+1; j <  ll_len(this); j++){
    			entidadAuxiliarDos = ll_get(this, i);
    			entidadAuxiliarTres = ll_get(this, j);

    			if(!order){
    				if(!pFunc(entidadAuxiliarDos, entidadAuxiliarTres)){
    					entidadAuxiliar = entidadAuxiliarDos;
    					ll_set(this, i, entidadAuxiliarTres);
    					ll_set(this, j, entidadAuxiliar);
    				}else{
    					entidadAuxiliar = entidadAuxiliarDos;
						ll_set(this, i, entidadAuxiliar);
						ll_set(this, j, entidadAuxiliarTres);
    				}
    				returnAux = 0;
    			}else{
    				if(pFunc(entidadAuxiliarDos, entidadAuxiliarTres) == 1){
						entidadAuxiliar = entidadAuxiliarDos;
						ll_set(this, i, entidadAuxiliarTres);
						ll_set(this, j, entidadAuxiliar);
					}else{
						entidadAuxiliar = entidadAuxiliarDos;
						ll_set(this, i, entidadAuxiliar);
						ll_set(this, j, entidadAuxiliarTres);
					}
    				returnAux = 0;
    			}
    		}
    	}
    }
    return returnAux;

}

int ll_incrementId(LinkedList* this){
	int id;
	int ultimoId = 0;
	Mesa* pElement;
	int autoIncrementar = 0;

	if(this != NULL){
		for(int i = 0; i < ll_len(this); i++){
			pElement = (Mesa*) ll_get(this, i);
			if(pElement != NULL){
				mesa_getIdInt(pElement, &id);
			}

			if((i == 0 && id >= 0) || id > ultimoId){
				ultimoId = id;
			}

		}
		if(ultimoId > autoIncrementar){
			autoIncrementar = ultimoId+1;
		}else{
			autoIncrementar++;
		}
	}
	return autoIncrementar;
}

LinkedList* ll_map(LinkedList *this, void* (*pFunc)(void*)) {
	LinkedList *auxLinkedList = NULL;
	void *pElement = NULL;
	int i;

	if (this != NULL && ll_len(this) > 0) {
		auxLinkedList = ll_newLinkedList();
		if (auxLinkedList != NULL) {
			for (i = 0; i < ll_len(this); i++) {
				pElement = ll_get(this, i);
				if (pElement != NULL) {
					pElement = pFunc(pElement);
					ll_add(auxLinkedList, pElement);
				}
			}
		}
	}
	return auxLinkedList;
}

LinkedList* ll_filter(LinkedList *this, int (*pFunc)(void*)) {
	LinkedList *auxLinkedList = NULL;
	void *pElement = NULL;
	int i;

	if (this != NULL) {
		auxLinkedList = ll_newLinkedList();
		if (auxLinkedList != NULL) {
			for (i = 0; i < ll_len(this); i++) {
				pElement = ll_get(this, i);
				if (pFunc(pElement) == 1) {
					ll_add(auxLinkedList, pElement);
				}
			}
		}
	}
	return auxLinkedList;
}

