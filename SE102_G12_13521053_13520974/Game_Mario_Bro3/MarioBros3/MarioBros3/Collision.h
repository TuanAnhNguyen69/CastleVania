#pragma once
#include"BaseObject.h"
#define MAX(a,b) a>b? a:b
#define MIN(a,b) a>b? b:a

class Collision
{
public:
	static float sweptAABB(BaseObject * b1, BaseObject * b2, int& normalx, int& normaly); //xac dinh co va cham hay khong (0-1)
	static BaseObject* GetSweptBroadphaseBox(BaseObject* B); //Lay hinh chư nhat bao quanh khi doi tuong va cham va ket qua sai khi va cham
	static bool AABBCheck(BaseObject* b1, BaseObject *b2); // Kiem tra 2 do ituong co giao nhau ve mat hinh hoc khong
	static void CheckCollision(BaseObject* b1, BaseObject* b2);//khi co va cham thi khong cho doi tuong di chuyen
	static void PreventMove(BaseObject* b1, BaseObject* b2, int nx, int ny); // xet va cham
	static void CollisionLine(BaseObject* b1, BaseObject* b2, int nx, int ny);//xet va cham voi cuc da bu
	Collision();
	~Collision();
};

