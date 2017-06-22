 #include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>

const int WIDTH = 640;
const int HEIGHT = 480;

int main(void)
{
	//variables
	bool done = false;
	bool render = false;
	int state = 1;	

	//allegro variable
	ALLEGRO_DISPLAY *screen = NULL;
		
	//program init
	if(!al_init())										//initialize Allegro
		return -1;

	display = al_create_display(WIDTH, HEIGHT);			//create our display object

	if(!display)										//test display object
		return -1;
	
	al_clear_to_color(al_map_rgb(255, 255, 255));
	al_flip_display();
	while(!done)
	{
			switch(state)
			{
				case 0:
					done = true;
					break;
				case 1:
					state = BeginScreen(screen);
					break;
				case 2:
					state = InstructionScreen(screen);
					break;
				case 3:
					state = GameScreen(screen);
					break;
				case 4:
					state = CongratulationsScreen(screen);
					break;
				case 5:
					state = GameOverScreen(screen)
					break;
				default:
					done = true;
					break;
			}
		}
	}

	al_destroy_display(screen);						//destroy our display object

	return 0;
}
