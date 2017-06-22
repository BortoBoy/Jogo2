#include <allegro5/allegro.h>

int CongratulationsScreen(ALLEGRO_DISPLAY* screen){
	al_clear_to_color(al_map_rgb(0,0,255));
	al_flip_display();
	al_rest(2.0);
	return 5;
}
