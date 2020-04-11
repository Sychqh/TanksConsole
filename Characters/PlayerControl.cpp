#include "../Other/Variables.h"
#include "../Characters/Bullet.h"
#include "../Other/Functions.h"
#include <thread>
#include <conio.h>

// Allows player control
void PlayerControl() {
	char playerInput = 0; // holds player input

	if (_kbhit()) // if the key is hit, check which one
		playerInput = _getch(); // gets player's input
	
	// Does things depending on the player input
	switch (playerInput) {
	// MOVEMENT
	// Up
	case 'w': { // w 
		Player1.Move(Up);
		break;
	}
	case 'W': { // W (caps lock)
		Player1.Move(Up);
		break;
	}
	case '�': { // � = w (russian symbol)
		Player1.Move(Up);
		break;
	}
	case '�': { //  � = W (russian caps lock symbol)
		Player1.Move(Up);
		break;
	}
	case 72: { //  Up Arrow (arrows)
		Player1.Move(Up);
		break;
	}
	// Down
	case 's': { // s
		Player1.Move(Down);
		break;
	}
	case 'S': { // S (caps lock)
		Player1.Move(Down);
		break;
	}
	case '�': { // � = s (russian symbol)
		Player1.Move(Down);
		break;
	}
	case '�': { // � = S (russian caps lock symbol)
		Player1.Move(Down);
		break;
	}
	case 80: { // Down Arrow (arrows)
		Player1.Move(Down);
		break;
	}
	// Left
	case 'a': { // a
		Player1.Move(Left);
		break;
	}
	case 'A': { // A (caps lock)
		Player1.Move(Left);
		break;
	}
	case '�': { // � = a (russian symbol)
		Player1.Move(Left);
		break;
	}
	case '�': { // � = A (russian caps lock symbol)
		Player1.Move(Left);
		break;
	}
	case 75: { // Left arrow (arrows)
		Player1.Move(Left);
		break;
	}
	// Right
	case 'd': { // d
		Player1.Move(Right);
		break;
	}
	case 'D': { // D (caps lock)
		Player1.Move(Right);
		break;
	}
	case '�': { // � = d (russian symbol)
		Player1.Move(Right);
		break;
	}
	case '�': { // � = D (russian caps lock symbol)
		Player1.Move(Right);
		break;
	}
	case 77: { // Right arrow (arrows)
		Player1.Move(Right);
		break;
	}

	// TURNING
	// Left
	case 'q': { // q
		Player1.TurnLeft();
		break;
	}
	case 'Q': { // Q (caps lock)
		Player1.TurnLeft();
		break;
	}
	case '�': { // � = q (russian symbol)
		Player1.TurnLeft();
		break;
	}
	case '�': { // � = Q (russian caps lock symbol)
		Player1.TurnLeft();
		break;
	}
	// Right
	case 'e': { // e
		Player1.TurnRight();
		break;
	}
	case 'E': { // E (caps lock)
		Player1.TurnRight();
		break;
	}
	case '�': { // � = e (russian symbol)
		Player1.TurnRight();
		break;
	}
	case '�': { // � = E (russian caps lock symbol)
		Player1.TurnRight();
		break;
	}

	// SHOOTING
	case ' ': { // Space
		Player1.Shoot();
		break;
	}
	case 13: { // Enter
		Player1.Shoot();
		break;
	}
	}

	/*
	// Does things depending on the player input
	switch (playerInput) {
	// MOVEMENT
	case 'w': { //  w - up
		Player.MoveUp();
		break;
	}
	case 's': { // s - down
		Player.MoveDown();
		break;
	}
	case 'a': { // a - left
		Player.MoveLeft();
		break;
	}
	case 'd': { // d - right
		Player.MoveRight();
		break;
	}
	// For CAPS lock
	case 'W': { //  W - up
		Player.MoveUp();
		break;
	}
	case 'S': { // S - down
		Player.MoveDown();
		break;
	}
	case 'A': { // A - left
		Player.MoveLeft();
		break;
	}
	case 'D': { // D - right
		Player.MoveRight();
		break;
	}
	// Russian symbols
	case '�': { // � = w - up
		Player.MoveUp();
		break;
	}
	case '�': { // � = s - down
		Player.MoveDown();
		break;
	}
	case '�': { // � = a - left
		Player.MoveLeft();
		break;
	}
	case '�': { // � = d - right
		Player.MoveRight();
		break;
	}
	// For CAPS lock russian symbols
	case '�': { //  � = W - up
		Player.MoveUp();
		break;
	}
	case '�': { // � = S - down
		Player.MoveDown();
		break;
	}
	case '�': { // � = A - left
		Player.MoveLeft();
		break;
	}
	case '�': { // � = D - right
		Player.MoveRight();
		break;
	}
	// Arrows
	case 72: { //  w - up
		Player.MoveUp();
		break;
	}
	case 80: { // s - down
		Player.MoveDown();
		break;
	}
	case 75: { // a - left
		Player.MoveLeft();
		break;
	}
	case 77: { // d - right
		Player.MoveRight();
		break;
	}
	// SHOOTING
	case ' ': { // space - shoot
		Player.Shoot();
		break;
	}
	case 13: {
		Player.Shoot();
		break;
	}
	}
	*/
}