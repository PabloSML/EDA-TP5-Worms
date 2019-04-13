#include "Drawable.h"
#include <iostream>
using namespace std;

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
drawAll(Drawable** drawables, int cant)
{
	for (int i = 0; i < cant; i++)
	{
		drawables[i]->draw();
	}
}

