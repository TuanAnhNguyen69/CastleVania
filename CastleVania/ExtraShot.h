#pragma once
#include "Item.h"
#include "Simon.h"
#include "SimonWeapon.h"
class ExtraShot : public Item
{
public:
	ExtraShot(void);
	void Active();
	void Draw();
	void Run();
	void OnCollision(BaseObject* obj, int nx, int ny);
	void OnInterSerct(BaseObject* obj);
	~ExtraShot(void);
};

