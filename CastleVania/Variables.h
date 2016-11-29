#include <d3dx9.h>
#include "dxaudio.h"

#define FULL_SCREEN								0		// 0: Window, 1: Full Screen
#define SCREEN_WIDTH							800
#define SCREEN_HEIGHT							600
#define GAME_TITLE								"Mario Bros 3"
#define OBJECT_WIDTH							50
#define OBJECT_HEIGHT							50
#define FRAME_NUMBER							120


extern CSound* SJump;
extern CSound* Map1;
//extern CSound* Die;
extern CSound* Eat_IMushroom;
extern CSound* Attack;
extern CSound* Coin;
extern CSound* Eat_Leaf;
extern CSound* Breaking;
extern CSound* Life_up;
extern CSound* Tail;
//extern CSound* Eat_Leaf;
extern CSound* Slip;
extern CSound* Squish;
void InitSound();
