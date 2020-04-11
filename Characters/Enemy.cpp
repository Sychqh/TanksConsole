#include "../Characters/Enemy.h"
#include "../Characters/Bullet.h"
#include "../Other/Functions.h"
#include "../Other/Variables.h"
#include "../Other/Enumerations.cpp"
#include <thread>
#include <cstdlib>
#include <ctime>

int Enemy::mEnemyHealthAmount = 20;

Enemy::Enemy() : Character() {
	mNumber = 0;
}
Enemy::Enemy(int Number) : Character() {
	mNumber = Number;
}

// Acess functions
int Enemy::Number() {
	return mNumber;
}

// Respawn function, puts back to spawn point
void Enemy::Respawn() {
	mEnemyHealthAmount--;

	Playfield[PosY()][PosX()].SetNotEnemy();
	Playfield[PosY()][PosX()].SetEnemyNumber(0);
	
	SetPosition(SpawnX(), SpawnY());

	Playfield[PosY()][PosX()].SetEnemy();
	Playfield[PosY()][PosX()].SetEnemyNumber(mNumber);
}

// Shooting function
void Enemy::Shoot() {
	switch (mNumber) {
	case 1: {
		if (BulletAlreadyFlies()) {}
		else {
			// Sets the bullet
			SetBullet(isEnemy1);

			// Puts bullet movement to another thread so it can be done at the same time as the main process
			std::thread thEnemy1Bullet(&Bullet::Fly, &chBullet());
			thEnemy1Bullet.detach();

			SetBulletFlight(true);
		}
	}
	case 2: {
		if (BulletAlreadyFlies()) {}
		else {
			// Sets the bullet
			SetBullet(isEnemy2);

			// Puts bullet movement to another thread so it can be done at the same time as the main process
			std::thread thEnemy2Bullet(&Bullet::Fly, &chBullet());
			thEnemy2Bullet.detach();
			
			SetBulletFlight(true);
		}
	}
	case 3: {
		if (BulletAlreadyFlies()) {}
		else {
			// Sets the bullet
			SetBullet(isEnemy3);

			// Puts bullet movement to another thread so it can be done at the same time as the main process
			std::thread thEnemy3Bullet(&Bullet::Fly, &chBullet());
			thEnemy3Bullet.detach();

			SetBulletFlight(true);
		}
	}
	}
	
}

// "AI" bot movement
void Enemy::Movement() {
	srand((unsigned)time(0)); // automatically randomizes rand() values
	while (!GameOver) {
		int shootChance; // the chances of shooting while moving
		int stepsAmount; // the amount of steps the bot makes

		// A little delay to make it look like the bot is thinking
		std::this_thread::sleep_for(std::chrono::milliseconds(500));

		// Randomizes the amount of steps
		stepsAmount = rand() % 10;
		
		// Randomly sets the direction of the bot
		// Every bot gets his own direction
		switch (mNumber) {
		case 1: {
			SetSightDirection(rand() % 4);
			break;
		}
		case 2: {
			SetSightDirection(rand() % 4);
			SetSightDirection(rand() % 4);
			break;
		}
		case 3: {
			SetSightDirection(rand() % 4);
			SetSightDirection(rand() % 4);
			SetSightDirection(rand() % 4);
			break;
		}
		}

		// Moves
		for (int i = 0; i < stepsAmount; i++) {
			std::this_thread::sleep_for(std::chrono::milliseconds(700));

			// Rerandomize the direction if can't move 
			if (!CanMove(SightDirection()))
				SetSightDirection(rand() % 4);

			Move(SightDirection());
			
			// Shoots with a chance
			shootChance = rand() % 10;
			//if (shootChance < 3)
				//Shoot();
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
}

bool Enemy::CanMove(int direction) {
	switch (SightDirection()) {
	case Up: {
		if (PosY() == 0 || Playfield[PosY() - 1][PosX()].HasCollisionBlocks() || Playfield[PosY() - 1][PosX()].HasCharacters())
			return false;
		return true;
		break;
	}
	case Down: {
		if (PosY() == (playfieldHeight - 1) || Playfield[PosY() + 1][PosX()].HasCollisionBlocks() || Playfield[PosY() + 1][PosX()].HasCharacters())
			return false;
		return true;
		break;
	}
	case Left: {
		if (PosX() == 0 || Playfield[PosY()][PosX() - 1].HasCollisionBlocks() || Playfield[PosY()][PosX() - 1].HasCharacters())
			return false;
		return true;
		break;
	}
	case Right: {
		if (PosX() == (playfieldWidth - 1) || Playfield[PosY()][PosX() + 1].HasCollisionBlocks() || Playfield[PosY()][PosX() + 1].HasCharacters())
			return false;
		return true;
		break;
	}
	}
	return false;
}

// 
void Enemy::Move(int direction) {
	// Setf the sight direction
	SetSightDirection(direction);

	// Sets previous position to non-enemy
	Playfield[PosY()][PosX()].SetNotEnemy();
	Playfield[PosY()][PosX()].SetEnemyNumber(0);

	// Moves in the schosen direcction
	switch (direction) {
	case Up: {
		// Collision detection
		if (PosY() == 0 || Playfield[PosY() - 1][PosX()].HasCollisionBlocks() || Playfield[PosY() - 1][PosX()].HasCharacters()) {}
		else {
			// Moves up
			DecreasePosY();
		}
		break;
	}
	case Down: {
		// Collision detection
		if (PosY() == (playfieldHeight - 1) || Playfield[PosY() + 1][PosX()].HasCollisionBlocks() || Playfield[PosY() + 1][PosX()].HasCharacters()) {}
		else {
			// Moves down
			AddPosY();
		}
		break;
	}
	case Left: {
		// Collision detection
		if (PosX() == 0 || Playfield[PosY()][PosX() - 1].HasCollisionBlocks() || Playfield[PosY()][PosX() - 1].HasCharacters()) {}
		else {
			// Moves left
			DecreasePosX();
		}
		break;
	}
	case Right: {
		// Collision detection
		if (PosX() == (playfieldWidth - 1) || Playfield[PosY()][PosX() + 1].HasCollisionBlocks() || Playfield[PosY()][PosX() + 1].HasCharacters()) {}
		else {
			// Moves right
			AddPosX();
		}
		break;
	}
	}
	
	// Sets the enemy to the new position
	Playfield[PosY()][PosX()].SetEnemy();
	Playfield[PosY()][PosX()].SetEnemyNumber(mNumber);
}

void Enemy::MoveBack() {}
/*
void Enemy::MoveBack() {
	// Sets previous position to non-enemy
	switch (mNumber) {
	case 1: {
		Playfield[PosY()][PosX()].SetNotEnemy1();

		break;
	}
	case 2: {
		Playfield[PosY()][PosX()].SetNotEnemy2();

		break;
	}
	case 3: {
		Playfield[PosY()][PosX()].SetNotEnemy3();

		break;
	}
	}

	// Moves the enemy back to his previous position
	switch (SightDirection()) {
	case Up: {
		AddPosY();
		break;
	}
	case Down: {
		DecreasePosY();
		break;
	}
	case Left: {
		AddPosX();
		break;
	}
	case Right: {
		DecreasePosX();
		break;
	}
	}

	// Sets the enemy to the new position
	switch (mNumber) {
	case 1: {
		Playfield[PosY()][PosX()].SetEnemy1();

		break;
	}
	case 2: {
		Playfield[PosY()][PosX()].SetEnemy2();

		break;
	}
	case 3: {
		Playfield[PosY()][PosX()].SetEnemy3();

		break;
	}
	}
}
*/