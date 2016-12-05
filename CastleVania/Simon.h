#pragma once
#include "MovableObject.h"
#include "SimonWeapon.h"
#include "GameTime.h"

#define AX_GO 0.0004
#define VX_GO 0.18
#define VY_JUMP -0.43
#define TIME_INDEX_CHANGE 0.3
#define WEAPON_POSX 16
#define WEAPON_POSY 8
#define WEAPON_BASIC 28
#define WEAPON_UPGRADE 44
#define WEAPON_HEIGHT 8
#define SIMON_HEIGHT 32
class Simon :
	public MovableObject
{
private:
	static Simon* instance;
protected:
	GameTime *delayIndexChange;
	int _curSimonAction;
	SimonWeapon* _weapon;
	GameTime* _timeBlink; // thời gian nhấp nháy
	bool isBlink;	 // thoi gian nhap nhay
	bool _isDownkJump; // có thả phím nhảy // có nhấn phím nhảy
	bool _isDownkSit;
	bool _isGoingUp;
	bool _isGoingDown;
	bool _isColl;
	bool _typeUp, _typeDown; //lên cấp, xuống cấp  
	bool _kLeft, _kRight, _kJump, _kUp, _kDown, _kAttack;
	bool _isUpJumpKey; //
	bool _isDownAtkKey; // có thả, nhấn phím tấn công
	bool isAttacking;
	void setSimonAction(SimonAction action); // thiết lập hành động mario

public:
	Simon();
	static Simon* GetInstance();
	bool _immortal;
	void Draw();
	void run();
	static int _pointcount;
	static int _life;
	void Jump();
	void OnCollision(BaseObject* obj, int nx, int ny);
	void ChangeAction();
	void ChangeDirection();
	void Move();
	void UpdateKey();
	void Attack();
	void Dead();
	void onInterSerct(BaseObject* obj);
	~Simon();
};

