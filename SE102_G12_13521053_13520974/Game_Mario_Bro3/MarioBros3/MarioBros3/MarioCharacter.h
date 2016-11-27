#pragma once
#include "dxManager.h"
#include "GameTime.h"
#include"Animation.h"
#include"SpriteManager.h"
#include"MovableObject.h"
#include"Keyboard.h"
#include "MarioTail.h"
#define AX_GO 0.0004
#define VX_GO 0.18
#define VX_SPEEDUP 0.2
#define VY_JUMP -0.43
#define VY_FALL -0.04
#define VY_RACOON_FLY -0.225
#define COUNT_SPEEDING_FLYABLE 7
#define TIME_INDEX_CHANGE 0.3
#define TIME_TYPEUP 0.5
#define TIME_KICK 0.2
#define TIME_BLINK 2.3
#define RACOON_WIDTH 20
#define SUPERMARIO_HEIGHT 27
#define RACOON_HEIGHT 28
#define MARIO_HEIGHT 16 
#define TAIL_POS_X 14
#define TAIL_POS_Y 18
#define TAIL_WIDTH 12
#define TAIL_HEIGHT 6
enum MarioType
{
	SMALL_MARIO,
	NORMAL_MARIO,
	RACOON
};



class MarioCharacter : public MovableObject
{
private:
	static MarioCharacter* instance;
protected:
	int maxSpeed;
	int iSpeed;
	GameTime *delayIndexChange;
	int _curMarioAction;
	int _enegryFly;
	MarioType _curType;
	MarioTail* _tail;
	bool isBlink;	 // thoi gian nhap nhay
	bool isUpkJump; // có thả phím nhảy
	bool isDownkJump; // có nhấn phím nhảy
	bool _canJump;
	bool _canFly;
	bool _fall;
	bool _isColl;
	bool _typeUp, _typeDown; //lên cấp, xuống cấp
	bool _kLeft, _kRight, _kJump, _kUp, _kDown, _kMove, _kSpeedup, _kCtrl, _kAttack;
	bool _isUpJumpKey; //
	bool _isUpAtkKey, _isDownAtkKey; // có thả, nhấn phím tấn công
	bool isTypeUp; // có đang tăng cấp
	bool isAttacking; 
	void setMarioAction(MarioAction action); // thiết lập hành động mario
	
	
public:
	MarioCharacter();
	bool _kBring;
	bool isBring;
	static MarioCharacter* GetInstance();
	GameTime* timeTypeUp; //thời gian lên cấp
	GameTime* timeTypeDown; // t/g xuống cấp
	GameTime* timeKick; // thời gian đá
	GameTime* _timeBlink; // thời gian nhấp nháy
	static int _coincount;
	static int _life;
	void Jump();
	void OnCollision(BaseObject* obj, int nx, int ny);
	void Falling();
	void ChangeType();
	void ChangeAction();
	void ChangeDirection();
	void Move();
	void Brake(); // hàm thắng
	void SpeedUp(); // tăng tốc
	void Run();
	void Fly();
	void Kick();
	void UpdateKey();
	void ChangeEnegryFly(); // thay đổi năng lượng bay
	void Attack();
	void Draw();
	void Dead();
	void SetIsTypeUp();
	void TypeUp(MarioType type);// Hàm tăng cấp
	void TypeDown(); // hàm xuống cấp
	void OnInterSerct(BaseObject* obj);
	void SetType(MarioType type);
	MarioType GetMarioType();
	~MarioCharacter();
};

