#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
	LinkedList* this= NULL;
	this = (LinkedList*)malloc(sizeof(LinkedList));
  if (this != NULL)
  {
  	this->pFirstNode=NULL;
  	this->size=0;
  }
	return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
    	returnAux = this->size;
    }
    return returnAux;
}

/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	int i;
	Node* pNode = NULL;

	if(this != NULL && nodeIndex >= 0 && nodeIndex < this->size)
	{
		pNode = this->pFirstNode; //es el nodo 0
		for(i=0; i<nodeIndex; i++)	//iteramos nodeIndex veces
		{
			pNode = pNode->pNextNode;
		}
	}

	return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}

/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{

	int returnAux = -1;
	Node* pNewNode;
	Node* pPreviusNode;

	if(this != NULL && nodeIndex >= 0 && nodeIndex <= this->size)
	{
		pNewNode = (Node*)malloc(sizeof(Node));
		if(pNewNode != NULL)
		{
			pNewNode->pElement = pElement;
			if(nodeIndex == 0)
			{
				pNewNode->pNextNode = this->pFirstNode;
				this->pFirstNode = pNewNode;
				this->size++;
				returnAux = 0;
			}
			else
			{
				pPreviusNode = getNode(this, nodeIndex-1);
				pNewNode->pNextNode = pPreviusNode->pNextNode;
				pPreviusNode->pNextNode = pNewNode;
				this->size++;
				returnAux = 0;
			}
		}
	}
	return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
	return addNode(this,nodeIndex,pElement);
}

/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
	int returnAux = -1;

	if(this != NULL)
	{
		if(addNode(this, this->size, pElement)==0)
		{
			returnAux = 0;
		}
	}
	return returnAux;
}

/** \brief Obtiene un elemento a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
	void* returnAux = NULL;
	Node* pNode = NULL;

	if(this != NULL && index >= 0 && index < this->size)
	{
		pNode = getNode(this, index);
		if(pNode != NULL)
		{
			returnAux = pNode->pElement;
		}
	}
	return returnAux;
}

/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
	int returnAux = -1;
	Node* pAux;

	if(this != NULL && index >= 0 && index < this->size)
	{
		pAux = getNode(this, index);
		if(pAux != NULL)
		{
			pAux->pElement = pElement;
			returnAux = 0;
		}
	}

	return returnAux;
}

/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
  int returnAux = -1;
  Node* previous;
  Node* actual;

	if(this != NULL && index >= 0 && index < this->size)
	{
		actual = getNode(this, index);
		if(actual != NULL && index==0)
		{
			this->pFirstNode = actual->pNextNode;
			this->size--;
			free(actual);
		}
		else
		{
			previous = getNode(this, index-1);
			if(actual != NULL && previous != NULL)
			{
				previous->pNextNode = actual->pNextNode; //guardo el siguiente nodo antes de eliminar
				this->size--;
				free(actual);
			}
		}
		returnAux = 0;
	}
  return returnAux;
}

/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
  int returnAux = -1;
  int i;

  if(this != NULL)
  {
  	for(i=0; i<this->size; i++)
  	{
  		if(ll_remove(this, i)==0)
  		{
  			returnAux = 0;
  		}
  	}
  }

  return returnAux;
}

/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
	int returnAux = -1;

	if(this != NULL)
	{
		if(ll_clear(this)==0)
		{
			free(this);
			returnAux = 0;
		}
	}

	return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
  int returnAux = -1;
  int i;
  void* pAux;

  if(this != NULL)
  {
  	for(i=0; i<this->size; i++)
  	{
  		pAux = ll_get(this, i);
  		if(pAux == pElement)
  		{
  			returnAux = i;
  			break;
  		}
  	}
  }

  return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
  int returnAux = -1;

  if(this != NULL)
  {
		if(this->size > 0)
		{
			returnAux = 0;
		}
		else
		{
			returnAux = 1;
		}
  }
  return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
	int returnAux = -1;

	if(this != NULL && index >= 0 && index <= this->size)
	{
		if(addNode(this, index, pElement)==0)
		{
			returnAux = 0;
		}
	}
	return returnAux;
}

/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this, int index)
{
  void* returnAux = NULL;
  Node* nodo;

	if(this != NULL && index >= 0 && index < this->size)
	{
		nodo = getNode(this, index);
		if(nodo != NULL)
		{
			returnAux = nodo->pElement;
			ll_remove(this, index);
		}
	}
  return returnAux;
}

/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
	int returnAux = -1;
	if(this != NULL)
	{
		returnAux = 1; //contiene el elemento
		if(ll_indexOf(this, pElement) == -1)
		{
			returnAux = 0; //No contiene el elemento
		}
	}
	return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this, LinkedList* this2)
{
  int returnAux = -1;
  int i;
  void* pElement;
  int respuesta;

  if(this != NULL && this2 != NULL)
  {
  	returnAux = 1; //estan contenidos en la lista
  	for(i=0; i<this2->size; i++)
  	{
  		pElement = ll_get(this2, i);
  		respuesta = ll_contains(this, pElement);
  		if(respuesta==0)
			{
				returnAux = 0; //NO estan contenidos en la lista
				break;
			}
  	}
  }

  return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
  LinkedList* cloneArray = NULL;
  int i;
  void* pElement;
  int len;

  len = ll_len(this);
  if(this!=NULL && from>=0 && from<=len && to>=0 && to<=len && from<to)
  {
  	cloneArray = ll_newLinkedList();
  	for(i=from; i<to; i++)
  	{
  		pElement = ll_get(this, i);
  		ll_add(cloneArray, pElement);
  	}
  }
  return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int len;

    len = ll_len(this);
    if(this!=NULL)
    {
    	cloneArray = ll_newLinkedList();
    	cloneArray = ll_subList(this, 0, len);
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                        ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
  int returnAux = -1;
  void* pElement1;
  void* pElement2;
  int respuesta;
  int len;
  int i;
	int flagSwap;

	len = ll_len(this);
	if(this != NULL && pFunc != NULL && (order == 0 || order == 1))
	{
		do //hacer mientras este desordenado
		{
			flagSwap = 0;
			for(i=0; i<(len-1); i++)
			{
				pElement1 = ll_get(this, i);
				pElement2 = ll_get(this, i+1);
				respuesta = pFunc(pElement1,pElement2);
				if( (order == 1 && respuesta == 1) || //str1 > str2 -> orden ascendente
						(order == 0 && respuesta == -1) ) //str1 < str2 -> orden descendente
				{
					ll_set(this,i,pElement2);
					ll_set(this,i+1,pElement1);
					flagSwap = 1;
				}
			}
		}while(flagSwap);
		returnAux = 0;
	}

  return returnAux;
}


/*----------------------   xxxxxxxxxxxxxxxxxxx    -------------------------------------------*/


/** \brief
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion a procesar
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                        ( 0) Si ok
 */
int ll_map(LinkedList* this, int (*pFunc)(void*))
{
  int returnAux = -1;
  int len = ll_len(this);
  int i;
  void* pElement;

  if(this!=NULL)
  {
  	for(i=0; i<len; i++)
  	{
  		pElement = ll_get(this, i);
  		pFunc(pElement);
  		returnAux = 0;
  	}
  }

  return returnAux;
}


























