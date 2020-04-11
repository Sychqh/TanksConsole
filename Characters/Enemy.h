#pragma once
#include "../Characters/Character.h"

class Enemy : public Character {
private:
	int mNumber;
	static int mEnemyHealthAmount;
public:
	// Constructors
	Enemy();
	Enemy(int Number);

	// Acess functions
	int Number();

	// Respawn function, puts back to spawn point
	void Respawn();

	// Shooting function
	void Shoot();

	//
	void Movement();
	bool CanMove(int direction);

	// Move functions
	void Move(int direction);
	void MoveBack();
	
	void MoveUp();
	void MoveRight();
	void MoveDown();
	void MoveLeft();
};