#include "node.h"
#include "lista(objects).h"
#include <cstddef> //include NULL

void List_Objects::L_Objects()
{
    this->header = new Node<Object*>();
}

void List_Objects::L_Insert(Object* info)	//insere na ordem...
{											//... prioridade para x
	Node<Object*>* hunter = header->dir;
	bool OK = false;
	while(!OK){
		if(hunter->dir->info->x > info->x ||
				hunter->dir == this->header)
			OK = true;
		else if(hunter->info->x == info->x &&
					hunter->dir->info->y < info->y)
			OK = true;
		if (!OK)
			hunter = hunter->dir;
	}
	//inserting
	Node<Object*>* aux = new Node<Object*>(info);
	aux->dir = hunter->dir;
	hunter->dir->esq = aux;
	hunter->dir = aux;
	aux->esq = hunter;

	//gnd
	hunter = NULL;
	aux = NULL;
}
