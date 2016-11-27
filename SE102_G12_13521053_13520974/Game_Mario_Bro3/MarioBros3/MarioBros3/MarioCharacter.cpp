#include "MarioCharacter.h"
#include"Enemy.h"
int MarioCharacter::_coincount = 0;
int MarioCharacter::_life = 3;

MarioCharacter::MarioCharacter() :MovableObject()
{
	//17,2380,216,196
	_listAction = SpriteManager::GetInstance()->listAnimation[SpriteMario];
	_position.X = 100;
	_position.Y = 2480;
	oldX = 100;
	oldY = 2480;
	_width = 16;
	_height = 16;
	_direction = RIGHT;
	_curType = SMALL_MARIO;
	_tail = new MarioTail();
	_tail->_collType = CollMario;
	isAttacking = false;
	ay = 0.001;
	delayIndexChange = new GameTime(1/ TIME_INDEX_CHANGE);
	timeTypeUp = GameTime::Create(1 / TIME_TYPEUP);
	timeTypeDown = GameTime::Create(1 / TIME_TYPEUP);
	timeKick = GameTime::Create(1 / TIME_KICK);
	_timeBlink = GameTime::Create(1 / TIME_BLINK);
	isTypeUp = false;
	_enegryFly = 0;
	_canFly = false;
	_isUpAtkKey = true;
	_isDownAtkKey = false;
	isUpkJump = true;
	isDownkJump = false;
	isBlink = true;
	setMarioAction(MarioGo);
	_collType = CollMario;
	if (_curType == SMALL_MARIO)
	{
		_width = 16;
		_height = 16;
	}
	isBring = false;
}
void MarioCharacter::setMarioAction(MarioAction action)
{
	if (_curAction != MARIO_ACTION_COUNT*_curType + action )
	{
		_curMarioAction = action;
		_curAction = MARIO_ACTION_COUNT*_curType + action;// set action tương ứng từng loại mario
		_curFrame = 0;
	}
}
MarioCharacter*MarioCharacter::instance = 0;

MarioCharacter*MarioCharacter::GetInstance()
{
	if (instance == 0)
	{
		instance = new MarioCharacter();
	}
	return instance;
}

void MarioCharacter::ChangeEnegryFly() // năng lượng bay
{
	if (_enegryFly != 0 && delayIndexChange->CanCreatNewFrame()) // nếu năng lượng bay khác 0 và trong khoảng thời gian tạo frame mới
	{
		if (_kSpeedup && dy==0) // khi bắt đầu tăng tốc và ở dưới đất
		{
			if (_enegryFly < COUNT_SPEEDING_FLYABLE)
				_enegryFly++;
		}
		else
			_enegryFly--;
	}
	if (_enegryFly ==0)
		_canFly = false;
}

void MarioCharacter::Run()
{
	
	//Draw();
	UpdateKey();

	ChangeDirection();
	Move();
	Jump();
	Kick();
	ChangeAction();
	Fly();
	Falling();
	SpeedUp();
	Brake();
	ChangeType();
	ChangeEnegryFly();
	TypeDown();
	Attack();
	if (_timeBlink->access)
	{
		if (!_timeBlink->CanCreatNewFrame())
		{
			if (isBlink)
				isBlink = 0;
			else
				isBlink = 1;
		}
		else
		{
			_timeBlink->access = false;
			isBlink = 1;
		}
	}
	MovableObject::Run();
}
void MarioCharacter::Draw()
{
	if (isBlink)
		MovableObject::Draw();
}
void MarioCharacter::UpdateKey()
{
	Keyboard::getInstance()->UpdateKeyboard();
	_kLeft = Keyboard::getInstance()->IsKeyDown(DIK_LEFT);
	_kRight = Keyboard::getInstance()->IsKeyDown(DIK_RIGHT);
	_kUp = Keyboard::getInstance()->IsKeyDown(DIK_UP);
	_kDown = Keyboard::getInstance()->IsKeyDown(DIK_DOWN);
	_kJump = Keyboard::getInstance()->IsKeyDown(DIK_SPACE);
	_kAttack = _kSpeedup = Keyboard::getInstance()->IsKeyDown(DIK_Z);
	_kCtrl = Keyboard::getInstance()->IsKeyDown(DIK_LCONTROL);
	_kBring = Keyboard::getInstance()->IsKeyDown(DIK_Z);
	_kMove = _kLeft != _kRight;
	if (_kJump && isUpkJump )
	{
		isUpkJump = false;
		isDownkJump = true;
	}
	if (Keyboard::getInstance()->IsKeyUp(DIK_SPACE))
	{

		isUpkJump = true;
		isDownkJump = false;
	}
	if (_kAttack && _isUpAtkKey)
	{
		_isDownAtkKey = true;
		_isUpAtkKey = false;
	}
	else
		_isDownAtkKey = false;
	if (Keyboard::getInstance()->IsKeyUp(DIK_Z))
	{
		_isUpAtkKey = true;
		_isDownAtkKey = false;
	}
	
}


