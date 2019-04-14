#ifndef SIMULATIONEVENTS_H
#define SIMULATIONEVENTS_H

#include "eventGenerator.h"

using namespace std;

class SimulationEvents :public eventGenerator
{
public:
	SimulationEvents();

	eventype getEvent();
	bool isThereEvent();
	bool notQuit();
	void setEvent(eventype);


};

#endif
