#pragma once
#include "MovableObject.h"
class Item : public MovableObject
{
public:
	Item();
	void Draw();
	void OnCollision(BaseObject* obj, int nx, int ny);
	void OnInterSerct(BaseObject* obj);
	void Run();
	virtual void Active();
	~Item();
};