void MarioCharacter::ChangeDirection()
{
	if (_kLeft)
		_direction = Direction::LEFT;
	else
	if (_kRight)
		_direction = Direction::RIGHT;
}


void MarioCharacter::Move()
{
	//if (_kMove)
	//{
	//	_kDown = false;
	//			
	//}
	if(_curMarioAction == MarioBrake)
		 return;
	if (_kLeft != _kRight && (_direction*dx >= 0))
	{
		if (abs(vx) ==0) // neu van toc = 0 thi cho gia toc mario phu thuoc vao huong di chuyen
			ax = _direction*AX_GO;
		else
		{
			if (abs(vx) < VX_GO)
			{
				ax = (vx / abs(vx))*AX_GO;
			}
			else
			{
				vx = _direction*VX_GO;
				ax = 0;
			}
		}
	}
	else
	{
		if (abs(vx) >= 0.01)
		{
			ax = -(vx / abs(vx))*AX_GO;
		}
		else
		{
			vx = 0;
			ax = 0;
		}
	}
}
void MarioCharacter::Jump()
{
	if (normaly == -1 && isDownkJump )//vecto phap tuyen huong len
	{
		if (_enegryFly == COUNT_SPEEDING_FLYABLE)
			_canFly = true;
		vy = VY_JUMP;
		isDownkJump = false;
		
	}
}
void MarioCharacter::OnCollision(BaseObject* obj, int nx, int ny)
{
	if (obj->_collType ==CollGround)
		Collision::PreventMove(this, obj, nx, ny);
	else
		c = false;
	if (obj->_collType == CollLine)
		Collision::CollisionLine(this, obj, nx, ny);
	
	if (obj->_collType == CollDie)
	{
		Dead();
	}
}
void MarioCharacter::Falling()
{
	if (((_curType == RACOON && normaly != -1 && dy>0) || _curAction == RacoonFlySlow) && isDownkJump && !_canFly)
	{
		vy = VY_FALL;
		setAction(RacoonFlySlow);
	}
}
void MarioCharacter::Brake()
{
	if ((_kRight && vx < 0) || (_kLeft && vx > 0))
	{

		if (abs(vx) >= 0.01)
		{
			ax = -(vx / abs(vx))*AX_GO;
		
		}
		else
		{
			vx = 0;
			ax = 0;
		}

	}
}

