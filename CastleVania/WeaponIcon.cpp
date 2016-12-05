#include "WeaponIcon.h"


WeaponIcon::WeaponIcon(void)
{
	_collType == CollItem;
	_alive = false;
	switch (id)
	{
		case 28:
			_listAction = SpriteManager::GetInstance()->listAnimation[SpriteAxeIcon];
		case 29:
			_listAction = SpriteManager::GetInstance()->listAnimation[SpriteBumerangIcon];
		case 30:
			_listAction = SpriteManager::GetInstance()->listAnimation[SpriteDaggerIcon];
		case 31:
			_listAction = SpriteManager::GetInstance()->listAnimation[SpriteFireBoomIcon];
		case 32:
			_listAction = SpriteManager::GetInstance()->listAnimation[SpriteMorningStarIcon];
		case 33:
			_listAction = SpriteManager::GetInstance()->listAnimation[SpriteWatchIcon];
	}
}

void WeaponIcon::Active()
{
	ay = GRAVITY;
	vy = 0.3;
	Item::Active();
}

void WeaponIcon::Draw()
{
	Item::Draw();
}

void WeaponIcon::Run()
{
	Item::Run();
}

void WeaponIcon::OnCollision(BaseObject* obj, int nx, int ny)
{
	if (obj->_collType == CollGround && _curAction == 0)
	{
		Collision::PreventMove(this, obj, nx, ny);
	}
	if (obj->_collType == CollLine)
		Collision::CollisionLine(this, obj, nx, ny);
	Item::OnCollision(BaseObject* obj, int nx, int ny);
}

void WeaponIcon::OnInterSerct(BaseObject* obj)
{
	if (obj->_collType == CollSimon)
		if(id == 32 && MorningStar::_level < 3)
			MorningStar::_level ++; 
		else
			if(id == 28 || id == 29 || id == 30 || id == 31 || id == 32)
				Simon::_weapon = true;
	Item::OnInterSerct(BaseObject* obj);
}

int WeaponIcon::GetID()
{
	return id;
}

WeaponIcon::~WeaponIcon(void)
{
}
