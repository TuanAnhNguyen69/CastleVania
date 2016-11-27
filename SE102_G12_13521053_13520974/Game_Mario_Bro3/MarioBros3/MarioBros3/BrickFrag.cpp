#include "BrickFrag.h"


BrickFrag::BrickFrag()
{
	_listAction = SpriteManager::GetInstance()->listAnimation[SpriteFrag];
	_width = 8;
	_height = 8;
	//_alive = false;
}
void BrickFrag::Draw()
{
	if (_alive)
	{
		this->UpdatePosition();
		MovableObject::Draw();
	}
}
void BrickFrag::Run()
{
	if (_alive)
	{
		MovableObject::Run();
	}
}

BrickFrag::~BrickFrag()
{
}
