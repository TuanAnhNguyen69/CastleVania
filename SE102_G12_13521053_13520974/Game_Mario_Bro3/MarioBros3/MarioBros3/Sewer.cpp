#include "Sewer.h"


Sewer::Sewer()
{
	_collType = CollGround;
	_listAction = SpriteManager::GetInstance()->listAnimation[SpriteSewer];
	ay = 0;
}
void Sewer::setObjectFromID()
{
	if (id == 8)
		_curAction = 0;
	if (id == 9)
		_curAction = 1;
	if (id == 18)
	{
		_curAction = 2;
	}
	if (id == 19)
		_curAction = 3;
	
}
void Sewer::Draw()
{
	MovableObject::Draw();
}
void Sewer::Run()
{
	MovableObject::Run();
	dy = 0;
}
Sewer::~Sewer()
{
}
