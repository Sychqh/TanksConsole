#pragma once

// Replaces a number with a word so it's easier to look at

enum ConsoleColor {
	Black = 0,
	DarkBlue = 1,
	DarkGreen = 2,
	DarkCyan = 3,
	DarkRed = 4,
	DarkPink = 5,
	Brown = 6,
	LightGray = 7,
	Gray = 8,
	Blue = 9,
	Green = 10,
	Cyan = 11,
	Red = 12,
	Pink = 13,
	Yellow = 14,
	White = 15
};

enum SightDirection {
	Up = 0,
	Down = 1,
	Left = 2,
	Right = 3
};

enum MetalType {
	Block = 0,
	Slash = 1,
	BackSlash = 2 
};

enum BulletType {
	Normal = 0,
	SuperFast = 1,
	Double = 2
};

enum WeaponType {
	Default = 0,
	Explosive = 1,
	Machinegun = 2,
	Laser = 3,
	Artillery = 4
};

enum WhoShot {
	isPlayer = 1,
	isEnemy1 = 2,
	isEnemy2 = 3,
	isEnemy3 = 4
};