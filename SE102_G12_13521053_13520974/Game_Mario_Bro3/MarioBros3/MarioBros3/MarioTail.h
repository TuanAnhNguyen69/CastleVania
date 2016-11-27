#pragma once
#include"MovableObject.h"
class MarioTail : public MovableObject
{
	static MarioTail* instance;
public:
	MarioTail();
	bool isAttack;
	static MarioTail* GetInstance();
	void OnInterSerct(BaseObject* obj);
	void Run();
	~MarioTail();
};

