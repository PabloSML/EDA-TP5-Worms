#ifndef EVENTGENERATOR_H
#define EVENTGENERATOR_H

#include <allegro5/allegro.h>

using namespace std;

enum eventype { PLAYER_1_WANTS_TO_WALK, PLAYER_2_WANTS_TO_WALK, PLAYER_1_WANTS_TO_JUMP, \
				PLAYER_2_WANTS_TO_JUMP, QUIT, REFRESH, NO_EVENT, FULL_COUNTER};

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

