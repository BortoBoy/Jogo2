#include "node.h"
#include "object.h"
#include <cstddef> //include NULL

template <typename T>
Node<T>::Node()
{
	this->dir = this;
	this->esq = this;
	this->info = NULL;
}

template <typename T>
Node<T>::Node(T info)
{
	this->info = info;
	this->dir = this;
	this->esq = this;
}

template class Node<Object*>;
