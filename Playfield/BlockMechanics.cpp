#include "../Other/Variables.h"
#include "../Other/Enumerations.cpp"
#include <thread>

void BlockMechanics() {
	while (true) {
		// Lava mechanics
		for (int i = 0; i < playfieldHeight; i++) {
			for (int j = 0; j < playfieldWidth; j++) {
				if (Playfield[i][j].HasLava()) {
					if (Playfield[i][j].HasPlayer()) {
						Player1.Respawn();
					}
					if (Playfield[i][j].HasEnemy()) {
						if (Playfield[i][j].EnemyNumber() == 1)
							Enemy1.Respawn();
						if (Playfield[i][j].EnemyNumber() == 2)
							Enemy2.Respawn();
						if (Playfield[i][j].EnemyNumber() == 3)
							Enemy3.Respawn();
					}
				}
			}
		}

		// Arrows mechanics
		for (int i = 0; i < playfieldHeight; i++) {
			for (int j = 0; j < playfieldWidth; j++) {
				// If there is an arrow, move very fast int the arrows direction
				if (Playfield[i][j].HasArrow()) {
					if (Playfield[i][j].HasPlayer()) {
						std::this_thread::sleep_for(std::chrono::milliseconds(30));

						for (int iterator = 0; i < 5; i++) {
							Player1.Move(Playfield[i][j].ArrowDirection());
							std::this_thread::sleep_for(std::chrono::milliseconds(30));
						}
					}
					if (Playfield[i][j].HasEnemy()) {
						switch (Playfield[i][j].EnemyNumber()) {
						case 1: {
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							for (int iterator = 0; i < 5; i++) {
								Enemy1.Move(Playfield[i][j].ArrowDirection());
								std::this_thread::sleep_for(std::chrono::milliseconds(30));

							}
						}
						case 2: {
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							for (int iterator = 0; i < 5; i++) {
								Enemy2.Move(Playfield[i][j].ArrowDirection());
								std::this_thread::sleep_for(std::chrono::milliseconds(30));

							}
						}
						case 3: {
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							for (int iterator = 0; i < 5; i++) {
								Enemy3.Move(Playfield[i][j].ArrowDirection());
								std::this_thread::sleep_for(std::chrono::milliseconds(30));

							}
						}
						}
					}
				}
			}
		}

		// Grass mechanic
		// Opens every grass block around the player
		for (int i = 0; i < playfieldHeight; i++) {
			for (int j = 0; j < playfieldWidth; j++) {
				if (Playfield[i][j].HasPlayer() && Playfield[i][j].HasGrass()) {
					Playfield[i][j].SetGrassOpened();
					// Special cases for block what are on the edges or last lines
					// so the don't use a block that doesn't exist
					if (i == 0) { // first vertical line, can't do left
						if (j == 0) {// 0-0 tile
							if (Playfield[i + 1][j].HasGrass())
								Playfield[i + 1][j].SetGrassOpened();
							if (Playfield[i + 1][j + 1].HasGrass())
								Playfield[i + 1][j + 1].SetGrassOpened();
							if (Playfield[i][j + 1].HasGrass())
								Playfield[i][j + 1].SetGrassOpened();
						}
						else if (j == (playfieldWidth - 1)) { // 0-last tile
							if (Playfield[i + 1][j].HasGrass())
								Playfield[i + 1][j].SetGrassOpened();
							if (Playfield[i + 1][j - 1].HasGrass())
								Playfield[i + 1][j - 1].SetGrassOpened();
							if (Playfield[i][j - 1].HasGrass())
								Playfield[i][j - 1].SetGrassOpened();
						}
						else { // only first vertical line
							if (Playfield[i + 1][j].HasGrass())
								Playfield[i + 1][j].SetGrassOpened();
							if (Playfield[i + 1][j + 1].HasGrass())
								Playfield[i + 1][j + 1].SetGrassOpened();
							if (Playfield[i + 1][j - 1].HasGrass())
								Playfield[i + 1][j - 1].SetGrassOpened();
							if (Playfield[i][j - 1].HasGrass())
								Playfield[i][j - 1].SetGrassOpened();
							if (Playfield[i][j + 1].HasGrass())
								Playfield[i][j + 1].SetGrassOpened();
						}	
					}
					else if (i == (playfieldHeight - 1)) { // last vertical line, can't do right 
						if (j == 0) { // last-0 tile
							if (Playfield[i - 1][j].HasGrass())
								Playfield[i - 1][j].SetGrassOpened();
							if (Playfield[i - 1][j + 1].HasGrass())
								Playfield[i - 1][j + 1].SetGrassOpened();
							if (Playfield[i][j + 1].HasGrass())
								Playfield[i][j + 1].SetGrassOpened();
						}
						else if (j == (playfieldWidth - 1)) { // last-last tile
							if (Playfield[i - 1][j].HasGrass())
								Playfield[i - 1][j].SetGrassOpened();
							if (Playfield[i - 1][j - 1].HasGrass())
								Playfield[i - 1][j - 1].SetGrassOpened();
							if (Playfield[i][j - 1].HasGrass())
								Playfield[i][j - 1].SetGrassOpened();
						}
						else { // only last vertical line
							if (Playfield[i - 1][j].HasGrass())
								Playfield[i - 1][j].SetGrassOpened();
							if (Playfield[i - 1][j + 1].HasGrass())
								Playfield[i - 1][j + 1].SetGrassOpened();
							if (Playfield[i - 1][j - 1].HasGrass())
								Playfield[i - 1][j - 1].SetGrassOpened();
							if (Playfield[i][j - 1].HasGrass())
								Playfield[i][j - 1].SetGrassOpened();
							if (Playfield[i][j + 1].HasGrass())
								Playfield[i][j + 1].SetGrassOpened();
						}
					}
					else if (j == 0) { // only first horizontal line, can't do up
						if (Playfield[i + 1][j].HasGrass())
							Playfield[i + 1][j].SetGrassOpened();
						if (Playfield[i + 1][j + 1].HasGrass())
							Playfield[i + 1][j + 1].SetGrassOpened();
						if (Playfield[i - 1][j + 1].HasGrass())
							Playfield[i - 1][j + 1].SetGrassOpened();
						if (Playfield[i - 1][j].HasGrass())
							Playfield[i - 1][j].SetGrassOpened();
						if (Playfield[i][j + 1].HasGrass())
							Playfield[i][j + 1].SetGrassOpened();
					}
					else if (j == (playfieldWidth - 1)) { // only last horizontal line, can't do down
						if (Playfield[i + 1][j].HasGrass())
							Playfield[i + 1][j].SetGrassOpened();
						if (Playfield[i + 1][j - 1].HasGrass())
							Playfield[i + 1][j - 1].SetGrassOpened();
						if (Playfield[i - 1][j - 1].HasGrass())
							Playfield[i - 1][j - 1].SetGrassOpened();
						if (Playfield[i - 1][j].HasGrass())
							Playfield[i - 1][j].SetGrassOpened();
						if (Playfield[i][j - 1].HasGrass())
							Playfield[i][j - 1].SetGrassOpened();
					}
					else { // no restrictions
						if (Playfield[i + 1][j].HasGrass())
							Playfield[i + 1][j].SetGrassOpened();
						if (Playfield[i - 1][j].HasGrass())
							Playfield[i - 1][j].SetGrassOpened();
						if (Playfield[i][j + 1].HasGrass())
							Playfield[i][j + 1].SetGrassOpened();
						if (Playfield[i][j - 1].HasGrass())
							Playfield[i][j - 1].SetGrassOpened();
						if (Playfield[i + 1][j + 1].HasGrass())
							Playfield[i + 1][j + 1].SetGrassOpened();
						if (Playfield[i - 1][j + 1].HasGrass())
							Playfield[i - 1][j + 1].SetGrassOpened();
						if (Playfield[i + 1][j - 1].HasGrass())
							Playfield[i + 1][j - 1].SetGrassOpened();
						if (Playfield[i - 1][j - 1].HasGrass())
							Playfield[i - 1][j - 1].SetGrassOpened();
					}
				}

				// Closes every grass block that's isn't close to a player
				if (Playfield[i][j].HasGrassOpened()) {
				// Special cases for blocks what are on the edges or last lines
				// so the don't use a block that doesn't exist
				// If the player isn't near the grass block, "close" it
				if (i == 0) { // first vertical line, can't do left
					if (j == 0) { // 0-0 tile
						if (Playfield[i + 1][j].HasPlayer() && Playfield[i + 1][j].HasGrass())
							continue;
						if (Playfield[i + 1][j + 1].HasPlayer() && Playfield[i + 1][j + 1].HasGrass())
							continue;
						if (Playfield[i][j + 1].HasPlayer() && Playfield[i][j + 1].HasGrass())
							continue;
					}
					else if (j == (playfieldWidth - 1)) { // 0-last tile
						if (Playfield[i + 1][j].HasPlayer() && Playfield[i + 1][j].HasGrass())
							continue;
						if (Playfield[i + 1][j - 1].HasPlayer() && Playfield[i + 1][j - 1].HasGrass() && Playfield[i + 1][j - 1].HasGrass())
							continue;
						if (Playfield[i][j - 1].HasPlayer() && Playfield[i][j - 1].HasGrass())
							continue;
					}
					else { // only first vertical line
						if (Playfield[i + 1][j].HasPlayer() && Playfield[i + 1][j].HasGrass())
							continue;
						if (Playfield[i + 1][j + 1].HasPlayer() && Playfield[i + 1][j + 1].HasGrass())
							continue;
						if (Playfield[i + 1][j - 1].HasPlayer() && Playfield[i + 1][j - 1].HasGrass() && Playfield[i + 1][j - 1].HasGrass())
							continue;
						if (Playfield[i][j - 1].HasPlayer() && Playfield[i][j - 1].HasGrass())
							continue;
						if (Playfield[i][j + 1].HasPlayer() && Playfield[i][j + 1].HasGrass())
							continue;
					}
				}
				else if (i == (playfieldHeight - 1)) {  // last vertical line, can't do right
					if (j == 0) { // last-0 tile
						if (Playfield[i - 1][j].HasPlayer() && Playfield[i - 1][j].HasGrass())
							continue;
						if (Playfield[i - 1][j + 1].HasPlayer() && Playfield[i - 1][j + 1].HasGrass())
							continue;
						if (Playfield[i][j + 1].HasPlayer() && Playfield[i][j + 1].HasGrass())
							continue;
					}
					else if (j == (playfieldWidth - 1)) { // last-last tile
						if (Playfield[i - 1][j].HasPlayer() && Playfield[i - 1][j].HasGrass())
							continue;
						if (Playfield[i - 1][j - 1].HasPlayer() && Playfield[i - 1][j - 1].HasGrass())
							continue;
						if (Playfield[i][j - 1].HasPlayer() && Playfield[i][j - 1].HasGrass())
							continue;
					}
					else { // only last vertical line
						if (Playfield[i - 1][j].HasPlayer() && Playfield[i - 1][j].HasGrass())
							continue;
						if (Playfield[i - 1][j + 1].HasPlayer() && Playfield[i - 1][j + 1].HasGrass())
							continue;
						if (Playfield[i - 1][j - 1].HasPlayer() && Playfield[i - 1][j - 1].HasGrass())
							continue;
						if (Playfield[i][j - 1].HasPlayer() && Playfield[i][j - 1].HasGrass())
							continue;
						if (Playfield[i][j + 1].HasPlayer() && Playfield[i][j + 1].HasGrass())
							continue;
					}
				}
				else if (j == 0) { // only first horizontal line, can't do up
					if (Playfield[i + 1][j].HasPlayer() && Playfield[i + 1][j].HasGrass())
						continue;
					if (Playfield[i + 1][j + 1].HasPlayer() && Playfield[i + 1][j + 1].HasGrass())
						continue;
					if (Playfield[i - 1][j + 1].HasPlayer() && Playfield[i - 1][j + 1].HasGrass())
						continue;
					if (Playfield[i - 1][j].HasPlayer() && Playfield[i - 1][j].HasGrass())
						continue;
					if (Playfield[i][j + 1].HasPlayer() && Playfield[i][j + 1].HasGrass())
						continue;
				}
				else if (j == (playfieldWidth - 1)) { // only last horizontal line, can't do down
					if (Playfield[i + 1][j].HasPlayer() && Playfield[i + 1][j].HasGrass())
						continue;
					if (Playfield[i + 1][j - 1].HasPlayer() && Playfield[i + 1][j - 1].HasGrass() && Playfield[i + 1][j - 1].HasGrass())
						continue;
					if (Playfield[i - 1][j - 1].HasPlayer() && Playfield[i - 1][j - 1].HasGrass())
						continue;
					if (Playfield[i - 1][j].HasPlayer() && Playfield[i - 1][j].HasGrass())
						continue;
					if (Playfield[i][j - 1].HasPlayer() && Playfield[i][j - 1].HasGrass())
						continue;
				}
				else { // no restrictions
					if (Playfield[i + 1][j].HasPlayer() && Playfield[i + 1][j].HasGrass())
						continue;
					if (Playfield[i - 1][j].HasPlayer() && Playfield[i - 1][j].HasGrass())
						continue;
					if (Playfield[i][j + 1].HasPlayer() && Playfield[i][j + 1].HasGrass())
						continue;
					if (Playfield[i][j - 1].HasPlayer() && Playfield[i][j - 1].HasGrass())
						continue;
					if (Playfield[i + 1][j + 1].HasPlayer() && Playfield[i + 1][j + 1].HasGrass())
						continue;
					if (Playfield[i - 1][j + 1].HasPlayer() && Playfield[i - 1][j + 1].HasGrass())
						continue;
					if (Playfield[i + 1][j - 1].HasPlayer() && Playfield[i + 1][j - 1].HasGrass() && Playfield[i + 1][j - 1].HasGrass())
						continue;
					if (Playfield[i - 1][j - 1].HasPlayer() && Playfield[i - 1][j - 1].HasGrass())
						continue;
					if (Playfield[i][j].HasPlayer() && Playfield[i][j].HasGrass())
						continue;
				}
				// Close the grass
				Playfield[i][j].SetGrassNotOpened();
				}
			}
		}
	}
	
}