#include "ExtraShot.h"


ExtraShot::ExtraShot(void)
{
	_collType = CollItem;
	_alive = false;
	switch(id)
	{
	case 17:
		_listAction = SpriteManager::GetInstance()->listAnimation[SpriteDoubleShot];
	case 27:
		_listAction = SpriteManager::GetInstance()->listAnimation[SpriteTripleShot];
	}
}

void ExtraShot::Draw()
{
	Item::Draw();
}

void ExtraShot::Run()
{
	Item::Run();
}

void ExtraShot::Active()
{
	Item::Active();
}

void ExtraShot::OnCollision(BaseObject* obj, int nx, int ny)
{
	Item::OnCollision(obj,nx,ny);
}

void ExtraShot::OnInterSerct(BaseObject* obj)
{
	if (obj->_collType == CollSimon)
	{
		switch (id)
		{
		case 17://hitper5second = 2, exist 90 second
		case 27://hitper5second = 3, exist 90 second
		}
	}
	Item::OnInterSerct(obj);
}


ExtraShot::~ExtraShot(void)
{
}
