#pragma once
#include "../Characters/Bullet.h"

class Character {
private:
	int mSightDirection; // the direction of sight
	int mPosX, mPosY; // position on the playfield
	int mSpawnX, mSpawnY; // spawn position
	
	Bullet mBullet;
public:
	// Default constructor
	Character();

	// Acess function
	int SightDirection();
	int PosX();
	int PosY();
	int SpawnX();
	int SpawnY();
	bool BulletAlreadyFlies();
	Bullet &chBullet();

	// Add and decrease funcions 
	void AddPosX();
	void AddPosY();
	void DecreasePosX();
	void DecreasePosY();
	
	// Set functions
	void SetSightDirection(int direction);
	void SetPosition(int PosX, int PosY);
	void SetSpawnPoint(int SpawnX, int SpawnY);
	void SetBullet(int WhoShot);
	void SetBulletFlight(bool state);

	// Respawn function, puts back to spawn point
	virtual void Respawn();

	// Shooting fucntion
	virtual void Shoot();

	// Move functions
	virtual void Move(int direction);
	void MoveBack();
};