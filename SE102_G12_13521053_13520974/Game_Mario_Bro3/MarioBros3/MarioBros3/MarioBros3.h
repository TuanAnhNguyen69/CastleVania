#pragma warning (disable : 4996)
#include "dxManager.h"
#include "GameTime.h"
#include <stdlib.h>
#include"Animation.h"
#include "Camera.h"
#include"SpriteManager.h"
#include"MovableObject.h"
#include"MarioCharacter.h"
#include"Keyboard.h"
#include"Mushroom.h"
#include"Collision.h"
#include"Turtle.h"
#include"Flower.h"
#include"Map.h"
#include "Ground.h"
class MarioBros3 : public DirectXGame
{
	
	GameTime *gameTime;
	Map *bg;
	
public:
	MarioBros3();
	bool Init(HINSTANCE);
	void GameInit();
	void Run();
	void End();
	void Update();
	void Draw();
	~MarioBros3();
};