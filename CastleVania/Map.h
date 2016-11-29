#pragma once


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include"BaseObject.h"
#include "dxManager.h"
#include"Collision.h"
//#include"Sewer.h"
//#include"Brick.h"
//#include "CCoin.h"
//#include "PBox.h"
//#include"LifeUp.h"
#include"Camera.h"
//#include"UnknownBox.h"
//#include"MarioCharacter.h"
//#include"PreventCamera.h"
//#include"Turtle.h"
//#include"IMushroom.h"
//#include"Mushroom.h"
//#include "PreTurtle.h"
//#include "Flower.h"
#include"Quadtree.h"
using namespace std;

enum ObjectType
{
	OBJMushroomGo,
	OBJMushroomFly,
	OBJTurtleGo,
	OBJTurtleRedGo,
	OBJTurtleFly,
	OBJFlowerShoot,
	OBJFlowerNonShoot,
	OBJGround,
	OBJSewer1,
	OBJSewer2,
	OBJBrick,
	OBJUnknownBox,
	OBJCoin,
	OBJLeverUp,
	OBJLine,
	OBJPBox,
	OBJPreventTurtle,
	OBJLifeUp,
	OBJSewer3,
	OBJSewer4,
	OBJPreventCam
	
};

class Map
{
	DXSurface *bg;
	vector<BaseObject * > listObj;
	//vector<UnknownBox * > listUnk;
	vector<BaseObject * > ListObjInView;
	Quadtree* tree;
	//PBox* p;
public:
	Map(DirectXGame*);
	//vector<Mushroom*> listMushroom;
	//vector<Turtle*> listTurtle;
	//vector<Flower*> listFlower;
	//vector<Brick*> listBrick;
	void LoadResource();
	void GetMapInfo(char *path);
	void LoadQuadtreeFromFile(char* path);
	void CreateObjFromFile();
	void Run();
	void Draw();
	~Map();
};

