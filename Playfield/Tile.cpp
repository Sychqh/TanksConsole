#include "../Playfield/Tile.h"

// Default constructor
Tile::Tile() {
	mHasBrick = false;
	mHasConcrete = false;
	mHasIce = false;
	mHasWater = false;
	mHasLava = false;

	mHasGrass = false;
	mHasGrassOpened = false;
	
	mHasArrow = false;
	mArrowDirection = 0;

	mHasMetal = false;
	mMetalType = 0;

	mHasEnemy = false;
	mEnemyNumber = 0;

	mHasPlayer = false;
	mHasBullet = false;
}
/*
bool Tile::HasNothing() {
	if (!HasBrick() && !HasConcrete() && !HasIce() && !HasWater() && !HasGrass() && !HasPlayer() && !HasEnemy() && !HasArrowUp() && !HasArrowDown() && !HasArrowLeft() && !HasArrowRight())
		return true;
	else
		return false;
}*/

// Acess functions
bool Tile::HasBrick() {
	return mHasBrick;
}
bool Tile::HasConcrete() {
	return mHasConcrete;
}
bool Tile::HasGrass() {
	return mHasGrass;
}
bool Tile::HasGrassOpened() {
	return mHasGrassOpened;
}
bool Tile::HasIce() {
	return mHasIce;
}
bool Tile::HasArrow() {
	return mHasArrow;
}
int Tile::ArrowDirection() {
	return mArrowDirection;
}
bool Tile::HasEnemy() {
	return mHasEnemy;
}
int Tile::EnemyNumber() {
	return mEnemyNumber;
}
bool Tile::HasWater() {
	return mHasWater;
}

bool Tile::HasLava() {
	return mHasLava;
}

bool Tile::HasMetal() {
	return mHasMetal;
}

int Tile::MetalType() {
	return mMetalType;
}

bool Tile::HasCollisionBlocks() {
	if (mHasBrick || mHasConcrete || mHasWater || mHasMetal)
		return true;
	else 
		return false;
}

bool Tile::HasCharacters() {
	if (mHasPlayer || mHasEnemy)
		return true;
	else
		return false;
}

bool Tile::HasPlayer() {
	return mHasPlayer;
}
bool Tile::HasBullet() {
	return mHasBullet;
}

int Tile::BulletWhose() {
	return mBulletWhose;
}

// Setting functions
void Tile::SetBrick() {
	mHasBrick = true;
}
void Tile::SetNotBrick() {
	mHasBrick = false;
}
void Tile::SetConcrete() {
	mHasConcrete = true;
}

void Tile::SetGrass() {
	mHasGrass = true;
}
void Tile::SetGrassOpened() {
	mHasGrassOpened = true;
}
void Tile::SetGrassNotOpened() {
	mHasGrassOpened = false;
}

void Tile::SetMetal() {
	mHasMetal = true;
}

void Tile::SetMetalType(int type) {
	mMetalType = type;
}

void Tile::SetArrow() {
	mHasArrow = true;
}

void Tile::SetArrowDirection(int direction) {
	mArrowDirection = direction;
}

void Tile::SetIce() {
	mHasIce = true;
}
void Tile::SetWater() {
	mHasWater = true;
}

void Tile::SetLava() {
	mHasLava = true;
}

void Tile::SetPlayer() {
	mHasPlayer = true;
}
void Tile::SetNotPlayer() {
	mHasPlayer = false;
}
void Tile::SetEnemy() {
	mHasEnemy = true;
}
void Tile::SetNotEnemy() {
	mHasEnemy = false;
}
void Tile::SetEnemyNumber(int number) {
	mEnemyNumber = number;
}

void Tile::SetBullet() {
	mHasBullet = true;
}
void Tile::SetNotBullet() {
	mHasBullet = false;
}

void Tile::SetBulletWhose(int whose) {
	mBulletWhose = whose;
}
