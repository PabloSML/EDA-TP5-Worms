#include "Worm.h"

Worm::Worm()
{
}

void
Worm::draw(float w_dis, float h_dis)
{
	al_draw_scaled_bitmap(image, 0, 0, al_get_bitmap_width(image), \
		al_get_bitmap_height(image), w_dis / 2, h_dis / 2, w_dis/10, h_dis/10, 0);
	al_flip_display();
}

void
Worm::walk()
{
	
}

void
Worm::jump()
{

}