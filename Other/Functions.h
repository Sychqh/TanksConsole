#pragma once
#include "../Characters/Bullet.h"
#include "../Characters/Enemy.h"
#include "../Other/Enumerations.cpp"

// Helpful functions
// Moving the console cursor
void gotoxy(int xpos, int ypos);

// Stops console cursor blinking to make it look clean
void NoCursorBlinking();

// Draws symbols with colors
void Draw(char inside, int insideColor, int backgroundColor = Black);

// Makes the bullet to fly 
void BulletFly(Bullet& bullet);

// Core functions
// Sets the playfield
void PlayfieldSetup();

// Draws everything
void Drawing();

// Allows player control
void PlayerControl();


// Allows blocks to work as intended
void BlockMechanics();



void BotMovementS(Enemy& enemy);