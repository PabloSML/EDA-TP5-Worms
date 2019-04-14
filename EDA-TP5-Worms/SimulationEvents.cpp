#include "SimulationEvents.h"



SimulationEvents::SimulationEvents()
{
	cont = 0;
	event_ = NO_EVENT;
}


bool
SimulationEvents::isThereEvent()
{
	if (event_ != NO_EVENT )
		return true;
	else
		return false;
}

bool
SimulationEvents::notQuit()
{
	//Funcion sin utilizar
	return true;
}

void 
SimulationEvents::setEvent(eventype)
{
	//Funcion sin utilizar
}

void 
SimulationEvents::incrementCont(void)
{
	cont += 1;
	if (cont == MAX_COUNTER_VALUE)
		event_ = FULL_COUNTER;
}