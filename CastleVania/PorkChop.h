#pragma once
#include "Item.h"
#include "Simon.h"
class PorkChop : public Item
{
public:
	PorkChop(void);
	void Active();
	void Draw();
	void Run();
	void OnCollision(BaseObject* obj, int nx, int ny);
	void OnInterSerct(BaseObject* obj);
	~PorkChop(void);
};

