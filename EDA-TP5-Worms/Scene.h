#ifndef SCENE_H
#define SCENE_H

#include "Drawable.h"

class Scene : public Drawable
{
public:
	Scene(){}

	void draw(float w_dis, float h_dis);
};

#endif