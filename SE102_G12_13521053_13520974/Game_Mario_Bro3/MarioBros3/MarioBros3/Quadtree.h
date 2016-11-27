#pragma once
#include "BaseObject.h"
#include "Collision.h"
#include "QuadNode.h"
#include "Camera.h"
#include <vector>
#include <fstream>
#include <list>
#include <iostream>

using namespace std;
class Quadtree
{
	RECT rec;
	vector<BaseObject *> list_Obj;
	vector<QuadNode*> listNode_inView;
	vector<BaseObject *> listobj_inView;
	QuadNode *root_node;
	vector<BaseObject * > _listObj;
public:

	void getListObject(vector<BaseObject * > _listObj);

	Quadtree();
	Quadtree(RECT rec);

	void FindNodeInView(QuadNode* node);

	vector<BaseObject *> InsertObjIntoView(QuadNode*);

	vector<BaseObject* > GetListObjInView();
	QuadNode* getRootNode();
	void Load(ifstream &file, vector<BaseObject *> listobj);

	//void RemoveObj(BaseObject*, QuadNode*);

	~Quadtree(); //test
};
