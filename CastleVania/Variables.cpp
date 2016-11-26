#include <d3dx9.h>
#include "Variables.h"

CSound* SJump;
CSound* Map1;
//CSound* Die;
CSound* Eat_IMushroom;
CSound* Attack;
CSound* Coin;
CSound* Eat_Leaf;
CSound* Breaking;
CSound* Life_up;
CSound* Tail;
CSound* Slip;
CSound* Squish;

void InitSound()
{
	SJump = LoadSound("data\\sound\\JumpingSFX.wav");
	Map1 = LoadSound("data\\sound\\map1.wav");
	//Die = LoadSound("Resource\\Music\\BG_Map2.wav");
	Eat_IMushroom = LoadSound("data\\sound\\Mushroom Obtained SFX.wav");
	Attack = LoadSound("data\\sound\\Bump V1 SFX.wav");
	Coin = LoadSound("data\\sound\\Coin.wav");
	Eat_Leaf = LoadSound("data\\sound\\Raccoon Leaf Obtained SFX.wav");
	Breaking = LoadSound("data\\sound\\Breaking Blocks SFX.wav");
	Life_up = LoadSound("data\\sound\\1-UpSFX.wav");
	Tail = LoadSound("data\\sound\\Raccoon Tail Whip SFX.wav");
	//Eat_Leaf = LoadSound("Resource\\Music\\Base_Bullet.wav");
	Slip = LoadSound("data\\sound\\Slipping SFX.wav");
	Squish = LoadSound("data\\sound\\Squish SFX.wav");
}