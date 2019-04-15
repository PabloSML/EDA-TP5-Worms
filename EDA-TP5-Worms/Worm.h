#ifndef WORM_H
#define WORM_H

#include "Drawable.h"
#include <allegro5/allegro_primitives.h>	//solo para debugging, borrar antes de entregar

#define CANT_OF_PLAYERS (2)	//Cantidad de players
#define ONE	(0)		//Player 1 (ocupa el lugar 0 del arreglo "drawables")
#define TWO (1)		//Player 2 (ocupa el lugar 1 del arreglo "drawables")
#define OBJECTS_DRAWABLES (CANT_OF_PLAYERS+1)	//Cantidad de objetos dibujables = jugadores + escenario
#define INICIAL_X_POSITION_PLAYER_1 (701.0)		//FALTA DEBUGUEAR LA POSICION INCIAL
#define INICIAL_X_POSITION_PLAYER_2 (1200.0)	//FALTA DEBUGUEAR LA POSICION INCIAL
#define INICIAL_Y_POSITION_PLAYER_2 (616.0)
#define MOVE_THRESHOLD (5) //El timer da eventos cada 20 ms. Si se multiplica por 5 seran 100ms (el umbral elegido para el movimiento)
#define MOVEMENT_UNIT  (27.0)
#define POS_X_RATIO_AJUST (0.7114583)	//Ajuste de resolucion eje x
#define POS_Y_RATIO_AJUST (1.1034483)
#define ERROR_BORDER_IMAGE_HIGH (42.0)
#define ERROR_BORDER_IMAGE_WIDTH (30)
//#define ERROR_BORDER_IMAGE_WIDTH_FLIP ()
#define TOTALS_IMAGE_PIXELS (60)
#define RATIO_WORM_AJUST (0.08)
#define ERROR_BORDER_HIGH_RATIO (ERROR_BORDER_IMAGE_HIGH / TOTALS_IMAGE_PIXELS)
#define ERROR_BORDER_WIDTH_RATIO (ERROR_BORDER_IMAGE_WIDTH / TOTALS_IMAGE_PIXELS)
//#define ERROR_BORDER_WIDTH_RATIO_FLIP (ERROR_BORDER_IMAGE_WIDTH_FLIP / TOTALS_IMAGE_PIXELS)



enum direction{RIGHT,LEFT};

using namespace std;

class Worm : public Drawable
{
public:
	//Constructor
	Worm(float x_, float y_, direction dir_);

	//Getters
	int getXCord(void) { return pos_x; };
	int getYCord(void) { return pos_y; };

	virtual void draw(float w_dis, float h_dis);
	void walk(char key,int cont);
	void jump();

private:
	float pos_x;
	float pos_y;
	direction look;
};

#endif
