#pragma once


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include"BaseObject.h"
#include "dxManager.h"
#include"Collision.h"
#include"Camera.h"
#include"Simon.h"
#include"Quadtree.h"
#include "Ground.h"
using namespace std;

enum ObjectType
{
	OBJGround=13,
	OBJStai=14,
};

class Map
{
	DXSurface *bg;
	vector<BaseObject * > listObj;
	vector<BaseObject * > ListObjInView;
	Quadtree* tree;
public:
	Map(DirectXGame*);
	void LoadResource();
	void GetMapInfo(char *path);
	void LoadQuadtreeFromFile(char* path);
	void CreateObjFromFile();
	void run();
	void Draw();
	~Map();
};

