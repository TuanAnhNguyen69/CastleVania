#include "MarioBros3.h"

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR	 lpCmdLine,
	int		 nCmdShow)
 {
	MarioBros3 *_game = new MarioBros3();
	_game->Init(hInstance);
	_game->Run();
	return 1;
}