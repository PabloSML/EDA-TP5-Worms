#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

// funciones de inicializacion y destruccion de allegro
bool initAll(ALLEGRO_DISPLAY*& display, ALLEGRO_TIMER*& timer, ALLEGRO_EVENT_QUEUE*& event_queue, ALLEGRO_SAMPLE*& sickBeats);
void deinitAll(ALLEGRO_DISPLAY*& display, ALLEGRO_TIMER*& timer, ALLEGRO_EVENT_QUEUE*& event_queue, ALLEGRO_SAMPLE*& sickBeats);