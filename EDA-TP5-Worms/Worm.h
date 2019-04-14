#ifndef WORM_H
#define WORM_H

#include "Drawable.h"

#define CANT_OF_PLAYERS (2)	//Cantidad de players
#define ONE	(0)		//Player 1 (ocupa el lugar 0 del arreglo "drawables")
#define TWO (1)		//Player 2 (ocupa el lugar 1 del arreglo "drawables")
#define OBJECTS_DRAWABLES (CANT_OF_PLAYERS+1)	//Cantidad de objetos dibujables = jugadores + escenario
#define INICIAL_POSITION_PLAYER_1 (701.0)
#define INICIAL_POSITION_PLAYER_2 (1212.0)
#define MOVE_THRESHOLD (5) //El timer da eventos cada 20 ms. Si se multiplica por 5 seran 100ms (el umbral elegido para el movimiento)
#define MOVEMENT_UNIT  (27.0)
#define ERROR_AJUST (5.5)
#define POS_Y (616.0 + ERROR_AJUST)
#define POS_X


enum direction{RIGHT,LEFT};

using namespace std;

class Worm : public Drawable
{
public:
	//Constructor
	Worm(float x_, direction dir_);

	//Getters
	int getXCord(void) { return pos_x; };
	int getYCord(void) { return pos_y; };

	virtual void draw(float w_dis, float h_dis);
	void walk(char key,int cont);
	void jump();

private:

	float pos_x;
	float pos_y;
	direction old_look;
	direction look;
};

#endif
