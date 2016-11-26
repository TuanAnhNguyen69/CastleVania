#include "GameTime.h"

GameTime::GameTime(int fps)
{
	init(fps);
}
void GameTime::init(float fps)
{
	m_timePerFrame = 1000.0 / fps;
	m_deltaTime = 0;
	m_starttime = GetTickCount();
	access = false;
}
void GameTime::Tick()
{
	m_starttime = GetTickCount();
	access = true;
}

bool GameTime::CanCreatNewFrame()
{
	
	m_now = GetTickCount();
	m_deltaTime = m_now - m_starttime;
	if (m_deltaTime >= m_timePerFrame)
	{
		if (m_deltaTime < 2 * m_timePerFrame)
		{
			m_deltaTimePrevious = m_deltaTime;
		}
		else
		{
			m_deltaTime = m_deltaTimePrevious;
		}
		m_starttime = m_now;
		return true;
	}
	else
		return false;
}
DWORD GameTime::GetTickPerFrame()
{
	return m_timePerFrame;
}

DWORD GameTime::GetDeltaTime()
{
	return m_deltaTime;
}


GameTime* GameTime::instance = 0;
GameTime * GameTime::getInstance(float fps)
{
	if (!instance)
		instance = Create(fps);
	return instance;
}

GameTime * GameTime::Create(float fps)
{
	GameTime* gt = new GameTime();
	gt->init(fps);
	return gt;
}



GameTime::GameTime()
{}

GameTime::~GameTime()
{
	
}
