#include "../Other/Functions.h"
#include "../Other/Variables.h"
#include "../Characters/Enemy.h"
#include <Windows.h>
#include <iostream>
#include <thread>
#include <chrono>

// Moving the console cursor
void gotoxy(int xpos, int ypos) {
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = xpos; scrn.Y = ypos;
	SetConsoleCursorPosition(hOuput, scrn);
}

// Stops console cursor blinking to make it look clean
void NoCursorBlinking() {
	void* handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(handle, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(handle, &structCursorInfo);
}

// Draws symbols with colors
void Draw(char inside, int insideColor, int backgroundColor) {
	SetConsoleTextAttribute(hConsole, (WORD)((backgroundColor << 4) | insideColor));
	std::cout << inside;
	SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | White));
}


