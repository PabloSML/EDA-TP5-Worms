#include "allegroAux.h"
#include "Scene.h"
#include "Worm.h"
#include "AllegroEvents.h"

static void dispatch(Drawable*[OBJECTS_DRAWABLES], Worm*, char key, eventype, ALLEGRO_TIMER*);

using namespace std;

int main()
{
	ALLEGRO_DISPLAY* display = NULL;
	ALLEGRO_SAMPLE* sickBeats = NULL;
	ALLEGRO_TIMER* timer = NULL;
	ALLEGRO_EVENT_QUEUE* event_queue = NULL;

	if (initAll(display, timer, event_queue, sickBeats))	//Inicio los servicios de allegro
	{
		AllegroEvents ev(event_queue); //Creo un objeto para eventos de Allegro
		Scene background;
		Worm player[CANT_OF_PLAYERS] = { Worm(INICIAL_X_POSITION_PLAYER_1, INICIAL_Y_POSITION_PLAYER_2, RIGHT, WORM1_NAME),
										 Worm(INICIAL_X_POSITION_PLAYER_2, INICIAL_Y_POSITION_PLAYER_2, LEFT, WORM2_NAME),
									   }; //Reescribir con new en caso de querer elegir la cantidad de players en tiempo de ejecucion

		Drawable* drawables[OBJECTS_DRAWABLES] = { &background, &player[ONE], &player[TWO] };

		if ( background.loadimg(SCENARIO_FILE) && player[ONE].loadimg(WORM_IMAGE) \
			&& player[TWO].loadimg(WORM_IMAGE) )		//Cargo los bitmaps del escenario y de cada worm
		{
			al_start_timer(timer);	//Comienza el timer
			do
			{
				if (ev.isThereEvent())		//si hay un evento de allegro
				{
					dispatch(drawables, player, ev.getKey(), ev.getEvent(),timer);
				}
			} while (ev.notQuit());

			for (int i = 0; i < OBJECTS_DRAWABLES; i++)
				drawables[i]->deloadimg(); //Destruyo el bitmap de background, el bitmap del worm 1 y el bitmap del worm 2
		}
		else
			cerr << "Images load failure" << endl;	//Si no pude cargar el background o algun worm mostro error

		//delete[] player;	//Descomentar esta linea solo en el caso de usar new y elegir la cantidad de players en tiempo de ejecucion
	}

	deinitAll(display, timer, event_queue, sickBeats);	//Destruyo todos los servicios de allegro

	return 0;
}

static void
dispatch(Drawable* drawables[OBJECTS_DRAWABLES], Worm *player, char key, eventype ev, ALLEGRO_TIMER *timer)
{
	switch (ev)
	{
	case USER_WANTS_TO_WALK:
		for (int i = 0; i < CANT_OF_PLAYERS; i++)
			player[i].startWalking(key);
		break;
	case USER_WANTS_TO_NOTWALK:
		for (int i = 0; i < CANT_OF_PLAYERS; i++)
			player[i].stopWalking(key);
		break;
	case USER_WANTS_TO_JUMP:
		for (int i = 0; i < CANT_OF_PLAYERS; i++)
			player[i].startJumping(key);
		break;
	case USER_WANTS_TO_NOTJUMP:
		for (int i = 0; i < CANT_OF_PLAYERS; i++)
			player[i].stopJumping(key);
		break;
	case QUIT:
		break;
	case REFRESH:		//cada 20ms
		for (int i = 0; i < CANT_OF_PLAYERS; i++)
			player[i].update();
		drawAll(drawables, OBJECTS_DRAWABLES, W_DIS, H_DIS);
		al_flip_display();
		break;
	}
}
