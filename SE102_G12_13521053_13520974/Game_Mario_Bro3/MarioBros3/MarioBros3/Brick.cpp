#include "Brick.h"


Brick::Brick()
{
	_collType = CollGround;
	_listAction = SpriteManager::GetInstance()->listAnimation[SpriteBrick];

	for (int i = 0; i < 4; i++)
	{
		frag[i] = new BrickFrag();
	}
}

void Brick::Draw()
{
	
	MovableObject::Draw();
	for (int i = 0; i < 4; i++)
	{
  		frag[i]->Draw();
	}
}
void Brick::Run()
{

	
	for (int i = 0; i < 4; i++)
	{
		frag[i]->Run();
	}
		MovableObject::Run();
	dy = 0;
}


void Brick::Destroy()
{
	this->_alive = false;
	for (int i = 0; i < 4; i++)
	{

		frag[i]->_alive = true;
		frag[i]->_position.X = this->_position.X;
		frag[i]->_position.Y = this->_position.Y;

		frag[i]->dx = 0;
		frag[i]->dy = 0;
		frag[i]->ay = GRAVITY;
	}
	frag[0]->vx = 0.2;
	frag[1]->vx = -0.2;
	frag[2]->vx = 0.2;
	frag[3]->vx = -0.2;

	frag[0]->vy = -0.4;
	frag[1]->vy = -0.4;
	frag[2]->vy = -0.2;
	frag[3]->vy = -0.2;

}
void Brick::OnCollision(BaseObject* obj, int nx, int ny)
{
	if(obj->_collType == CollMario);
	{
		Collision::PreventMove(this, obj, nx, ny);
		if (ny == 1)
			Destroy();
	}
	OnInterSerct(obj);
	MovableObject::OnCollision(obj, nx, ny);
}
void Brick::OnInterSerct(BaseObject* obj)
{
	if (obj->_collType == CollTail && _curAction == 0)
	{
		Destroy();
	}
	if (_curAction == 1 && obj->_collType == CollMario){
		_alive = false;
	}
	MovableObject::OnInterSerct(obj);
}


Brick::~Brick()
{
}
