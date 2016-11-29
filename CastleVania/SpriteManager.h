#pragma once
#include"Animation.h"
#include "Sprite.h"

enum SpriteType
{
	SpriteMario,
	SpriteEMushroom,
	SpriteTurtle,
	SpriteEFlower,
	SpriteUBrick,
	SpriteTail,
	SpriteCoin,
	SpriteLeverUp,
	SpriteBrick,
	SpriteFrag,
	SpritePBox,
	SpriteLifeUp,
	SpritePreTurtle,
	SpriteBullet,
	SpriteSewer
};
#define MARIO_ACTION_COUNT 12
enum MarioAction
{
	MarioStand,
	MarioGo,
	MarioSit,
	MarioJump,
	MarioBrake,
	MarioFall,
	MarioSpeedup,
	MarioKick,
	MarioFly,
	MarioBringStand,
	MarioBringGo,
	MarioBringJump,
	MarioDie = 36,
	RacoonFlySlow = 37,
	RacoonAttack = 38,
	SuperToRacoon = 39,
	MarioToSuper = 40
};
#define EMUSHROOM_ACTION_COUNT 3
enum EMushroomAction
{
	EMushroomGo,
	EMushroomFly,
	EMushroomDie
};

enum TurtleAction
{
	TurtleGo,
	TurtleFly,
	TurtleSprink,
	TurtleRecovery
};

enum EFlowerAction
{
	FlowerShootLB,
	FlowerShootLT,
	FlowerShootRB,
	FlowerShootRT,
	FlowerRise
};
enum UnknownBrickType
{
	UBActive,
	UBUnActive

};
enum LeverUp
{
	ItemMushroom,
	ItemLeaf
};
enum CoinType
{
	UnkCoin
};
enum BrickType
{
	ActiveBrick
};
class SpriteManager
{
private:
	static SpriteManager* instance;
public:
	Sprite** listAnimation;
	int count;
	static SpriteManager* GetInstance(DirectXGame* dx = 0);
	SpriteManager(DirectXGame* dx);
	void AddMario(DirectXGame* dx);
	void AddMushroom(DirectXGame* dx);
	void AddTurtle(DirectXGame * dx);
	void AddFlower(DirectXGame* dx);
	void AddUBrick(DirectXGame* dx);
	void AddTail(DirectXGame* dx);
	void AddCoin(DirectXGame* dx);
	void AddLeverUp(DirectXGame* dx);
	void Addbrick(DirectXGame* dx);
	void AddFrag(DirectXGame* dx);
	void AddPBox(DirectXGame* dx);
	void AddLifeUp(DirectXGame* dx);
	void AddPreTurtle(DirectXGame* dx);
	void AddBullet(DirectXGame* dx);
	void AddSewer(DirectXGame* dx);
	 ~SpriteManager();
};

