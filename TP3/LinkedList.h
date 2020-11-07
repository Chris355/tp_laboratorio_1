/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif


// ----------- Publicas ------------- //

LinkedList* ll_newLinkedList(void); //Crea un nuevo LinkedList en memoria de manera dinamica
int ll_len(LinkedList* this); //Retorna la cantidad de elementos de la lista

Node* test_getNode(LinkedList* this, int nodeIndex); //Permite realizar el test de la funcion getNode la cual es privada
int test_addNode(LinkedList* this, int nodeIndex,void* pElement); //Permite realizar el test de la funcion addNode la cual es privada

int ll_add(LinkedList* this, void* pElement); //Agrega un elemento a la lista
void* ll_get(LinkedList* this, int index); //Devuelve un elemento en una posicion determinada
int ll_set(LinkedList* this, int index,void* pElement); //Modifica un elemento de la lista
int ll_remove(LinkedList* this,int index); //Elimina un elemento de la lista
int ll_clear(LinkedList* this); //Elimina todos los elementos de la lista
int ll_deleteLinkedList(LinkedList* this); //Elimina todos los elementos de la lista y la lista

int ll_indexOf(LinkedList* this, void* pElement); //Busca el indice de la primer ocurrencia del elemento pasado como parametro
int ll_isEmpty(LinkedList* this); //Indica si la lista esta o no vacia
int ll_push(LinkedList* this, int index, void* pElement); //Inserta un nuevo elemento en la lista en la posicion indicada
void* ll_pop(LinkedList* this,int index); //Elimina el elemento de la posicion indicada y retorna su puntero
int ll_contains(LinkedList* this, void* pElement); //Determina si la lista contiene o no el elemento pasado como parametro
int ll_containsAll(LinkedList* this,LinkedList* this2); //Determina si todos los elementos de la lista (this2) estan contenidos en la lista (this)

LinkedList* ll_subList(LinkedList* this,int from,int to); //Crea y retorna una nueva lista con los elementos indicados
LinkedList* ll_clone(LinkedList* this); //Crea y retorna una nueva lista con los elementos de la lista pasada como parametro

int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order); //Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro





