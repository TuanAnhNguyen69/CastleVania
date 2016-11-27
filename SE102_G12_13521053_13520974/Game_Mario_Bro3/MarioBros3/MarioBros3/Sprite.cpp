#include "Sprite.h"


Sprite::Sprite(int count)
{
	index = 0;
	_count = count;
	listAction = new Animation*[count];
}

Animation* Sprite::get(int i)
{
   	return listAction[i];
}

void Sprite::Add(Animation* item)
{
	listAction[index] = item;
	index++;
}

Sprite::~Sprite()
{
}
