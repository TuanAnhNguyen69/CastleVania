#pragma once
#include"Item.h"
#include"MarioCharacter.h"
class LifeUp : public Item
{
public:
	LifeUp();
	void Active();
	void Draw();
	void Run();
	void OnCollision(BaseObject* obj, int nx, int ny);
	void OnInterSerct(BaseObject* obj);
	~LifeUp();
};