void MarioCharacter::Fly()
{
	if (_curType == RACOON)
	{
		if (_enegryFly >= COUNT_SPEEDING_FLYABLE && isDownkJump)
			_canFly = true;
		if (_enegryFly <= 0)
			_canFly = false;
		if (_canFly && isDownkJump)
		{
			//		Camera::GetInstance()->canUp = true;
			//if (_curType == RACOON)
			vy = VY_RACOON_FLY;

		}
	}
	//else
	//	Camera::GetInstance()->canUp = false;
}
void MarioCharacter::ChangeAction()
{
	if (_isDead)
	{
		_curAction = MarioDie;
		_curFrame = 0;
		return;
	}

	if (isBring)
	{
		if (dy == 0)
		{

			if (dx == 0)
			{
				setMarioAction(MarioBringStand);
			}
			else
				setMarioAction(MarioBringGo);
		}
		else
			setMarioAction(MarioBringJump);
		return;
	}

	if (_kMove)
	{
		_kDown = false;
	}
	if (timeKick->access)
	{
		setMarioAction(MarioKick);
		timeTypeDown->access = false;
		return;
	}
	if (timeTypeDown->access)
		return;
	if (_curAction == RacoonAttack && _curFrame < _listAction->get(_curAction)->getCount() - 1)
	{
		_timeDelay->m_timePerFrame = 70;
		return;
	}
	
	if (_direction*vx < 0 && dy == 0)
	{
		setMarioAction(MarioBrake);
		return;
	}
	if (vx != 0 && _curMarioAction!=MarioSpeedup && dy==0)
		setMarioAction(MarioGo);
	if (dy != 0)
	{
		if (_curMarioAction != MarioFly)
		{
			if (dy < 0)
				setMarioAction(MarioJump);
			else
				setMarioAction(MarioFall);
		}
	}
	
	if (vx == 0 && dy == 0)
		setMarioAction(MarioStand);
	if (_enegryFly == COUNT_SPEEDING_FLYABLE && _curMarioAction != MarioSpeedup && _curAction != RacoonAttack)
	{
		
		setMarioAction(MarioSpeedup);
	}
	if (_kSpeedup && dy == 0 && _curAction!=RacoonAttack)
		_timeDelay->m_timePerFrame = 50;
	else
		_timeDelay->m_timePerFrame = 1000.0/8;
	if (_canFly && dy != 0)// && _curAction != RacoonFlySlow && _curMarioAction != MarioFall)
	{
		setMarioAction(MarioFly);
		Camera::GetInstance()->canUp = true;
	}

	if (_curType > 0)
	{
		if (_kDown&&_curMarioAction != MarioSit)
		{
			setMarioAction(MarioSit);
			if (_curMarioAction == MarioSit)
			{
				_position.Y -= MARIO_HEIGHT - _height;
				_height = MARIO_HEIGHT;
			}
			if (_kLeft != _kRight)
			{
				setMarioAction(MarioGo);
				_height = SUPERMARIO_HEIGHT;
			}
		}

		else if (!_kDown && _height == MARIO_HEIGHT /*&& (_kLeft||_kRight)*/)
		{
			_position.Y -= SUPERMARIO_HEIGHT - _height;
			_height = SUPERMARIO_HEIGHT;
			
		}
	}
	//if (_position.X <= 37 && _direction == LEFT)
	//{
	//	vx = 0;
	//}
	
	
}
void MarioCharacter::SpeedUp()
{
	if (_kSpeedup && _kMove && _curMarioAction != MarioBrake)
	{
		//	setMarioAction(MarioSpeedup);
		if (_enegryFly == 0)
		{

			delayIndexChange->Tick();
			_enegryFly = 1;
		}
		if (dy == 0)
		{

			if (dx != 0)
				vx = (dx / abs(dx))* VX_SPEEDUP;
			else
				vx = _direction*VX_SPEEDUP;
		}
	}
}

void MarioCharacter::ChangeType()
{
	if (_kUp && !isTypeUp)
	{
		timeTypeUp->Tick();
		isTypeUp = true;
	}
	if (isTypeUp)
	{
		if (_curType == SMALL_MARIO)
		{
			TypeUp(NORMAL_MARIO);
		}
		else
		{
			TypeUp(RACOON);
		}
	}
	if (_kCtrl)
	{
		timeTypeDown->Tick();
		_timeBlink->Tick();
	}
}

