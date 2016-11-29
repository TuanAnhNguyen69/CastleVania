#include "CastleVania.h"
CastleVania::CastleVania() :DirectXGame()
{
	
}
void CastleVania::GameInit()
{
	Camera::GetInstance()->Init(16, 2380, 260, 196);
	Camera::GetInstance()->oldX = 16;
	Camera::GetInstance()->oldY = 2380;
	bg = new Map(this);
	//InitSound();
	SpriteManager::GetInstance(this);
	//Camera::GetInstance()->InitPlayer(MarioCharacter::GetInstance());
	bg->LoadResource();
}

bool CastleVania::Init(HINSTANCE hInstance)
{
	if (!Init_Window(hInstance))
	{		
		return false;
	}

	if (!Init_Direct3D())
	{
		return false;
	}	
	GameInit();
	
	//DirectSound_Init(_hWnd);
	Keyboard::Create(hInstance, _hWnd);
	return true;
}

void CastleVania::Run()
{
	MSG msg;
	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			if (msg.message == WM_QUIT)
				return;
		}
		Keyboard::getInstance()->PollKeyboard();
		Keyboard::getInstance()->UpdateKeyboard();
			Update();

			if (this->BeginScene())
			{
				this->SpriteHandler_Begin();

				this->Clear();
										
				Draw();
										
				this->SpriteHandler_End();
				this->EndScene();
			}
			this->Present();
	}
}


void CastleVania::Update()
{

	//MarioCharacter::GetInstance()->Run();
	Camera::GetInstance()->CameraRun();
	bg->Run();
	Camera::GetInstance()->UpdatePosition();
	//MarioCharacter::GetInstance()->UpdatePosition();


	/*if (MarioCharacter::GetInstance()->_isDead)
	{
		MarioCharacter::_life--;
		MarioCharacter::GetInstance()->_isDead = false;
		MarioCharacter::GetInstance()->_position.X = MarioCharacter::GetInstance()->oldX;
		MarioCharacter::GetInstance()->_position.Y = MarioCharacter::GetInstance()->oldY;
		Camera::GetInstance()->_position.X = Camera::GetInstance()->oldX;
		Camera::GetInstance()->_position.Y = Camera::GetInstance()->oldY;
		MarioCharacter::GetInstance()->SetType(SMALL_MARIO);
	}*/

}

void CastleVania::Draw()
{
	bg->Draw();
	char b[20];

	//PrintText("$", 10, 10, 10, D3DCOLOR_XRGB(0, 0, 0));
	//PrintText((itoa(MarioCharacter::GetInstance()->_coincount, b, 10)), 10, 20, 10, D3DCOLOR_XRGB(0, 0, 0));
	//PrintText("M", 10, 10, 20, D3DCOLOR_XRGB(0, 0, 0));
	//PrintText((itoa(MarioCharacter::GetInstance()->_life, b, 10)), 10, 20, 20, D3DCOLOR_XRGB(0, 0, 0));
	//if (MarioCharacter::GetInstance()->_life < 0)
	//{
	//	//MarioCharacter::GetInstance()->_life = 0;
	//	PrintText("GameOver", 20, 100, 80, D3DCOLOR_XRGB(0, 0, 0));
	//	MarioCharacter::GetInstance()->vx = 0;
	//	MarioCharacter::GetInstance()->vy = 0;
	//	MarioCharacter::GetInstance()->ay = 0;
	//	MarioCharacter::GetInstance()->_curAction = MarioDie;
	//}
	//MarioCharacter::GetInstance()->Draw();
}