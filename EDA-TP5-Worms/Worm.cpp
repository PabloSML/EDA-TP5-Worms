#include "Worm.h"

Worm::Worm(float x_, float y_, direction dir_)
{
	pos_y = y_;
	pos_x = x_;
	look = dir_;
}

void
Worm::draw(float w_dis, float h_dis)
{
	if (look == RIGHT) //si el worm tiene que mirar hacia la derecha roto el bitmap
	{
		//al_draw_filled_circle(701* POS_X_RATIO_AJUST, 616*POS_Y_RATIO_AJUST,10, al_map_rgb(255, 255, 255)); //solo para debugging, borrar antes de entregar
		//al_draw_filled_circle(1212*POS_X_RATIO_AJUST, 616*POS_Y_RATIO_AJUST,10, al_map_rgb(255, 255, 255)); //solo para debugging, borrar antes de entregar
		al_draw_scaled_bitmap(image, 0, 0, al_get_bitmap_width(image), al_get_bitmap_height(image), \
							 (pos_x * POS_X_RATIO_AJUST) - (w_dis * RATIO_WORM_AJUST * ERROR_BORDER_WIDTH_RATIO), \
							 (pos_y * POS_Y_RATIO_AJUST) - (h_dis * RATIO_WORM_AJUST * ERROR_BORDER_HIGH_RATIO), \
							  w_dis * RATIO_WORM_AJUST, h_dis * RATIO_WORM_AJUST, ALLEGRO_FLIP_HORIZONTAL);
	} 
	else //Dibujo la imagen del worm normal
	{
		//al_draw_filled_circle(701 * POS_X_RATIO_AJUST, 616*POS_Y_RATIO_AJUST, 10, al_map_rgb(255, 255, 255)); //solo para debugging, borrar antes de entregar
		//al_draw_filled_circle(1212 *POS_X_RATIO_AJUST, 616*POS_Y_RATIO_AJUST, 10, al_map_rgb(255, 255, 255)); //solo para debugging, borrar antes de entregar
		al_draw_scaled_bitmap(image, 0, 0, al_get_bitmap_width(image),al_get_bitmap_height(image), \
							 (pos_x * POS_X_RATIO_AJUST) - (w_dis * RATIO_WORM_AJUST * ERROR_BORDER_WIDTH_RATIO) , \
							 (pos_y * POS_Y_RATIO_AJUST) - (h_dis * RATIO_WORM_AJUST * ERROR_BORDER_HIGH_RATIO), \
			                  w_dis * RATIO_WORM_AJUST, h_dis * RATIO_WORM_AJUST, 0);
	}
	al_flip_display();
}

void
Worm::walk(char key, int cont)
{
	if (cont > MOVE_THRESHOLD && (key == 'd' || key == '>') && pos_x < 1125) //le reste 60 mas por el tamaño del gusano
	{
		look = RIGHT;
		pos_x += MOVEMENT_UNIT;	//Mueve el worm 27 pixeles a la derecha
	}
	else if (cont > MOVE_THRESHOLD && (key == 'a' || key == '<') && pos_x > 728)
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
