#include "CastleVania.h"

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR	 lpCmdLine,
	int		 nCmdShow)
 {
	CastleVania *_game = new CastleVania();
	_game->Init(hInstance);
	_game->Run();
	return 1;
}