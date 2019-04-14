#include "allegroAux.h"
#include "Scene.h"
#include "Worm.h"
#include "AllegroEvents.h"
#include "SimulationEvents.h"

static void dispatch(eventype, Drawable**,Worm*,char key, SimulationEvents*);

using namespace std;

int main()
{
	ALLEGRO_DISPLAY* display = NULL;
	ALLEGRO_SAMPLE* sickBeats = NULL;
	ALLEGRO_TIMER* timer = NULL;
	ALLEGRO_EVENT_QUEUE* event_queue = NULL;

	if (initAll(display, timer, event_queue, sickBeats))	//Inicio los servicios de allegro
	{
		SimulationEvents ev2;
		AllegroEvents ev(event_queue);
		Scene background;
		Worm player[CANT_OF_PLAYERS] = { Worm(INICIAL_POSITION_PLAYER_1,RIGHT),
										 Worm(INICIAL_POSITION_PLAYER_2,LEFT),
									   };
		Drawable* drawables[OBJECTS_DRAWABLES] = { &background, &player[ONE], &player[TWO] };

		if ( background.init(SCENARIO_FILE) && player[ONE].init(WORM_IMAGE) \
			&& player[TWO].init(WORM_IMAGE) )		//Cargo los bitmaps del escenario y de cada worm
		{
			al_start_timer(timer);	//Comienza el contador

			do
			{
				if (ev2.isThereEvent() && ev2.getEvent() == FULL_COUNTER)
					ev2.setCounterToZero();
				if (ev.isThereEvent())
					dispatch(ev.getEvent(), drawables, player, ev.getKey(), &ev2);
			} while (ev.notQuit());

			for (int i = 0; i < OBJECTS_DRAWABLES; i++)
				drawables[i]->deinit(); //Destruyo el bitmap de background, el bitmap del worm 1 y el bitmap del worm 2
		}
		else
			cerr << "Images load failure" << endl;	//Si no pude cargar el backgroung o algun worm muestro error

		//delete[] player;	
	}

	deinitAll(display, timer, event_queue, sickBeats);	//Destruyo todos los servicios de allegro

	return 0;
}


static void dispatch(eventype ev, Drawable* drawables[OBJECTS_DRAWABLES],Worm *player,char key, SimulationEvents* ev2)
{
	switch (ev)
	{
		case USER_WANTS_TO_WALK:
			for (int i = 0; i < CANT_OF_PLAYERS; i++)
				player[i].walk(key, ev2->getCont());
			break;
		case USER_WANTS_TO_JUMP:
			for (int i = 0; i < CANT_OF_PLAYERS; i++)
				player[i].jump(key);
			break;
		case QUIT:
			cout << "quiero salir" << endl;
			break;
		case REFRESH:
			ev2->incrementCont();
			drawAll(drawables, OBJECTS_DRAWABLES, W_DIS, H_DIS);
			break;
	}
}
