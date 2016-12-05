#pragma once
#include "Item.h"
#include "Simon.h"
#include "Enemy.h"
class Cross : public Item
{
public:
	Cross(void);
	void Active();
	void Draw();
	void Run();
	void OnCollision(BaseObject* obj, int nx, int ny);
	void OnInterSerct(BaseObject* obj);
	~Cross(void);
};
