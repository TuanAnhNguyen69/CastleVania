#include "Turtle.h"


Turtle::Turtle(void) :Enemy()
{
	//_width = 16;
	//_height = 20;
	_timeRecovery = GameTime::Create(1 /TIME_RECOVERY);
	_timeRecovering = GameTime::Create(1.0 / 0.4);
	isInvert = false;
	_direction = LEFT;
	TurtleSprinkGo = 0;
	isBringed = false;
	_listAction = SpriteManager::GetInstance()->listAnimation[SpriteTurtle];
}

void Turtle::setTurtleAction(TurtleAction action)
{
	if (_curAction != action + _curType*TURTLE_ACTION_COUNT)
	{
		_curAction = TURTLE_ACTION_COUNT*_curType + action;
		_curTurtleAction = action;
		_curFrame = 0;
	}
}
//float s = 0;
void Turtle::Go()
{
	vx = VX_TURTLE*_direction;
}
void Turtle::Fly()
{
	vx = VX_TURTLE*_direction;
	if (vy == 0)
		vy = VY_TURTLE;
	
}
void Turtle::OnCollision(BaseObject* obj, int nx, int ny)
{
	if (MarioCharacter::GetInstance()->_kBring && _curTurtleAction == TurtleSprink && dx == 0 && obj == MarioCharacter::GetInstance())
	{
		MarioCharacter::GetInstance()->isBring = true;
		isBringed = true;
		return;
	}
	if (_curTurtleAction == TurtleSprink && vx!=0 && obj->_collType == CollEnemy)
		return;
	if (obj->_collType != CollMario)
	{
		Enemy::OnCollision(obj, nx, ny);
		return;
	}
	//if (ny == -1 && obj->_collType == CollMario)
	//	vx = 0;
	if (_curTurtleAction == TurtleSprink)
	{
		if (vx == 0)
		{
			//MarioCharacter::GetInstance()->timeTypeDown->access = false;
			if (nx != 0)
			{
				_canAttMario = false;
				MarioCharacter::GetInstance()->timeKick->Tick();
				TurtleSprinkGo = 2 * VX_TURTLE;
				if (nx == -1)
				{
					_direction = RIGHT;
				}
				if (nx == 1)
				{
					_direction = LEFT;
				}
			}
		}
		
		
	}
}
void Turtle::OnInterSerct(BaseObject* obj)
{
	if (MarioCharacter::GetInstance()->_kBring && _curTurtleAction == TurtleSprink && dx==0 && obj == MarioCharacter::GetInstance())
	{
		MarioCharacter::GetInstance()->isBring = true;
		isBringed = true;
		return;
	}
	if (isBringed)
		return;
	//if (obj->_collType == CollMario)
	Enemy::OnInterSerct(obj);
	
	if (obj->_collType == CollMario)
	{
		_timeRecovery->Tick();
	}
	if (obj->_collType == CollEnemy && _curTurtleAction == TurtleSprink && dx!=0)
	{
		((Enemy*)obj)->Dead();
	}

	
	
	
}
void Turtle::Run()
{
	
	switch (_curTurtleAction)
	{
	case TurtleGo:
		Go();
		if (isBringed)
			AfterBringed();
		_collType = CollEnemy;
		break;
	case TurtleFly:
		Fly();
		_collType = CollEnemy;
		break;
	case TurtleSprink:
		if (vx == 0)
			_collType = CollEnemy;
		else
			_collType = CollTail;
		if (TurtleSprinkGo == 0)
		{

			_curFrame = -1;
			if (!_timeRecovery->access)
				_timeRecovery->Tick();
			if (_timeRecovery->CanCreatNewFrame() && _timeRecovery->access)
			{
				setTurtleAction(TurtleRecovery);
				_position.Y -= TURTLE_RECOVERY_HEIGHT - _height;
				_height = TURTLE_RECOVERY_HEIGHT;
				_timeRecovery->access = false;
				_timeRecovering->Tick();
			}
		}
		if (isBringed)
		{
			OnBringed();
		}

		if (!MarioCharacter::GetInstance()->_kBring && isBringed)
			AfterBringed();
		vx = _direction*TurtleSprinkGo;
		break;
	case TurtleRecovery:
		if (_timeRecovering->CanCreatNewFrame() && _timeRecovering->access)
		{
			setTurtleAction(TurtleGo);
			_position.Y -= TURTLE_GO_HEIGHT - _height;
			_height = TURTLE_GO_HEIGHT;
			_timeRecovering->access = false;
			isInvert = false;
		}
		break;
	default:
		break;
	}
	if (MarioCharacter::GetInstance()->timeKick->access || MarioCharacter::GetInstance()->_timeBlink->access || vx == 0)
		_canAttMario = false;
	else
		_canAttMario = true;
	Enemy::Run();
}
void Turtle::setObjectFromID()
{
	if (id == 2)
	{
		_curType = TurtleGreen;
		setTurtleAction(TurtleGo);
		
	}
	if (id == 3)
	{
		_curType = TurtleRed;
		setTurtleAction(TurtleGo);
		
	}
	if (id == 4)
	{
		_curType = TurtleGreen;
		setTurtleAction(TurtleFly);
		_position.Y -= _height - 28;
		_height = 28;
		
	}
	isInvert = false;
}

