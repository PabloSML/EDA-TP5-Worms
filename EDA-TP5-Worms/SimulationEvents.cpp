#include "SimulationEvents.h"



SimulationEvents::SimulationEvents()
{
}

eventype
SimulationEvents::getEvent()
{
	eventype ev = NO_EVENT;

	return ev;
}

bool
SimulationEvents::isThereEvent()
{
	return true;
}

bool
SimulationEvents::notQuit()
{
	return true;
}

void 
SimulationEvents::setEvent(eventype)
{

}