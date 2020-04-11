#include "../Characters/Player.h"
#include "../Other/Variables.h"
#include "../Other/Enumerations.cpp"
#include <thread>

Player::Player() : Character() {
	mHealthAmount = 5;
}

int Player::HeathAmount() {
	return mHealthAmount;
}

void Player::Respawn() {
	mHealthAmount--;
	Playfield[PosY()][PosX()].SetNotPlayer();

	SetPosition(SpawnX(), SpawnY());
	Playfield[PosY()][PosX()].SetPlayer();
}

void Player::Shoot() {
	if (BulletAlreadyFlies()) {}
	else {
		// Sets the bullet
		SetBullet(isPlayer);

		// Puts bullet movement to another thread so it can be done at the same time as the main process
		std::thread threadPlayerBullet(&Bullet::Fly, &chBullet());
		threadPlayerBullet.detach();

		SetBulletFlight(true);
	}
}

void Player::Move(int direction) {
	// Sets the sight direction
	SetSightDirection(direction);

	// Sets previous position to non-player
	Playfield[PosY()][PosX()].SetNotPlayer();

	// Moves in the chosen direcction
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

	// Sets the player to the new position
	Playfield[PosY()][PosX()].SetPlayer();
}

// Turning functions, turns to the side
void Player::TurnLeft() {
	switch (SightDirection()) {
	case Up: {
		SetSightDirection(Left);
		break;
	}
	case Down: {
		SetSightDirection(Right);
		break;
	}
	case Left: {
		SetSightDirection(Down);
		break;
	}
	case Right: {
		SetSightDirection(Up);
		break;
	}
	}
}
void Player::TurnRight() {
	switch (SightDirection()) {
	case Up: {
		SetSightDirection(Right);
		break;
	}
	case Down: {
		SetSightDirection(Left);
		break;
	}
	case Left: {
		SetSightDirection(Up);
		break;
	}
	case Right: {
		SetSightDirection(Down);
		break;
	}
	}
}
