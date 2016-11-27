#pragma once
#include "BaseObject.h"
#include<vector>
using namespace std;
class PreventCamera :
	public BaseObject
{
	static vector<PreventCamera*>* listPreventCamera;
public:
	static vector<PreventCamera*>* getlistPreventCamera();
	PreventCamera();
	~PreventCamera();
};

