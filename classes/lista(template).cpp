#include "lista(template).h"
#include <cstddef> //include NULL

template <typename T>
List<T>::List()
{
	header = new Node<T>();
}

template <typename T>
void List<T>::L_Insert(T info)
{
	Node<T>* aux = new Node<T>(info);
	aux->esq = header->esq;
	aux->esq->dir = aux;
	aux->dir = header;
	header->esq = aux;
}

template <typename T>
void List<T>::L_Remove(T &info, bool OK)
{
	Node<T>* hunter;
	hunter = header->dir;
	OK = false;
	while(hunter != header && !OK){
		if(hunter->info == info)
			OK = true;
	}
	if(OK){
		hunter->esq->dir = hunter->dir;
		hunter->dir->esq = hunter->esq;
		delete[] hunter;
		hunter = NULL;
	}
}

template <typename T>
bool List<T>::L_Search(T &info)
{
	Node<T>* hunter;
	hunter = header->dir;
	while(hunter != header){
		if(hunter->info == info)
			return true;
	}
	return false;
}
