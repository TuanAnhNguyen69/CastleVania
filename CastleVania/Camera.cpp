#include "Camera.h"

Camera*Camera::instance = 0;
Camera*Camera::GetInstance()
{
	if (instance == 0)
	{
		instance = new Camera();
	}
	return instance;
}

void Camera::Init(int x, int y, int w, int h)
{
	_position.X = x;
	_position.Y = y;
	_width = w;
	_height = h;
	dx = 0;
	dy = 0;
}
void Camera::InitPlayer(BaseObject *p)
{
	player = p;
}
vector<BaseObject*>* Camera::GetListObj()
{
	return &ListObj;
}

vector<BaseObject*>* Camera::GetListEnemy()
{
	return &ListEnemy;
}
vector<BaseObject*>* Camera::GetListGround()
{
	return &ListGround;
}
vector<BaseObject*>* Camera::GetListItem()
{
	return &ListItem;
}

void Camera::AddObjectToListCol()
{
	ListEnemy.clear();
	ListGround.clear();
	ListItem.clear();

	bool allowAdd;
	for each(BaseObject* o in ListObj)
	{
		switch (o->_collType)
		{
		case CollEnemy:
	case CollWeapon:
			allowAdd = true;
			for each(BaseObject* o2 in ListEnemy)
			{
				if (o == o2)
				{
					allowAdd = false;
					break;
				}
			}
			if (allowAdd)
				ListEnemy.push_back(o);
			break;
		case CollGround:
		case CollStair:
			allowAdd = true;
			for each(BaseObject* o2 in ListGround)
			{
				if (o == o2)
				{
					allowAdd = false;
					break;
				}
			}
			if (allowAdd)
				ListGround.push_back(o);
			break;
		case CollItem:
			allowAdd = true;
			for each(BaseObject* o2 in ListItem)
			{
				if (o == o2)
				{
					allowAdd = false;
					break;
				}
			}
			if (allowAdd)
				ListItem.push_back(o);
			break;
		default:
			break;
		}
	}
}
void Camera::UpdatePosition()
{
	_position.X += dx;
	_position.Y += dy;
}
void Camera::ImportObject(vector<BaseObject*> listObj)
{

	bool allowAdd;
	for each(BaseObject* o1 in listObj)
	{
		allowAdd = true;
		for each(BaseObject* o2 in ListObj)
		{
			if (o1 == o2)
			{
				allowAdd = false;
				break;
			}
		}
		if (allowAdd)
		{
			if (!Collision::AABBCheck(Camera::GetInstance(), o1->oldObj) && !Collision::AABBCheck(Camera::GetInstance(), o1))
			{
				o1->setObjectFromID();
				o1->_position.X = o1->oldX;
				o1->_position.Y = o1->oldY;
			}
			ListObj.push_back(o1);
		}
	}



}

void Camera::CameraRun()
{
	int x, y;
	y = _position.Y + _height / 2;
	x = _position.X + _width / 2;
	if ((player->_position.X + player->dx > x && player->dx > 0) || (player->_position.X + player->dx < x && player->dx < 0))
	{
		dx = player->dx;
	}
	else
		dx = 0;

	if (player->_position.X + player->dx < 20)
	{
		player->_position.X = 20;
		player->dx = 0;
	}
	if (player->Right() + player->dx > 2828)
	{
		player->_position.X = 2828 - player->_width;
		player->dx = 0;
	}

	if ((player->_position.Y + player->dy > y && player->dy > 0) || (player->_position.Y + player->dy < y && player->dy < 0))
	{
		dy = player->dy;
	}
	else
		dy = 0;
}
void Camera::OnCollision(BaseObject* obj, int nx, int ny)
{
	Collision::PreventMove(this, obj, nx, ny);
}
RECT Camera::ToRect()
{
	RECT r;
	r.top = _position.Y;
	r.bottom = _position.Y + _height;
	r.left = _position.X;
	r.right = _position.X + _width;

	return r;
}