#include "../Playfield/Tile.h"
#include "../Other/Variables.h"
#include "../Other/Enumerations.cpp"

// Sets the playfield
void PlayfieldSetup() {
	// The map of the level
	int levelMap[playfieldHeight][playfieldWidth] = {
		10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
		10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
		10, 10, 31, 10, 10, 26, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 27, 10, 10, 10, 10, 10,
		10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 33, 10, 10, 10, 10,
		10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
		10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
		10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
		10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 25, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
		10, 10, 20, 20, 20, 20, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
		10, 10, 20, 20, 20, 20, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
		10, 10, 20, 20, 20, 20, 10, 10, 10, 10, 10, 25, 10, 10, 10, 10, 10, 25, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
		10, 10, 20, 20, 20, 20, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
		10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 32, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
		10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 25, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
		10, 10, 10, 10, 10, 10, 10, 11, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
		10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
		10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
		10, 10, 10, 10, 10, 27, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 26, 10, 10, 10, 10, 10,
		10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
		30, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
	};

	// Converts map to the playfield
	for (int i = 0; i < playfieldHeight; i++) {
		for (int j = 0; j < playfieldWidth; j++) {
			// Sets tiles depending to the number placed
			switch (levelMap[i][j]) {
			case 10: {
				// Nothing

				break;
			}
			case 11: {
				// Sets brick
				Playfield[i][j].SetBrick();
				
				break;
			}
			case 12: {
				// Sets concrete
				Playfield[i][j].SetConcrete();
				
				break;
			}
			case 13: {
				// Sets water
				Playfield[i][j].SetWater();

				break;
			}
			case 14: {
				// Sets ice
				Playfield[i][j].SetIce();

				break;
			}
			case 15: {
				// Sets lava
				Playfield[i][j].SetLava();

				break;
			}
			// Special blocks
			case 20: {
				// Sets grass
				Playfield[i][j].SetGrass();

				break;
			}
			case 21: {
				// Sets up arrow
				Playfield[i][j].SetArrow();
				Playfield[i][j].SetArrowDirection(Up);

				break;
			}
			case 22: {
				// Sets down arrow
				Playfield[i][j].SetArrow();
				Playfield[i][j].SetArrowDirection(Down);

				break;
			}
			case 23: {
				// Sets left arrow
				Playfield[i][j].SetArrow();
				Playfield[i][j].SetArrowDirection(Left);


				break;
			}
			case 24: {
				// Sets right arrow
				Playfield[i][j].SetArrow();
				Playfield[i][j].SetArrowDirection(Right);

				break;
			}
			case 25: {
				// Sets block metal
				Playfield[i][j].SetMetal();
				Playfield[i][j].SetMetalType(Block);

				break;
			}
			case 26: {
				// Sets slash metal
				Playfield[i][j].SetMetal();
				Playfield[i][j].SetMetalType(Slash);

				break;
			}
			case 27: {
				// Sets backslash metal
				Playfield[i][j].SetMetal();
				Playfield[i][j].SetMetalType(BackSlash);

				break;
			}
			// Characters
			case 30: {
				// Sets the player
				Playfield[i][j].SetPlayer();

				// Sets player position
				Player1.SetPosition(j, i);

				// Sets player spawn point
				Player1.SetSpawnPoint(j, i);

				break;
			}
			case 31: {
				// Sets the 1st enemy
				Playfield[i][j].SetEnemy();
				Playfield[i][j].SetEnemyNumber(1);
				// Sets 1st enemy position
				Enemy1.SetPosition(j, i);

				// Sets 1st enemy spawn point
				Enemy1.SetSpawnPoint(j, i);

				break;
			}
			case 32: {
				// Sets the 2nd enemy
				Playfield[i][j].SetEnemy();
				Playfield[i][j].SetEnemyNumber(2);

				// Sets 2nd enemy position
				Enemy2.SetPosition(j, i);

				// Sets 2nd enemy spawn point
				Enemy2.SetSpawnPoint(j, i);

				break;
			}
			case 33: {
				// Sets the 3rd enemy
				Playfield[i][j].SetEnemy();
				Playfield[i][j].SetEnemyNumber(3);

				// Sets 3rd enemy position
				Enemy3.SetPosition(j, i);

				// Sets 3rd enemy spawn point
				Enemy3.SetSpawnPoint(j, i);

				break;
			}
			}
		}
	}
}