#pragma once
#include "Enemy.h"
#include "Bullet.h"
#define EFLOWER_ACTION_COUNT 5
#define VY_FLOWERRISE -0.1
#define DISTANCE_ACTIVE 50
#define DISTANCE_FLOWER_SHOOT 30
#define DISTANCE_FLOWER_RISE 30
enum FlowerState
{
	FlowerTop,
	FlowerMoving,
	FlowerBottom
};

class Flower : public Enemy
{
private:
	
protected:
	int _curFlowerAction;
	GameTime* _timeTop;
	GameTime * _timeBottom;
	FlowerState _flowerstate;
	bool isRise;
	void setFlowerAction(EFlowerAction action);
public:
	Flower();
	void OnCollision(BaseObject* obj, int nx, int ny);
	void OnInterSerct(BaseObject* obj);
	void setObjectFromID();
	void ChangeTypeAction();
	void Shoot();
	void Run();
	void Draw();
	~Flower();
};

