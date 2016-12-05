#include "ImmortalPotion.h"


ImmortalPotion::ImmortalPotion(void)
{
	_collType == CollItem;
	_alive = false;
	_listAction = SpriteManager::GetInstance()->listAnimation[SpriteImmortalPotion];
}

void ImmortalPotion::Active()
{
	vy = 0.3;
	Item::Active();
}

void ImmortalPotion::Draw()
{
	Item::Draw();
}

void ImmortalPotion::Run()
{
	Item::Run();
}

void ImmortalPotion::OnCollision(BaseObject* obj, int nx, int ny)
{
	if (obj->_collType == CollGround && _curAction == 0)
	{
		Collision::PreventMove(this, obj, nx, ny);
	}
	if (obj->_collType == CollGround)
		Collision::CollisionLine(this, obj, nx, ny);
	Item::OnCollision(obj, nx, ny);
}

void ImmortalPotion::OnInterSerct(BaseObject* obj)
{

	if (obj->_collType == CollSimon)
		//Simon::_immortal = true;

	Item::OnInterSerct( obj);
}

ImmortalPotion::~ImmortalPotion(void)
{
}
