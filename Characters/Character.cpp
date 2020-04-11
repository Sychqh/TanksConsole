#include "../Characters/Character.h"
#include "../Characters/Bullet.h"
#include "../Other/Functions.h"
#include "../Other/Enumerations.cpp"
#include "../Other/Variables.h"
#include <thread>
#include <chrono>

// Default constructor
Character::Character() {
	mSightDirection = Up;
	mPosY = mPosX = 0;
	mSpawnX = mSpawnY = 0;
}

// Acess function
int Character::SightDirection() {
	return mSightDirection;
}
int Character::PosX() {
	return mPosX;
}
int Character::PosY() {
	return mPosY;
}
int Character::SpawnX() {
	return mSpawnX;
}
int Character::SpawnY() {
	return mSpawnY;
}

bool Character::BulletAlreadyFlies() {
	return mBullet.AlreadyFlies();
}

Bullet &Character::chBullet() {
	return mBullet;
}

// Add and decrease funcions
void Character::AddPosX() {
	mPosX++;
}
void Character::AddPosY() {
	mPosY++;
}
void Character::DecreasePosX() {
	mPosX--;
}
void Character::DecreasePosY() {
	mPosY--;
}

// Setting function
void Character::SetSightDirection(int direction) {
	mSightDirection = direction;
}
void Character::SetPosition(int PosX, int PosY) {
	mPosX = PosX;
	mPosY = PosY;
}
void Character::SetSpawnPoint(int SpawnX, int SpawnY) {
	mSpawnX = SpawnX;
	mSpawnY = SpawnY;
}

void Character::SetBullet(int WhoShot) {
	mBullet.SetBullet(mSightDirection, mPosX, mPosY, WhoShot);
}

void Character::SetBulletFlight(bool state) {
	mBullet.SetFlight(state);
}

// Respawn function, puts back to spawn point
void Character::Respawn() {}
// Shooting fucntion
void Character::Shoot() {}


// Move function
void Character::Move(int direction) {}

// Moves the player back to his last position
void Character::MoveBack() {
	// Sets previous position to non-player
	Playfield[mPosY][mPosX].SetNotPlayer();

	// Moves the player back to his previous position
	switch (mSightDirection) {
	case Up: {
		mPosY++;
		break;
	}
	case Down: {
		mPosY--;
		break;
	}
	case Left: {
		mPosX++;
		break;
	}
	case Right: {
		mPosX--;
		break;
	}
	}

	// Sets the player to the new position
	Playfield[mPosY][mPosX].SetPlayer();
}
