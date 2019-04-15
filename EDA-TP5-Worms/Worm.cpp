#include "Worm.h"

Worm::Worm(float x_, direction dir_)
{
	pos_y = POS_Y;
	pos_x = x_;
	look = dir_;
}

void
Worm::draw(float w_dis, float h_dis)
{
	if (look == RIGHT)
	{
		al_draw_scaled_bitmap(image, 0, 0, al_get_bitmap_width(image), \
							  al_get_bitmap_height(image), pos_x - w_dis / 20, pos_y - h_dis / 20, \
							  w_dis / 10, h_dis / 10, ALLEGRO_FLIP_HORIZONTAL);
	}
	else
	{
		al_draw_scaled_bitmap(image, 0, 0, al_get_bitmap_width(image), \
							  al_get_bitmap_height(image), pos_x - w_dis / 10, pos_y - h_dis / 20, \
			                  w_dis / 10, h_dis / 10, 0);
	}
	al_flip_display();
}

void
Worm::walk(char key, int cont)
{
	if (cont > MOVE_THRESHOLD && (key == 'd' || key == '>'))
	{
		look = RIGHT;
		pos_x += MOVEMENT_UNIT;	//Mueve el worm 27 pixeles a la derecha
	}
	else if (cont > MOVE_THRESHOLD && (key == 'a' || key == '<'))
	{
		look = LEFT;
		pos_x -= MOVEMENT_UNIT;	//Mueve el worm 27 pixeles a la izquierda
	}
	else if (cont <= MOVE_THRESHOLD && (key == 'd' || key == '>'))
	{
		look = RIGHT;
	}
	else if (cont <= MOVE_THRESHOLD && (key == 'a' || key == '<'))
	{
		look = LEFT;
	}
}

void
Worm::jump(void)
{

}
