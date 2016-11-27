#include "Quadtree.h"


Quadtree::Quadtree()
{
	root_node = new QuadNode();
}

Quadtree::Quadtree(RECT r)
{
	rec = r;
}
void Quadtree::getListObject(vector<BaseObject * > listObj)
{
	_listObj = listObj;
}



void Quadtree::FindNodeInView(QuadNode* node)
{
	if (node == NULL)
		return;
	if (node->GetRect() && !Collision::AABBCheck(Camera::GetInstance(), node->GetRect()))
		return;

	if (node->GetNum_Node() == 4)
	{
		FindNodeInView(node->tl);
		FindNodeInView(node->tr);
		FindNodeInView(node->bl);
		FindNodeInView(node->br);
		return;
	}
	if (node->getListObjInNode().size() == 0)
		return;
	Camera::GetInstance()->ImportObject(node->getListObjInNode());

}
QuadNode* Quadtree::getRootNode()
{
	return root_node;
}
void Quadtree::Load(ifstream &file, vector<BaseObject *> listObj)
{
	//root_node->LoadNode(file, listObj);
	//int pos_x; file >> pos_x;
	//int pos_y; file >> pos_y;
	//int width; file >> width;
	//int height; file >> height;
	//int Num_Node; file >> Num_Node;
	//int object_num; file >> object_num;

	//rec.left = pos_x;
	//rec.top = pos_y;
	//rec.right = pos_x + width;
	//rec.bottom = pos_y + height;


	//if (Num_Node == 0 && object_num == 0)
	//	return;

	//if (Num_Node == 4)
	//{
	//	CreateSubNode();
	//	/*LeftTop->Load(file, listObj);
	//	RightTop->Load(file, listObj);
	//	LeftBot->Load(file, listObj);
	//	RightBot->Load(file, listObj);*/
	//}
	//else
	//{
	//	for (int i = 0; i < object_num; i++)
	//	{
	//		int k; file >> k;
	//		if (k < listObj.size())
	//		{
	//			list_Obj.push_back(listObj[k]);
	//		}
	//	}
	//}
}

vector<BaseObject *> Quadtree::InsertObjIntoView(QuadNode * n)
{
	/*
	if (n->GetChildNode(1) == NULL)
	{
	if (Collision::AABBCheck(Camera::GetInstance(), n->GetRect()))
	{

	bool allowadd = true;
	for each (BaseObject* o in  n->getListObjInNode())
	{
	for each (BaseObject* o1 in  listobj_inView)
	{
	if (o == o1)
	{
	allowadd = false;
	break;
	}
	}
	if (allowadd)
	this->listobj_inView.push_back(o);
	}

	}
	}
	else
	{
	if (Collision::AABBCheck(Camera::GetInstance(), n->GetChildNode(1)->GetRect()))
	{
	InsertObjIntoView(n->GetChildNode(1));
	}
	if (Collision::AABBCheck(Camera::GetInstance(), n->GetChildNode(2)->GetRect()))
	{
	InsertObjIntoView(n->GetChildNode(2));
	}
	if (Collision::AABBCheck(Camera::GetInstance(), n->GetChildNode(3)->GetRect()))
	{
	InsertObjIntoView(n->GetChildNode(3));
	}
	if (Collision::AABBCheck(Camera::GetInstance(), n->GetChildNode(4)->GetRect()))
	{
	InsertObjIntoView(n->GetChildNode(4));
	}
	}*/
	return listobj_inView;
}

vector<BaseObject* > Quadtree::GetListObjInView()
{
	InsertObjIntoView(root_node);
	return this->listobj_inView;
}

//void Quadtree::RemoveObj(BaseObject* obj, QuadNode* node){
//	if (node->GetChildNode(1) == NULL)
//	{
//		node->RemoveObj(obj);
//	}
//	else
//	{
//		this->RemoveObj(obj, node->GetChildNode(1));
//		this->RemoveObj(obj, node->GetChildNode(2));
//		this->RemoveObj(obj, node->GetChildNode(3));
//		this->RemoveObj(obj, node->GetChildNode(4));
//	}
//}

Quadtree::~Quadtree()
{
}
