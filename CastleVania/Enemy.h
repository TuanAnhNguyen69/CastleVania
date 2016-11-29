#pragma once
#include"MovableObject.h"
#include"Animation.h"
#include "dxManager.h"
#include "GameTime.h"
#include"Animation.h"
#include"SpriteManager.h"
#include"Keyboard.h"
class Enemy : public MovableObject
{
protected:
	bool _isColl;
	
public:
	Enemy();
	void OnCollision(BaseObject* obj, int nx, int ny);
	void OnInterSerct(BaseObject* obj);
	virtual void Attacked();
	bool _canAttMario;
	void Draw();
	void Run();
	~Enemy();
};

