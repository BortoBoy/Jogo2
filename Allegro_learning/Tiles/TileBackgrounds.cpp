#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

const int WIDTH = 800;
const int HEIGHT = 600;

bool keys[] = {false, false, false, false};
enum KEYS{UP, DOWN, LEFT, RIGHT};

int main(void)
{
	//variables
	bool done = false;
	bool render = false;	

	int xOff = 0;
	int yOff = 0;

	int mapColumns = 10;
	int mapSize = 100;
	int tileSize = 128;

	int map[] =	{0, 0, 1, 1, 0, 0, 1, 1, 0, 0,
				 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 
				 1, 0, 0, 0, 1, 1, 0, 0, 0, 1,
				 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 
				 0, 0, 1, 1, 0, 0, 1, 1, 0, 0,
				 0, 0, 1, 1, 0, 0, 1, 1, 0, 0,
				 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 
				 1, 0, 0, 0, 1, 1, 0, 0, 0, 1,
				 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 
				 0, 0, 1, 1, 0, 0, 1, 1, 0, 0};


	//allegro variable
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer;
	ALLEGRO_BITMAP *bgSheet = NULL;
	
	//program init
	if(!al_init())										//initialize Allegro
		return -1;

	display = al_create_display(WIDTH, HEIGHT);			//create our display object

	if(!display)										//test display object
		return -1;

	//addon init
	al_install_keyboard();
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_primitives_addon();

	bgSheet = al_load_bitmap("background.png");

	
	event_queue = al_create_event_queue();
	timer = al_create_timer(1.0 / 60);

	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_start_timer(timer);
	while(!done)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch(ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = true;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = true;
				break;
			case ALLEGRO_KEY_UP:
				keys[UP] = true;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = true;
				break;
			}
		}
		else if(ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			switch(ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = false;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = false;
				break;
			case ALLEGRO_KEY_UP:
				keys[UP] = false;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = false;
				break;
			}
		}
		else if(ev.type == ALLEGRO_EVENT_TIMER)
		{
			xOff -= keys[RIGHT] * 5;
			xOff += keys[LEFT] * 5;
			yOff -= keys[DOWN] * 5;
			yOff += keys[UP] * 5;

			render = true;
		}

		if(render && al_is_event_queue_empty(event_queue))
		{
			render = false;

			for(int i = 0; i < mapSize; i++)
			{
				al_draw_bitmap_region(bgSheet, tileSize * map[i], 0, tileSize, tileSize, 
					xOff + tileSize * (i % mapColumns), yOff + tileSize * (i / mapColumns), 0);
			}

			al_flip_display();
			al_clear_to_color(al_map_rgb(0,0,0));
		}
	}

	al_destroy_bitmap(bgSheet);
	al_destroy_event_queue(event_queue);
	al_destroy_display(display);						//destroy our display object

	return 0;
}
