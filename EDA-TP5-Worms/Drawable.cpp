#include "Drawable.h"

bool
Drawable::loadimg(const char* fileName)
{
	bool success = true;
	image = al_load_bitmap(fileName);	//cargo la imagen definida en fileNmae
	if (!image)
	{
		cout << "Failed to load drawable bitmap!" << endl;
		success = false;
	}
	return success;
}

void
Drawable::deloadimg()
{
	al_destroy_bitmap(image);	//destruyo la imagen y su posicion de memoria reservada asociada
	image = NULL;
}

void
drawAll(Drawable** drawables, int cant,float w_dis, float h_dis)
{
	for (int i = 0 ; i < cant; i++)
	{
		drawables[i]->draw(w_dis,h_dis);	//Dibujo todos los objetos drawables
	}
}

