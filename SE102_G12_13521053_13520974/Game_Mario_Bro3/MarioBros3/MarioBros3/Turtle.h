#pragma once
#include"Enemy.h"
#include"MovableObject.h"
//#include "dxManager.h"
//#include "GameTime.h"
//#include"Animation.h"
//#include"SpriteManager.h"
//#include"MovableObject.h"
//#include"Keyboard.h"

#define TURTLE_ACTION_COUNT 4
#define TIME_TURTLE_DIE 0.5
#define VX_TURTLE 0.08
#define VY_TURTLE -0.3
#define TIME_RECOVERY 7.0
#define TURTLE_RECOVERY_HEIGHT 18
#define TURTLE_SPRINK_HEIGHT 16
#define TURTLE_GO_HEIGHT 27
enum TurtleType
{
	TurtleGreen,
	TurtleRed
};


class Turtle :public Enemy
{
private:

protected:
	int _curTurtleAction;

	TurtleType _curType;
	GameTime* _timeRecovery;
	GameTime* _timeRecovering;
	bool isInvert; 
	float TurtleSprinkGo;
	void setTurtleAction(TurtleAction action);
	bool isBringed;
public:
	Turtle(void);
	void OnCollision(BaseObject* obj, int nx, int ny);
	void OnInterSerct(BaseObject* obj);
	void setObjectFromID();
	void Draw();
	void Attacked();
	void Go();
	void Fly();
	void Run();
	void OnBringed();
	void AfterBringed();
	void Dead();
	~Turtle(void);
};


