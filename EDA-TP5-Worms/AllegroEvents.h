#ifndef ALLEGROEVENTS_H
#define ALLEGROEVENTS_H

#include <allegro5/allegro.h>
#include "eventGenerator.h"

#define RIGHT	('>')
#define	LEFT	('<')
#define UP		('^')

using namespace std;

class AllegroEvents :public eventGenerator
{
public:
	AllegroEvents();

	//int getKey() { return key; };

	eventype getEvent(ALLEGRO_EVENT_QUEUE*);
	bool isThereEvent(ALLEGRO_EVENT_QUEUE*);
	bool notQuit();
	void setEvent(eventype);

private:
	char key;
	bool quit;
};

#endif 

