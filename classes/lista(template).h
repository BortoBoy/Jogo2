#ifndef __LISTA__
#define __LISTA__
#include "node.h"

template <typename T>
class List{
		public:
			Node<T>* header;
			
			List();
			void L_Insert(T);
			void L_Remove(T&, bool);
			bool L_Search(T&);
};

#endif
