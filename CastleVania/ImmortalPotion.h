#pragma once
#include "Item.h"
#include "Simon.h"

class ImmortalPotion : public Item
{ 
public:
	ImmortalPotion(void);
	void Active();
	void Draw();
	void Run();
	void OnCollision(BaseObject* obj, int nx, int ny);
	void OnInterSerct(BaseObject* obj);
	~ImmortalPotion(void);
};
