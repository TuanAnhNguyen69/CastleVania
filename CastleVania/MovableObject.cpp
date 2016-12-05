#include "MovableObject.h"

MovableObject::MovableObject() :BaseObject()
{
	vx = 0;
	vy = 0;
	dx = 0;
	dy = 0;
	vyJump = -0.4;
	_timeDelay = new GameTime(8); //8 frame/s
}

int MovableObject::gametime = 16;

MovableObject::MovableObject(int actionCount, Direction defaultDirection)
{
	//_listAction = SpriteManager::GetInstance()->listAnimation[Spri]
	
	_curFrame = 0;
	_direction = defaultDirection;
	this->_time = 0;
	this->_deltaTime = 0.0f;
	this->_isDead = false;
}
void MovableObject::setAction(int action)
{
	if (_curAction != action)
	{
		_curAction = action;
		_curFrame = 0;
	}
}
void MovableObject::Update(GameTime *gameTime)
{
	
	this->UpdateAnimation();

}

void MovableObject::Draw()
{
	if (_alive) // neu doi tuong con song
	{
		_listAction->get(_curAction)->Draw(this, _curFrame, _direction);
	}

}

void MovableObject::run()
{
	if (_alive)
	{
		dx += vx;
		dy +=vy;
		normalx = 0;
		normaly = 0;
		UpdateAnimation();
		c = false;
	}
	//BaseObject::Run();
}

void MovableObject::UpdatePosition()
{
	if (_collType == CollSimon)
		int a = 5;
	if (c) // nếu có va chạm chéo thì sẽ cập nhật lại 1 trong 2 vecto
	{
		if (_collType == CollSimon)
			int a = 5;
		if (abs(dx) > abs(dy))
			dy = 0;
		else
			dx = 0;
	}

	_position.X += dx;
	_position.Y += dy;
	dx = 0;
	dy = 0;
	//BaseObject::UpdatePosition();
}

void MovableObject::UpdateAnimation()
{
	if (_curFrame < 0)
	{
		_curFrame = 0;
		return;
	}
	
	if (_timeDelay->CanCreatNewFrame())
	{
		_curFrame = _listAction->get(_curAction)->NextFrame(_curFrame);
		
	}
	
}

void MovableObject::Dead()
{
	if (!_isDead)
	{ 
		vy = vyJump;
		_isDead = true;
		dy = 0;
	}
}