void MarioCharacter::TypeUp(MarioType type)
{
	if (!timeTypeUp->CanCreatNewFrame())
	{
		gametime = 0;
		if (_curType == SMALL_MARIO)
		{
			_curAction = MarioToSuper;
			_curFrame = 0;
			_position.Y -= SUPERMARIO_HEIGHT - _height;
			_height = SUPERMARIO_HEIGHT;
			//_width = 16;
		}
		else if (_curType == NORMAL_MARIO)
		{
			_curAction = SuperToRacoon;
			_curFrame = 0;
			_position.Y -= RACOON_HEIGHT - _height;
			_height = RACOON_HEIGHT;
		}	
	}
	else
	{
		gametime = 16;
		if (_curType == SMALL_MARIO)
		{
			_position.Y -= MARIO_HEIGHT - _height;
			_height = MARIO_HEIGHT;
		}
		isTypeUp = false;
		_curType = type;
		_curAction = _curType*MARIO_ACTION_COUNT + _curMarioAction;
	}
}
void MarioCharacter::TypeDown()
{
	if (_timeBlink->access && _timeBlink->CanCreatNewFrame())
	{
		_timeBlink->access = false;
		isBlink = true;
	}
	if (timeTypeDown->CanCreatNewFrame() && timeTypeDown->access)
	{
		//if (_timeBlink->CanCreatNewFrame())
		//_timeBlink->access = false;
		//isBlink = true;
		gametime = 16;
		timeTypeDown->access = false;
		if (_curType == SMALL_MARIO)
		{
			Dead();
			return;
		}
		//_timeBlink->access = false;
		if (_curType > NORMAL_MARIO)
		{
			_curType = NORMAL_MARIO;
			_height = SUPERMARIO_HEIGHT;
		}
		else
		{
			_curType = SMALL_MARIO;
			_height = MARIO_HEIGHT;
			//_width = 12;
		}
		
	}
	
	if (timeTypeDown->access && _curType >= NORMAL_MARIO)
	{
		gametime = 0;
		if (_curType > NORMAL_MARIO)
		{
			if (_curAction != SuperToRacoon)
			{
				_curAction = SuperToRacoon;
				_curFrame = 0;
			}
		}
		else if (_curType == NORMAL_MARIO)
		{
			if (_curAction != MarioToSuper)
			{
				_curAction = MarioToSuper;
				_curFrame = 0;
			}
		}
		
	}
	
}
void MarioCharacter::Attack()
{
	if (_curType != RACOON)
		return;
	if (_isDownAtkKey && _curType == RACOON && _curAction != RacoonAttack)
	{
		_curAction = RacoonAttack;
		isAttacking = true;
		_curFrame = 0;
		MarioTail::GetInstance()->isAttack = true;

		MarioTail::GetInstance()->_alive = true;

		if (!MarioTail::GetInstance()->isAttack)
		{
			MarioTail::GetInstance()->_alive = false;
		}

		if (_direction == Direction::RIGHT)
			MarioTail::GetInstance()->init(_position.X + TAIL_POS_X, _position.Y + TAIL_POS_Y, TAIL_WIDTH, TAIL_HEIGHT);
		else																				   			   
			MarioTail::GetInstance()->init(_position.X - TAIL_WIDTH-10, _position.Y + TAIL_POS_Y, TAIL_WIDTH, TAIL_HEIGHT);
	}
	else
		MarioTail::GetInstance()->_alive = false;
	if (isAttacking && _curAction == RacoonAttack)
	{
		if (_curFrame == _listAction->get(_curAction)->getCount() - 1)
		{
			
			isAttacking = false;
			MarioTail::GetInstance()->_alive = false;
		}
	}
}

void MarioCharacter::Kick()
{ 
	if (timeKick->CanCreatNewFrame() && timeKick->access)
		timeKick->access = false;
}

void MarioCharacter::Dead()
{
	if (!_isDead)
	{
		//_timeBlink->Tick();
		//if (_curType == SMALL_MARIO)
		//{
		_curAction = MarioDie;
		_curFrame = 0;
		vy = vyJump;
		//_isColl = false;
		vx = 0;
		_isDead = true;
			
		MovableObject::Dead();
		////}

	}
}
MarioType MarioCharacter::GetMarioType()
{
	return _curType;
}
void MarioCharacter::SetIsTypeUp()
{
	isTypeUp = true;
}

void MarioCharacter::OnInterSerct(BaseObject* obj)
{
	if (obj->_collType == CollDie)
	{
		
		Dead();
		
	}
	if (obj->_collType == CollEnemy && _curType == SMALL_MARIO && obj->id != 16 && ((Enemy*)obj)->_canAttMario)
	{
		_curAction = MarioDie;
		vx = 0;
		vy = 0;
	}
}

void MarioCharacter::SetType(MarioType type)
{
	this->_curType = type;
	if (type == SMALL_MARIO)
		_height = MARIO_HEIGHT;
}

MarioCharacter::~MarioCharacter()
{}

