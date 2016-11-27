#pragma once
#include "Item.h"
#include "CCoin.h"
#include"Brick.h"
#include "BaseObject.h"
class PBox : public Item
{

public:
	PBox();
	bool change;
	void Change();
	vector<Brick*> listBrick;
	void Draw();
	void Run();
	void OnCollision(BaseObject* obj, int nx, int ny);
	void OnInterSerct(BaseObject* obj);
	void Active();
	~PBox();
};

