#ifndef _CAMERA_H_
#define _CAMERA_H_

#include <d3dx9.h>
#include"Collision.h"
#include <vector>

using namespace std;
class Camera :public BaseObject
{
private:
	static Camera* instance;
	BaseObject *player;
	vector<BaseObject*> ListObj;
	vector<BaseObject*> ListEnemy;
	vector<BaseObject*> ListGround;
	vector<BaseObject*> ListItem;

public:
	static Camera* GetInstance();
	void Init(int, int, int, int);
	void InitPlayer(BaseObject *p);
	vector<BaseObject*>* GetListObj();
	vector<BaseObject*>* GetListEnemy();
	vector<BaseObject*>* GetListGround();
	vector<BaseObject*>* GetListItem();

	void ImportObject(vector<BaseObject*> listObj);
	void AddObjectToListCol();
	void UpdatePosition();
	void CameraRun();
	void OnCollision(BaseObject* obj, int nx, int ny);
	RECT ToRect();
};
#endif