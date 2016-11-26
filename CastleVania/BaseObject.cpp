#include "BaseObject.h"


BaseObject::BaseObject()
{
	_curAction = 0;
	_alive = true;
	_isDead = false;
	
}

BaseObject * BaseObject::Create(int x, int y, int width, int height)
{
	BaseObject* b = new BaseObject();
	b->_position.X = x;
	b->_position.Y = y;
	b->_width = width;
	b->_height = height;
	return b;
}

void BaseObject::Draw()
{
}

void BaseObject::Run()
{
}
void BaseObject::setObjectFromID()
{
	_position.X = oldX;
	_position.Y = oldY;
}
void BaseObject::SetPosition(Point pos)
{
	_position = pos;
}
void BaseObject::init(int x, int y, int w, int h)
{
	_position.X = x;
	_position.Y = y;
	_width = w;
	_height = h;
}
void BaseObject::SetPosition(int x, int y)
{
	_position.X = x;
	_position.Y = y;
}
int BaseObject::xCenter()
{
	return _position.X + _width / 2;
}
void BaseObject::OnCollision(BaseObject* obj, int nx, int ny)
{

}
void BaseObject::OnInterSerct(BaseObject* obj)
{

}
Point BaseObject::GetPosition()
{
	return _position;
}
void BaseObject::UpdatePosition()
{
}

int BaseObject::Left()
{
	return _position.X ;
}
int BaseObject::Right()
{
	return Left() + _width ;
}
int BaseObject::Top()
{
	return _position.Y ;
}
int BaseObject::Bottom()
{
	return Top() + _height;
}

BaseObject::~BaseObject()
{
}