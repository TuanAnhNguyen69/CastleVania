#include "Map.h"

int x, y, w, h;
Map::Map(DirectXGame*g)
{
	bg = new DXSurface(g);

}

void Map::LoadResource()
{
	bg->LoadSurface("background.png", D3DCOLOR_XRGB(255, 255, 255));
	GetMapInfo("data//Map//mapbros.txt"); //map
	LoadQuadtreeFromFile("data//Map//mapbrosQuadtree.txt"); //finalQuadtree
	
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
		case OBJSewer1:
		case OBJSewer3:
		case OBJSewer4:
		{
						  obj = new Sewer();
						  break;
		}
		case OBJSewer2:
		{
						  obj = new Sewer();
						  break;
		}
		case OBJBrick:
		{
						 f >> index;
						 if (index == 0)
						 {
							 obj = new Brick();
							 listBrick.push_back((Brick*)obj);
							 break;
						 }
						 else if (index != 0)
						 {

							 obj = new UnknownBox();
							 listUnk.push_back(((UnknownBox*)obj));
							 ((UnknownBox*)obj)->indexitem = index;
							 //listBrick.push_back((Brick*)obj);
							 break;
						 }
		}
		case OBJUnknownBox:
		{
							  obj = new UnknownBox();
							  listUnk.push_back(((UnknownBox*)obj));
							  f >> ((UnknownBox*)obj)->indexitem;
							  break;
		}
		case OBJCoin:
			obj = new CCoin();
			break;
		case OBJPreventCam:
			//obj = new PreventCamera();
			break;
		case OBJMushroomGo:
		case OBJMushroomFly:
			obj = new Mushroom();
			listMushroom.push_back((Mushroom*)obj);
			break;
		case OBJTurtleGo:
		case OBJTurtleRedGo:
		case OBJTurtleFly:
			obj = new Turtle();
			listTurtle.push_back((Turtle*)obj);
			break;
		case OBJLine:
			obj = new Ground();
			obj->_collType = CollLine;
			break;
		case OBJFlowerShoot:
		case OBJFlowerNonShoot:
			obj = new Flower();
			
			listFlower.push_back((Flower*)obj);
			break;
		case OBJLeverUp:
			obj = new IMushroom();
			break;
		case OBJPBox:
			obj = new PBox();
			p = (PBox*)obj;
			break;
		case OBJLifeUp:
			obj = new LifeUp();
			break;
		case OBJPreventTurtle:
			obj = new PreTurtle();
			break;

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
	for each (UnknownBox* unk in listUnk)
	{
		unk->item = (Item*)listObj.at(unk->indexitem);
		listObj.at(unk->indexitem)->_alive = false;
	}
	for each(Brick* b in listBrick)
	{
		p->listBrick.push_back(b);
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
void Map::Run()
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
		Collision::CheckCollision(MarioCharacter::GetInstance(), obj1);
		Collision::CheckCollision(MarioTail::GetInstance(), obj1);
	}
	for each (BaseObject* obj1 in *Camera::GetInstance()->GetListItem())
	{
		Collision::CheckCollision(MarioCharacter::GetInstance(), obj1);
		
	}
	for each (BaseObject* obj in *Camera::GetInstance()->GetListGround())
	{
		Collision::CheckCollision(MarioCharacter::GetInstance(), obj); 
		Collision::CheckCollision(MarioTail::GetInstance(), obj);


		for each (BaseObject* obj2 in *Camera::GetInstance()->GetListItem())
		{
			Collision::CheckCollision(obj2, obj);
		}
		for each (BaseObject* obj1 in *Camera::GetInstance()->GetListEnemy())
		{
			Collision::CheckCollision(obj1, obj);
		}

	}
	Bullet::BulletRun();
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

	for each (PreventCamera* p in *PreventCamera::getlistPreventCamera())
	{
		Collision::CheckCollision(Camera::GetInstance(), p);
		Collision::CheckCollision(MarioCharacter::GetInstance(), p);
	}

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
	Bullet::BulletDraw();
}


Map::~Map()
{
}
