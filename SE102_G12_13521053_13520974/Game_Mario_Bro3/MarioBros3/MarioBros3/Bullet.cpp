#include "Bullet.h"

vector<Bullet *>* Bullet::listBullet = 0;
vector<Bullet *>* Bullet::GetList()
{
	if (!listBullet)
		listBullet = new	vector<Bullet *>();
	return listBullet;
}
Bullet::Bullet() :MovableObject()
{
	_listAction = SpriteManager::GetInstance()->listAnimation[SpriteBullet];
	_collType = CollEnemy;
	
}

void Bullet::Run()
{
	_position.X += dx;
	_position.Y += dy;
}
void Bullet::OnInterSerct(BaseObject* obj)
{ 
	if (obj->_collType == CollMario)
	{
		MarioCharacter::GetInstance()->timeTypeDown->Tick();
		MarioCharacter::GetInstance()->_timeBlink->Tick();
	}
}
void Bullet::BulletRun()
{
	for each(Bullet* b in *GetList())
	{
		b->Run();
		Collision::CheckCollision(MarioCharacter::GetInstance(), b);
	}
}
void Bullet::BulletDraw()
{
	for each (Bullet *b in *GetList())
	{
		b->Draw();
	}
}
Bullet::~Bullet()
{
}
