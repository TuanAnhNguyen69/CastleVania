#pragma once
#ifndef _BASEOBJECT_H
#define _BASEOBJECT_H

//#include "dxManager.h"
#include "GameTime.h"
//#include "Camera.h"
#include"Point.h"
//#include "Animation.h"
#include "SweptAABB.h"
//#include"SpriteManager.h"

enum CollisionType
{
	CollGround,
	CollMario,
	CollEnemy,
	CollTail,
	CollItem,
	CollLine,
	CollDie
};
class BaseObject
{
protected:
	
public:
//	
	int id;
	bool _alive;
	int _width, _height; // do dai, do cao of hinh
	Point _position; //vi tri cua hinh
	int _curAction; // 
	float vx, vy, ax, ay, dx, dy;
	int oldX, oldY;
	bool c;
	CollisionType _collType;
	bool _isDead;
public:
	int normalx, normaly;
	BaseObject();
	static BaseObject* Create(int x, int y, int width, int height);
	virtual void Run();
	virtual void Draw();
	void setObjectFromID();
	BaseObject* oldObj;
	void SetPosition(Point pos);
	void SetPosition(int x, int y);
	void init(int x, int y, int w, int h);
	Point GetPosition();
	int xCenter();
	virtual void OnCollision(BaseObject* obj, int nx, int ny);
	virtual void OnInterSerct(BaseObject* obj);
	virtual void UpdatePosition();
	int Left();
	int Right();
	int Top();
	int Bottom();
	virtual ~BaseObject();
};

#endif