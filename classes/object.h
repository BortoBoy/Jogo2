#ifndef __OBJ__
#define __OBJ__
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

class Object{
	public:
		ALLEGRO_BITMAP* sprite;
		int x;
		int y;

		//methods
		Object(ALLEGRO_BITMAP*, int, int);
		~Object();
};

#endif
