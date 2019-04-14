#ifndef ALLEGROAUX_H
#define ALLEGROAUX_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#define SUCCESS 1
#define FAILURE 0
#define FPS 50.0
#define W_DIS 1200
#define H_DIS 720
#define OST_FILE "coda.wav"
#define SCENARIO_FILE "Scenario.png"
#define WORM_IMAGE "wwalk-F4.png"


// funciones de inicializacion y destruccion de allegro
bool initAll(ALLEGRO_DISPLAY*& display, ALLEGRO_TIMER*& timer, ALLEGRO_EVENT_QUEUE*& event_queue, ALLEGRO_SAMPLE*& sickBeats);
void deinitAll(ALLEGRO_DISPLAY*& display, ALLEGRO_TIMER*& timer, ALLEGRO_EVENT_QUEUE*& event_queue, ALLEGRO_SAMPLE*& sickBeats);

#endif