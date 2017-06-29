#include "object.h"

Object::Object(ALLEGRO_BITMAP* sprite, int x, int y)
{
    this->sprite = sprite;
    this->x = x;
    this->y = y;
}

Object::~Object()
{
    al_destroy_bitmap(sprite);
}
