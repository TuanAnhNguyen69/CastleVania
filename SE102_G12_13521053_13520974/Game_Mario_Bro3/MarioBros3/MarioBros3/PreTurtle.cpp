#include "PreTurtle.h"


PreTurtle::PreTurtle() : MovableObject()
{
	_collType = CollEnemy;
	_listAction = SpriteManager::GetInstance()->listAnimation[SpritePreTurtle];
	_alive = true;
	//dy = 0;
}
void PreTurtle::OnCollision(BaseObject* obj, int nx, int ny)
{
	if (obj->_collType == CollMario || obj->_curAction!= 0)
		return;
	if (obj->_collType == CollEnemy && obj->_curAction == 0)
	{
		Collision::PreventMove(this, obj, nx, ny);
	}
}

void PreTurtle::Draw(){}
void PreTurtle::Run()
{
	MovableObject::Run();
	dy = 0;
}


PreTurtle::~PreTurtle()
{
}
