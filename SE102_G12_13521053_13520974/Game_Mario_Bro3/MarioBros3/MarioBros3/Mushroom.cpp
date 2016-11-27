#include "Mushroom.h"
Mushroom::Mushroom() :Enemy()
{
	_position.X = 50;
	_position.Y = 50;
	_width = 16;
	_height = MUSHROOMGO_HEIGHT;
	_direction = LEFT;
	_timeDie = GameTime::Create(1 / MUSHROOM_DIE);
	_timeDie->access = false;
	_indexFly = 0;
	if (_curType == EMushroomFly)
	{
		_height = MUSHROOMFLY_HEIGHT; //24
	}
	_listAction = SpriteManager::GetInstance()->listAnimation[SpriteEMushroom];
}
void Mushroom::setMushroomAction(EMushroomAction action)
{
	if (_curAction != EMUSHROOM_ACTION_COUNT*_curType + action)
	{
		_curAction = EMUSHROOM_ACTION_COUNT*_curType + action;
		_curMushroomAction = action;
		_curFrame = 0;

	}
}
void Mushroom::OnCollision(BaseObject* obj, int nx, int ny)
{
	if (obj->_collType != CollMario)
	{
		Enemy::OnCollision(obj, nx, ny);
	}
	//if (obj->_collType == CollMario && ny == -1)
	//{
	//	Attacked();
	//}
}
void Mushroom::setObjectFromID()
{
	
	if (id == 0)
	{
		_curType = EMUSHROOM_YELLOW;
		setMushroomAction(EMushroomGo);
		_position.Y += _height - MUSHROOMGO_HEIGHT;
		_height = MUSHROOMGO_HEIGHT;
	}
	if (id == 1)
	{
		_curType = EMUSHROOM_RED;
		setMushroomAction(EMushroomFly);
		_position.Y += _height - MUSHROOMFLY_HEIGHT;
		_height = MUSHROOMFLY_HEIGHT;
	}
}
void Mushroom::OnInterSerct(BaseObject* obj)
{
	if (_curMushroomAction == EMushroomDie)
		return;
	if (_curMushroomAction != EMushroomDie)
	{
		Enemy::OnInterSerct(obj);
		if (obj->_collType == CollTail)
			_isColl = false;
	}
	
}
void Mushroom::Go()
{
	vx = _direction*VELOC_MUSHROOM_GO;
	//vx = 0;
}
void Mushroom::Fly()
{
	vx = _direction*VELOC_MUSHROOM_GO;
	if (dy == 0)
	{
		if (_indexFly < MUSHROOM_INDEX_GO)
		{
			vy = 0;
			if (_curFrame == 2)
				_curFrame = 0;
		}
		else
		if (_indexFly < MUSHROOM_INDEX_FLY)
		{
			vy = VELOC_MUSHROOM_FLY / 2;
		}
		
		else
		{
			_indexFly = 0;
			vy = VELOC_MUSHROOM_FLY;
		}
		_indexFly++;
	}
}
void Mushroom::Draw()
{
	//if (_isDead)
	//	return;
	Enemy::Draw();
}
void Mushroom::Run()
{
	if (_isDead)
	{
		Enemy::Run();
		return;
	}

		switch (_curMushroomAction)
		{
		case EMushroomGo:
			Go();
			break;
		case EMushroomFly:
			Fly();
			break;
		case EMushroomDie:
			vx = 0;
			if (_timeDie->CanCreatNewFrame() && _timeDie->access)
			{
				_alive = false;
				_timeDie->access = false;
			}
			break;
		default:
			break;
		}
	//}
	Enemy::Run();
}

void Mushroom::Attacked()
{

	if (_curMushroomAction == EMushroomFly)
	{
		setMushroomAction(EMushroomGo);
		_position.Y += _height - MUSHROOMGO_HEIGHT;
		_height = MUSHROOMGO_HEIGHT;
		return;
	}

	if (!_timeDie->access)
	{
		_timeDie->Tick();
		setMushroomAction(EMushroomDie);
		_position.Y += _height - MUSHROOMDIE_HEIGHT;
		_height = MUSHROOMDIE_HEIGHT;
		vx = 0;
	}
}
Mushroom::~Mushroom()
{
}
