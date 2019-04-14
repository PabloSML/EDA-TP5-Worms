#ifndef WORM_H
#define WORM_H


#define PLAYERS (2)	//Cantidad de players
#define ONE	(0)		//Player 1 (ocupa el lugar 0 del arreglo "drawables")
#define TWO (1)		//Player 2 (ocupa el lugar 1 del arreglo "drawables")
//Si se agregan mas players se debe modificar el arreglo "drawables" del main
#define OBJECTS_DRAWABLES (PLAYERS+1)	//Cantidad de objetos dibujables = jugadores + escenario
#define MOVE_THRESHOLD (5) //El timer da eventos cada 20 ms. Si se multiplica por 5 seran 100ms (el umbral elegido para el movimiento)

#include "Drawable.h"

class Worm : public Drawable
{
public:
	Worm();

	void draw(float w_dis, float h_dis);
	void walk();
	void jump();

private:
	int direction;
	int speed;
	
};

#endif
