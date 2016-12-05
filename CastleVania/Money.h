#pragma once
#include "Item.h"
#include "Simon.h"
class Money : public Item
{
public:
	Money(void);
	void Active();
	void Draw();
	void Run();
	void OnCollision(BaseObject* obj, int nx, int ny);
	void OnInterSerct(BaseObject* obj);
	~Money(void);
};

