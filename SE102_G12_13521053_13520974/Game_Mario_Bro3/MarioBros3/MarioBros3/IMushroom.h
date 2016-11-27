#pragma once
#include "Item.h"
#include"Enemy.h"
#include "MarioCharacter.h"
#define AY_LEAF 0.0007
#define VY_LEAF 0.38
#define VX_IM -0.08
class IMushroom : public Item
{

public:
	IMushroom();
	void Active();
	void Draw();
	void Run();
	void OnCollision(BaseObject* obj, int nx, int ny);
	void OnInterSerct(BaseObject* obj);
	~IMushroom();
};

