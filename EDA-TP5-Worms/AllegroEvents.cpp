#include "AllegroEvents.h"


AllegroEvents::AllegroEvents()
{
	quit = false;
}

eventype
AllegroEvents::getEvent(ALLEGRO_EVENT_QUEUE* event_queue)
{
	ALLEGRO_EVENT ev;
	al_get_next_event(event_queue, &ev);
	eventype event = NO_EVENT;

	if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
	{
		switch (ev.keyboard.keycode)
		{
		case ALLEGRO_KEY_A:
			key = 'a';
			event =USER_WANTS_TO_WALK;
			break;
		case ALLEGRO_KEY_LEFT:
			key = LEFT;
			event = USER_WANTS_TO_WALK;
			break;
		case ALLEGRO_KEY_D:
			key = 'd';
			event = USER_WANTS_TO_WALK;
			break;
		case ALLEGRO_KEY_RIGHT:
			key = RIGHT;
			event = USER_WANTS_TO_WALK;
			break;
		case ALLEGRO_KEY_W:
			key = 'w';
			event = USER_WANTS_TO_JUMP;
			break;
		case ALLEGRO_KEY_UP:
			key = UP;
			event = USER_WANTS_TO_JUMP;
			break;
		case ALLEGRO_KEY_ESCAPE:
			quit = true;
			event = QUIT;
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

	return event;
}

bool
AllegroEvents::isThereEvent(ALLEGRO_EVENT_QUEUE* event_queue)
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
