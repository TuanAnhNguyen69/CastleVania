#pragma once
#include"MovableObject.h"
class PreTurtle :public MovableObject
{
public:
	PreTurtle();
	void Draw();
	void Run();
	void OnCollision(BaseObject* obj, int nx, int ny);
	~PreTurtle();
};

