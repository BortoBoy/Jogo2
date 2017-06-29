#include <allegro5/allegro.h>

int GameScreen(ALLEGRO_DISPLAY* screen){
	al_clear_to_color(al_map_rgb(0,255,0));
	al_flip_display();
	al_rest(2.0);
	return 4;
}
