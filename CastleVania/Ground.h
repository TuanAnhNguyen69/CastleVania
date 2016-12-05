#pragma once
#include "SpriteManager.h"
#include "StaticObject.h"
class Ground :
	public StaticObject
{
public:
	Ground();
	void setObjectFromID();
	void Draw();
	~Ground();
};

