#include "../Characters/Bullet.h"
#include "../Other/Variables.h"
#include "../Other/Enumerations.cpp"
#include <thread>

// Default constructor
Bullet::Bullet() {
	mFlyDirection = Up;
	mPosX = mPosY = 0;
	mWhoShot = 0;
	mAlreadyFlies = false;
}

// Constructor that allows setting everything
Bullet::Bullet(int flyDirection, int PosX, int PosY, int WhoShot) {
	mFlyDirection = flyDirection;
	mPosX = PosX;
	mPosY = PosY;
	mWhoShot = WhoShot;
	mAlreadyFlies = false;
}

// Acess functions
int Bullet::PosX() {
	return mPosX;
}
int Bullet::PosY() {	
	return mPosY;
}
int Bullet::FlyDirection() {
	return mFlyDirection;
}

bool Bullet::AlreadyFlies() {
	return mAlreadyFlies;
}

// Setting functions
void Bullet::SetBullet(int direction, int PosX, int PosY, int whoShot) {
	mFlyDirection = direction;
	mPosX = PosX;
	mPosY = PosY;
	mWhoShot = whoShot;
}

void Bullet::SetFlyDirection(int direction) {
	mFlyDirection = direction;
}

void Bullet::SetFlight(bool state) {
	mAlreadyFlies = state;
}

void Bullet::Fly() {
	while (!GameOver) {
		// Sleeps for some time to make changes visible
		std::this_thread::sleep_for(std::chrono::milliseconds(100));

		Playfield[mPosY][mPosX].SetNotBullet();

		if (Playfield[mPosY][mPosX].HasMetal()) {
			switch (Playfield[mPosY][mPosX].MetalType()) {
			case Block: {
				switch (mFlyDirection) {
				case Up: {
					mFlyDirection = Down;
					break;
				}
				case Down: {
					mFlyDirection = Up;
					break;
				}
				case Left: {
					mFlyDirection = Right;
					break;
				}
				case Right: {
					mFlyDirection = Left;
					break;
				}
				}
				break;
			}
			case Slash: {
				switch (mFlyDirection) {
				case Up: {
					mFlyDirection = Right;
					break;
				}
				case Down: {
					mFlyDirection = Left;
					break;
				}
				case Left: {
					mFlyDirection = Down;
					break;
				}
				case Right: {
					mFlyDirection = Up;
					break;
				}
				}
				break;
			}
			case BackSlash: {
				switch (mFlyDirection) {
				case Up: {
					mFlyDirection = Left;
					break;
				}
				case Down: {
					mFlyDirection = Right;
					break;
				}
				case Left: {
					mFlyDirection = Up;
					break;
				}
				case Right: {
					mFlyDirection = Down;
					break;
				}
				}
				break;
			}
			}
		}

		switch (mFlyDirection) {
		case Up: {
			mPosY--;
			break;
		}
		case Down: {
			mPosY++;
			break;
		}
		case Left: {
			mPosX--;
			break;
		}
		case Right: {
			mPosX++;
			break;
		}
		}

		// If the bullet is on the edge of the playfield, stop the movement
		if (mPosY == 0 || mPosY == (playfieldHeight - 1) || mPosX == (playfieldWidth - 1) || mPosX == 0) {

			// Stops the movement
			mAlreadyFlies = false;

			return;
		}
		
		// If the bullet hits a concrete, other bullet, lava stop the movement
		if (Playfield[mPosY][mPosX].HasConcrete()
			|| Playfield[mPosY][mPosX].HasBullet()
			|| Playfield[mPosY][mPosX].HasLava()) {
			// Stops the movement
			mAlreadyFlies = false;

			return;
		}


		if (Playfield[mPosY][mPosX].HasBrick()) {
			// Removes the block hit by the bullet
			Playfield[mPosY][mPosX].SetNotBrick();

			// Stops the movement
			mAlreadyFlies = false;

			return;
		}

		if (Playfield[mPosY][mPosX].HasPlayer()) {
			// Stops the movement and respawns the player if it was any of enemies shooting
			mAlreadyFlies = false;

			if (mWhoShot == isEnemy1 
				|| mWhoShot == isEnemy2 
				|| mWhoShot == isEnemy3)
				Player1.Respawn();

			return;
		}

		if (Playfield[mPosY][mPosX].HasEnemy()) {
			// Stops the movement and respawns the player if it was any of enemies shooting
			mAlreadyFlies = false;

			if (mWhoShot == isPlayer) {
				switch (Playfield[mPosY][mPosX].EnemyNumber()) {
				case 1: {
					Enemy1.Respawn();
					break;
				}
				case 2: {
					Enemy2.Respawn();
					break;
				}
				case 3: {
					Enemy3.Respawn();
					break;
				}
				}
			}

			return;
		}

		// Sets the new position
		Playfield[mPosY][mPosX].SetBullet();
		Playfield[mPosY][mPosX].SetBulletWhose(mWhoShot);
	}
}

// Move functions
void Bullet::MoveUp() {
	mPosY--;
}
void Bullet::MoveDown() {
	mPosY++;
}
void Bullet::MoveLeft() {
	mPosX--;
}
void Bullet::MoveRight() {
	mPosX++;
}