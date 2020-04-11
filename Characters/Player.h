#pragma once
#include "../Characters/Character.h"

class Player : public Character {
	int mHealthAmount; // the amount of health left
private:
public:
	// Default constructor

	Player();
	// Acess function
	int HeathAmount();

	// Respawning function
	void Respawn();

	// Shooting function
	void Shoot();

	// Moving function
	void Move(int direction);

	// Turning functions
	void TurnLeft();
	void TurnRight();
};