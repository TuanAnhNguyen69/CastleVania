#pragma once
#include"Enemy.h"
#define VELOC_MUSHROOM_GO 0.0625
#define VELOC_MUSHROOM_FLY -0.4
#define MUSHROOM_DIE 0.5
#define MUSHROOM_FLY_COUNT 12 
#define MUSHROOMGO_HEIGHT 16
#define MUSHROOMFLY_HEIGHT 22
#define MUSHROOMDIE_HEIGHT 9
#define MUSHROOM_INDEX_FLY 23
#define MUSHROOM_INDEX_GO 20
enum EMushroomType
{
	EMUSHROOM_YELLOW,
	EMUSHROOM_RED
};
class Mushroom : public Enemy
{
private:
protected:
	int _curMushroomAction;
	
	bool _canFly;
	GameTime* _timeDie;
	int _indexFly;
public:
	Mushroom();
	EMushroomType _curType;
	void Fly();
	void Go();
	void setMushroomAction(EMushroomAction action);
	void setObjectFromID();
	void OnCollision(BaseObject* obj, int nx, int ny);
	void OnInterSerct(BaseObject* obj);
	void Attacked();
	void Run();
	void Draw();
	~Mushroom();
};

