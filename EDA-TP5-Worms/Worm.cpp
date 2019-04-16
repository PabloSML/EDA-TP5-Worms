#include "Worm.h"

Worm::Worm(float x_, float y_, direction dir_, const char* name)
{
	pos_y = y_;
	pos_x = x_;
	look = dir_;
	state = IDLE;
	this->name = name;
	counter = 0;
	walkCycle[0] = WALK4; walkCycle[1] = WALK5; walkCycle[2] = WALK6; walkCycle[3] = WALK7;
	walkCycle[4] = WALK8; walkCycle[5] = WALK9; walkCycle[6] = WALK10; walkCycle[7] = WALK11;
	walkCycle[8] = WALK11; walkCycle[9] = WALK12; walkCycle[10] = WALK13; walkCycle[11] = WALK14;
	walkCycle[12] = WALK15;

	jumpCycle[0] = JUMP1; jumpCycle[1] = JUMP2; jumpCycle[2] = JUMP3; jumpCycle[3] = JUMP4;
	jumpCycle[4] = JUMP5; jumpCycle[5] = JUMP6; jumpCycle[6] = JUMP7; jumpCycle[7] = JUMP8;
	jumpCycle[8] = JUMP9; jumpCycle[9] = JUMP10; jumpCycle[10] = JUMP9; jumpCycle[11] = JUMP8;
	jumpCycle[12] = JUMP7; jumpCycle[13] = JUMP6;
}

void
Worm::draw(float w_dis, float h_dis)
{
	if (look == RIGHT) //si el worm tiene que mirar hacia la derecha roto el bitmap
	{
		al_draw_scaled_bitmap(image, 0, 0, al_get_bitmap_width(image), al_get_bitmap_height(image), \
							 (pos_x * POS_X_RATIO_AJUST) - (w_dis * RATIO_WORM_AJUST * ERROR_BORDER_WIDTH_RATIO), \
							 (pos_y * POS_Y_RATIO_AJUST) - (h_dis * RATIO_WORM_AJUST * ERROR_BORDER_HIGH_RATIO), \
							  w_dis * RATIO_WORM_AJUST, h_dis * RATIO_WORM_AJUST, ALLEGRO_FLIP_HORIZONTAL);
	} 
	else //Dibujo la imagen del worm normal
	{
		al_draw_scaled_bitmap(image, 0, 0, al_get_bitmap_width(image),al_get_bitmap_height(image), \
							 (pos_x * POS_X_RATIO_AJUST) - (w_dis * RATIO_WORM_AJUST * ERROR_BORDER_WIDTH_RATIO) , \
							 (pos_y * POS_Y_RATIO_AJUST) - (h_dis * RATIO_WORM_AJUST * ERROR_BORDER_HIGH_RATIO), \
			                  w_dis * RATIO_WORM_AJUST, h_dis * RATIO_WORM_AJUST, 0);
	}
}

void
Worm::startWalking(char key)
{
	if (state == IDLE)	//Verifico que el worm este quieto
	{
		if (name == WORM1_NAME)	 //Verifico que sea el worm 1  para utilizar las teclas correspondientes 
		{
			if (key == '>')		//Si se presiono la flecha derecha
			{
				look = RIGHT;
				state = START_WALKING;
			}
			else if (key == '<') //Si se presiono la flecha derecha
			{
				look = LEFT;
				state = START_WALKING;
			}
		}
		else if (name == WORM2_NAME) // Verifico que sea el worm 2  para utilizar las teclas correspondientes
		{
			if (key == 'd')		//Si se presiono la tecla d
			{
				look = RIGHT;	
				state = START_WALKING; 
			}
			else if (key == 'a')	//Si se presiono la tecla a
			{
				look = LEFT;
				state = START_WALKING;
			}
		}
	}
}
void

Worm::stopWalking(char key)
{
	if (state == START_WALKING || state == WALKING)		 //verifico los estaods del worm
	{
		if (name == WORM1_NAME && (key == '>' || key == '<'))	//verifico que el worm 1 y sus teclas coincidan
			state = STOP_WALKING;
		else if (name == WORM2_NAME && (key == 'd' || key == 'a')) //verifico que el worm 2 y sus teclas coincidan
			state = STOP_WALKING;
	}
}
void

Worm::startJumping(char key)
{
	if (state == IDLE && ((name == WORM1_NAME && key == '^') || (name == WORM2_NAME && key == 'w')))
		state = JUMPING;
}
void

Worm::stopJumping(char key)
{
	if (state == JUMPING)	//verifico el estado del worm
	{
		if(name == WORM1_NAME && key == '^')	//verifico que el worm 1 y sus teclas coincidan
			state = STOP_JUMPING;
		else if (name == WORM2_NAME && key == 'w')  //verifico que el worm 2 y sus teclas coincidan
			state = STOP_JUMPING;
	}
}

