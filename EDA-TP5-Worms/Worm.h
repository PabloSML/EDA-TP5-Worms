#ifndef WORM_H
#define WORM_H

#include "Drawable.h"
#include <allegro5/allegro_primitives.h>	//solo para debugging, borrar antes de entregar

#define CANT_OF_PLAYERS (2)	//Cantidad de players
#define WORM1_NAME "Agustin"
#define WORM2_NAME "Marc"
#define ONE	(0)		//Player 1 (ocupa el lugar 0 del arreglo "drawables")
#define TWO (1)		//Player 2 (ocupa el lugar 1 del arreglo "drawables")
#define OBJECTS_DRAWABLES (CANT_OF_PLAYERS+1)	//Cantidad de objetos dibujables = jugadores + escenario
#define INICIAL_X_POSITION_PLAYER_1 (701.0)		//FALTA DEBUGUEAR LA POSICION INCIAL
#define INICIAL_X_POSITION_PLAYER_2 (1050.0)	//FALTA DEBUGUEAR LA POSICION INCIAL
#define INICIAL_Y_POSITION_PLAYER_2 (616.0)
#define MOVE_THRESHOLD (5) //El timer da eventos cada 20 ms. Si se multiplica por 5 seran 100ms (el umbral elegido para el movimiento)
#define MOVEMENT_UNIT  (27.0)			//El worm se mueve a razon de 27 pixeles 
//#define POS_X_RATIO_AJUST (1.0)	//Ajuste de resolucion eje x
//#define POS_Y_RATIO_AJUST (1.0)	//Ajuste de resolucion eje y
#define POS_X_RATIO_AJUST (0.7114583)	//Ajuste de resolucion eje x
#define POS_Y_RATIO_AJUST (1.1034483)	//Ajuste de resolucion eje y
#define POS_MIN_X (630.0)
#define POS_MAX_X (1130.0)
#define ERROR_BORDER_IMAGE_HIGH (42.0)	//La imagen tiene que "correrse" 42.0 para que el worm sea dibujado correctamente
#define ERROR_BORDER_IMAGE_WIDTH (30)	//La imagen tiene que "correrse" para que el worm se dibuje correctamente y que se quede en el mismo lugar cuando "flipee"
#define TOTALS_IMAGE_PIXELS (60)		//Pixeles de ancho y largo de las imagenes de los worms
#define RATIO_WORM_AJUST (0.08)			//Porcentaje de reduccion de las imagenes originales (eleccion propia)
#define ERROR_BORDER_HIGH_RATIO (ERROR_BORDER_IMAGE_HIGH / TOTALS_IMAGE_PIXELS)		
#define ERROR_BORDER_WIDTH_RATIO (ERROR_BORDER_IMAGE_WIDTH / TOTALS_IMAGE_PIXELS)



enum direction {RIGHT,LEFT};
enum wormState {IDLE, START_WALKING, WALKING, STOP_WALKING, JUMPING, STOP_JUMPING};

using namespace std;

class Worm : public Drawable
{
public:
	//Constructor
	Worm(float x_, float y_, direction dir_, const char* name);

	//Getters
	int getXCord(void) { return pos_x; };
	int getYCord(void) { return pos_y; };

	virtual void draw(float w_dis, float h_dis);

	void update();

	void startWalking(char key);
	void stopWalking(char key);

	void startJumping(char key);
	void stopJumping(char key);

private:
	const char* name;
	float pos_x;
	float pos_y;
	direction look;
	wormState state;
	int counter;
	const char* walkCycle[13];
	const char* jumpCycle[14];
	float posx0;
};

#endif
