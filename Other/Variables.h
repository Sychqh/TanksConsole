#pragma once
#include "../Playfield/Tile.h"
#include "../Characters/Character.h"
#include "../Characters/Enemy.h"
#include "../Characters/Player.h"
#include "../Characters/Bullet.h"
#include <Windows.h>

// For console colors
extern HANDLE hConsole;

// The dimensions of the playfield
const int playfieldHeight = 20;
const int playfieldWidth = 30;

// The playfield itself
extern Tile Playfield[playfieldHeight][playfieldWidth];

// checks if there is a bullet that already flies, if yes, doesn't shoot again
extern bool BulletAlreadyFliesPlayer;
extern bool BulletAlreadyFliesEnemy1;
extern bool BulletAlreadyFliesEnemy2;
extern bool BulletAlreadyFliesEnemy3;

// The main player
extern Player Player1;

// All enemies existing at the time
extern Enemy Enemy1;
extern Enemy Enemy2;
extern Enemy Enemy3;

// All bullet
extern Bullet bulletPlayer;
extern Bullet bulletEnemy2;
extern Bullet bulletEnemy1;
extern Bullet bulletEnemy3;

// True is the game is over
extern bool GameOver;
