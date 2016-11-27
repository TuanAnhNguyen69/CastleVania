#include "MarioTail.h"

MarioTail* MarioTail::instance = 0;
MarioTail::MarioTail()
{
	_listAction = NULL;
	_collType = CollTail;
	isAttack = true;
}
MarioTail* MarioTail::GetInstance()
{ 
	if (instance == 0)
		instance = new MarioTail();
	return instance;
}
void MarioTail::OnInterSerct(BaseObject* obj)
{
	_listAction = NULL;
	if (isAttack)
		_listAction = SpriteManager::GetInstance()->listAnimation[SpriteTail];
	isAttack = false;
	_alive = false;
}
void MarioTail::Run()
{
	if (_listAction)
	{
		_listAction = NULL;
		isAttack = false;
	}
}
MarioTail::~MarioTail()
{
}
