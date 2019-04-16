#include "Scene.h"

void
Scene::draw(float w_dis, float h_dis)
{
	al_clear_to_color(al_map_rgb(255, 255, 102));	//seteo el color de fondo
	al_draw_scaled_bitmap(image, 0, 0,al_get_bitmap_width(image), \
						  al_get_bitmap_height(image), 0, 0, w_dis, h_dis,0);	//dibujo el escenario escalandolo a la resolucion elegida
}