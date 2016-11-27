#pragma once
#include"BaseObject.h"
#include "Ground.h"
#include "dxManager.h"
#include"Collision.h"
#include"Sewer.h"
#include"Brick.h"
#include"UnknownBox.h"
#include"MarioCharacter.h"
#include"PreventCamera.h"
#include"Turtle.h"
#include"Mushroom.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <list>
#define path_quadtree L"Data//Map//MapQuadtree.txt"
using namespace std;

class QuadNode : public BaseObject
{
protected:
	int ID;
	int x, y, w, h;
	int num_node;
	int num_obj;
	BaseObject *rect;
	vector<BaseObject*> ListObjectInNode;
	//vector<BaseObject*> listEnemy;
	//vector<BaseObject*> listItem;
	//vector<BaseObject*> listGround;
public:
	QuadNode();
	QuadNode(char* path);
	QuadNode(int id, BaseObject* r);

	void LoadNode(ifstream *f, vector<BaseObject*> listObj);

	//BaseObject* GetObjInNode(int k);

	void CreateSubNode();

	QuadNode *tl, *tr, *bl, *br;
	BaseObject* GetRect();

	QuadNode* GetChildNode(int);

	int GetID();
	int GetNum_Obj();
	int GetNum_Node();

	vector<BaseObject*> getListObjInNode();

	//void getListEnemy(vector<BaseObject * > listObj);
	//void getListGround(vector<BaseObject * > listObj);
	//void getListItem(vector<BaseObject * > listObj);

	//void RemoveObj(BaseObject*);
	~QuadNode();
};

