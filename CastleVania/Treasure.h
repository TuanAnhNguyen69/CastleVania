#pragma once
#include "Item.h"
#include "Simon.h"
class Treasure : public Item
{
public:
	Treasure(void);
	void Active();
	void Draw();
	void Run();
	void OnCollision(BaseObject* obj, int nx, int ny);
	void OnInterSerct(BaseObject* obj);
	~Treasure(void);
};

