#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

class Drawable
{
public:
	Drawable(){}

	bool init(const char* fileName);
	void deinit();
	virtual void draw() = 0; // la funcion de draw debe ser redefinida por cada drawable distinto

protected:
	ALLEGRO_BITMAP* image; //la imagen asociada al drawable
private:

};

// esta funcion recibe un arreglo de punteros a drawables y ejecuta el metodo draw de cada uno
void drawAll(Drawable** drawables, int cant);