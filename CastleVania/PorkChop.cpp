#include "PorkChop.h"


PorkChop::PorkChop(void)
{
	_collType = CollItem;
	_alive = false;
	
		_listAction = SpriteManager::GetInstance()->listAnimation[SpritePorkChop];
}

void PorkChop::Draw()
{
	Item::Draw();
}

void PorkChop::Run()
{
	Item::Run();
}

void PorkChop::Active()
{
	Item::Active();
}

void PorkChop::OnCollision(BaseObject* obj, int nx, int ny)
{
	Item::OnCollision(BaseObject* obj, int nx, int ny);
}

void PorkChop::OnInterSerct(BaseObject* obj)
{
	if (obj->_collType == CollSimon)
		Simon::_health += 10;
	Item::OnInterSerct(obj);
}


PorkChop::~PorkChop(void)
{
}
