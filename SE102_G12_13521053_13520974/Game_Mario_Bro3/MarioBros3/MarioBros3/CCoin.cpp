#include "CCoin.h"

CCoin::CCoin() :Item()
{
	_collType = CollItem;
	_alive = true;
	ay = 0;
	_listAction = SpriteManager::GetInstance()->listAnimation[SpriteCoin];
}

void CCoin::Active()
{
	if (vy==0)
		MarioCharacter::_coincount += 1;
	vy = -0.35;
	ay = 0.001;
	Item::Active();
	
}

void CCoin::Draw()
{
	Item::Draw();
}

void CCoin::Run()
{

	if (dy > 0 && _position.Y + dy > oldY)
		_alive = false;
	Item::Run();
	if (dy == 1)
		dy = 0;
	
}

void CCoin::OnCollision(BaseObject* obj, int nx, int ny)
{

}

void CCoin::OnInterSerct(BaseObject* obj)
{
	if (obj->_collType == CollMario && dy != 0)
		return;
	Item::OnInterSerct(obj);
	if (obj->_collType == CollMario)
	{
		MarioCharacter::_coincount += 1;
		//PlaySound(Coin);
	}
}

CCoin::~CCoin()
{
}
