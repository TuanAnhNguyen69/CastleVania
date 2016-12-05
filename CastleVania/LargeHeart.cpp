#include "LargeHeart.h"


LargeHeart::LargeHeart(void)
{
	_collType == CollItem;
	_alive = false;
	_listAction = SpriteManager::GetInstance()->listAnimation[SpriteLargeHeart];
}

void LargeHeart::Active()
{
	vy = 0.3;
	Item::Active();
}

void LargeHeart::Draw()
{
	Item::Draw();
}

void LargeHeart::Run()
{
	Item::Run();
}

void LargeHeart::OnCollision(BaseObject* obj, int nx, int ny)
{
	if (obj->_collType == CollGround && _curAction == 0)
	{
		Collision::PreventMove(this, obj, nx, ny);
	}
	if (obj->_collType == CollGround)
		Collision::CollisionLine(this, obj, nx, ny);
	Item::OnCollision(obj, nx, ny);
}

void LargeHeart::OnInterSerct(BaseObject* obj)
{
	//if (obj->_collType == CollSimon)
		//Simon::_heart += 5;
	Item::OnInterSerct(obj);
}


LargeHeart::~LargeHeart(void)
{
}
