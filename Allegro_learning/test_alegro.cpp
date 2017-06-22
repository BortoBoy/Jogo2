#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <iostream>
using namespace std;

int main()
{
	ALLEGRO_DISPLAY *tela = NULL;
	
	if(!al_init()){ //verificando a funcionabilidade do allegro
		 al_show_native_message_box(NULL, NULL, NULL,
        "failed to initialize allegro!", NULL, 0);
		return -1;
	}
	
	tela = al_create_display(640, 480);
	if(!tela)
	{
	    al_show_native_message_box(NULL, NULL, NULL,
        "failed to initialize display!", NULL, 0);
	    return -1;
	}		
	al_clear_to_color(al_map_rgb(255, 0, 255));
	al_flip_display();
	al_rest(5.0);
	al_destroy_display(tela);
	
	return 0;
	
}
