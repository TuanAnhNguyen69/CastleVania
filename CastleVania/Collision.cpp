#include "Collision.h"


Collision::Collision()
{

}

BaseObject* Collision::GetSweptBroadphaseBox(BaseObject* B)
{
	int x, y, w, h;
	x = B->dx > 0 ? B->_position.X : B->_position.X + B->dx;
	y = B->dy > 0 ? B->_position.Y : B->_position.Y + B->dy;
	w = B->dx > 0 ? B->_width + B->dx : B->_width - B->dx;
	h = B->dy > 0 ? B->_height + B->dy : B->_height - B->dy;
	BaseObject* broadphasebox = BaseObject::Create(x, y, w, h);
	return broadphasebox;
}

float Collision::sweptAABB(BaseObject * b1, BaseObject * b2, int& normalx, int& normaly)
{
	float xInvEntry, yInvEntry;
	float xInvExit, yInvExit;

	if (b1->dx > 0.0f)
	{
		xInvEntry = b2->_position.X - (b1->_position.X + b1->_width);
		xInvExit = (b2->_position.X + b2->_width) - b1->_position.X;
	}
	else
	{
		xInvEntry = (b2->_position.X + b2->_width) - b1->_position.X;
		xInvExit = b2->_position.X - (b1->_position.X + b1->_width);
	}

	if (b1->dy > 0.0f)
	{
		yInvEntry = b2->_position.Y - (b1->_position.Y + b1->_height);
		yInvExit = (b2->_position.Y + b2->_height) - b1->_position.Y;
	}
	else
	{
		yInvEntry = (b2->_position.Y + b2->_height) - b1->_position.Y;
		yInvExit = b2->_position.Y - (b1->_position.Y + b1->_height);
	}

	float xEntry, yEntry;
	float xExit, yExit;

	if (b1->dx == 0.0f)
	{
		xEntry = -std::numeric_limits<float>::infinity();
		xExit = std::numeric_limits<float>::infinity();
	}
	else
	{
		/*if (xInvEntry != 0)
		xEntry = (xInvEntry - abs(b1->dx) / b1->dx) / b1->dx;
		else
		xEntry = 0;
		xExit = xInvExit / b1->dx;*/
		xEntry = xInvEntry / b1->dx;
		xExit = xInvExit / b1->dx;
	}

	if (b1->dy == 0.0f)
	{
		yEntry = -std::numeric_limits<float>::infinity();
		yExit = std::numeric_limits<float>::infinity();
	}
	else
	{
		yEntry = yInvEntry / b1->dy;
		yExit = yInvExit / b1->dy;
	}

	float entryTime = MAX(xEntry, yEntry);
	float exitTime = MIN(xExit, yExit);

	if (entryTime > exitTime || xEntry < 0.0f && yEntry < 0.0f || xEntry > 1.0f || yEntry > 1.0f)
		//if (entryTime > exitTime || xEntry > 1.0f || yEntry > 1.0f)
	{
		normalx = 0.0f;
		normaly = 0.0f;
		return 1.0f;
	}
	else
	{
		if (xEntry > yEntry)
		{
			if (b1->dx <= 0.0f)
			{
				normalx = 1.0f;
				normaly = 0.0f;
			}
			else
			{
				normalx = -1.0f;
				normaly = 0.0f;
			}

		}
		else
		{
			if (b1->dy <= 0.0f)
			{
				normalx = 0.0f;
				normaly = 1.0f;
			}
			else
			{
				normalx = 0.0f;
				normaly = -1.0f;
			}

		}
		return entryTime;
	}
}
void Collision::PreventMove(BaseObject* b1, BaseObject* b2, int nx, int ny)
{
	if (b1->_collType == CollSimon)
		int a = 5;
	if (b2->id>6 && b2->id < 12)
		b1->c = true;
	else
		b1->c = false;
	if (b1->Top()<b2->Bottom() && b1->Bottom()>b2->Top())
	{
		if (b2->Left() - b1->Right() < b1->dx && b1->dx > 0)
		{
			b1->dx = b2->Left() - b1->Right();
			if (nx != 0)
			{
				b1->vx = 0;
			}
			
		}
		if (b2->Right() - b1->Left() > b1->dx && b1->dx < 0)
		{
			b1->dx = b2->Right() - b1->Left();
			if (nx != 0)
			{
				b1->vx = 0;
			}
		}

		/*if (abs(b1->dx) > abs(b1->dx*collisionTime))
		b1->dx *= -normalX*collisionTime;*/
	}
	else
		b1->normalx = 0;
	if (b1->Left()<b2->Right() && b1->Right()>b2->Left())
	{
		if (b2->Top() - b1->Bottom() < b1->dy && b1->dy > 0)
		{
			b1->dy = b2->Top() - b1->Bottom();
			b1->vy = 0;
			
		}
		if (b2->Bottom() - b1->Top() > b1->dy && b1->dy < 0)
		{
			b1->dy = b2->Bottom() - b1->Top() + 1;
			b1->vy = 0;
		}

		b1->c = false;
		/*if (abs(b1->dy)> abs(b1->dy*collisionTime))
		b1->dy *= -normalY*collisionTime;*/
	}
	else
		b1->normaly = 0;
}
bool Collision::AABBCheck(BaseObject* b1, BaseObject *b2)
{
	return !(b1->Top() > b2->Bottom() || b2->Top() > b1->Bottom() || b1->Left() > b2->Right() || b1->Right()  < b2->Left());
}

void Collision::CheckCollision(BaseObject* b1, BaseObject* b2)
{
	
	if (!b1->_alive || !b2->_alive)
		return;
	if (b1 == b2)
		return;
	if (AABBCheck(b1, b2))
	{
		b1->OnInterSerct(b2);
		b2->OnInterSerct(b1);
	}
	if (b1->_isDead || b2->_isDead)
		return;
	BaseObject* broadphase = GetSweptBroadphaseBox(b1);
	if (AABBCheck(broadphase, b2))
	{
		int normalx, normaly;
		int collisionTime = sweptAABB(b1, b2, normalx, normaly);
		
		if (normalx != 0)
			b1->normalx = normalx;
		//b1->vx = 0;
		if (normaly != 0)
		{
			b1->normaly = normaly;
		}
		if (collisionTime < 1)
		{
			b1->OnCollision(b2, normalx, normaly);
			b2->OnCollision(b1, normalx, normaly);
		}
	}
	delete broadphase;
}
void Collision::CollisionLine(BaseObject* b1, BaseObject* b2, int nx, int ny)
{
	//b1->normaly = 0;
	//if (AABBCheck(b1, b2))
	//	return;
	if (b1->_collType == CollSimon)
 		int a = 5;
	b1->c = false;
	if (b1->Left()<b2->Right() && b1->Right()>b2->Left())
	{
		if (abs(b2->Top() - b1->Bottom()) < abs(b1->dy) && b1->dy > 0)
		{
			b1->dy = b2->Top() - b1->Bottom();
			b1->vy = 0;
			b1->normaly = -1;
		}
	}
	else
		b1->normaly = 0;
}
Collision::~Collision()
{
	
}