void
Worm::update()
{
	int index;	// este index sera usado para acceder a los respectivos arreglos de imagenes walkCycle y jumpCycle
	int t;	// t representa la variable temporal para la fisica de los worms. En esta implementacion esta ligada a los frames
	switch (state)
	{
	case IDLE:
		break;
	case START_WALKING:		// en el estado START_WALKING se espera que pasen los 100ms para pasar al estado WALKING si no se recibe otro evento (warm-up)
		counter++;
		if (counter == MOVE_THRESHOLD)
			state = WALKING;
		break;
	case WALKING: case STOP_WALKING:	// los dos estados ejecutan el walkCycle del worm. La diferencia es que al concluir, WALKING pasa a START WALKING
//											mientras que STOP_WALKING pasa a IDLE

		if (counter < MOVE_THRESHOLD)	// si o si se esta en STOP_WALKING. Se resetea el contador y se pasa a IDLE
		{
			counter = 0;
			state = IDLE;
			deloadimg();
			loadimg(walkCycle[0]);
		}
		else if (counter == MOVE_THRESHOLD)	// las primeras tres imagenes que se muestran pasado el MOVE_THRESHOLD corresponden al warm-up visual del worm
		{
			counter++;
			deloadimg();
			loadimg(WALK1);
		}
		else if (counter == MOVE_THRESHOLD + 1)
		{
			counter++;
			deloadimg();
			loadimg(WALK2);
		}
		else if (counter == MOVE_THRESHOLD + 2)
		{
			counter++;
			deloadimg();
			loadimg(WALK3);
		}
		else    // una vez realizado el warm-up visual, se entra en el walkCyle, el cual correra tres veces desplazando el worm en 27 pixeles en total
		{
			if ((look == LEFT && (pos_x - MOVEMENT_UNIT) > POS_MIN_X) || (look == RIGHT && (pos_x + MOVEMENT_UNIT) < POS_MAX_X)) // se verifica no salir de los limites
			{
				counter++;
				index = counter - 9;	// este offset de 9 permite a index apuntar a la imagen de walkCycle que corresponde e incrementarse a la par del counter
				deloadimg();
				if (index < 13)		// durante los primeros frames, la imagen simula movimiento aunque la pos_x del worm no varia
					loadimg(walkCycle[index]);
				else if (index == 13 || index == 27) // en estos frames se realiza efectivamente un desplazamiento de 9 pixeles del worm. 
//														Entre estos dos desplazamientos y uno mas adelante se logran los 27 pixeles totales
				{
					if (look == LEFT)
						pos_x -= 9;
					else if (look == RIGHT)
						pos_x += 9;
					loadimg(walkCycle[0]);
				}
				else if (index < 27)	// en el segundo ciclo de walkCycle, el indice se decrementa en 14 para conseguir un indice valido del arreglo
				{	
					index -= 14;
					loadimg(walkCycle[index]);
				}
				else if (index < 41)	// en el tercer ciclo, se decrementa en 28 para lograr el indice valido
				{
					index -= 28;
					loadimg(walkCycle[index]);
				}
				else if (index == 41)	// el ultimo frame. Se pasa al proximo estado correspondiente, se realiza el desplazamiento final y se resetea counter
				{
					if (state == WALKING)
						state = START_WALKING;
					else if (state == STOP_WALKING)
						state = IDLE;
					counter = 0;
					if (look == LEFT)
						pos_x -= 9;
					else if (look == RIGHT)
						pos_x += 9;
					loadimg(walkCycle[0]);
				}
			}
			else
			{
				state = IDLE;
				counter = 0;
			}
		}

		break;

	case JUMPING: case STOP_JUMPING:	// analogamente a la caminata, la diferencia radica en el estado al que se llega una vez finalizado el salto
		deloadimg();
		counter++;

		if (counter < 3 || counter == 49)	// dos frames sin movimiento al principio y al final
		{
			if(counter == 1)
				posx0 = pos_x;	//se guarda la posicion inicial en x para hacer el calculo de trayectoria
			loadimg(WALK1);
		}
		else if (counter < 7)	// el manejo del indice es analogo al caso de la caminata
		{
			index = counter - 3;
			loadimg(jumpCycle[index]);
		}
		else if (counter < 40)	// durante 33 frames, la imagen sera la misma y se calcula la trayectoria del worm
		{
			t = counter - 6; // establece la relacion entre t (tiempo teorico) y el numero de frame

			// a continuacion estan los calculos del desplazamiento horizontal en el tiempo(frames) segun el sentido de la mirada
			if (look == RIGHT)
			{
				pos_x = posx0 + 4.5*(1.0/2.0)*t;	// 1/2 = cos(60)
				if (pos_x > POS_MAX_X)
					pos_x = POS_MAX_X;
			}
			else if (look == LEFT)
			{
				pos_x = posx0 - 4.5*(1.0/2.0)*t;
				if (pos_x < POS_MIN_X)
					pos_x = POS_MIN_X;
			}

			pos_y = (INICIAL_Y_POSITION_PLAYER) - (4.5)*(sin(M_PI / 3.0))*(t) + (1.0 / 2.0) * GRAV * t * t;	// calculo de la altura segun el tiempo(frames)

			loadimg(jumpCycle[4]);
		}
		else if (counter < 49)	// los frames posteriores a la caida muestran la amortiguacion del impacto
		{
			index = counter - 35;
			loadimg(jumpCycle[index]);
		}
		else if (counter == 50)	// en el ultimo frame se pasa al siguiente estado correspondiente, se resetea counter y se ajusta la posicion en el eje y
		{
			if (state == STOP_JUMPING)
				state = IDLE;
			counter = 0;
			loadimg(jumpCycle[4]);
			pos_y = INICIAL_Y_POSITION_PLAYER; // la ecuacion del tiro oblicuo no resulta exactamente en el piso luego de 33 frames, se corrige ese delta	
		}
		break;
	}
}