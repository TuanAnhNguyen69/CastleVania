#include "LifeUp.h"


LifeUp::LifeUp()
{
	_collType = CollItem;
	_alive = false;
	_listAction = SpriteManager::GetInstance()->listAnimation[SpriteLifeUp];
}

void LifeUp::Draw()
{
	Item::Draw();
}
void LifeUp::Run()
{
	Item::Run();
}

void LifeUp::OnCollision(BaseObject* obj, int nx, int ny)
{
	if (obj->_collType == CollGround)
	{
		Collision::PreventMove(this, obj, nx, ny);
		if (nx != 0 && Bottom() < obj->Top() && obj->_collType == CollGround)
		{
			_direction = (Direction)(-_direction);
			dx = -dx;
		}
	}
}

void LifeUp::Active()
{
	_collType = CollEnemy;
	ay = GRAVITY;
	vx = 0.08;
	Item::Active();
}

void LifeUp::OnInterSerct(BaseObject* obj)
{
	//life up
	if (obj->_collType == CollMario)
		MarioCharacter::_life++;
	Item::OnInterSerct(obj);
}

LifeUp::~LifeUp()
{
}
