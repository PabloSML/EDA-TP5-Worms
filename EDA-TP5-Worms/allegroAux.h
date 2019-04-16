#ifndef ALLEGROAUX_H
#define ALLEGROAUX_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_primitives.h>	//solo para debugging, borrar antes de entregar

#define SUCCESS 1
#define FAILURE 0
#define FPS 50.0
#define W_DIS 1920	//Si se cambia la resolucion se debe modificar POS_X_RATIO_AJUST y POS_Y_RATIO_AJUST en Worm.h
#define H_DIS 696	//Si se cambia la resolucion se debe modificar POS_X_RATIO_AJUST y POS_Y_RATIO_AJUST en Worm.h
//#define W_DIS 1366	//Si se cambia la resolucion se debe modificar POS_X_RATIO_AJUST y POS_Y_RATIO_AJUST en Worm.h
//#define H_DIS 768	//Si se cambia la resolucion se debe modificar POS_X_RATIO_AJUST y POS_Y_RATIO_AJUST en Worm.h
#define OST_FILE "coda.wav"
#define SCENARIO_FILE "Scenario.png"
#define WORM_IMAGE "wwalk-F4.png"


// funciones de inicializacion y destruccion de allegro
bool initAll(ALLEGRO_DISPLAY*& display, ALLEGRO_TIMER*& timer, ALLEGRO_EVENT_QUEUE*& event_queue, ALLEGRO_SAMPLE*& sickBeats);
void deinitAll(ALLEGRO_DISPLAY*& display, ALLEGRO_TIMER*& timer, ALLEGRO_EVENT_QUEUE*& event_queue, ALLEGRO_SAMPLE*& sickBeats);

#endif