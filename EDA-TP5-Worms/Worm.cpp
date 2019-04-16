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
	if (state == IDLE)
	{
		if (name == WORM1_NAME)
		{
			if (key == '>')
			{
				look = RIGHT;
				state = START_WALKING;
			}
			else if (key == '<')
			{
				look = LEFT;
				state = START_WALKING;
			}
		}
		else if (name == WORM2_NAME)
		{
			if (key == 'd')
			{
				look = RIGHT;
				state = START_WALKING;
			}
			else if (key == 'a')
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
	if (state == START_WALKING || state == WALKING)
	{
		if (name == WORM1_NAME && (key == '>' || key == '<'))
			state = STOP_WALKING;
		else if (name == WORM2_NAME && (key == 'd' || key == 'a'))
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
	if (state == JUMPING)
	{
		if(name == WORM1_NAME && key == '^')
			state = STOP_JUMPING;
		else if (name == WORM2_NAME && key == 'w')
			state = STOP_JUMPING;
	}
}

void
Worm::update()
{
	int index;
	int t;
	switch (state)
	{
	case IDLE:
		break;
	case START_WALKING:
		counter++;
		if (counter == MOVE_THRESHOLD)
			state = WALKING;
		break;
	case WALKING: case STOP_WALKING:
		if (counter < 5)	// si o si estoy en STOP_WALKING
		{
			counter = 0;
			state = IDLE;
			deloadimg();
			loadimg(walkCycle[0]);
		}
		else if (counter == MOVE_THRESHOLD)
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
		else
		{
			if ((look == LEFT && (pos_x - MOVEMENT_UNIT) > POS_MIN_X) || (look == RIGHT && (pos_x + MOVEMENT_UNIT) < POS_MAX_X))
			{
				counter++;
				index = counter - 9;	//obtengo un indice para el walkCycle
				deloadimg();
				if (index < 13)
					loadimg(walkCycle[index]);
				else if (index == 13 || index == 27)
				{
					if (look == LEFT)
						pos_x -= 9;
					else if (look == RIGHT)
						pos_x += 9;
					loadimg(walkCycle[0]);
				}
				else if (index < 27)
				{
					index -= 14;
					loadimg(walkCycle[index]);
				}
				else if (index < 41)
				{
					index -= 28;
					loadimg(walkCycle[index]);
				}
				else if (index == 41)
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

	case JUMPING: case STOP_JUMPING:
		deloadimg();
		counter++;

		if (counter < 3 || counter == 49)	// dos frames sin movimiento al principio y al final
		{
			if(counter == 1)
				posx0 = pos_x;	//se guarda la posicion inicial en x para hacer el calculo de trayectoria
			loadimg(WALK1);
		}
		else if (counter < 7)
		{
			index = counter - 3;
			loadimg(jumpCycle[index]);
		}
		else if (counter < 40)
		{
			t = counter - 6; // establece la relacion entre t (tiempo teorico) y el numero de frame

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

			pos_y = (INICIAL_Y_POSITION_PLAYER_2) - (4.5)*(sin(M_PI / 3.0))*(t) + (1.0 / 2.0) * (0.24) * t * t;

			loadimg(jumpCycle[4]);
		}
		else if (counter < 49)
		{
			index = counter - 35;
			loadimg(jumpCycle[index]);
		}
		else if (counter == 50)
		{
			if (state == STOP_JUMPING)
				state = IDLE;
			counter = 0;
			loadimg(jumpCycle[4]);
		}
		break;
	}
}