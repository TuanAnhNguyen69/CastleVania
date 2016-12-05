#include "Map.h"

int x, y, w, h;
Map::Map(DirectXGame*g)
{
	bg = new DXSurface(g);

}

void Map::LoadResource()
{
	bg->LoadSurface("Data//Map//Level02a.png", D3DCOLOR_XRGB(255, 255, 255));
	GetMapInfo("Data//Map//02tesstOBJ.txt"); //map
	LoadQuadtreeFromFile("Data//Map//02tesstQuadtree.txt"); //finalQuadtree
	
}
void Map::GetMapInfo(char *path)
{
	BaseObject* obj = 0;
	fstream f;
	f.open(path);
	int n;

	f >> n;
	for (int i = 0; i < n; i++)
	{
		int id;
		f >> id;
		int index = 0;
		switch (id)
		{
		case OBJGround:
		{
			obj = new Ground();
			break;
		}
		default:
			break;
		}
		f >> obj->_position.X;
		f >> obj->_position.Y;
		f >> obj->_width;
		f >> obj->_height;
			
		obj->oldX = obj->_position.X;
		obj->oldY = obj->_position.Y;
		obj->oldObj = new BaseObject();
		obj->oldObj->init(obj->_position.X, obj->_position.Y, obj->_width, obj->_height);
		listObj.push_back(obj);

		obj->id = id;
		obj->setObjectFromID();

	}
}

void Map::CreateObjFromFile()
{
	for (int i = 0; i < listObj.size(); i++)
	{
		for each(BaseObject* obj in listObj)
		{
			obj->Create(x, y, w, h);
		}
	}
}
void Map::LoadQuadtreeFromFile(char* path)
{

	tree = new Quadtree();
	ifstream file(path);

	tree->getListObject(listObj);

	tree->getRootNode()->LoadNode(&file, listObj);
	file.close();
}
void Map::run()
{
	//Camera::GetInstance()->GetListEnemy()->clear();
	//Camera::GetInstance()->GetListGround()->clear();
	//Camera::GetInstance()->GetListItem()->clear();
	for (int i = 0; i < Camera::GetInstance()->GetListObj()->size();)//doi tuong nam trong camera, neu checkAABB sai thi se xoa ra khoi camera
	{
		if (!Collision::AABBCheck(Camera::GetInstance(), Camera::GetInstance()->GetListObj()->at(i)))
			Camera::GetInstance()->GetListObj()->erase(Camera::GetInstance()->GetListObj()->begin() + i);
		else
			i++;
	}


	tree->FindNodeInView(tree->getRootNode());// tim khong gian roi nhet doi tuong do vao camera
	Camera::GetInstance()->AddObjectToListCol();
	for each (BaseObject* obj in *Camera::GetInstance()->GetListEnemy())
	{
		obj->Run();
	}
	for each (BaseObject* obj in *Camera::GetInstance()->GetListGround())
	{
		obj->Run();
	}
	for each (BaseObject* obj in *Camera::GetInstance()->GetListItem())
	{
		obj->Run();
	}

	for each (BaseObject* obj1 in *Camera::GetInstance()->GetListEnemy())
	{
		Collision::CheckCollision(Simon::GetInstance(), obj1);
		Collision::CheckCollision(SimonWeapon::GetInstance(), obj1);
	}
	for each (BaseObject* obj1 in *Camera::GetInstance()->GetListItem())
	{
		Collision::CheckCollision(Simon::GetInstance(), obj1);
		
	}
	for each (BaseObject* obj in *Camera::GetInstance()->GetListGround())
	{
		Collision::CheckCollision(Simon::GetInstance(), obj); 
		Collision::CheckCollision(SimonWeapon::GetInstance(), obj);


		for each (BaseObject* obj2 in *Camera::GetInstance()->GetListItem())
		{
			Collision::CheckCollision(obj2, obj);
		}
		for each (BaseObject* obj1 in *Camera::GetInstance()->GetListEnemy())
		{
			Collision::CheckCollision(obj1, obj);
		}

	}
	//Bullet::BulletRun();
	for each(BaseObject* obj in *Camera::GetInstance()->GetListEnemy())
	{
		for each (BaseObject* obj1 in *Camera::GetInstance()->GetListEnemy())
		{
			Collision::CheckCollision(obj1, obj);
		}
	}
	for each (BaseObject* obj in *Camera::GetInstance()->GetListEnemy())
	{
		obj->UpdatePosition();
	}
	for each (BaseObject* obj in *Camera::GetInstance()->GetListGround())
	{
		obj->UpdatePosition();
	}

	for each (BaseObject* obj in *Camera::GetInstance()->GetListItem())
	{
		obj->UpdatePosition();
	}

	/*for each (PreventCamera* p in *PreventCamera::getlistPreventCamera())
	{
		Collision::CheckCollision(Camera::GetInstance(), p);
		Collision::CheckCollision(MarioCharacter::GetInstance(), p);
	}
*/
}
void Map::Draw()
{
	bg->Draw();
	for each (BaseObject* obj in *Camera::GetInstance()->GetListEnemy())
	{
		obj->Draw();
	}
	for each (BaseObject* obj in *Camera::GetInstance()->GetListGround())
	{
		obj->Draw();
	}
	for each (BaseObject* obj in *Camera::GetInstance()->GetListItem())
	{
		obj->Draw();
	}
	//Bullet::BulletDraw();
}


Map::~Map()
{
}
