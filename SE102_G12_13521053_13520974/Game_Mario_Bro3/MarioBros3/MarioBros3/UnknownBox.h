#pragma once
#include"Enemy.h"
#include "MovableObject.h"
#include "Item.h"
class UnknownBox : public MovableObject
{
protected:

	int _curUBState;
	void setUBState(UnknownBrickType);
public:
	UnknownBox();
	int indexitem;
	void Draw();
	Item* item;
	void Run();
	void setObjectFromID();
	void OnCollision(BaseObject * obj, int nx, int ny);
	void OnInterSerct(BaseObject * obj);
	void Active();
	//void OnCollition(BaseObject* obj, int nx, int ny);
	//void OnInterSerct(BaseObject* obj);
	~UnknownBox();
};

