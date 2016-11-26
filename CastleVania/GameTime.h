#pragma once
#include <windows.h>
#include <time.h>
#include "Variables.h"

class GameTime
{
private:

	DWORD m_deltaTimePrevious;
	DWORD m_starttime;
	DWORD m_now;

	GameTime();
	void init(float fps);
	static GameTime* instance;
public:
	bool access;
	GameTime(int fps);
	void Tick();
	DWORD m_deltaTime;
	DWORD m_timePerFrame;
	bool CanCreatNewFrame();
	
	DWORD GetDeltaTime();
	DWORD GetGameTime();
	DWORD GetTickPerFrame();
	void Release();
	static GameTime* getInstance(float fps = 0);


	static GameTime *Create(float fps);

	~GameTime();
};
