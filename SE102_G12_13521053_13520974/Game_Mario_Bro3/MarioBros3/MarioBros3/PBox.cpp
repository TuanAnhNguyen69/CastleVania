#include "PBox.h"


PBox::PBox()
{
	_collType = CollItem;
	_alive = false;
	_listAction = SpriteManager::GetInstance()->listAnimation[SpritePBox];
	_curAction = 0;
	_direction = RIGHT;
	change = false;
}

void PBox::Active()
{
	Item::Active();
}

void PBox::Draw()
{
	Item::Draw();
}


void PBox::Run()
{
	Item::Run();
	dy = 0;
}

void PBox::Change()
{
	if (change)
	{
		for each(Brick* b in listBrick)
		{
			b->_curAction = 1;
			b->_collType = CollItem;
		}
	}
}

void PBox::OnCollision(BaseObject* obj, int nx, int ny)
{
	if (obj->_collType == CollMario && _curAction == 0)
	{
		_curAction = 1;
		change = true;
		Change();
	}
}

void PBox::OnInterSerct(BaseObject* obj)
{

}
PBox::~PBox()
{
}