void Turtle::Attacked()
{
	if (_curTurtleAction == TurtleFly)
	{
		setTurtleAction(TurtleGo);
		_height = 27;
		return;
	}
	else
	{
		setTurtleAction(TurtleSprink);
	//	_position.Y += _height - 16;
		_height = TURTLE_SPRINK_HEIGHT;
		
		if (vx == 0)
		{
			TurtleSprinkGo = 2 * VX_TURTLE;
			if (MarioCharacter::GetInstance()->Right() < _position.X + _width / 2)
				_direction = RIGHT;
			if (MarioCharacter::GetInstance()->Left() > _position.X + _width / 2)
				_direction = LEFT;
			_timeRecovery->Tick();
		}
		else
			TurtleSprinkGo = 0;
	}
}
void Turtle::Dead()
{
	if (!isInvert)
	{
		isInvert = true;
		setTurtleAction(TurtleSprink);
		_height = TURTLE_SPRINK_HEIGHT;
		
		vy = -0.4;
		vx = 0;
		dy = 0;
		//_isDead = true;
	}
}
void Turtle::Draw()
{
	D3DXMATRIX b;

	if (isInvert)
	{
		_listAction->get(_curAction)->_dxGame.GetSprite()->GetTransform(&b);
		_listAction->get(_curAction)->_dxGame.GetSprite()->SetTransform(&(b*Animation::flipMatrixVertical(Point(_position.X, _position.Y + _height / 2 - Camera::GetInstance()->_position.Y)))); // vì dxGame vẽ lên backbuffer, ma
		
	}
	Enemy::Draw();
	if (isInvert)
	{
		_listAction->get(_curAction)->_dxGame.GetSprite()->SetTransform(&b);

	}
}
void Turtle::OnBringed()
{
	
	_canAttMario = false;
	_position.X = MarioCharacter::GetInstance()->_position.X;
	_position.Y = MarioCharacter::GetInstance()->_position.Y;
	dx = 0;
	dy = 0;
	vx = 0;
	vy = 0;
	TurtleSprinkGo = 0;
}
void Turtle::AfterBringed()
{
	isBringed = false;
	MarioCharacter::GetInstance()->isBring = false;
	//_canAttMario = true;
	//MarioCharacter::GetInstance()->setAction(MarioKick);
	TurtleSprinkGo = 2*VX_TURTLE;
	_direction = MarioCharacter::GetInstance()->_direction;
	vx = 2 * MarioCharacter::GetInstance()->_direction*VX_TURTLE;
	dx = vx*gametime;
	if (vx <0)
		_position.X = MarioCharacter::GetInstance()->_position.X - 5;
	else
		_position.X = MarioCharacter::GetInstance()->Right() + 5;
	MarioCharacter::GetInstance()->timeKick->Tick();
}
Turtle::~Turtle(void)
{
}
