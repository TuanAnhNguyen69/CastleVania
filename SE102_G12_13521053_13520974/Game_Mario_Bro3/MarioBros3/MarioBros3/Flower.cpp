#include "Flower.h"

Flower::Flower() :Enemy()
{
	//_position.X = 100;
	//_position.Y = 50;
	_direction = LEFT;
	_timeTop = GameTime::Create(1.0 / 2);
	_timeBottom = GameTime::Create(1.0 / 2);
	_listAction = SpriteManager::GetInstance()->listAnimation[SpriteEFlower];
	ay = 0;
	isRise = true;
	_flowerstate = FlowerBottom;
}
void Flower::setFlowerAction(EFlowerAction action)
{
	if (_curAction != action)
	{
	 	_curAction =action;
		_curFlowerAction = action;
		_curFrame = 0;

	}
}

void Flower::OnCollision(BaseObject* obj, int nx, int ny)
{
	/*if (obj == MarioCharacter::GetInstance())
		MarioCharacter::GetInstance()->Dead();*/
}
void Flower::OnInterSerct(BaseObject* obj)
{
	if (obj->_collType == CollMario)
	{
		MarioCharacter::GetInstance()->timeTypeDown->Tick();
		MarioCharacter::GetInstance()->_timeBlink->Tick();
	}
	if (obj->_collType == CollTail)
	{
		_alive = false;
	}
}
void Flower::setObjectFromID()
{
	if (id == 6)
	{
		setFlowerAction(FlowerShootLT);
	}
	if (id == 5)
	{
		setFlowerAction(FlowerRise);
	}
}
void Flower::Shoot()
{
	if (_curAction == FlowerRise)
		return;
	Bullet *b = new Bullet();
	b->_position.X = _position.X + _width / 2;
	b->_position.Y = _position.Y + _width / 2;
	Bullet::GetList()->push_back(b);
	switch (_curAction)
	{
	case FlowerShootLB:
		
		b->dx = -2;
		b->dy = 1;
		
		break;
	case FlowerShootLT:
		b->dx = -2;
		b->dy = -1;
		break;
	case FlowerShootRB:
		b->dx = 2;
		b->dy = 1;
		break;
	case FlowerShootRT:
		b->dx = 2;
		b->dy = -1;
		break;
	default:
		break;
	}
}
void Flower::Draw()
{

	Enemy::Draw();
}
void Flower::Run()
{
	ChangeTypeAction();

	switch (_flowerstate)
	{
	case FlowerTop:
		if (!_timeTop->access)
		{
			_timeTop->Tick();
		}
		if (_timeTop->CanCreatNewFrame() && _timeTop->access)
		{
			Shoot();
			_flowerstate = FlowerMoving;
			vy = - VY_FLOWERRISE;
			_timeTop->access = false;
		}
		_curFrame = -1;
		break;
	case FlowerBottom:
		if (abs(MarioCharacter::GetInstance()->xCenter() - xCenter()) < DISTANCE_ACTIVE)
		{
			_timeBottom->access = false;
			return;
		}
		if (!_timeBottom->access)
			_timeBottom->Tick();
		if (_timeBottom->CanCreatNewFrame() && _timeBottom->access)
		{ 
			_flowerstate = FlowerMoving;
			vy = VY_FLOWERRISE;
			_timeBottom->access = false;
		}
		break;
	case FlowerMoving:
		if (((_position.Y + dy < oldY - DISTANCE_FLOWER_SHOOT && _curAction<4) || (_position.Y + dy < oldY - DISTANCE_FLOWER_RISE && _curAction==4)) && vy < 0)
		{
			_flowerstate = FlowerTop;
			vy = 0;
		}
		if (_position.Y + dy > oldY && vy > 0)
		{
			_flowerstate = FlowerBottom;
			vy = 0;
		}
		break;
	}
	
	Enemy::Run();
	if (dy == 1 && vy==0)
		dy = 0;
}
void Flower::ChangeTypeAction()
{
	if (_curFlowerAction == FlowerRise)
		return;
	if (MarioCharacter::GetInstance()->_position.Y > _position.Y)
	{
		if (MarioCharacter::GetInstance()->_position.X < _position.X)
		{
			setFlowerAction(FlowerShootLB);
		}
		else
			setFlowerAction(FlowerShootRB);
	}
	else
	{
		if (MarioCharacter::GetInstance()->_position.X < _position.X)
			setFlowerAction(FlowerShootLT);
		else
			setFlowerAction(FlowerShootRT);
	}
}
Flower::~Flower()
{
}
