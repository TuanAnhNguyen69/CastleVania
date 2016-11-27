#include "PreventCamera.h"


PreventCamera::PreventCamera()
{
	_collType = CollItem;
}
vector<PreventCamera*>* PreventCamera::listPreventCamera = 0;

vector<PreventCamera*>* PreventCamera::getlistPreventCamera()
{
	if (listPreventCamera == 0)
	{
		listPreventCamera = new vector<PreventCamera*>();
		PreventCamera* p = new PreventCamera();
		p->init(0, 2128, 2848, 16);
		
		listPreventCamera->push_back(p);
		p = new PreventCamera();
		p->init(0, 2128, 16, 450);
		listPreventCamera->push_back(p);
		p = new PreventCamera();
		p->init(2832, 2128, 16, 450);
		listPreventCamera->push_back(p);
		p = new PreventCamera();
		p->init(0, 2576, 2848, 16);
		p->_collType = CollDie;
		listPreventCamera->push_back(p);
	}
	return listPreventCamera;
}

PreventCamera::~PreventCamera()
{
}
