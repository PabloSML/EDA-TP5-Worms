#ifndef EVENTGENERATOR_H
#define EVENTGENERATOR_H

//*************************************************INCLUDE*************************************************
#include <allegro5/allegro.h>

using namespace std;

//*************************************************EVENTS*************************************************
//Eventos del dispacher
enum eventype { USER_WANTS_TO_WALK, USER_WANTS_TO_JUMP, USER_WANTS_TO_NOTWALK, USER_WANTS_TO_NOTJUMP,
			QUIT, REFRESH, NO_EVENT, FULL_COUNTER};
			
//*************************************************CLASS*************************************************
class eventGenerator
{
public:
	eventGenerator();
	~eventGenerator();

	virtual eventype getEvent(void) = 0;
	virtual bool isThereEvent(void) = 0;
	virtual bool notQuit(void) = 0;
};

#endif

