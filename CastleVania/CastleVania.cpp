#include "CastleVania.h"
CastleVania::CastleVania() :DirectXGame()
{
	
}
void CastleVania::GameInit()
{
	Camera::GetInstance()->Init(1790,622, 256, 178);
	Camera::GetInstance()->oldX = 1790;
	Camera::GetInstance()->oldY = 622;
	bg = new Map(this);
	//InitSound();
	SpriteManager::GetInstance(this);
	Camera::GetInstance()->InitPlayer(Simon::GetInstance());
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

void CastleVania::run()
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
		Keyboard::GetInstance()->PollKeyboard();
		Keyboard::GetInstance()->UpdateKeyboard();
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

	Simon::GetInstance()->run();
	Camera::GetInstance()->CameraRun();
	bg->run();
	Camera::GetInstance()->UpdatePosition();
	Simon::GetInstance()->UpdatePosition();


	if (Simon::GetInstance()->_isDead)
	{
		Simon::_life--;
		Simon::GetInstance()->_isDead = false;
		Simon::GetInstance()->_position.X = Simon::GetInstance()->oldX;
		Simon::GetInstance()->_position.Y = Simon::GetInstance()->oldY;
		Camera::GetInstance()->_position.X = Camera::GetInstance()->oldX;
		Camera::GetInstance()->_position.Y = Camera::GetInstance()->oldY;
	}

}

void CastleVania::Draw()
{
	bg->Draw();
	char b[20];

	if (Simon::GetInstance()->_life < 0)
	{
		Simon::GetInstance()->_life = 0;
		PrintText("GameOver", 20, 100, 80, D3DCOLOR_XRGB(255, 255, 255));
		Simon::GetInstance()->vx = 0;
		Simon::GetInstance()->vy = 0;
		Simon::GetInstance()->_curAction = SimonDie;
	}
	Simon::GetInstance()->Draw();
}