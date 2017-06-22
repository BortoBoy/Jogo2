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
	
	public:		
		//contructor e destructor
		Background(float, float, float, float, short, short, ALLEGRO_BITMAP *, bool, bool);
		
		//get e set
		ALLEGRO_BITMAP* getImage();
		
		//members functions
		void UpdateBack();
		void DrawBack();
};

Background::Background(float x, float y, float valX, float velY, short dirX, short dirY, ALLEGRO_BITMAP *image, bool recreate, bool scaleyaxis){
	this->x = x;
	this->y = y;
	this->image = image;
	this->velX = 0;
	this->velY = 0;
	this->dirX = 1;
	this->dirY = 1;
	this->width =  al_get_bitmap_width(image);
	this->height = al_get_bitmap_height(image);
	this->WIDTH =  al_get_display_width(screen);
	this->HEIGHT = al_get_display_height(screen);
	this->screen = screen;
	this->recreate = recreate;
	this->scaleyaxis= scaleyaxis;
}

ALLEGRO_BITMAP* Background::getImage()
{
	return this->image;
}

void Background::UpdateBack()
{
	x += velX * dirX;
	y += velY * dirY;
	if(x <= -WIDTH || x > WIDTH)
		x = 0;
	if(y <= -HEIGHT || x > HEIGHT)
		y = 0;
	
}

void Background::DrawBack()
{
	if(scaleyaxis)
		al_draw_scaled_bitmap(this->image, x, y, width, height, x, y, width, HEIGHT, 0);
	else
		al_draw_bitmap(this->image, x, y, 0);
	
	if(recreate){
		if(x < 0 && x+width < WIDTH)
			al_draw_bitmap(this->image, x+width, y, 0);
		else if(x > 0)
			al_draw_bitmap(this->image,x-width, y, 0);
		else if(y < 0 && y+height < HEIGHT)
			al_draw_bitmap(this->image,x, y+width, 0);
		else if(y > 0)
			al_draw_bitmap(this->image,x, y-width, 0);
	}
}
