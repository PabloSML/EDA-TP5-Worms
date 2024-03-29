#include "AllegroEvents.h"
#include <iostream>

AllegroEvents::AllegroEvents(ALLEGRO_EVENT_QUEUE* event_queue_)
{
	quit = false;	
	event_queue = event_queue_;	//registro la fila de eventos
}

eventype
AllegroEvents::getEvent(void)
{
	ALLEGRO_EVENT ev;
	al_get_next_event(event_queue, &ev);
	eventype event = NO_EVENT;

	if (ev.type == ALLEGRO_EVENT_KEY_DOWN)  //Con este evento se guarda la primera tecla que presiono el usuario o se cierra la ventana
	{										//si se presiona la tecla ESC
		switch (ev.keyboard.keycode)
		{
		case ALLEGRO_KEY_A:
			key = 'a';
			event = USER_WANTS_TO_WALK;
			break;
		case ALLEGRO_KEY_LEFT:
			key = '<';
			event = USER_WANTS_TO_WALK;
			break;
		case ALLEGRO_KEY_D:
			key = 'd';
			event = USER_WANTS_TO_WALK;
			break;
		case ALLEGRO_KEY_RIGHT:
			key = '>';
			event = USER_WANTS_TO_WALK;
			break;
		case ALLEGRO_KEY_W:
			key = 'w';
			event = USER_WANTS_TO_JUMP;
			break;
		case ALLEGRO_KEY_UP:
			key = '^';
			event = USER_WANTS_TO_JUMP;
			break;
			case ALLEGRO_KEY_ESCAPE: case ALLEGRO_KEY_Q:
				quit = true;
				event = QUIT;
				break;
		}
	}

	else if (ev.type == ALLEGRO_EVENT_KEY_UP)  //Este evento avisa cuando la tecla se dejo de presionar, para determinar
	{										  //el moviemnto o solo el cambio de mirada
		switch (ev.keyboard.keycode)
		{
		case ALLEGRO_KEY_A:
			key = 'a';
			event = USER_WANTS_TO_NOTWALK;
			break;
		case ALLEGRO_KEY_LEFT:
			key = '<';
			event = USER_WANTS_TO_NOTWALK;
			break;
		case ALLEGRO_KEY_D:
			key = 'd';
			event = USER_WANTS_TO_NOTWALK;
			break;
		case ALLEGRO_KEY_RIGHT:
			key = '>';
			event = USER_WANTS_TO_NOTWALK;
			break;
		case ALLEGRO_KEY_W:
			key = 'w';
			event = USER_WANTS_TO_NOTJUMP;
			break;
		case ALLEGRO_KEY_UP:
			key = '^';
			event = USER_WANTS_TO_NOTJUMP;
			break;
		}
	}
	else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)	//Evento para cerrar la ventana desde la cruz del display
	{
		quit = true;
		event = QUIT;
	}
	else if (ev.type == ALLEGRO_EVENT_TIMER)	//Evento para redibujar la pantalla
		event = REFRESH;

	return event;
}

bool
AllegroEvents::isThereEvent(void)
{
	if (al_is_event_queue_empty(event_queue))
		return false;
	else
		return true;
}

bool
AllegroEvents::notQuit()
{
	if (quit)
		return false;
	else
		return true;

}

