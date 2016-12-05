#include "Treasure.h"


Treasure::Treasure(void)
{
	_collType = CollItem;
	_alive = false;
	switch (id)
	{
	case 23:
		_listAction = SpriteManager::GetInstance()->listAnimation[SpriteMoney1000];
	case 16:
		_listAction = SpriteManager::GetInstance()->listAnimation[SpriteCrown];
	case 26:
		_listAction = SpriteManager::GetInstance()->listAnimation[SpriteTreasureChest];
	}
}

void Treasure::Draw()
{
	Item::Draw();
}

void Treasure::Run()
{
	Item::Run();
}

void Treasure::Active()
{
	Item::Active();
}

void Treasure::OnCollision(BaseObject* obj, int nx, int ny)
{
	Item::OnCollision(BaseObject* obj, int nx, int ny);
}

void Treasure::OnInterSerct(BaseObject* obj)
{
	if (obj->_collType == CollSimon)
		switch (id)
		{
			case 23:
				Simon::_point += 1000;
			case 16:
				Simon::_point += 2000;
			case 26:
				Simon::_point += 2000;
		}
	Item::OnInterSerct(obj);
}


Treasure::~Treasure(void)
{
}
