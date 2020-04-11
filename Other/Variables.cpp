#include "../Playfield/Tile.h"
#include "../Characters/Character.h"
#include "../Characters/Enemy.h"
#include "../Characters/Player.h"
#include "../Characters/Bullet.h"
#include "../Other/Enumerations.cpp"
#include <Windows.h>

// For console colors
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

// The dimensions of the playfield
const int playfieldHeight = 20;
const int playfieldWidth = 30;

// The playfield itself
Tile Playfield[playfieldHeight][playfieldWidth];

// checks if there is a bullet that already flies, if yes, doesn't shoot again
bool BulletAlreadyFliesPlayer = false;
bool BulletAlreadyFliesEnemy1 = false;
bool BulletAlreadyFliesEnemy2 = false;
bool BulletAlreadyFliesEnemy3 = false;

// The main player
Player Player1;

// All enemies existing at the time
Enemy Enemy1(1);
Enemy Enemy2(2);
Enemy Enemy3(3);

// All bullets
Bullet bulletPlayer;
Bullet bulletEnemy1;
Bullet bulletEnemy2;
Bullet bulletEnemy3;

// True is the game is over
bool GameOver = false;

