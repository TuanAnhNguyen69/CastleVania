#pragma once
#include"Animation.h"
#include "Sprite.h"

enum SpriteType
{
	SpriteSimon,
	SpriteSimonWeapon,
	SpriteCross,
	SpriteDoubleShot,
	SpriteTripleShot,
	SpriteImmortalPotion, 
	SpriteLargeHeart
};

enum SimonAction
{
	SimonStand,
	SimonMove,
	SimonUpStair,
	SimonDownStair,
	SimonSit,
	SimonJump,
	SimonThrow,
	SimonAttack,
	SimonHit,
	SimonDie,
	SimonUpgrade

};
class SpriteManager
{
private:
	static SpriteManager* instance;
public:
	Sprite** listAnimation;
	int count;
	static SpriteManager* GetInstance(DirectXGame* dx = 0);
	SpriteManager(DirectXGame* dx);
	void AddSimon(DirectXGame* dx);
	void AddSimonWeapon(DirectXGame* dx);
	~SpriteManager();
};

