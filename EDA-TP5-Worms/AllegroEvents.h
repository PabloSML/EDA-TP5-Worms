#ifndef ALLEGROEVENTS_H
#define ALLEGROEVENTS_H

//*************************************************INCLUDES*************************************************
#include <allegro5/allegro.h>
#include "eventGenerator.h"

using namespace std;

//*************************************************CLASS*************************************************
class AllegroEvents :public eventGenerator
{
public:
	//Constructor
	AllegroEvents(ALLEGRO_EVENT_QUEUE*);

	//Getters
	char getKey(void) { return key; };
	virtual eventype getEvent(void);

	//Metodos
	virtual bool isThereEvent(void);
	virtual bool notQuit(void);

private:
	char key;	//tecla presionada
	bool quit;	
	ALLEGRO_EVENT_QUEUE* event_queue;	//fila de eventos
};

#endif 

