#pragma once
#include "MovableObject.h"
enum WeaponType
{
	BASIC,
	MORNING_STAR,
	UPGRADED_MORNING_STAR
};
class SimonWeapon :
	public MovableObject
{
	WeaponType type;
	static SimonWeapon* instance;
	

public:
	SimonWeapon();
	static SimonWeapon* GetInstance();
	bool isAttack;
	void onInterSerct(BaseObject* obj);
	WeaponType getType();
	void setType(WeaponType);
	void run();
	~SimonWeapon();
};

