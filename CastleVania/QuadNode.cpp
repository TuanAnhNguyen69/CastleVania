#include "QuadNode.h"


QuadNode::QuadNode()
{
	rect = new BaseObject();
}

QuadNode::QuadNode(char* path)
{
	/*ifstream f;
	f.open(path);
	LoadNode(f);*/
}

QuadNode::QuadNode(int id, BaseObject* r)
{
	this->tl = NULL;
	this->tr = NULL;
	this->br = NULL;
	this->bl = NULL;
	this->ID = id;
	this->rect = r;
}

int QuadNode::GetID()
{
	return this->ID;
}

int QuadNode::GetNum_Node()
{
	return this->num_node;
}

int QuadNode::GetNum_Obj()
{
	return this->num_obj;
}

QuadNode* QuadNode::GetChildNode(int i)
{
	switch (i)
	{
	case 1:
		return this->tl;
	case 2:
		return this->tr;
	case 3:
		return this->bl;
	case 4:
		return this->br;
	}
}

//BaseObject* QuadNode::GetObjInNode(int k)
//{ 
//	BaseObject* obj = new BaseObject();
//
//	switch (k)
//	{
//		case 7:
//		{
//					obj = new Ground();
//					listGround.push_back(obj);
//					break;
//		}
//		case 8:
//		{
//					obj = new Sewer();
//					listGround.push_back(obj);
//					break;
//		}
//		case 9:
//		{
//					obj = new Sewer();
//					listGround.push_back(obj);
//					break;
//		}
//		case 10:
//		{
//					obj = new Brick();
//					listGround.push_back(obj);
//					break;
//		}
//		case 11:
//		{
//					obj = new UnknownBox();
//					listGround.push_back(obj);
//					break;
//		}
//		case 12:
//			break;
//		case 16:
//			obj = new PreventCamera();
//			break;
//		case 0:
//
//		case 1:
//			obj = new Mushroom();
//			listEnemy.push_back(obj);
//			break;
//		case 2:
//		case 3:
//		case 4:
//			obj = new Turtle();
//			listEnemy.push_back(obj);
//			break;
//		default:
//			break;	
//	}
//	return obj;
//}

void QuadNode::CreateSubNode()
{
	this->tl = new QuadNode();
	this->tr = new QuadNode();
	this->bl = new QuadNode();
	this->br = new QuadNode();
}

void QuadNode::LoadNode(ifstream *f, vector<BaseObject*> listObj)
{
	(*f) >> rect->_position.X;
	(*f) >> rect->_position.Y;
	(*f) >> rect->_width;
	(*f) >> rect->_height;
	(*f) >> num_node;
	(*f) >> num_obj;


	///rect.left ??
	///rect.right ??
	///rect.bottom ??
	///rect.top ??

	if (num_node == 0 && num_obj == 0)
	{
		return;
	}

	if (num_node == 4)
	{
		CreateSubNode();
		tl->LoadNode(f, listObj);
		tr->LoadNode(f, listObj);
		bl->LoadNode(f, listObj);
		br->LoadNode(f, listObj);
	}
	else
	{
		for (int i = 0; i < num_obj; i++)
		{
			int k; (*f) >> k;
			ListObjectInNode.push_back(listObj.at(k));
		}
	}
}

BaseObject* QuadNode::GetRect()
{
	return rect;
}

vector<BaseObject *> QuadNode::getListObjInNode()
{
	return ListObjectInNode;
}



QuadNode::~QuadNode()
{
}
