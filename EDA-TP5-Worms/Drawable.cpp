#include "Drawable.h"

bool
Drawable::init(const char* fileName)
{
	bool success = true;
	image = al_load_bitmap(fileName);
	if (!image)
	{
		cout << "Failed to load drawable bitmap!" << endl;
		success = false;
	}
	return success;
}

void
Drawable::deinit()
{
	al_destroy_bitmap(image);
}

void
drawAll(Drawable** drawables, int cant,float w_dis, float h_dis)
{
	for (int i = 0; i < cant; i++)
	{
		drawables[i]->draw(w_dis,h_dis);
	}
}

