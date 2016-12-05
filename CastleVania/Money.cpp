#include "Money.h"


Money::Money(void)
{
	_collType = CollItem;
	_alive = false;
	switch (id)
	{
	case 20:
		_listAction = SpriteManager::GetInstance()->listAnimation[SpriteMoney100];
	case 21:
		_listAction = SpriteManager::GetInstance()->listAnimation[SpriteMoney400];
	case 22:
		_listAction = SpriteManager::GetInstance()->listAnimation[SpriteMoney700];
	}
}

void Money::Draw()
{
	Item::Draw();
}

void Money::Run()
{
	Item::Run();
}

void Money::Active()
{
	ay = GRAVITY;
	vy = 0.3;
	Item::Active();
}

void Money::OnCollision(BaseObject* obj, int nx, int ny)
{
	if (obj->_collType == CollGround && _curAction == 0)
	{
		Collision::PreventMove(this, obj, nx, ny);
	}
	if (obj->_collType == CollLine)
		Collision::CollisionLine(this, obj, nx, ny);
	Item::OnCollision(BaseObject* obj, int nx, int ny);

}

void Money::OnInterSerct(BaseObject* obj)
{
	if (obj->_collType == CollSimon)
	{
		switch (id)
		{
			case 20:
				Simon::_ponit += 100;
			case 21:
				Simon::_point += 400;
			case 22:
				Simon::_point += 700;
		}
	}
	Item::OnInterSerct(obj);
}

Money::~Money(void)
{
}
