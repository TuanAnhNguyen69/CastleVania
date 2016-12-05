#include "Ground.h"


Ground::Ground()
{
	_collType = CollGround;
}


void Ground::setObjectFromID()
{
	if (id == 14)
	{
		_collType = CollStair;
	}
}


void Ground::Draw()
{
}


Ground::~Ground()
{
}
