/*
	Started: 12.07.2019
	Finished:
	Time spent: 37

	боты стрел€ют по две пули
*/

#include "../Characters/Bullet.h"
#include "../Characters/Character.h"
#include "../Characters/Enemy.h"
#include "../Other/Functions.h"
#include "../Playfield/Tile.h"
#include "../Other/Enumerations.cpp"
#include "../Other/Variables.h"

#include <iostream> // for printing
#include <Windows.h> // for coloring text
#include <conio.h> // for _getch()
#include <thread> // for bullet movement and AI
#include <chrono> // for sleep

int main() {
	system("title Tanks"); // changes the title of console window to Tanks
	system("mode con cols=100 lines=50"); // changes the size of the screen
	NoCursorBlinking(); // stops console cursor blinking to make it look clean
	SetConsoleCP(1251); // for russian symbols imput
	SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | White)); // beginning color for everything is black background, white symbols
	
	
	// Sets the playfield
	PlayfieldSetup();
	
	std::thread thBlockMech(BlockMechanics);
	thBlockMech.detach();
	
	std::thread thEnemy1(&Enemy::Movement, &Enemy1);
	thEnemy1.detach();

	std::thread thEnemy2(&Enemy::Movement, &Enemy2);
	thEnemy2.detach();

	std::thread thEnemy3(&Enemy::Movement, &Enemy3);
	thEnemy3.detach();
	

	// GAME LOOP
	do {
		Drawing();

		PlayerControl();

	} while (!GameOver);

	system("pause");
}