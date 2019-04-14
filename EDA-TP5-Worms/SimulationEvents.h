#ifndef SIMULATIONEVENTS_H
#define SIMULATIONEVENTS_H

#include "eventGenerator.h"

#define MAX_COUNTER_VALUE 50

using namespace std;

class SimulationEvents :public eventGenerator
{
public:
	//Constructor
	SimulationEvents();

	//Getters
	char getCont(void) { return cont; };
	virtual eventype getEvent(void) { return event_; };

	//Setter
	virtual void setEvent(eventype);
	void setCounterToZero(void) { cont = 0; event_ = NO_EVENT; };

	//Metodos
	void incrementCont(void);
	virtual bool isThereEvent(void);
	virtual bool notQuit(void);

private:
	int cont;
	eventype event_;
};

#endif
