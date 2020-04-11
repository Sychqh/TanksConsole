#pragma once

class Bullet {
private:
	int mFlyDirection;
	int mPosX, mPosY;
	int mWhoShot;
	bool mAlreadyFlies;
public:
	// Default constructor
	Bullet();
	// Constructor that allows setting everything
	Bullet(int flyDirection, int PosX, int PosY, int WhoShot);

	// Acess functions
	int PosX();
	int PosY();
	int FlyDirection();
	bool AlreadyFlies();

	// Setting function
	void SetBullet(int direction, int PosX, int PosY, int whoShot);
	void SetFlyDirection(int direction);
	void SetFlight(bool state);

	void Fly();

	// Move functions
	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
};