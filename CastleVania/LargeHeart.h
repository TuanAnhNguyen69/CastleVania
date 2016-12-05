#pragma once
#include "Item.h"
#include "Simon.h"
class LargeHeart : public Item
{
public:
	LargeHeart(void);
	void Active();
	void Draw();
	void Run();
	void OnCollision(BaseObject* obj, int nx, int ny);
	void OnInterSerct(BaseObject* obj);
	~LargeHeart(void);
};

