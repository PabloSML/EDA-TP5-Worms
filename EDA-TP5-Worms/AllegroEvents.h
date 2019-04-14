#ifndef ALLEGROEVENTS_H
#define ALLEGROEVENTS_H

#include <allegro5/allegro.h>
#include "eventGenerator.h"

using namespace std;

class AllegroEvents :public eventGenerator
{
public:
	//Constructor
	AllegroEvents(ALLEGRO_EVENT_QUEUE*);

	//Getters
	char getKey(void) { return key; };
	virtual eventype getEvent(void);

	//Setter
	virtual void setEvent(eventype);

	//Metodos
	virtual bool isThereEvent(void);
	virtual bool notQuit(void);

private:
	char key;
	bool quit;
	ALLEGRO_EVENT_QUEUE* event_queue;
};

#endif 

