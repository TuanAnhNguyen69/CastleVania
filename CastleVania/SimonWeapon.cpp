#include "SimonWeapon.h"


SimonWeapon* SimonWeapon::instance = 0;
SimonWeapon::SimonWeapon()
{
	_listAction = NULL;
	_collType = CollWeapon;
	isAttack = true;
}

SimonWeapon* SimonWeapon::GetInstance()
{
	if (instance == 0)
		instance = new SimonWeapon();
	return instance;
}

void SimonWeapon::onInterSerct(BaseObject* obj)
{
	_listAction = NULL;
	if (isAttack)
		_listAction = SpriteManager::GetInstance()->listAnimation[SpriteSimonWeapon];
	isAttack = false;
	_alive = false;
}

void SimonWeapon::run()
{
	if (_listAction)
	{
		_listAction = NULL;
		isAttack = false;
	}
}

WeaponType SimonWeapon::getType()
{
	return type;
}

void SimonWeapon::setType(WeaponType type)
{
	this->type = type;
}

SimonWeapon::~SimonWeapon()
{
}
