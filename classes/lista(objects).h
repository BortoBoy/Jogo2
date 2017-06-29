#ifndef __LISTOBJ__
#define __LISTOBJ__
#include "lista(template).h"
#include "object.h"

class List_Objects : public List<Object*>
{
	public:
		void L_Objects();
		void L_Insert(Object*);
};

#endif
