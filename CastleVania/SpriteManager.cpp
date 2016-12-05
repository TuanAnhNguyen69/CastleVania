#include "SpriteManager.h"

SpriteManager* SpriteManager::instance = 0;
SpriteManager::SpriteManager(DirectXGame* dx)
{
	count = 14; //so luong doi tuong
	listAnimation = new Sprite*[count];
	AddSimon(dx);
	//listAnimation[Simon] = new Animation(dx, 1, 2, 10, "mario.png", D3DCOLOR_XRGB(255, 255, 255), RIGHT); 
}

SpriteManager* SpriteManager::GetInstance(DirectXGame* dx)
{
	if (instance == 0)
	{
		instance = new SpriteManager(dx);
	}
	return instance;
}

void SpriteManager::AddSimon(DirectXGame* dx)
{
	listAnimation[SpriteSimon] = new Sprite(24); //so luong hanh dong cua mario
	listAnimation[SpriteSimon]->Add(new Animation(dx, 1, 1, 10, "Data\\simon\\simon_stand.png", D3DCOLOR_XRGB(255, 255, 255),LEFT));
	listAnimation[SpriteSimon]->Add(new Animation(dx, 1, 3, 10, "Data\\simon\\simon_move.png", D3DCOLOR_XRGB(255, 255, 255), LEFT));
	listAnimation[SpriteSimon]->Add(new Animation(dx, 1, 1, 10, "Data\\simon\\simon_upstair.png", D3DCOLOR_XRGB(255, 255, 255), LEFT));
	listAnimation[SpriteSimon]->Add(new Animation(dx, 1, 1, 10, "Data\\simon\\simon_downstair.png", D3DCOLOR_XRGB(255, 255, 255), LEFT));
	listAnimation[SpriteSimon]->Add(new Animation(dx, 1, 1, 10, "Data\\simon\\simon_sit.png", D3DCOLOR_XRGB(255, 255, 255), LEFT));
	listAnimation[SpriteSimon]->Add(new Animation(dx, 1, 1, 10, "Data\\simon\\simon_sit.png", D3DCOLOR_XRGB(255, 255, 255), LEFT));
	listAnimation[SpriteSimon]->Add(new Animation(dx, 1, 3, 10, "Data\\simon\\simon_fire_stand.png", D3DCOLOR_XRGB(255, 255, 255), LEFT));
	listAnimation[SpriteSimon]->Add(new Animation(dx, 1, 3, 10, "Data\\simon\\simon_fire_upstair.png", D3DCOLOR_XRGB(255, 255, 255), LEFT));
	listAnimation[SpriteSimon]->Add(new Animation(dx, 1, 3, 10, "Data\\simon\\simon_fire_downstair.png", D3DCOLOR_XRGB(255, 255, 255), LEFT));
	//listAnimation[SpriteSimon]->Add(new Animation(dx, 3, 1, 10, "Data\\simon\\simon_basic_attack_stand.png", D3DCOLOR_XRGB(255, 255, 255), LEFT));
	//listAnimation[SpriteSimon]->Add(new Animation(dx, 3, 1, 10, "Data\\simon\\simon_basic_morning_star_stand.png", D3DCOLOR_XRGB(255, 255, 255), LEFT));
	//listAnimation[SpriteSimon]->Add(new Animation(dx, 12, 1,40, "Data\\simon\\simon_upgraded_morning_star_stand.png", D3DCOLOR_XRGB(255, 255, 255), LEFT));
	//listAnimation[SpriteSimon]->Add(new Animation(dx, 3, 1, 10, "Data\\simon\\simon_basic_attack_upstair.png", D3DCOLOR_XRGB(255, 255, 255), LEFT));
	//listAnimation[SpriteSimon]->Add(new Animation(dx, 3, 1, 10, "Data\\simon\\simon_basic_morning_star_upstair.png", D3DCOLOR_XRGB(255, 255, 255), LEFT));
	//listAnimation[SpriteSimon]->Add(new Animation(dx, 12, 1, 40, "Data\\simon\\simon_upgraded_morning_star_upstair.png", D3DCOLOR_XRGB(255, 255, 255), LEFT));
	//listAnimation[SpriteSimon]->Add(new Animation(dx, 3, 1, 10, "Data\\simon\\simon_basic_attack_downstair.png", D3DCOLOR_XRGB(255, 255, 255), LEFT));
	//listAnimation[SpriteSimon]->Add(new Animation(dx, 3, 1, 10, "Data\\simon\\simon_basic_morning_star_downstair.png", D3DCOLOR_XRGB(255, 255, 255), LEFT));
	//listAnimation[SpriteSimon]->Add(new Animation(dx, 12, 1, 40, "Data\\simon\\simon_upgraded_morning_star_downstair.png", D3DCOLOR_XRGB(255, 255, 255), LEFT));
	//listAnimation[SpriteSimon]->Add(new Animation(dx, 3, 1, 10, "Data\\simon\\simon_basic_attack_sit.png", D3DCOLOR_XRGB(255, 255, 255), LEFT));
	//listAnimation[SpriteSimon]->Add(new Animation(dx, 3, 1, 10, "Data\\simon\\simon_basic_morning_star_sit.png", D3DCOLOR_XRGB(255, 255, 255), LEFT));
	//listAnimation[SpriteSimon]->Add(new Animation(dx, 12, 1, 40, "Data\\simon\\simon_upgraded_morning_star_sit.png", D3DCOLOR_XRGB(255, 255, 255), LEFT));
	listAnimation[SpriteSimon]->Add(new Animation(dx, 1, 1, 10, "Data\\simon\\simon_hit.png", D3DCOLOR_XRGB(255, 255, 255), LEFT));
	listAnimation[SpriteSimon]->Add(new Animation(dx, 1, 1, 10, "Data\\simon\\simon_die.png", D3DCOLOR_XRGB(255, 255, 255), LEFT));
	listAnimation[SpriteSimon]->Add(new Animation(dx, 1, 3, 10, "Data\\simon\\simon_upgraded_morning_star.png", D3DCOLOR_XRGB(255, 255, 255), LEFT));

}
void SpriteManager::AddSimonWeapon(DirectXGame* dx)
{ 
	listAnimation[SpriteSimonWeapon] = new Sprite(1);
	listAnimation[SpriteSimonWeapon]->Add(new Animation(dx, 1, 4, 10, "Data\\otherdata\\flame_hit.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
}

SpriteManager::~SpriteManager()
{
}
