#include "allegroAux.h"
#include "Scene.h"
#include "Worm.h"
#include "AllegroEvents.h"
#include "SimulationEvents.h"

static void dispatch(eventype, Drawable* drawables[3]);
//void checkUserIntervention(ALLEGRO_EVENT,Worm*);
//void redraw();

using namespace std;

int main()
{
	ALLEGRO_DISPLAY* display = NULL;
	ALLEGRO_SAMPLE* sickBeats = NULL;
	ALLEGRO_TIMER* timer = NULL;
	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	AllegroEvents ev;
	bool quit = false;

	if (initAll(display, timer, event_queue, sickBeats))	//Inicio los servicios de allegro
	{
		Scene background;
		Worm* player = new Worm[PLAYERS];
		Drawable* drawables[OBJECTS_DRAWABLES] = { &background, &player[ONE], &player[TWO] };

		if ( background.init(SCENARIO_FILE) && player[ONE].init(WORM_IMAGE) \
			&& player[TWO].init(WORM_IMAGE) )		//Cargo los bitmaps del escenario y de cada worm
		{
			al_start_timer(timer);	//Comienza el contador
			drawAll(drawables, OBJECTS_DRAWABLES, W_DIS, H_DIS);

			do
			{
				if (ev.isThereEvent(event_queue))
					dispatch(ev.getEvent(event_queue), drawables);
			} while (ev.notQuit());

			background.deinit();	//Destruyo el bitmap de background
			player[ONE].deinit();	//Destruyo el bitmap del worm 1
			player[TWO].deinit();	//Destruyo el bitmap del worm 2
		}
		else
			cerr << "Images load failure" << endl;	//Si no pude cargar el backgroung o algun worm muestro error

		delete[] player;	
	}

	deinitAll(display, timer, event_queue, sickBeats);	//Destruyo todos los servicios de allegro

	return 0;
}


static void dispatch(eventype ev, Drawable* drawables[OBJECTS_DRAWABLES])
{
	switch (ev)
	{
		case USER_WANTS_TO_WALK:
			
			break;
		case USER_WANTS_TO_JUMP:
			cout << "quiero saltar" <<endl;
			break;
		case QUIT:
			cout << "quiero salir" << endl;
			break;
		case REFRESH:
			//cout << "quiero refrescar" << endl;
			break;
	}
}
