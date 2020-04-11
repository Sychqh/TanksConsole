#include "../Other/Functions.h"
#include "../Other/Variables.h"
#include <iostream>

// Draws everything
void Drawing() {
	int printOffsetWidth = 10, printOffsetHeight = 10; // the offset from the corner of the screen

	//---------------------------------------- DRAWING THE BORDER -----------------------
	gotoxy(printOffsetWidth, printOffsetHeight); // moves console cursor to the offset position

	// Up-left edge
	Draw((char)201, White);
	// Up
	for (int i = 0; i < playfieldWidth; i++) {
		Draw((char)205, White);
	}
	// Up-right edge
	Draw((char)187, White); 

	std::cout << std::endl;

	// Left
	for (int i = 0; i < playfieldHeight; i++) {
		gotoxy(printOffsetWidth, printOffsetHeight + i + 1);

		Draw((char)186, White);
		std::cout << std::endl;

	}

	//gotoxy(printOffsetWidth + playfieldWidth + 1, printOffsetHeight)

	// Right
	for (int i = 0; i < playfieldHeight; i++) {
		gotoxy(printOffsetWidth + playfieldWidth + 1, printOffsetHeight + i + 1); // moves console cursor to needed position

		Draw((char)186, White);
		std::cout << std::endl;
	}

	gotoxy(printOffsetWidth, printOffsetHeight + playfieldHeight + 1); // moves console cursor to needed position

	// Down-left edge
	Draw((char)200, White);
	// Down
	for (int i = 0; i < playfieldWidth; i++) {
		Draw((char)205, White);
	}
	// Down-right edge
	Draw((char)188, White);
	//------------------------------------------------------------------

	// up - 30 down - 31 right - 16 left - 17
	// пулька 249 бетое 178 кирпич 177 кусты 176 блок 219
	// arrows up 24 down 25 right 26 left 27
	// горизонталь 196 верт 179
	// слеш лево-право 47 право-лево 92

	//------------------------------DRAWING THE PLAYFIELD------------
	for (int i = 0; i < playfieldHeight; i++) {
		gotoxy(printOffsetWidth + 1, printOffsetHeight + i + 1); // moves console cursor to needed position

		for (int j = 0; j < playfieldWidth; j++) {
			// Draws brick
			if (Playfield[i][j].HasBrick()) {
				Draw((char)177, DarkRed);
			}

			// Draws concrete
			else if (Playfield[i][j].HasConcrete()) {
				Draw((char)178, Gray);
			}

			// Draws water
			else if (Playfield[i][j].HasWater()) {
				// Draws bullets that go through
				if (Playfield[i][j].HasBullet()) {
					Draw((char)249, Yellow, Blue);
				}
				// Draws just water block
				else {
					Draw(' ', Blue, Blue);
				}
			}

			// Draws lava
			else if (Playfield[i][j].HasLava()) {
				// Draws bullets that go through
				if (Playfield[i][j].HasBullet()) {
					Draw((char)249, Yellow, Red);
				}
				// Draws just lava block
				else {
					Draw((char)176, Yellow, Red);
				}
			}

			// Draws grass
			else if (Playfield[i][j].HasGrass()) {
				// Draws "opened" grass
				if (Playfield[i][j].HasGrassOpened()) {
					// Draws bullet in "opened" grass
					if (Playfield[i][j].HasBullet()) {
						Draw((char)249, Yellow, DarkGreen);
					}
					// Draws player in "opened" grass
					else if (Playfield[i][j].HasPlayer()) {
						if (Player1.SightDirection() == Up)
							Draw((char)30, Green, DarkGreen); // up triangle
						if (Player1.SightDirection() == Down)
							Draw((char)31, Green, DarkGreen); // down triangle
						if (Player1.SightDirection() == Right)
							Draw((char)16, Green, DarkGreen); // right triangle
						if (Player1.SightDirection() == Left)
							Draw((char)17, Green, DarkGreen); // left triangle
					}
					else if (Playfield[i][j].HasEnemy()) {
						switch (Playfield[i][j].EnemyNumber()) {
							// Draws 1st enemy in "opened" grass
						case 1: {
							if (Enemy1.SightDirection() == Up)
								Draw((char)30, Red, DarkGreen); // up triangle
							if (Enemy1.SightDirection() == Down)
								Draw((char)31, Red, DarkGreen); // down triangle
							if (Enemy1.SightDirection() == Right)
								Draw((char)16, Red, DarkGreen); // right triangle
							if (Enemy1.SightDirection() == Left)
								Draw((char)17, Red, DarkGreen); // left triangle
							break;
						}
								// Draws the 2nd enemy in "opened" grass
						case 2: {
							if (Enemy2.SightDirection() == Up)
								Draw((char)30, Red, DarkGreen); // up triangle
							if (Enemy2.SightDirection() == Down)
								Draw((char)31, Red, DarkGreen); // down triangle
							if (Enemy2.SightDirection() == Right)
								Draw((char)16, Red, DarkGreen); // right triangle
							if (Enemy2.SightDirection() == Left)
								Draw((char)17, Red, DarkGreen); // left triangle
							break;
						}
								// Draws the 3rd enemy in "opened" grass
						case 3: {
							if (Enemy3.SightDirection() == Up)
								Draw((char)30, Red, DarkGreen); // up triangle
							if (Enemy3.SightDirection() == Down)
								Draw((char)31, Red, DarkGreen); // down triangle
							if (Enemy3.SightDirection() == Right)
								Draw((char)16, Red, DarkGreen); // right triangle
							if (Enemy3.SightDirection() == Left)
								Draw((char)17, Red, DarkGreen); // left triangle
							break;
						}
						}
					}
					// Draws "opened" grass block
					else {
						Draw(' ', DarkGreen, DarkGreen);
					}
				}
				// Draws just grass block
				else {
					Draw((char)176, DarkGreen);
				}
			}

			// Draws ice
			else if (Playfield[i][j].HasIce()) {
				// Draws bullet on ice
				if (Playfield[i][j].HasBullet()) {
					Draw((char)249, Yellow, DarkCyan);
				}
				// Draws player on ice
				else if (Playfield[i][j].HasPlayer()) {
					if (Player1.SightDirection() == Up)
						Draw((char)30, Green, DarkCyan); // up triangle
					if (Player1.SightDirection() == Down)
						Draw((char)31, Green, DarkCyan); // down triangle
					if (Player1.SightDirection() == Right)
						Draw((char)16, Green, DarkCyan); // right triangle
					if (Player1.SightDirection() == Left)
						Draw((char)17, Green, DarkCyan); // left triangle
				}
				if (Playfield[i][j].HasEnemy()) {
					switch (Playfield[i][j].EnemyNumber()) {
					// Draws 1st enemy on ice
					case 1: {
						if (Enemy1.SightDirection() == Up)
							Draw((char)30, Red, DarkCyan); // up triangle
						if (Enemy1.SightDirection() == Down)
							Draw((char)31, Red, DarkCyan); // down triangle
						if (Enemy1.SightDirection() == Right)
							Draw((char)16, Red, DarkCyan); // right triangle
						if (Enemy1.SightDirection() == Left)
							Draw((char)17, Red, DarkCyan); // left triangle
						break;
					}
					// Draws the 2nd enemy on ice
					case 2: {
						if (Enemy2.SightDirection() == Up)
							Draw((char)30, Red, DarkCyan); // up triangle
						if (Enemy2.SightDirection() == Down)
							Draw((char)31, Red, DarkCyan); // down triangle
						if (Enemy2.SightDirection() == Right)
							Draw((char)16, Red, DarkCyan); // right triangle
						if (Enemy2.SightDirection() == Left)
							Draw((char)17, Red, DarkCyan); // left triangle
						break;
					}
					// Draws the 3rd enemy on ice
					case 3: {
						if (Enemy3.SightDirection() == Up)
							Draw((char)30, Red, DarkCyan); // up triangle
						if (Enemy3.SightDirection() == Down)
							Draw((char)31, Red, DarkCyan); // down triangle
						if (Enemy3.SightDirection() == Right)
							Draw((char)16, Red, DarkCyan); // right triangle
						if (Enemy3.SightDirection() == Left)
							Draw((char)17, Red, DarkCyan); // left triangle
						break;
					}
					}
				}
				// Draws just ice block
				else {
					Draw(' ', DarkCyan, DarkCyan);
				}
				
			}

			// Draws metal
			else if (Playfield[i][j].HasMetal()) {
				switch (Playfield[i][j].MetalType()) {
				// Block metal
				case Block: {
					Draw((char)219, LightGray);
					break;
				}
				// Slash metal
				case Slash: {
					Draw((char)47, LightGray);
					break;
				}
				// Backslash metal
				case BackSlash: {
					Draw((char)92, LightGray);
					break;
				}
				}
			}

			// Draws bullets
			else if (Playfield[i][j].HasBullet()) {
				Draw((char)249, LightGray);
			}
			
			// Draws a player
			else if (Playfield[i][j].HasPlayer()) {
				if (Player1.SightDirection() == Up)
					Draw((char)30, Green); // up triangle
				if (Player1.SightDirection() == Down)
					Draw((char)31, Green); // down triangle
				if (Player1.SightDirection() == Right)
					Draw((char)16, Green); // right triangle
				if (Player1.SightDirection() == Left)
					Draw((char)17, Green); // left triangle
			}

			// Draws enemies
			else if (Playfield[i][j].HasEnemy()) {
				switch (Playfield[i][j].EnemyNumber()) {
				// Draws the 1st enemy
				case 1: {
					if (Enemy1.SightDirection() == Up)
						Draw((char)30, Red); // up triangle
					if (Enemy1.SightDirection() == Down)
						Draw((char)31, Red); // down triangle
					if (Enemy1.SightDirection() == Right)
						Draw((char)16, Red); // right triangle
					if (Enemy1.SightDirection() == Left)
						Draw((char)17, Red); // left triangle
					break;
				}
				// Draws the 2nd enemy
				case 2: {
					if (Enemy2.SightDirection() == Up)
						Draw((char)30, Red); // up triangle
					if (Enemy2.SightDirection() == Down)
						Draw((char)31, Red); // down triangle
					if (Enemy2.SightDirection() == Right)
						Draw((char)16, Red); // right triangle
					if (Enemy2.SightDirection() == Left)
						Draw((char)17, Red); // left triangle
					break;
				}
				// Draws the 3rd enemy
				case 3: {
					if (Enemy3.SightDirection() == Up)
						Draw((char)30, Red); // up triangle
					if (Enemy3.SightDirection() == Down)
						Draw((char)31, Red); // down triangle
					if (Enemy3.SightDirection() == Right)
						Draw((char)16, Red); // right triangle
					if (Enemy3.SightDirection() == Left)
						Draw((char)17, Red); // left triangle
					break;
				}
				}
			}
			
			// Draws arrows
			else if (Playfield[i][j].HasArrow()) {
				switch (Playfield[i][j].ArrowDirection()) {
					// Draws up arrow
				case Up: {
					// If the arrow is on first horizontal line of playfield, don't check the higher one
					if (i == 0) {
						// Draw up triangle if there is another arrow block down
						if (Playfield[i + 1][j].HasArrow() && Playfield[i][j].ArrowDirection() == Up) {
							Draw((char)30, White);
						}
						// Draws just an up arrow
						else {
							Draw((char)24, White);
						}
					}
					// If the arrow is on last horizontal line of playfield, don't check the lower one
					else if (i == (playfieldHeight - 1)) {
						// Drows a vertical line if there is another arrow block up
						if (Playfield[i - 1][j].HasArrow() && Playfield[i][j].ArrowDirection() == Up) {
							Draw((char)179, White);
						}
						// Draws just an up arrow
						else {
							Draw((char)24, White);
						}
					}
					// Drows a vertical line if there is another arrow block up and down or just up
					else if (((Playfield[i + 1][j].HasArrow() && Playfield[i][j].ArrowDirection() == Up)
						&& (Playfield[i - 1][j].HasArrow() && Playfield[i][j].ArrowDirection() == Up))
						|| (Playfield[i - 1][j].HasArrow() && Playfield[i][j].ArrowDirection() == Up)) {

						Draw((char)179, White);
					}
					// Draw up triangle if there is another arrow block down
					else if (Playfield[i + 1][j].HasArrow() && Playfield[i][j].ArrowDirection() == Up) {
						Draw((char)30, White);
					}
					// Draws just an up arrow
					else {
						Draw((char)24, White);
					}

					break;
				}
						 // Draws down arrow
				case Down: {
					// If the arrow is on first horizontal line of playfield, don't check the higher one
					if (i == 0) {
						// Draw vertical line if there is another arrow block down
						if (Playfield[i + 1][j].HasArrow() && Playfield[i][j].ArrowDirection() == Down) {
							Draw((char)179, White);
						}
						// Draws just a down arrow
						else {
							Draw((char)25, White);
						}
					}
					// If the arrow is on last horizontal line of playfield, don't check the lower one
					else if (i == (playfieldHeight - 1)) {
						// Drows down triangle if there is another arrow block up
						if (Playfield[i - 1][j].HasArrow() && Playfield[i][j].ArrowDirection() == Down) {
							Draw((char)31, White);
						}
						// Draws just a down arrow
						else {
							Draw((char)25, White);
						}
					}
					// Draw vertical line if there are another arrow blocks down and up or just down
					else if (((Playfield[i + 1][j].HasArrow() && Playfield[i][j].ArrowDirection() == Down)
						&& (Playfield[i - 1][j].HasArrow() && Playfield[i][j].ArrowDirection() == Down))
						|| (Playfield[i + 1][j].HasArrow() && Playfield[i][j].ArrowDirection() == Down)) {

						Draw((char)179, White);
					}
					// Drows down triangle if there is another arrow block up
					else if (Playfield[i - 1][j].HasArrow() && Playfield[i][j].ArrowDirection() == Down) {
						Draw((char)31, White);
					}
					// Draws just a down arrow
					else {
						Draw((char)25, White);
					}
					break;
				}
						   // Draws down arrow
				case Left: {
					// If the arrow is on first horizontal line of playfield, don't check the left one
					if (j == 0) {
						// Draw left triangle if there is another arrow block right
						if (Playfield[i][j + 1].HasArrow() && Playfield[i][j].ArrowDirection() == Left) {
							Draw((char)17, White);
						}
						// Draws just a left arrow
						else {
							Draw((char)27, White);
						}
					}
					// If the arrow is on last horizontal line of playfield, don't check the right one
					else if (i == (playfieldWidth - 1)) {
						// Drows horizontal line if there is another arrow block up
						if (Playfield[i][j - 1].HasArrow() && Playfield[i][j].ArrowDirection() == Left) {
							Draw((char)196, White);
						}
						// Draws just a down arrow
						else {
							Draw((char)27, White);
						}
					}
					// Draw horizontal line if there are another arrow block left and right or just left
					else if (((Playfield[i][j + 1].HasArrow() && Playfield[i][j].ArrowDirection() == Left)
						&& (Playfield[i][j - 1].HasArrow() && Playfield[i][j].ArrowDirection() == Left))
						|| (Playfield[i][j - 1].HasArrow() && Playfield[i][j].ArrowDirection() == Left)) {
						Draw((char)196, White);
					}
					// Drows left triangle if there is another arrow block right
					else if (Playfield[i][j + 1].HasArrow() && Playfield[i][j].ArrowDirection() == Left) {
						Draw((char)17, White);
					}
					// Draws just a left arrow
					else {
						Draw((char)27, White);
					}
					break;
				}
						   // Draws right arrow
				case Right: {
					// If the arrow is on first horizontal line of playfield, don't check the left one
					if (j == 0) {
						// Draw right triangle if there is another arrow block right
						if (Playfield[i][j + 1].HasArrow() && Playfield[i][j].ArrowDirection() == Right) {
							Draw((char)196, White);
						}
						// Draws just a left arrow
						else {
							Draw((char)26, White);
						}
					}
					// If the arrow is on last horizontal line of playfield, don't check the right one
					else if (i == (playfieldWidth - 1)) {
						// Drows horizontal line if there is another arrow block up
						if (Playfield[i][j - 1].HasArrow() && Playfield[i][j].ArrowDirection() == Right) {
							Draw((char)16, White);
						}
						// Draws just a right arrow
						else {
							Draw((char)26, White);
						}
					}
					// Draw horizontal line if there are another arrow block left and right or just left
					else if (((Playfield[i][j + 1].HasArrow() && Playfield[i][j].ArrowDirection() == Right)
						&& (Playfield[i][j - 1].HasArrow() && Playfield[i][j].ArrowDirection() == Right))
						|| (Playfield[i][j + 1].HasArrow() && Playfield[i][j].ArrowDirection() == Right)) {
						Draw((char)196, White);
					}
					// Drows right triangle if there is another arrow block left
					else if (Playfield[i][j - 1].HasArrow() && Playfield[i][j].ArrowDirection() == Right) {
						Draw((char)16, White);
					}
					// Draws just a right arrow
					else {
						Draw((char)26, White);
					}
					break;
				}
				}
			}

			// Draws nothing
			else {
				Draw(' ', Black);
			}
		}

		std::cout << std::endl;
	}

	// Places cursor to the beginning to overwrite everything and so update the screen
	// and also without screen blinking unlike with system("cls")
	gotoxy(0, 0);
	//--------------------------------------------------------------------------------------------------------------------
}
	