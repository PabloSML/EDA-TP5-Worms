#include "AllegroEvents.h"
#include <iostream>

AllegroEvents::AllegroEvents(ALLEGRO_EVENT_QUEUE* event_queue_)
{
	quit = false;
	event_queue = event_queue_;
}

eventype
AllegroEvents::getEvent(void)
{
	ALLEGRO_EVENT ev;
	al_get_next_event(event_queue, &ev);
	//al_flush_event_queue(event_queue);
	eventype event = NO_EVENT;

	if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
	{
		switch (ev.keyboard.keycode)
		{
			case ALLEGRO_KEY_A: case ALLEGRO_KEY_LEFT: case ALLEGRO_KEY_D:
			case ALLEGRO_KEY_RIGHT: case ALLEGRO_KEY_W: case ALLEGRO_KEY_UP:
				event = USER_PRESS_IMPORTANCE_KEY;
				break;
			case ALLEGRO_KEY_ESCAPE:
				quit = true;
				event = QUIT;
				break;
		}
	}
	else if (ev.type == ALLEGRO_EVENT_KEY_UP)
	{
		switch (ev.keyboard.keycode)
		{
		case ALLEGRO_KEY_A:
			key = 'a';
			event = PLAYER_1_WANTS_TO_WALK;
			break;
		case ALLEGRO_KEY_LEFT:
			key = '<';
			event = PLAYER_2_WANTS_TO_WALK;
			break;
		case ALLEGRO_KEY_D:
			key = 'd';
			event = PLAYER_1_WANTS_TO_WALK;
			break;
		case ALLEGRO_KEY_RIGHT:
			key = '>';
			event = PLAYER_2_WANTS_TO_WALK;
			break;
		case ALLEGRO_KEY_W:
			key = 'w';
			event = PLAYER_1_WANTS_TO_JUMP;
			break;
		case ALLEGRO_KEY_UP:
			key = '^';
			event = PLAYER_2_WANTS_TO_JUMP;
			break;
		}
	}
	else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
	{
		quit = true;
		event = QUIT;
	}
	else if (ev.type == ALLEGRO_EVENT_TIMER)
		event = REFRESH;

	//if (event != REFRESH)
	//	cout << "evento :" << event << endl;

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

void
AllegroEvents::setEvent(eventype)
{

}
