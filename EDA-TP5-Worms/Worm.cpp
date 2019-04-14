#include "Worm.h"

Worm::Worm(float x_, direction dir_)
{
	pos_y = POS_Y;
	pos_x = x_;
	old_look = dir_;
	look = dir_;
}

void
Worm::draw(float w_dis, float h_dis)
{
	if (look != old_look)
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
Worm::walk(char key,int cont)
{
	if (cont >= MOVE_THRESHOLD && (key == 'd' || key == '>'))
		pos_x += MOVEMENT_UNIT;	//Mueve el worm 27 pixeles a la derecha
	else if (cont >= MOVE_THRESHOLD && (key == 'a' || key == '<'))
		pos_x -= MOVEMENT_UNIT;	//Mueve el worm 27 pixeles a la izquierda
	else if (cont < MOVE_THRESHOLD && (key == 'd' || key == '>'))
	{
		old_look = look;	//Guarda la mirada que tenia el worm
		look = RIGHT;	//Cambia la mirada del worm hacia la derecha
	}
	else if (cont == MOVE_THRESHOLD && (key == 'a' || key == '<'))
	{
		old_look = look;	//Guarda la mirada que tenia el worm
		look = LEFT;		//Cambia la mirada del worm hacia la izquierda
	}
}

void
Worm::jump()
{

}