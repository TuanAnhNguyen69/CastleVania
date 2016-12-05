#pragma once
#include "Item.h"
#include "Simon.h"
class SmallHeart : public Item
{
public:
	SmallHeart(void);
	void Active();
	void Draw();
	void Run();
	void OnCollision(BaseObject* obj, int nx, int ny);
	void OnInterSerct(BaseObject* obj);
	~SmallHeart(void);
};

