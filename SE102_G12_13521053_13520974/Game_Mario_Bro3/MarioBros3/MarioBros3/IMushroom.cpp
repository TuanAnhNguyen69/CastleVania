#include "IMushroom.h"


IMushroom::IMushroom() :Item()
{
	_collType = CollItem;
	//_alive = true;
	_listAction = SpriteManager::GetInstance()->listAnimation[SpriteLeverUp];
}
void IMushroom::Draw()
{
	Item::Draw();
}
void IMushroom::Run()
{
	
	Item::Run();
	/*if (dy == 1)
		dy = 0;*/
}
void IMushroom::OnCollision(BaseObject* obj, int nx, int ny)
{

	if (obj->_collType == CollGround && _curAction == 0)
	{
		Collision::PreventMove(this, obj, nx, ny);
	}
	if (obj->_collType == CollLine)
		Collision::CollisionLine(this, obj, nx, ny);
	//if (nx != 0 && Right() > obj->Left())
	//{
	//	_direction = (Direction)(-_direction);
	//	dx = -dx;
	//}
}

void IMushroom::Active()
{
	if (MarioCharacter::GetInstance()->GetMarioType() == SMALL_MARIO)
	{
		_curAction = 0;
		_curFrame = 0;
		_collType = CollEnemy;
		ay = GRAVITY;
		vx = -VX_IM;
	}
	if (MarioCharacter::GetInstance()->GetMarioType() == NORMAL_MARIO || MarioCharacter::GetInstance()->GetMarioType() == RACOON)
	{
		_curAction = 1;
		_curFrame = 0;
		ay = AY_LEAF;
		vy -= VY_LEAF;
		
	
	}
	//_position.Y += 16;
	
	Item::Active();
}
void IMushroom::OnInterSerct(BaseObject* obj)
{
	/*if (obj->_collType == CollMario && dy != 0)
		return;*/
	
	if (obj->_collType == CollMario)
	{
		MarioCharacter::GetInstance()->timeTypeUp->Tick();
		MarioCharacter::GetInstance()->SetIsTypeUp();
	}
	Item::OnInterSerct(obj);
}
IMushroom::~IMushroom()
{
}
