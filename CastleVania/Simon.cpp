#include "Simon.h"
#include "Enemy.h"

int Simon::_pointcount = 0;
int Simon::_life = 3;


Simon::Simon() :MovableObject()
{
	_listAction = SpriteManager::GetInstance()->listAnimation[SpriteSimon];
	_position.X = 1857;
	_position.Y = 770;
	oldX = 1857;
	oldY = 770;
	_width = 32;
	_height = 32;
	_direction = RIGHT;
	_weapon = new SimonWeapon();
	_weapon->_collType = CollWeapon;
	isAttacking = false;
	delayIndexChange = new GameTime(1 / TIME_INDEX_CHANGE);
	_isDownAtkKey = false;
	_isDownkJump = false;
	_isDownkSit = false;
	_isGoingUp = false;
	_isGoingDown = false;
	isBlink = true;
	setSimonAction(SimonStand);
	_collType = CollSimon;
	vy = 1;
}


Simon::~Simon()
{
}

void Simon::setSimonAction(SimonAction action)
{
	if (_curAction != action)
	{
		_curSimonAction = action;
		_curAction = action;
		_curFrame = 0;
	}
}

Simon*Simon::instance = 0;

Simon*Simon::GetInstance()
{
	if (instance == 0)
	{
		instance = new Simon();
	}
	return instance;
}



void Simon::run()
{

	//Draw();
	UpdateKey();
	ChangeDirection();
	ChangeAction();
	Move();
	Jump();
	Attack();
	Dead();
	MovableObject::run();
}
void Simon::Draw()
{
		MovableObject::Draw();
}
void Simon::UpdateKey()
{
	Keyboard::GetInstance()->UpdateKeyboard();
	_kLeft = Keyboard::GetInstance()->IsKeyDown(DIK_LEFT);
	_kRight = Keyboard::GetInstance()->IsKeyDown(DIK_RIGHT);
	_kUp = Keyboard::GetInstance()->IsKeyDown(DIK_UP);
	_kDown = Keyboard::GetInstance()->IsKeyDown(DIK_DOWN);
	_kJump = Keyboard::GetInstance()->IsKeyDown(DIK_Z);
	_kAttack = Keyboard::GetInstance()->IsKeyDown(DIK_X);
	if (_kJump && !_isDownkJump)
	{
		_isDownkJump = true;
	}
	/*if (Keyboard::GetInstance()->IsKeyUp(DIK_Z))
	{
		_isDownkJump = false;
	}
	if (_kAttack && !_isDownAtkKey)
	{
		_isDownAtkKey = true;
	}
	else
		_isDownAtkKey = false;
	if (Keyboard::GetInstance()->IsKeyUp(DIK_X))
	{
		_isDownAtkKey = false;
	}*/

}


void Simon::ChangeDirection()
{
	if (_kLeft)
		_direction = Direction::LEFT;
	else
		if (_kRight)
			_direction = Direction::RIGHT;
}


void Simon::Move()
{
	if (_kLeft != _kRight)
	{
		if (_kLeft)
		{
			
			vx = -1;
		}
		else
		{
			vx = 1;
		}
		setSimonAction(SimonMove);
	}
	else
	{
		vx = 0;
	}
		
	
	
}
void Simon::Jump()
{
		if (normaly == -1 && _isDownkJump)//vecto phap tuyen huong len
		{
			vy = -1;
			_isDownkJump = false;
		}
		else { vy = 0; }
	
	
}
void Simon::OnCollision(BaseObject* obj, int nx, int ny)
{
	if (obj->_collType == CollSimon)
		Collision::PreventMove(this, obj, nx, ny);
	else
		c = false;
	if (obj->_collType == CollGround)
		vy=0;
	if(obj->_collType == CollStair)
	if (obj->_collType == CollEnemy)
	{
		Dead();
	}
}

void Simon::ChangeAction()
{
	if (_isDead)
	{
		_curAction = SimonDie;
		_curFrame = 0;
		return;
	}

	if (_curAction == SimonAttack  && _curFrame < _listAction->get(_curAction)->getCount() - 1)
	{
		_timeDelay->m_timePerFrame = 70;
		return;
	}
	if (vx == 0 && vy == 0)
		setSimonAction(SimonStand);
	if (_isDownkJump && dy == 0)// && _curAction != RacoonFlySlow && _curSimonAction != MarioFall)
	{
		normaly = -1;
		setSimonAction(SimonJump);
	}

	if (_kDown && _curSimonAction != SimonSit)
	{
		setSimonAction(SimonSit);
		if (_curSimonAction == SimonSit)
		{
			_position.Y += 4;
			_height = SIMON_HEIGHT;
		}
		if (_kLeft != _kRight)
		{
			setSimonAction(SimonMove);
			_height = SIMON_HEIGHT;
			_position.Y -= 4;
		}
	}
}
void Simon::Attack()
{
	if (_isDownAtkKey && _curAction != SimonAttack)
	{
		int weaponWidth;
		if (SimonWeapon::GetInstance()->getType() == UPGRADED_MORNING_STAR)
			weaponWidth = WEAPON_UPGRADE;
		else
			weaponWidth = WEAPON_BASIC;
		_curAction = SimonAttack;
		isAttacking = true;
		_curFrame = 0;
		SimonWeapon::GetInstance()->isAttack = true;

		if (!SimonWeapon::GetInstance()->isAttack)
			if (_curAction == SimonMove || _curAction == SimonJump)
			{
				SimonWeapon::GetInstance()->_alive = false;
			}
		if (_direction == Direction::RIGHT)
			SimonWeapon::GetInstance()->init(_position.X + WEAPON_POSX, _position.Y + WEAPON_POSY, weaponWidth, WEAPON_HEIGHT);
		else
			SimonWeapon::GetInstance()->init(_position.X - weaponWidth, _position.Y + WEAPON_POSY, weaponWidth, WEAPON_HEIGHT);
	}
	else
		SimonWeapon::GetInstance()->_alive = false;
	if(isAttacking && _curAction==SimonAttack)
	{
		if (_curFrame == _listAction->get(_curAction)->getCount() - 1)
		{
			isAttacking = false;
			SimonWeapon::GetInstance()->_alive = false;
		}
	}

}

void Simon::Dead()
{
	if (_isDead)
	{
		//_timeBlink->Tick();
		//if (_curType == SMALL_MARIO)
		//{
		_curAction = SimonDie;
		_curFrame = 0;
		vy = vyJump;
		vx = 0;
		MovableObject::Dead();
		////}

	}
}
void Simon::onInterSerct(BaseObject* obj)
{
	if (obj->_collType == CollEnemy && ((Enemy*)obj)->_canAttMario)
	{
		if (_life < 0)
		{
			_isDead = true;
		}
		vx = 0;
		vy = 0;
	}
}
