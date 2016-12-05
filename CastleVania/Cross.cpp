#include "Cross.h"


Cross::Cross(void)
{
	_collType == CollItem;
	_alive = false;
	_listAction = SpriteManager::GetInstance()->listAnimation[SpriteCross];
}

void Cross::Active()
{
	vy = 0.3;
	Item::Active();
}

void Cross::Draw()
{
	Item::Draw();
}

void Cross::Run()
{
	Item::Run();
}

void Cross::OnCollision(BaseObject* obj, int nx, int ny)
{
	if (obj->_collType == CollGround && _curAction == 0)
	{
		Collision::PreventMove(this, obj, nx, ny);
	}
	if (obj->_collType == CollGround)
		Collision::CollisionLine(this, obj, nx, ny);
	Item::OnCollision(obj, nx, ny);
}

void Cross::OnInterSerct(BaseObject* obj)
{
	/*
	if (obj->_collType == CollSimon)
	{
		kill_all_enemy
	}
	*/
	Item::OnInterSerct(obj);
}




Cross::~Cross(void)
{
}
