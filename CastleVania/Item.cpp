#include "Item.h"


Item::Item() :MovableObject()
{
	_collType = CollItem;
	_alive = true;
}
void Item::Draw()
{
	MovableObject::Draw();
}
void Item::run()
{
	MovableObject::run();
}

void Item::Active()
{
	_alive = true;

}

void Item::OnCollision(BaseObject* obj, int nx, int ny)
{
	if (obj->_collType == CollSimon)
		this->_alive = false;
}
void Item::onInterSerct(BaseObject* obj)
{
	if (obj->_collType == CollSimon)
		this->_alive = false;
}

Item::~Item()
{
}
