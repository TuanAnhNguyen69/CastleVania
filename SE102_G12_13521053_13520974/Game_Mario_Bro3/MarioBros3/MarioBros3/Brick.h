#pragma once
#include "MovableObject.h"
#include "MarioCharacter.h"
#include "MarioTail.h"
#include "BrickFrag.h"
class Brick : public MovableObject
{
protected:
	BrickFrag* frag[4];
public:

	Brick();
	void Draw();
	
	void Destroy();
	void OnCollision(BaseObject* obj, int nx, int ny);
	void OnInterSerct(BaseObject* obj);
	void Run();
	~Brick();
};

