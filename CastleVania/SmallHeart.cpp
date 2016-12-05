#include "SmallHeart.h"


SmallHeart::SmallHeart(void)
{
	_collType == CollItem;
	_alive = false;
	_listAction = SpriteManager::GetInstance()->listAnimation[SpriteSmallHeart];
}

void SmallHeart::Active()
{
	ay = GRAVITY;
	vy = 0.3;
	if(dx < 6)
		vx = 0.3;
	else
		vx = -0.3;
	Item::Active();
}

void SmallHeart::Draw()
{
	Item::Draw();
}

void SmallHeart::Run()
{
	Item::Run();
}

void SmallHeart::OnCollision(BaseObject* obj, int nx, int ny)
{
	if (obj->_collType == CollGround && _curAction == 0)
	{
		Collision::PreventMove(this, obj, nx, ny);
	}
	if (obj->_collType == CollLine)
		Collision::CollisionLine(this, obj, nx, ny);
	Item::OnCollision(BaseObject* obj, int nx, int ny);
}

void SmallHeart::OnInterSerct(BaseObject* obj)
{
	if (obj->_collType == CollSimon)
		Simon::_heart += 1;
	Item::OnInterSerct(BaseObject* obj);
}

SmallHeart::~SmallHeart(void)
{
}
