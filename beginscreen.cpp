#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include "../background.cpp"

int BeginScreen(ALLEGRO_DISPLAY* screen){
	//variables
	bool done;
	bool lmouse;
	bool render;
	int answer;
	
	//allegro variables
	ALLEGRO_BITMAP *imageback = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;	
	
	//init	//addon init
	al_init_image_addon();
	al_install_mouse();
	
	event_queue = al_create_event_queue();
	timer = al_create_timer(1.0 / 60);
	
	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	
	al_start_timer(timer);
	imageback = al_load_bitmap("files/initialbackground.jpg");
	
	if (imageback == NULL)  //verificando se foi possivel abrir a imagem
	{
		al_show_native_message_box(
	     screen,
	     "ERROR",
	     "ALLEGRO can't be open initial background",
	     "Maybe the image file is not compatible",
	     NULL,
	     ALLEGRO_MESSAGEBOX_ERROR);
	     al_rest(2.0);
	     return 0;
	}
	
	Background background(0, 0, 0, 0, 1, 1, imageback, false, false);
	lmouse = false;	
	const int backWidth = al_get_bitmap_width(background.getImage());
	const int backHeight = al_get_bitmap_height(background.getImage());
	
	//program init
	while(!done)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		//mouse click
		if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			if(ev.mouse.button == 1)
				lmouse = true;
		}
		if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
		{
			if(ev.mouse.button == 1)
				lmouse = false;
		}
		
		//timer
		else if(ev.type == ALLEGRO_EVENT_TIMER)
		{
			render = true;
		}

		//////////////////////////////////////////////////////////////////////////////////////////////////////
		//PROGRAM
		//////////////////////////////////////////////////////////////////////////////////////////////////////
		//render
		if(render && al_is_event_queue_empty(event_queue))
		{
			render = false;
			
			background.DrawBack();
			al_flip_display();
		}
		
		//stop
		if(lmouse){
			done = true;
			answer = 2;
		}
	}
	al_destroy_bitmap(imageback);
	al_destroy_event_queue(event_queue);
	return answer;
}
