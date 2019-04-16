#ifndef SCENE_H
#define SCENE_H

//*************************************************INCLUDE*************************************************
#include "Drawable.h"

using namespace std;

//*************************************************DEFINE*************************************************
#define SCENARIO_FILE "Scenario.png"

//*************************************************CLASS*************************************************
class Scene : public Drawable
{
public:
	//Constructor
	Scene(){}

	//Metodo virtual
	virtual void draw(float w_dis, float h_dis);
};

#endif