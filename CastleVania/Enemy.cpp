#include "Enemy.h"


Enemy::Enemy()
{
	_collType = CollEnemy;
	_canAttMario = true;
	_isColl = false;
}
void Enemy::OnCollision(BaseObject* obj, int nx, int ny)
{
	//if (obj == MarioCharacter::GetInstance())
	//	return;

	if (obj->_collType != CollItem && obj->_collType != CollGround)
	{

		Collision::PreventMove(this, obj, nx, ny);
	}
	if (obj->_collType == CollGround)
		Collision::CollisionLine(this, obj, nx, ny);
	if (nx != 0 && Bottom() > obj->Top() && obj->_collType!=CollGround)
	{
		_direction = (Direction)(-_direction);
		dx = -dx;
	}

	
}

void Enemy::Attacked()
{
	
}
void Enemy::onInterSerct(BaseObject* obj)
{
	if (obj->_collType == CollWeapon)
	{
		Dead();
	}
	//if (obj->_collType == CollMario &&!MarioCharacter::GetInstance()->_isDead && !_isDead)
	//{
	//	if (obj->Bottom() < _position.Y + _height / 2)
	//	{
	//		Attacked();
	//		obj->vy = -0.2;
	//		vy = 0;
	//		dy = _height / 2;
	//		obj->dy = -_height / 2;
	//		return;
	//	}
	//	/*else
	//	{
	//		if (MarioCharacter::GetInstance()->_curAction != MarioKick)
	//			MarioCharacter::GetInstance()->Dead();
	//	}*/
	//}
	//if (obj == MarioCharacter::GetInstance() && !MarioCharacter::GetInstance()->_isDead && !_isDead)
	//{
	//	if (MarioCharacter::GetInstance()->_timeBlink->access)
	//		return;
	//	if (MarioCharacter::GetInstance()->timeKick->access)
	//		return;
	//	if (_canAttMario && !MarioCharacter::GetInstance()->_timeBlink->access)
	//	{
	//		MarioCharacter::GetInstance()->timeTypeDown->Tick();
	//		MarioCharacter::GetInstance()->_timeBlink->Tick();
	//	}
	//}

	
}

void Enemy::Draw()
{
	D3DXMATRIX b;

	//flipMatrixVertical
	if (_isDead)
	{
  		_listAction->get(_curAction)->_dxGame.GetSprite()->GetTransform(&b);
		_listAction->get(_curAction)->_dxGame.GetSprite()->SetTransform(&(b*Animation::flipMatrixVertical(Point(_position.X, _position.Y + _height / 2 - Camera::GetInstance()->_position.Y)))); // vì dxGame vẽ lên backbuffer, ma
	}
	MovableObject::Draw();
	if (_isDead)
		_listAction->get(_curAction)->_dxGame.GetSprite()->SetTransform(&b);
}

void Enemy::run()
{
	MovableObject::run();
}
Enemy::~Enemy()
{
}
