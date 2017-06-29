#ifndef	__Back__
#define __Back__

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

class Background
{
	private:
		float x;
		float y;
		float velX;
		float velY;
		short dirX;
		short dirY;
		int width;
		int height;
		int WIDTH;
		int HEIGHT;
		ALLEGRO_BITMAP *image;
		ALLEGRO_DISPLAY *screen;
		bool recreate;
		bool scaleyaxis;
		bool animation_left_right;

	public:
		//contructor e destructor
		Background(float, float, float, float, short, short, ALLEGRO_BITMAP *, ALLEGRO_DISPLAY*, bool, bool, bool);

		//get e set
		ALLEGRO_BITMAP* getImage();

		//members functions
		void UpdateBack();
		ALLEGRO_BITMAP* DrawBack();
};
#endif
