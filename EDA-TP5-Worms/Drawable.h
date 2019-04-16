#ifndef DRAWABLE_H
#define DRAWABLE_H

//*************************************************INCLUDES*************************************************
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <iostream>

using namespace std;

//*************************************************CLASS*************************************************
class Drawable
{
public:
	//Constructor
	Drawable(){}

	//Metodos
	bool loadimg(const char* fileName);
	void deloadimg();
	virtual void draw(float,float) = 0; // la funcion de draw debe ser redefinida por cada drawable distinto

protected:
	ALLEGRO_BITMAP* image; //la imagen asociada al drawable
};

// esta funcion recibe un arreglo de punteros a drawables y ejecuta el metodo draw de cada uno
void drawAll(Drawable** drawables, int cant, float w_dis,float h_dis);

#endif