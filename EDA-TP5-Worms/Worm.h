#ifndef WORM_H
#define WORM_H

//*************************************************INCLUDES*************************************************
#include "Drawable.h"
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

//*************************************************DEFINES*************************************************
#define CANT_OF_PLAYERS (2)	//Cantidad de players
#define WORM1_NAME "Agustin"	//Nombre player1
#define WORM2_NAME "Marc"		//Nombre player2
#define ONE	(0)		//Player 1 (ocupa el lugar 0 del arreglo "drawables")
#define TWO (1)		//Player 2 (ocupa el lugar 1 del arreglo "drawables")
#define OBJECTS_DRAWABLES (CANT_OF_PLAYERS+1)	//Cantidad de objetos dibujables = jugadores + escenario
#define INICIAL_X_POSITION_PLAYER_1 (701.0)		
#define INICIAL_X_POSITION_PLAYER_2 (1050.0)	
#define INICIAL_Y_POSITION_PLAYER_2 (616.0)
#define MOVE_THRESHOLD (5)	 //El timer da eventos cada 20 ms. Si se multiplica por 5 seran 100ms (el umbral elegido para el movimiento)
#define MOVEMENT_UNIT  (27.0)			//El worm se mueve a razon de 27 pixeles 
#define POS_X_RATIO_AJUST (0.7114583)	//Ajuste de resolucion eje x (ver tabla en allegroAux.h para verificar)
#define POS_Y_RATIO_AJUST (1.1034483)	//Ajuste de resolucion eje y (ver tabla en allegroAux.h para verificar)
#define POS_MIN_X (630.0)				//Posicion minima real en la que se debe setear x para que el bitmap se dibuje entre 701-1212
#define POS_MAX_X (1130.0)				//Posicion maxima real en la que se debe setear x para que el bitmap se dibuje entre 701-1212
#define ERROR_BORDER_IMAGE_HIGH (42.0)	//La imagen tiene que "correrse" 42.0 para que el worm sea dibujado correctamente
#define ERROR_BORDER_IMAGE_WIDTH (30)	//La imagen tiene que "correrse" para que el worm se dibuje correctamente y que se quede en el mismo lugar cuando "flipee"
#define TOTALS_IMAGE_PIXELS (60)		//Pixeles de ancho y largo de las imagenes de los worms
#define RATIO_WORM_AJUST (0.08)			//Porcentaje de reduccion de las imagenes originales (eleccion propia)
#define ERROR_BORDER_HIGH_RATIO (ERROR_BORDER_IMAGE_HIGH / TOTALS_IMAGE_PIXELS)		//Porcentaje del borde sobre la imagen (en este caso 0.5) 	
#define ERROR_BORDER_WIDTH_RATIO (ERROR_BORDER_IMAGE_WIDTH / TOTALS_IMAGE_PIXELS)	//Porcentaje del borde sobre la imagen (en este caso 0.5)
#define GRAV = (0.24)		//Constante de gravedad
#define WORM_IMAGE "wwalk-F4.png"

	//************ IMAGENES DE WALK **********************
#define WALK1 "wwalk-F1.png"
#define WALK2 "wwalk-F2.png"
#define WALK3 "wwalk-F3.png"
#define WALK4 "wwalk-F4.png"
#define WALK5 "wwalk-F5.png"
#define WALK6 "wwalk-F6.png"
#define WALK7 "wwalk-F7.png"
#define WALK8 "wwalk-F8.png"
#define WALK9 "wwalk-F9.png"
#define WALK10 "wwalk-F10.png"
#define WALK11 "wwalk-F11.png"
#define WALK12 "wwalk-F12.png"
#define WALK13 "wwalk-F13.png"
#define WALK14 "wwalk-F14.png"
#define WALK15 "wwalk-F15.png"	
	//************ IMAGENES DE JUMP **********************
#define JUMP1 "wjump-F1.png"
#define JUMP2 "wjump-F2.png"
#define JUMP3 "wjump-F3.png"
#define JUMP4 "wjump-F4.png"
#define JUMP5 "wjump-F5.png"
#define JUMP6 "wjump-F6.png"
#define JUMP7 "wjump-F7.png"
#define JUMP8 "wjump-F8.png"
#define JUMP9 "wjump-F9.png"
#define JUMP10 "wjump-F10.png"
	//*****************************************************

//*************************************************ENUMS*************************************************
//Direccion hacia donde esta orientada la mirada del worm
enum direction {RIGHT,LEFT};
//Estados del worm
enum wormState {IDLE, START_WALKING, WALKING, STOP_WALKING, JUMPING, STOP_JUMPING};

//*************************************************CLASS*************************************************
class Worm : public Drawable
{
public:
	//Constructor
	Worm(float x_, float y_, direction dir_, const char* name);

	//Getters
	int getXCord(void) { return pos_x; };
	int getYCord(void) { return pos_y; };

	//Metodos
	virtual void draw(float w_dis, float h_dis);

	void update();

	void startWalking(char key);	//Movimiento del worm
	void stopWalking(char key);		//El worm deja de moverse si se solto alguna tecla de movimiento correspondiente

	void startJumping(char key);	//Salto del worm
	void stopJumping(char key);		//El worm deja de saltar si se solto la tecla de salto  correspondiente

private:
	const char* name;	
	float pos_x;		
	float pos_y;
	direction look;
	wormState state;
	int counter;		//Contador de eventos
	const char* walkCycle[13];
	const char* jumpCycle[14];
	float posx0;
};

#endif
