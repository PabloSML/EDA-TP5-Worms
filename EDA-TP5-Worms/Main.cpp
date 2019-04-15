#include "allegroAux.h"
#include "Scene.h"
#include "Worm.h"
#include "AllegroEvents.h"
#include "SimulationEvents.h"

static void dispatch(Drawable*[OBJECTS_DRAWABLES], Worm*, char key, SimulationEvents*, eventype, ALLEGRO_TIMER*);

using namespace std;

int main()
{
	ALLEGRO_DISPLAY* display = NULL;
	ALLEGRO_SAMPLE* sickBeats = NULL;
	ALLEGRO_TIMER* timer = NULL;
	ALLEGRO_EVENT_QUEUE* event_queue = NULL;

	if (initAll(display, timer, event_queue, sickBeats))	//Inicio los servicios de allegro
	{
		SimulationEvents ev2;	//Creo un objeto para eventos de la simulacion
		AllegroEvents ev(event_queue); //Creo un objeto para eventos de Allegro
		Scene background;
		Worm player[CANT_OF_PLAYERS] = { Worm(INICIAL_X_POSITION_PLAYER_1, INICIAL_Y_POSITION_PLAYER_2, RIGHT),
										 Worm(INICIAL_X_POSITION_PLAYER_2, INICIAL_Y_POSITION_PLAYER_2, LEFT),
									   }; //Reescribir con new en caso de querer elegir la cantidad de players en tiempo de ejecucion
		Drawable* drawables[OBJECTS_DRAWABLES] = { &background, &player[ONE], &player[TWO] };

		if ( background.init(SCENARIO_FILE) && player[ONE].init(WORM_IMAGE) \
			&& player[TWO].init(WORM_IMAGE) )		//Cargo los bitmaps del escenario y de cada worm
		{
			al_start_timer(timer);	//Comienza el timer
			do
			{
				//printf("contador de eventos de timer: %d \n", ev2.getCont()); //Solo para debugging, borrar antes de entregar
				if (ev2.isThereEvent() && ev2.getEvent() == FULL_COUNTER)		//Si llegue a 1000ms
				{
					ev2.setCounterToZero();	//Reseteo el contador
					al_stop_timer(timer);	//Detengo el timer hasta que llegue otro evento que me interese
					//printf("pare el contador \n");		//Solo para debugging, borrar antes de entregar
				} 
				if (ev.isThereEvent())		//si hay un evento de allegro
				{
					dispatch(drawables, player, ev.getKey(), &ev2, ev.getEvent(),timer);
				}
			} while (ev.notQuit());

			for (int i = 0; i < OBJECTS_DRAWABLES; i++)
				drawables[i]->deinit(); //Destruyo el bitmap de background, el bitmap del worm 1 y el bitmap del worm 2
		}
		else
			cerr << "Images load failure" << endl;	//Si no pude cargar el backgroung o algun worm muestro error

		//delete[] player;	//Descomentar esta linea solo en el caso de usar new y elegir la cantidad de players en tiempo de ejecucion
	}

	deinitAll(display, timer, event_queue, sickBeats);	//Destruyo todos los servicios de allegro

	return 0;
}


static void dispatch(Drawable* drawables[OBJECTS_DRAWABLES],Worm *player,char key, SimulationEvents*ev2, eventype ev,ALLEGRO_TIMER *timer)
{
	switch (ev)
	{
		case USER_PRESS_IMPORTANCE_KEY:
			al_start_timer(timer);	//Comienza el timer si el usuario presiono una tecla de importancia	
			break;
		case PLAYER_1_WANTS_TO_WALK:
			//cout << "quiero caminar1" << key << endl; //Solo para debugging, borrar antes de entregar
			player[ONE].walk(key, ev2->getCont());
			break;
		case PLAYER_2_WANTS_TO_WALK:
			//cout << "quiero caminar2" << key << endl; //Solo para debugging, borrar antes de entregar
			player[TWO].walk(key, ev2->getCont());
			break;
		case PLAYER_1_WANTS_TO_JUMP:
			//cout << "quiero saltar1" << key << endl; //Solo para debugging, borrar antes de entregar
			player[ONE].jump();
			break;
		case PLAYER_2_WANTS_TO_JUMP:
			//cout << "quiero saltar2" << key << endl; //Solo para debugging, borrar antes de entregar
			player[TWO].jump();
			break;
		case QUIT:
			//cout << "quiero salir" << endl; //Solo para debugging, borrar antes de entregar
			break;
		case REFRESH:
			ev2->incrementCont(); //Cada ves que actualizo la pantalla (cada 20ms) aumento el contador de la simulacion
			drawAll(drawables, OBJECTS_DRAWABLES, W_DIS, H_DIS);	//Dibujo el escenario y los worms
			break;
	}
}
