#include "SpriteManager.h"

SpriteManager* SpriteManager::instance = 0;
SpriteManager::SpriteManager(DirectXGame* dx)
{
	count = 14; //so luong doi tuong
	listAnimation = new Sprite*[count];
	AddMario(dx);
	AddMushroom(dx);
	AddTurtle(dx);
	AddFlower(dx);
	AddTail(dx);
	AddUBrick(dx);
	AddCoin(dx);
	AddLeverUp(dx);
	Addbrick(dx);
	AddFrag(dx);
	AddPBox(dx);
	AddLifeUp(dx);
	AddPreTurtle(dx);
	AddBullet(dx);
	AddSewer(dx);
	//listAnimation[MarioGo] = new Animation(dx, 1, 2, 10, "mario.png", D3DCOLOR_XRGB(255, 255, 255), RIGHT); 
}

SpriteManager* SpriteManager::GetInstance(DirectXGame* dx)
{
	if (instance == 0)
	{
		instance = new SpriteManager(dx);
	}
	return instance;
}

void SpriteManager::AddMario(DirectXGame* dx)
{
	listAnimation[SpriteMario] = new Sprite(34); //so luong hanh dong cua mario
	listAnimation[SpriteMario]->Add(new Animation(dx, 1, 1, 10, "data\\sprite\\Mario\\mario_stand.png", D3DCOLOR_XRGB(0,255,255), RIGHT));
	listAnimation[SpriteMario]->Add(new Animation(dx, 1, 2, 10, "data\\sprite\\Mario\\mario_go.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteMario]->Add(new Animation(dx, 1, 1, 10, "data\\sprite\\Mario\\mario_stand.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteMario]->Add(new Animation(dx, 1, 1, 10, "data\\sprite\\Mario\\mario_jump.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteMario]->Add(new Animation(dx, 1, 1, 10, "data\\sprite\\Mario\\mario_brake.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteMario]->Add(new Animation(dx, 1, 1, 10, "data\\sprite\\Mario\\mario_fall.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteMario]->Add(new Animation(dx, 1, 2, 10, "data\\sprite\\Mario\\mario_speedup.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteMario]->Add(new Animation(dx, 1, 1, 10, "data\\sprite\\Mario\\mario_kick.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteMario]->Add(new Animation(dx, 1, 1, 10, "data\\sprite\\Mario\\mario_fly.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	//listAnimation[SpriteMario]->Add(new Animation(dx, 1, 2, 10, "data\\sprite\\Mario\\mario_bring.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteMario]->Add(new Animation(dx, 1, 1, 10, "data\\sprite\\Mario\\mario_bring_stand.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteMario]->Add(new Animation(dx, 1, 2, 10, "data\\sprite\\Mario\\mario_bring.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteMario]->Add(new Animation(dx, 1, 1, 10, "data\\sprite\\Mario\\mario_bring_jump.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteMario]->Add(new Animation(dx, 1, 1, 10, "data\\sprite\\Mario\\supermario_stand.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteMario]->Add(new Animation(dx, 1, 2, 10, "data\\sprite\\Mario\\supermario_go.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteMario]->Add(new Animation(dx, 1, 1, 10, "data\\sprite\\Mario\\supermario_sit.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteMario]->Add(new Animation(dx, 1, 1, 10, "data\\sprite\\Mario\\supermario_jump.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteMario]->Add(new Animation(dx, 1, 1, 10, "data\\sprite\\Mario\\supermario_brake.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteMario]->Add(new Animation(dx, 1, 1, 10, "data\\sprite\\Mario\\supermario_fall.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteMario]->Add(new Animation(dx, 1, 3, 10, "data\\sprite\\Mario\\supermario_speedup.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteMario]->Add(new Animation(dx, 1, 1, 10, "data\\sprite\\Mario\\supermario_kick.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteMario]->Add(new Animation(dx, 1, 1, 10, "data\\sprite\\Mario\\supermario_fly.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteMario]->Add(new Animation(dx, 1, 1, 10, "data\\sprite\\Mario\\supermario_bring_stand.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteMario]->Add(new Animation(dx, 1, 2, 10, "data\\sprite\\Mario\\supermario_bring_go.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteMario]->Add(new Animation(dx, 1, 1, 10, "data\\sprite\\Mario\\supermario_bring_jump.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteMario]->Add(new Animation(dx, 1, 1, 10, "data\\sprite\\Mario\\racoonmario_stand.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteMario]->Add(new Animation(dx, 1, 2, 10, "data\\sprite\\Mario\\racoonmario_go.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteMario]->Add(new Animation(dx, 1, 1, 10, "data\\sprite\\Mario\\racoonmario_sit.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteMario]->Add(new Animation(dx, 1, 1, 10, "data\\sprite\\Mario\\racoonmario_jump.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteMario]->Add(new Animation(dx, 1, 1, 10, "data\\sprite\\Mario\\racoonmario_brake.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteMario]->Add(new Animation(dx, 1, 1, 10, "data\\sprite\\Mario\\racoonmario_fall.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteMario]->Add(new Animation(dx, 1, 3, 10, "data\\sprite\\Mario\\racoonmario_speedup.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteMario]->Add(new Animation(dx, 1, 1, 10, "data\\sprite\\Mario\\racoonmario_kick.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteMario]->Add(new Animation(dx, 1, 3, 10, "data\\sprite\\Mario\\racoonmario_fly.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteMario]->Add(new Animation(dx, 1, 1, 10, "data\\sprite\\Mario\\racoonmario_bring_stand.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteMario]->Add(new Animation(dx, 1, 2, 10, "data\\sprite\\Mario\\racoonmario_bring_go.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteMario]->Add(new Animation(dx, 1, 1, 10, "data\\sprite\\Mario\\racoonmario_bring_jump.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteMario]->Add(new Animation(dx, 1, 1, 10, "data\\sprite\\Mario\\mario_die.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteMario]->Add(new Animation(dx, 1, 3, 10, "data\\sprite\\Mario\\racoonmario_flyslow.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteMario]->Add(new Animation(dx, 1, 4, 10, "data\\sprite\\Mario\\racoonmario_attack.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteMario]->Add(new Animation(dx, 1, 2, 10, "data\\sprite\\Mario\\super_racoon.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteMario]->Add(new Animation(dx, 1, 2, 10, "data\\sprite\\Mario\\mario_super.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
}

void SpriteManager::AddMushroom(DirectXGame* dx)
{
	listAnimation[SpriteEMushroom] = new Sprite(6); 
	listAnimation[SpriteEMushroom]->Add(new Animation(dx, 1, 2, 10, "data\\sprite\\Mushroom\\mushroom_yellow_go.png", D3DCOLOR_XRGB(0, 172, 255), LEFT));
	listAnimation[SpriteEMushroom]->Add(new Animation(dx, 1, 2, 10, "data\\sprite\\Mushroom\\mushroom_yellow_fly.png", D3DCOLOR_XRGB(0, 172, 255), LEFT));
	listAnimation[SpriteEMushroom]->Add(new Animation(dx, 1, 1, 10, "data\\sprite\\Mushroom\\mushroom_yellow_die.png", D3DCOLOR_XRGB(0, 172, 255), LEFT));
	listAnimation[SpriteEMushroom]->Add(new Animation(dx, 1, 2, 10, "data\\sprite\\Mushroom\\mushroom_red_go.png", D3DCOLOR_XRGB(0, 172, 255), LEFT));
	listAnimation[SpriteEMushroom]->Add(new Animation(dx, 1, 4, 10, "data\\sprite\\Mushroom\\mushroom_red_fly.png", D3DCOLOR_XRGB(0, 172, 255), LEFT));
	listAnimation[SpriteEMushroom]->Add(new Animation(dx, 1, 1, 10, "data\\sprite\\Mushroom\\mushroom_red_die.png", D3DCOLOR_XRGB(0, 172, 255), LEFT));
}

void SpriteManager::AddTurtle(DirectXGame* dx)
{
	listAnimation[SpriteTurtle] = new Sprite(8);
	listAnimation[SpriteTurtle]->Add(new Animation(dx, 1, 2, 10, "data\\sprite\\Turtle\\Turtleblue_Go.png", D3DCOLOR_XRGB(0, 172, 255), LEFT));
	listAnimation[SpriteTurtle]->Add(new Animation(dx, 1, 4, 10, "data\\sprite\\Turtle\\Turtleblue_Fly.png", D3DCOLOR_XRGB(0, 172, 255), LEFT));
	listAnimation[SpriteTurtle]->Add(new Animation(dx, 1, 4, 10, "data\\sprite\\Turtle\\Turtleblue_die.png", D3DCOLOR_XRGB(0, 172, 255), LEFT));
	listAnimation[SpriteTurtle]->Add(new Animation(dx, 1, 2, 10, "data\\sprite\\Turtle\\Turtleblue_recovery.png", D3DCOLOR_XRGB(0, 172, 255), LEFT));
	listAnimation[SpriteTurtle]->Add(new Animation(dx, 1, 2, 10, "data\\sprite\\Turtle\\TurtleRed_Go.png", D3DCOLOR_XRGB(0, 172, 255), LEFT));
	listAnimation[SpriteTurtle]->Add(new Animation(dx, 1, 4, 10, "data\\sprite\\Turtle\\TurtleRed_Fly.png", D3DCOLOR_XRGB(0, 172, 255), LEFT));
	listAnimation[SpriteTurtle]->Add(new Animation(dx, 1, 4, 10, "data\\sprite\\Turtle\\TurtleRed_die.png", D3DCOLOR_XRGB(0, 172, 255), LEFT));
	listAnimation[SpriteTurtle]->Add(new Animation(dx, 1, 2, 10, "data\\sprite\\Turtle\\TurtleRed_recovery.png", D3DCOLOR_XRGB(0, 172, 255), LEFT));

}

void SpriteManager::AddFlower(DirectXGame* dx)
{
	listAnimation[SpriteEFlower] = new Sprite(5); //so luong hanh dong cua mario
	listAnimation[SpriteEFlower]->Add(new Animation(dx, 1, 2, 10, "data\\sprite\\Flower\\Flower_LB.png", D3DCOLOR_XRGB(255, 0, 0), LEFT));
	listAnimation[SpriteEFlower]->Add(new Animation(dx, 1, 2, 10, "data\\sprite\\Flower\\Flower_LT.png", D3DCOLOR_XRGB(255, 0, 0), LEFT));
	listAnimation[SpriteEFlower]->Add(new Animation(dx, 1, 2, 10, "data\\sprite\\Flower\\Flower_RB.png", D3DCOLOR_XRGB(255, 0, 0), LEFT));
	listAnimation[SpriteEFlower]->Add(new Animation(dx, 1, 2, 10, "data\\sprite\\Flower\\Flower_RT.png", D3DCOLOR_XRGB(255, 0, 0), LEFT));
	listAnimation[SpriteEFlower]->Add(new Animation(dx, 1, 2, 10, "data\\sprite\\Flower\\Flower_Rise.png", D3DCOLOR_XRGB(255, 0, 0), LEFT));

}

void SpriteManager::AddTail(DirectXGame* dx)
{ 
	listAnimation[SpriteTail] = new Sprite(1);
	listAnimation[SpriteTail]->Add(new Animation(dx, 1, 1, 10, "data\\sprite\\Mario\\Tail.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
}

void SpriteManager::AddUBrick(DirectXGame* dx)
{
	listAnimation[SpriteUBrick] = new Sprite(3);
	listAnimation[SpriteUBrick]->Add(new Animation(dx, 1, 4, 10, "data\\UBActive.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteUBrick]->Add(new Animation(dx, 1, 1, 10, "data\\UBUnActive.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteUBrick]->Add(new Animation(dx, 1, 4, 10, "data\\brick.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
}
void SpriteManager::AddCoin(DirectXGame* dx)
{
	listAnimation[SpriteCoin] = new Sprite(2);
	listAnimation[SpriteCoin]->Add(new Animation(dx, 1, 4, 10, "data\\coin.png", D3DCOLOR_XRGB(255, 255, 255), RIGHT));
	listAnimation[SpriteCoin]->Add(new Animation(dx, 1, 4, 10, "data\\brick.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
}

void SpriteManager::AddLeverUp(DirectXGame* dx)
{
	listAnimation[SpriteLeverUp] = new Sprite(2);
	listAnimation[SpriteLeverUp]->Add(new Animation(dx, 1, 1, 10, "data\\imushroom.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteLeverUp]->Add(new Animation(dx, 1, 1, 10, "data\\leaf.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
}

void SpriteManager::Addbrick(DirectXGame* dx)
{
	listAnimation[SpriteBrick] = new Sprite(2);
	listAnimation[SpriteBrick]->Add(new Animation(dx, 1, 4, 10, "data\\brick.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteBrick]->Add(new Animation(dx, 1, 4, 10, "data\\coin.png", D3DCOLOR_XRGB(255, 255, 255), RIGHT));

}
void SpriteManager::AddFrag(DirectXGame* dx)
{
	listAnimation[SpriteFrag] = new Sprite(1);
	listAnimation[SpriteFrag]->Add(new Animation(dx, 1, 1, 10, "data\\fragment.png", D3DCOLOR_XRGB(160, 255, 240), RIGHT));
}
void SpriteManager::AddPBox(DirectXGame* dx)
{
	listAnimation[SpritePBox] = new Sprite(2);
	listAnimation[SpritePBox]->Add(new Animation(dx, 1, 1, 10, "data\\PBox.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpritePBox]->Add(new Animation(dx, 1, 1, 10, "data\\UPBox.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
}
void SpriteManager::AddLifeUp(DirectXGame* dx)
{
	listAnimation[SpriteLifeUp] = new Sprite(1);
	listAnimation[SpriteLifeUp]->Add(new Animation(dx, 1, 1, 10, "data\\lifeup.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
}
void SpriteManager::AddPreTurtle(DirectXGame* dx)
{
	listAnimation[SpritePreTurtle] = new Sprite(1);
	listAnimation[SpritePreTurtle]->Add(new Animation(dx, 1, 1, 10, "data\\no.png", D3DCOLOR_XRGB(255, 255, 255), RIGHT));
}

void SpriteManager::AddBullet(DirectXGame* dx)
{
	listAnimation[SpriteBullet] = new Sprite(1);
	listAnimation[SpriteBullet]->Add(new Animation(dx, 1, 4 , 10, "data\\BulletImage.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));

}
void SpriteManager::AddSewer(DirectXGame* dx)
{
	listAnimation[SpriteSewer] = new Sprite(4);
	listAnimation[SpriteSewer]->Add(new Animation(dx, 1, 1, 10, "data\\s1.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteSewer]->Add(new Animation(dx, 1, 1, 10, "data\\s2.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteSewer]->Add(new Animation(dx, 1, 1, 10, "data\\s3.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteSewer]->Add(new Animation(dx, 1, 1, 10, "data\\s4.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
}
SpriteManager::~SpriteManager()
{
}
