#ifndef EVENTGENERATOR_H
#define EVENTGENERATOR_H

#include <allegro5/allegro.h>

using namespace std;

enum eventype { USER_WANTS_TO_WALK, USER_WANTS_TO_JUMP, QUIT, REFRESH, NO_EVENT, FULL_COUNTER};


class eventGenerator
{
public:
	eventGenerator();
	~eventGenerator();

	virtual eventype getEvent(void) = 0;
	virtual bool isThereEvent(void) = 0;
	virtual bool notQuit(void) = 0;
	virtual void setEvent (eventype) = 0;
};

#endif

