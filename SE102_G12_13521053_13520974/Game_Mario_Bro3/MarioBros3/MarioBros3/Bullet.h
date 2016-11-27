#pragma once
#include "MovableObject.h"
#include "MarioCharacter.h"
class Bullet: public MovableObject
{
	static vector<Bullet *>* listBullet;

public:
	Bullet();
	void Run();
	static  vector<Bullet *>* GetList();
	void OnInterSerct(BaseObject* obj);
	static void BulletRun();
	static void BulletDraw();
	~Bullet();
};

