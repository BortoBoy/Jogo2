#include "background.h"

Background::Background(float x,
                       float y,
                       float velX,
                       float velY,
                       short dirX,
                       short dirY,
                       ALLEGRO_BITMAP *image,
                       ALLEGRO_DISPLAY *screen,
                       bool recreate,
                       bool scaleyaxis,
                       bool animation_left_right){
	this->x = x;
	this->y = y;
	this->image = image;
	this->velX = velX;
	this->velY = velY;
	this->dirX = dirX;
	this->dirY = dirY;
	this->width =  al_get_bitmap_width(image);
	this->height = al_get_bitmap_height(image);
	this->WIDTH =  al_get_display_width(screen);
	this->HEIGHT = al_get_display_height(screen);
	this->screen = screen;
	this->recreate = recreate;
	this->scaleyaxis = scaleyaxis;
	this->animation_left_right = animation_left_right;
}

ALLEGRO_BITMAP* Background::getImage()
{
	return this->image;
}

void Background::UpdateBack()
{
	if(recreate){ //this conditions restore the image
		x += velX * dirX;
		y += velY * dirY;
		if(x <= -width || x >= width)
			x = 0;
		if(y <= -height || x >= height)
			y = 0;
	}
	else{ //this conditions locked the image on the screen, it never out of screen
			x += velX * dirX;
			y += velY * dirY;
	}
}

ALLEGRO_BITMAP* Background::DrawBack() //imagem deve ser maior que o display em X
{
	al_clear_to_color(al_map_rgb(255,0,255));

	if(scaleyaxis) //scaling Y
    {
		this->width = (width * HEIGHT)/height;//sem deformar a imagem
		this->height = HEIGHT;

		ALLEGRO_BITMAP* aux = image;
		image = al_create_bitmap(width, height);
		al_set_target_bitmap(image);
		al_draw_scaled_bitmap(aux, 0, 0, al_get_bitmap_width(aux), al_get_bitmap_height(aux), 0, 0, width, height, 0);

        al_set_target_bitmap(al_get_backbuffer(screen));
		al_destroy_bitmap(aux);
		aux = NULL;

		scaleyaxis = false;
	}

	al_draw_bitmap(image, x, y, 0);

	if(recreate) //just for X axis
    {
		if(x+width < WIDTH)
			al_draw_bitmap(image, x+width-2, y, 0);
		if(x>0)
			al_draw_bitmap(image, x-width+2, y, 0);
	}

    if(animation_left_right) //just for X axis
    {
        if(x+width <= WIDTH)
			this->dirX = 1;
		if(x >= -1)
			this->dirX = -1;
	}
	return image;
}

