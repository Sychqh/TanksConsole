#pragma once

class Tile {
private:
	// Different types of blocks
	bool mHasBrick; // regular block, can be removed by bullets
	bool mHasConcrete; // can't be removed by bullets
	bool mHasWater; // can shoot through but can't move in
	bool mHasLava; // can't shoot through and move in

	// Bullets ricoshet of it
	bool mHasMetal;
	int mMetalType;

	bool mHasGrass; // can hide inside
	bool mHasGrassOpened; // show everything in the grass if the player is nearby

	bool mHasIce; // makes you slide
	
	// Boosts you in the direction
	bool mHasArrow;
	int mArrowDirection;
	
	// Enemies
	bool mHasEnemy;
	int mEnemyNumber;

	// Main player
	bool mHasPlayer;

	// Bullet
	bool mHasBullet;
	int mBulletWhose;
public:
	// Default constructor
	Tile();

	// Acess functions
	// Regular blocks
	bool HasBrick();
	bool HasConcrete();
	bool HasWater();
	bool HasLava();

	// Metal
	bool HasMetal();
	int MetalType();

	// Special combined functions for cleaner code
	bool HasCollisionBlocks();
	bool HasCharacters();

	// Grass
	bool HasGrass();
	bool HasGrassOpened();

	// Ice
	bool HasIce();
	
	// Arrow
	bool HasArrow();
	int ArrowDirection();
	
	// Enemies
	bool HasEnemy();
	int EnemyNumber();

	// Player
	bool HasPlayer();

	// Bullet
	bool HasBullet();
	int BulletWhose();

	// Setting function
	// Regualr blocks
	void SetBrick();
	void SetNotBrick();

	void SetConcrete();
	void SetIce();
	void SetWater();
	void SetLava();

	// Grass
	void SetGrass();
	void SetGrassOpened();
	void SetGrassNotOpened();

	// Metal
	void SetMetal();
	void SetMetalType(int type);

	// Arrow
	void SetArrow();
	void SetArrowDirection(int direction);

	// Player
	void SetPlayer();
	void SetNotPlayer();

	// Enemies
	void SetEnemy();
	void SetNotEnemy();
	void SetEnemyNumber(int number);

	// Bullet
	void SetBullet();
	void SetNotBullet();
	void SetBulletWhose(int whose);
};