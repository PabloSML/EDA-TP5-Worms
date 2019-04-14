#ifndef EVENTGENERATOR_H
#define EVENTGENERATOR_H

#include <allegro5/allegro.h>

using namespace std;

enum eventype {USER_WANTS_TO_WALK, USER_WANTS_TO_JUMP, QUIT, REFRESH, NO_EVENT };

class eventGenerator
{
public:
	eventGenerator();
	~eventGenerator();

	virtual eventype getEvent(ALLEGRO_EVENT_QUEUE*) = 0;
	virtual bool isThereEvent(ALLEGRO_EVENT_QUEUE*) = 0;
	virtual bool notQuit() = 0;
	virtual void setEvent (eventype) = 0;
};

#endif

