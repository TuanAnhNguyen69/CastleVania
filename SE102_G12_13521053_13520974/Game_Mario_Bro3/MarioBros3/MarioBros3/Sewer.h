#pragma once
#include"MovableObject.h"
class Sewer:public MovableObject
{
public:
	Sewer();
	void setObjectFromID();
	void Draw();
	void Run();
	~Sewer();
};

