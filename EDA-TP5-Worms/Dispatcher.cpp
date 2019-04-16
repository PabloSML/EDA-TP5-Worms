#include "Dispatcher.h"
#include "allegroAux.h"

void
dispatch(Drawable* drawables[OBJECTS_DRAWABLES], Worm *player, char key, eventype ev, ALLEGRO_TIMER *timer)
{
	switch (ev)
	{
	case USER_WANTS_TO_WALK:		//Evento de tecla de movimiento apretada
		for (int i = 0; i < CANT_OF_PLAYERS; i++)	//Llamo de la funcion de movimiento de todos los players
			player[i].startWalking(key);
		break;
	case USER_WANTS_TO_NOTWALK:			//Evento de tecla de movimiento soltada
		for (int i = 0; i < CANT_OF_PLAYERS; i++)	//Llamo de la funcion de detencion de todos los players
			player[i].stopWalking(key);
		break;
	case USER_WANTS_TO_JUMP:		//Evento de tecla de salto apretada
		for (int i = 0; i < CANT_OF_PLAYERS; i++)	//Llamo de la funcion de salto de todos los players	
			player[i].startJumping(key);
		break;
	case USER_WANTS_TO_NOTJUMP:				//Evento de tecla de salto soltada
		for (int i = 0; i < CANT_OF_PLAYERS; i++)	//Llamo de la funcion de "no saltar" de todos los players
			player[i].stopJumping(key);
		break;
	case QUIT:			//Salida del programa
		cout << "exit game succesfully" << endl;	//Mensaje de salida
		break;
	case REFRESH:		//Display update cada 20ms
		for (int i = 0; i < CANT_OF_PLAYERS; i++)	//Actualizo a todos los players
			player[i].update();
		drawAll(drawables, OBJECTS_DRAWABLES, W_DIS, H_DIS);
		al_flip_display();
		break;
	}
}