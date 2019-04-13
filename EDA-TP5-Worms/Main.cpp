#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_color.h>
#include <iostream>
#include <vector>
#include "allegroAux.h"
#include "Drawable.h"
#include "Scene.h"

using namespace std;

#define SCENARIO_FILE "Scenario.png"

int main()
{
	ALLEGRO_DISPLAY* display = NULL;
	ALLEGRO_SAMPLE* sickBeats = NULL;
	ALLEGRO_TIMER* timer = NULL;
	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_EVENT ev;
	bool quit = false;
	const char* file = SCENARIO_FILE;

	if (initAll(display, timer, event_queue, sickBeats))
	{
		Drawable* drawables[3];
		Scene background;
		drawables[0] = &background;

		background.init(SCENARIO_FILE);

		al_clear_to_color(al_map_rgb(255,255,102));
		drawAll(drawables, 1);
		al_flip_display();

		while (!quit)
		{
			if (al_get_next_event(event_queue, &ev))
			{
				if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
					quit = true;
			}
		}
		background.deinit();
	}

	deinitAll(display, timer, event_queue, sickBeats);


	return 0;
}