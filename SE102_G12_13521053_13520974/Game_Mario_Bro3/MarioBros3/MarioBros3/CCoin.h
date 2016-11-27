#pragma once
#include "Item.h"
#include "MarioCharacter.h"
class CCoin : public Item
{
public:
	CCoin();
	void Draw();
	void Run();
	void OnCollision(BaseObject* obj, int nx, int ny);
	void OnInterSerct(BaseObject* obj);
	void Active();
	~CCoin();
};

