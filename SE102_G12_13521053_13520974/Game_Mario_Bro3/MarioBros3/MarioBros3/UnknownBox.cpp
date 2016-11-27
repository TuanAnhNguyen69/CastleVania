#include "UnknownBox.h"


UnknownBox::UnknownBox()
{
	//_width = 16;
	//_height = 16;
	_listAction = SpriteManager::GetInstance()->listAnimation[SpriteUBrick];
	//setUBState(UBUnActive);
	//_curFrame = 3;
	_curUBState = UBActive;
	_direction = RIGHT;
	_collType = CollGround;
	ay = 0;
}

void UnknownBox::setUBState(UnknownBrickType type)
{
	if (_curUBState != type + _curUBState * 2)
	{
		_curUBState = 2 * _curUBState + type;
		_curUBState = type;
		_curFrame = 0;
	}
	/*if (_curUBState != type)
		_curUBState = type;*/
}

void UnknownBox::Active()
{
	_curAction = 1;
	_curFrame = 0;
	vy = -0.13;
	ay = 0.001;
	((Item*)item)->Active();
}

void UnknownBox::OnCollision(BaseObject * obj, int nx, int ny)
{
	if (obj->_collType == CollTail)
	{
		Active();
	}
	if (obj->_collType == CollMario  && ny == 1 && _curAction != 1)
	{
		Active();
	}
	Collision::PreventMove(this, obj, nx, ny);
}

void UnknownBox::OnInterSerct(BaseObject * obj)
{
	if (obj->_collType == CollTail && _curAction != 1)
	{
		Active();
	}
}
void UnknownBox::setObjectFromID()
{
	if (_curAction == 1)
		return;
	if (id == 10)
	{
		_curAction = 2;
	}
	if (id == 11)
	{
		_curAction = 0;
	}
}

void UnknownBox::Draw()
{
	MovableObject::Draw();
}

void UnknownBox::Run()
{
	if (_position.Y + dy > oldY && dy > 0)
	{
		dy = 0;
		_position.Y = oldY;
		ay = 0;
		vy = 0;
	}
	MovableObject::Run();
	if (dy == 1)
		dy = 0;
}
UnknownBox::~UnknownBox()
{
}
