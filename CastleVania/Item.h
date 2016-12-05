#pragma once
#include "MovableObject.h"
class Item : public MovableObject
{
public:
	Item();
	void Draw();
	void OnCollision(BaseObject* obj, int nx, int ny);
	void onInterSerct(BaseObject* obj);
	void run();
	virtual void Active();
	~Item();
};

