/*
// Makes the bullet to fly
void BulletFly(Bullet& bullet) {
	while (true) {
		// Sleeps for some time to make changes visible
		std::this_thread::sleep_for(std::chrono::milliseconds(50));

		if(BulletAlreadyFliesPlayer)
		// Unsets the old position
			Playfield[bullet.posY()][bullet.posX()].SetNotBullet();

		// Moves the bullet accroding to the direction
		switch (bullet.FlyDirection()) {
		case Up: {
			if (bullet.posY() == 0) {  // if the bullet is on the edge of the playfield, stop the movement
				BulletAlreadyFliesPlayer = false;
				BulletAlreadyFliesEnemy1 = false;
				BulletAlreadyFliesEnemy2 = false;
				BulletAlreadyFliesEnemy3 = false;
				return;
			}
			else {
				// If the bullet hits a concrete or an another bullet, stop the movement
				if (Playfield[bullet.posY() - 1][bullet.posX()].HasConcrete() || Playfield[bullet.posY() - 1][bullet.posX()].HasBullet()) {
					BulletAlreadyFliesPlayer = false;
					BulletAlreadyFliesEnemy1 = false;
					BulletAlreadyFliesEnemy2 = false;
					BulletAlreadyFliesEnemy3 = false;
					return;
				}
				else {
					if (Playfield[bullet.posY() - 1][bullet.posX()].HasBrick()) {
						// Removes the block hit by the bullet
						Playfield[bullet.posY() - 1][bullet.posX()].SetNotBrick();

						// Stops the movement
						BulletAlreadyFliesPlayer = false;
						BulletAlreadyFliesEnemy1 = false;
						BulletAlreadyFliesEnemy2 = false;
						BulletAlreadyFliesEnemy3 = false;
						return;
					}
					else {
						// If there is a player or enemies, respawn them and stop movement
						if (Playfield[bullet.posY() - 1][bullet.posX()].HasPlayer()) {
							Player.Respawn();

							// Stops the movement
							BulletAlreadyFliesPlayer = false;
							BulletAlreadyFliesEnemy1 = false;
							BulletAlreadyFliesEnemy2 = false;
							BulletAlreadyFliesEnemy3 = false;
							return;
						}
						else {
							if (Playfield[bullet.posY() - 1][bullet.posX()].HasEnemy1()) {
								Enemy1.Respawn();

								// Stops the movement
								BulletAlreadyFliesPlayer = false;
								BulletAlreadyFliesEnemy1 = false;
								BulletAlreadyFliesEnemy2 = false;
								BulletAlreadyFliesEnemy3 = false;
								return;
							}
							else {
								if (Playfield[bullet.posY() - 1][bullet.posX()].HasEnemy2()) {
									Enemy2.Respawn();

									// Stops the movement
									BulletAlreadyFliesPlayer = false;
									BulletAlreadyFliesEnemy1 = false;
									BulletAlreadyFliesEnemy2 = false;
									BulletAlreadyFliesEnemy3 = false;
									return;
								}
								else {
									if (Playfield[bullet.posY() - 1][bullet.posX()].HasEnemy3()) {
										Enemy3.Respawn();

										// Stops the movement
										BulletAlreadyFliesPlayer = false;
										BulletAlreadyFliesEnemy1 = false;
										BulletAlreadyFliesEnemy2 = false;
										BulletAlreadyFliesEnemy3 = false;
										return;
									}
									else
										bullet.MoveUp(); // move up
								}
							}
						}
					}
				}
			}

			break;
		}
		case Down: {
			if (bullet.posY() == (playfieldHeight - 1)) { // if the bullet is on the edge of the playfield, stop the movement
				BulletAlreadyFliesPlayer = false;
				BulletAlreadyFliesEnemy1 = false;
				BulletAlreadyFliesEnemy2 = false;
				BulletAlreadyFliesEnemy3 = false;
				return;
			}
			else {
				// If the bullet hits a concrete or an another bullet, stop the movement
				if (Playfield[bullet.posY() + 1][bullet.posX()].HasConcrete() || Playfield[bullet.posY() + 1][bullet.posX()].HasBullet()) {
					BulletAlreadyFliesPlayer = false;
					BulletAlreadyFliesEnemy1 = false;
					BulletAlreadyFliesEnemy2 = false;
					BulletAlreadyFliesEnemy3 = false;
					return;
				}
				else {
					if (Playfield[bullet.posY() + 1][bullet.posX()].HasBrick()) {
						// Removes the block hit by the bullet
						Playfield[bullet.posY() + 1][bullet.posX()].SetNotBrick();

						// Stops the movement
						BulletAlreadyFliesPlayer = false;
						BulletAlreadyFliesEnemy1 = false;
						BulletAlreadyFliesEnemy2 = false;
						BulletAlreadyFliesEnemy3 = false;
						return;
					} //|| Playfield[m_posY - 1][posX() - 1].HasEnemy()) {} // if there is a block or an enemy, do nothing
					else {
						// If there is a player or enemies, respawn them and stop movement
						if (Playfield[bullet.posY() + 1][bullet.posX()].HasPlayer()) {
							Player.Respawn();

							// Stops the movement
							BulletAlreadyFliesPlayer = false;
							BulletAlreadyFliesEnemy1 = false;
							BulletAlreadyFliesEnemy2 = false;
							BulletAlreadyFliesEnemy3 = false;
							return;
						}
						else {
							if (Playfield[bullet.posY() + 1][bullet.posX()].HasEnemy1()) {
								Enemy1.Respawn();

								// Stops the movement
								BulletAlreadyFliesPlayer = false;
								BulletAlreadyFliesEnemy1 = false;
								BulletAlreadyFliesEnemy2 = false;
								BulletAlreadyFliesEnemy3 = false;
								return;
							}
							else {
								if (Playfield[bullet.posY() + 1][bullet.posX()].HasEnemy2()) {
									Enemy2.Respawn();

									// Stops the movement
									BulletAlreadyFliesPlayer = false;
									BulletAlreadyFliesEnemy1 = false;
									BulletAlreadyFliesEnemy2 = false;
									BulletAlreadyFliesEnemy3 = false;
									return;
								}
								else {
									if (Playfield[bullet.posY() + 1][bullet.posX()].HasEnemy3()) {
										Enemy3.Respawn();

										// Stops the movement
										BulletAlreadyFliesPlayer = false;
										BulletAlreadyFliesEnemy1 = false;
										BulletAlreadyFliesEnemy2 = false;
										BulletAlreadyFliesEnemy3 = false;
										return;
									}
									else
										bullet.MoveDown(); // move down
								}
							}
						}
					}
				}
			}

			break;
		}
		case Left: {
			if (bullet.posX() == 0) { // if the bullet is on the edge of the playfield, stop the movement
				BulletAlreadyFliesPlayer = false;
				BulletAlreadyFliesEnemy1 = false;
				BulletAlreadyFliesEnemy2 = false;
				BulletAlreadyFliesEnemy3 = false;
				return;
			}
			else {
				// If the bullet hits a concrete or an another bullet, stop the movement
				if (Playfield[bullet.posY()][bullet.posX() - 1].HasConcrete() || Playfield[bullet.posY()][bullet.posX() - 1].HasBullet()) {
					BulletAlreadyFliesPlayer = false;
					BulletAlreadyFliesEnemy1 = false;
					BulletAlreadyFliesEnemy2 = false;
					BulletAlreadyFliesEnemy3 = false;
					return;
				}
				else {
					if (Playfield[bullet.posY()][bullet.posX() - 1].HasBrick()) {
						// Removes the block hit by the bullet
						Playfield[bullet.posY()][bullet.posX() - 1].SetNotBrick();

						// Stops the movement
						BulletAlreadyFliesPlayer = false;
						BulletAlreadyFliesEnemy1 = false;
						BulletAlreadyFliesEnemy2 = false;
						BulletAlreadyFliesEnemy3 = false;
						return;
					} //|| Playfield[m_posY - 1][posX() - 1].HasEnemy()) {} // if there is a block or an enemy, do nothing
					else {
						// If there is a player or enemies, respawn them and stop movement
						if (Playfield[bullet.posY()][bullet.posX() - 1].HasPlayer()) {
							Player.Respawn();

							// Stops the movement
							BulletAlreadyFliesPlayer = false;
							BulletAlreadyFliesEnemy1 = false;
							BulletAlreadyFliesEnemy2 = false;
							BulletAlreadyFliesEnemy3 = false;
							return;
						}
						else {
							if (Playfield[bullet.posY()][bullet.posX() - 1].HasEnemy1()) {
								Enemy1.Respawn();

								// Stops the movement
								BulletAlreadyFliesPlayer = false;
								BulletAlreadyFliesEnemy1 = false;
								BulletAlreadyFliesEnemy2 = false;
								BulletAlreadyFliesEnemy3 = false;
								return;
							}
							else {
								if (Playfield[bullet.posY()][bullet.posX() - 1].HasEnemy2()) {
									Enemy2.Respawn();

									// Stops the movement
									BulletAlreadyFliesPlayer = false;
									BulletAlreadyFliesEnemy1 = false;
									BulletAlreadyFliesEnemy2 = false;
									BulletAlreadyFliesEnemy3 = false;
									return;
								}
								else {
									if (Playfield[bullet.posY()][bullet.posX() - 1].HasEnemy3()) {
										Enemy3.Respawn();

										// Stops the movement
										BulletAlreadyFliesPlayer = false;
										BulletAlreadyFliesEnemy1 = false;
										BulletAlreadyFliesEnemy2 = false;
										BulletAlreadyFliesEnemy3 = false;
										return;
									}
									else
										bullet.MoveLeft(); // move left
								}
							}
						}
					}
				}
			}

			break;
		}
		case Right: {
			if (bullet.posX() == (playfieldWidth - 1)) { // if the bullet is on the edge of the playfield, stop the movement
				BulletAlreadyFliesPlayer = false;
				BulletAlreadyFliesEnemy1 = false;
				BulletAlreadyFliesEnemy2 = false;
				BulletAlreadyFliesEnemy3 = false;
				return;
			}
			else {
				// If the bullet hits a concrete or an another bullet, stop the movement
				if (Playfield[bullet.posY()][bullet.posX() + 1].HasConcrete() || Playfield[bullet.posY()][bullet.posX() + 1].HasBullet()) {
					BulletAlreadyFliesPlayer = false;
					BulletAlreadyFliesEnemy1 = false;
					BulletAlreadyFliesEnemy2 = false;
					BulletAlreadyFliesEnemy3 = false;
					return;
				}
				else {
					if (Playfield[bullet.posY()][bullet.posX() + 1].HasBrick()) {
						// Removes the block hit by the bullet
						Playfield[bullet.posY()][bullet.posX() + 1].SetNotBrick();

						// Stops the movement
						BulletAlreadyFliesPlayer = false;
						BulletAlreadyFliesEnemy1 = false;
						BulletAlreadyFliesEnemy2 = false;
						BulletAlreadyFliesEnemy3 = false;
						return;
					} //|| Playfield[m_posY - 1][posX() - 1].HasEnemy()) {} // if there is a block or an enemy, do nothing
					else {
						// If there is a player or enemies, respawn them and stop movement
						if (Playfield[bullet.posY()][bullet.posX() + 1].HasPlayer()) {
							Player.Respawn();

							// Stops the movement
							BulletAlreadyFliesPlayer = false;
							BulletAlreadyFliesEnemy1 = false;
							BulletAlreadyFliesEnemy2 = false;
							BulletAlreadyFliesEnemy3 = false;
							return;
						}
						else {
							if (Playfield[bullet.posY()][bullet.posX() + 1].HasEnemy1()) {
								Enemy1.Respawn();

								// Stops the movement
								BulletAlreadyFliesPlayer = false;
								BulletAlreadyFliesEnemy1 = false;
								BulletAlreadyFliesEnemy2 = false;
								BulletAlreadyFliesEnemy3 = false;
								return;
							}
							else {
								if (Playfield[bullet.posY()][bullet.posX() + 1].HasEnemy2()) {
									Enemy2.Respawn();

									// Stops the movement
									BulletAlreadyFliesPlayer = false;
									BulletAlreadyFliesEnemy1 = false;
									BulletAlreadyFliesEnemy2 = false;
									BulletAlreadyFliesEnemy3 = false;
									return;
								}
								else {
									if (Playfield[bullet.posY()][bullet.posX() + 1].HasEnemy3()) {
										Enemy3.Respawn();

										// Stops the movement
										BulletAlreadyFliesPlayer = false;
										BulletAlreadyFliesEnemy1 = false;
										BulletAlreadyFliesEnemy2 = false;
										BulletAlreadyFliesEnemy3 = false;
										return;
									}
									else
										bullet.MoveRight(); // move right
								}
							}
						}
					}
				}
			}

			break;
		}
		}

		// Sets the new position
		Playfield[bullet.posY()][bullet.posX()].SetBullet();
	}
}
*/

/*
		// Moves the bullet accroding to the direction
		switch (m_FlyDirection) {
		case Up: {
			if (m_posY == 0) {
				switch (m_WhoShot) {
				case isPlayer: {
					BulletAlreadyFliesPlayer = false;
				}
				case isEnemy1: {
					BulletAlreadyFliesEnemy1 = false;
				}
				case isEnemy2: {
					BulletAlreadyFliesEnemy2 = false;
				}
				case isEnemy3: {
					BulletAlreadyFliesEnemy3 = false;
				}
				}
				return;
			}
			else {
				// If the bullet hits a concrete or an aher bullet, stop the movement
				if (Playfield[m_posY - 1][m_posX].HasConcrete() || Playfield[m_posY - 1][m_posX].HasBullet() || Playfield[m_posY - 1][m_posX].HasLava()) {
					switch (m_WhoShot) {
					case isPlayer: {
						BulletAlreadyFliesPlayer = false;
					}
					case isEnemy1: {
						BulletAlreadyFliesEnemy1 = false;
					}
					case isEnemy2: {
						BulletAlreadyFliesEnemy2 = false;
					}
					case isEnemy3: {
						BulletAlreadyFliesEnemy3 = false;
					}
					}
					return;
				}
				else {
					if (Playfield[m_posY - 1][m_posX].HasBrick()) {
						// Removes the block hit by the bullet
						Playfield[m_posY - 1][m_posX].SetNotBrick();

						// Stops the movement
						switch (m_WhoShot) {
						case isPlayer: {
							BulletAlreadyFliesPlayer = false;
						}
						case isEnemy1: {
							BulletAlreadyFliesEnemy1 = false;
						}
						case isEnemy2: {
							BulletAlreadyFliesEnemy2 = false;
						}
						case isEnemy3: {
							BulletAlreadyFliesEnemy3 = false;
						}
						}
						return;
					}
					else {
						// If there is a player or enemies, respawn them and stop movement
						if (Playfield[m_posY - 1][m_posX].HasPlayer()) {
							// Stops the movement and respawns the player if it was any of enemies shooting
							switch (m_WhoShot) {
							case isPlayer: {
								BulletAlreadyFliesPlayer = false;
							}
							case isEnemy1: {
								Player.Respawn();
								BulletAlreadyFliesEnemy1 = false;
							}
							case isEnemy2: {
								Player.Respawn();
								BulletAlreadyFliesEnemy2 = false;
							}
							case isEnemy3: {
								Player.Respawn();
								BulletAlreadyFliesEnemy3 = false;
							}
							}

							return;
						}
						else {
							if (Playfield[m_posY - 1][m_posX].HasEnemy1()) {
								// Stops the movement and respawns the 1st enemy if it was player shooting
								switch (m_WhoShot) {
								case isPlayer: {
									Enemy1.Respawn();
									BulletAlreadyFliesPlayer = false;
								}
								case isEnemy1: {
									BulletAlreadyFliesEnemy1 = false;
								}
								case isEnemy2: {
									BulletAlreadyFliesEnemy2 = false;
								}
								case isEnemy3: {
									BulletAlreadyFliesEnemy3 = false;
								}
								}

								return;
							}
							else {
								if (Playfield[m_posY - 1][m_posX].HasEnemy2()) {
									// Stops the movement and respawns the 2nd enemy if it was player shooting
									switch (m_WhoShot) {
									case isPlayer: {
										Enemy2.Respawn();
										BulletAlreadyFliesPlayer = false;
									}
									case isEnemy1: {
										BulletAlreadyFliesEnemy1 = false;
									}
									case isEnemy2: {
										BulletAlreadyFliesEnemy2 = false;
									}
									case isEnemy3: {
										BulletAlreadyFliesEnemy3 = false;
									}
									}

									return;
								}
								else {
									if (Playfield[m_posY - 1][m_posX].HasEnemy3()) {
										// Stops the movement and respawns the 3rd enemy if it was player shooting
										switch (m_WhoShot) {
										case isPlayer: {
											Enemy3.Respawn();
											BulletAlreadyFliesPlayer = false;
										}
										case isEnemy1: {
											BulletAlreadyFliesEnemy1 = false;
										}
										case isEnemy2: {
											BulletAlreadyFliesEnemy2 = false;
										}
										case isEnemy3: {
											BulletAlreadyFliesEnemy3 = false;
										}
										}

										return;
									}
									else
										MoveUp(); // move up
								}
							}
						}
					}
				}
			}

			break;
		}
		case Down: {
			if (m_posY == (playfieldHeight - 1)) { // if the bullet is on the edge of the playfield, stop the movement
				switch (m_WhoShot) {
				case isPlayer: {
					BulletAlreadyFliesPlayer = false;
				}
				case isEnemy1: {
					BulletAlreadyFliesEnemy1 = false;
				}
				case isEnemy2: {
					BulletAlreadyFliesEnemy2 = false;
				}
				case isEnemy3: {
					BulletAlreadyFliesEnemy3 = false;
				}
				}
				return;
			}
			else {
				// If the bullet hits a concrete or an aher bullet, stop the movement
				if (Playfield[m_posY + 1][m_posX].HasConcrete() || Playfield[m_posY + 1][m_posX].HasBullet() || Playfield[m_posY + 1][m_posX].HasLava()) {
					switch (m_WhoShot) {
					case isPlayer: {
						BulletAlreadyFliesPlayer = false;
					}
					case isEnemy1: {
						BulletAlreadyFliesEnemy1 = false;
					}
					case isEnemy2: {
						BulletAlreadyFliesEnemy2 = false;
					}
					case isEnemy3: {
						BulletAlreadyFliesEnemy3 = false;
					}
					}
					return;
				}
				else {
					if (Playfield[m_posY + 1][m_posX].HasBrick()) {
						// Removes the block hit by the bullet
						Playfield[m_posY + 1][m_posX].SetNotBrick();

						// Stops the movement
						switch (m_WhoShot) {
						case isPlayer: {
							BulletAlreadyFliesPlayer = false;
						}
						case isEnemy1: {
							BulletAlreadyFliesEnemy1 = false;
						}
						case isEnemy2: {
							BulletAlreadyFliesEnemy2 = false;
						}
						case isEnemy3: {
							BulletAlreadyFliesEnemy3 = false;
						}
						}
						return;
					}
					else {
						// If there is a player or enemies, respawn them and stop movement
						if (Playfield[m_posY + 1][m_posX].HasPlayer()) {
							// Stops the movement and respawns the player if it was any of enemies shooting
							switch (m_WhoShot) {
							case isPlayer: {
								BulletAlreadyFliesPlayer = false;
							}
							case isEnemy1: {
								Player.Respawn();
								BulletAlreadyFliesEnemy1 = false;
							}
							case isEnemy2: {
								Player.Respawn();
								BulletAlreadyFliesEnemy2 = false;
							}
							case isEnemy3: {
								Player.Respawn();
								BulletAlreadyFliesEnemy3 = false;
							}
							}

							return;
						}
						else {
							if (Playfield[m_posY + 1][m_posX].HasEnemy1()) {
								// Stops the movement and respawns the 1st enemy if it was player shooting
								switch (m_WhoShot) {
								case isPlayer: {
									Enemy1.Respawn();
									BulletAlreadyFliesPlayer = false;
								}
								case isEnemy1: {
									BulletAlreadyFliesEnemy1 = false;
								}
								case isEnemy2: {
									BulletAlreadyFliesEnemy2 = false;
								}
								case isEnemy3: {
									BulletAlreadyFliesEnemy3 = false;
								}
								}

								return;
							}
							else {
								if (Playfield[m_posY + 1][m_posX].HasEnemy2()) {
									// Stops the movement and respawns the 2nd enemy if it was player shooting
									switch (m_WhoShot) {
									case isPlayer: {
										Enemy2.Respawn();
										BulletAlreadyFliesPlayer = false;
									}
									case isEnemy1: {
										BulletAlreadyFliesEnemy1 = false;
									}
									case isEnemy2: {
										BulletAlreadyFliesEnemy2 = false;
									}
									case isEnemy3: {
										BulletAlreadyFliesEnemy3 = false;
									}
									}

									return;
								}
								else {
									if (Playfield[m_posY + 1][m_posX].HasEnemy3()) {
										// Stops the movement and kills the 3rd enemy if it was player shooting
										switch (m_WhoShot) {
										case isPlayer: {
											Enemy3.Respawn();
											BulletAlreadyFliesPlayer = false;
										}
										case isEnemy1: {
											BulletAlreadyFliesEnemy1 = false;
										}
										case isEnemy2: {
											BulletAlreadyFliesEnemy2 = false;
										}
										case isEnemy3: {
											BulletAlreadyFliesEnemy3 = false;
										}
										}
										return;
									}
									else
										MoveDown(); // move down
								}
							}
						}
					}
				}
			}

			break;
		}
		case Left: {
			if (m_posX == 0) { // if the bullet is on the edge of the playfield, stop the movement
				switch (m_WhoShot) {
				case isPlayer: {
					BulletAlreadyFliesPlayer = false;
				}
				case isEnemy1: {
					BulletAlreadyFliesEnemy1 = false;
				}
				case isEnemy2: {
					BulletAlreadyFliesEnemy2 = false;
				}
				case isEnemy3: {
					BulletAlreadyFliesEnemy3 = false;
				}
				}
				return;
			}
			else {
				// If the bullet hits a concrete or an aher bullet, stop the movement
				if (Playfield[m_posY][m_posX - 1].HasConcrete() || Playfield[m_posY][m_posX - 1].HasBullet() || Playfield[m_posY][m_posX - 1].HasLava()) {
					switch (m_WhoShot) {
					case isPlayer: {
						BulletAlreadyFliesPlayer = false;
					}
					case isEnemy1: {
						BulletAlreadyFliesEnemy1 = false;
					}
					case isEnemy2: {
						BulletAlreadyFliesEnemy2 = false;
					}
					case isEnemy3: {
						BulletAlreadyFliesEnemy3 = false;
					}
					}
					return;
				}
				else {
					if (Playfield[m_posY][m_posX - 1].HasBrick()) {
						// Removes the block hit by the bullet
						Playfield[m_posY][m_posX - 1].SetNotBrick();

						// Stops the movement
						switch (m_WhoShot) {
						case isPlayer: {
							BulletAlreadyFliesPlayer = false;
						}
						case isEnemy1: {
							BulletAlreadyFliesEnemy1 = false;
						}
						case isEnemy2: {
							BulletAlreadyFliesEnemy2 = false;
						}
						case isEnemy3: {
							BulletAlreadyFliesEnemy3 = false;
						}
						}
						return;
					}
					else {
						// If there is a player or enemies, respawn them and stop movement
						if (Playfield[m_posY][m_posX - 1].HasPlayer()) {
							// Stops the movement and respawns the player if it was any of enemies shooting
							switch (m_WhoShot) {
							case isPlayer: {
								BulletAlreadyFliesPlayer = false;
							}
							case isEnemy1: {
								Player.Respawn();
								BulletAlreadyFliesEnemy1 = false;
							}
							case isEnemy2: {
								Player.Respawn();
								BulletAlreadyFliesEnemy2 = false;
							}
							case isEnemy3: {
								Player.Respawn();
								BulletAlreadyFliesEnemy3 = false;
							}
							}

							return;
						}
						else {
							if (Playfield[m_posY][m_posX - 1].HasEnemy1()) {
								// Stops the movement and respawns the 1st enemy if it was player shooting
								switch (m_WhoShot) {
								case isPlayer: {
									Enemy1.Respawn();
									BulletAlreadyFliesPlayer = false;
								}
								case isEnemy1: {
									BulletAlreadyFliesEnemy1 = false;
								}
								case isEnemy2: {
									BulletAlreadyFliesEnemy2 = false;
								}
								case isEnemy3: {
									BulletAlreadyFliesEnemy3 = false;
								}
								}

								return;
							}
							else {
								if (Playfield[m_posY][m_posX - 1].HasEnemy2()) {
									// Stops the movement and respawns the 2nd enemy if it was player shooting
									switch (m_WhoShot) {
									case isPlayer: {
										Enemy2.Respawn();
										BulletAlreadyFliesPlayer = false;
									}
									case isEnemy1: {
										BulletAlreadyFliesEnemy1 = false;
									}
									case isEnemy2: {
										BulletAlreadyFliesEnemy2 = false;
									}
									case isEnemy3: {
										BulletAlreadyFliesEnemy3 = false;
									}
									}

									return;
								}
								else {
									if (Playfield[m_posY][m_posX - 1].HasEnemy3()) {
										// Stops the movement and respawns the 3rd enemy if it was player shooting
										switch (m_WhoShot) {
										case isPlayer: {
											Enemy3.Respawn();
											BulletAlreadyFliesPlayer = false;
										}
										case isEnemy1: {
											BulletAlreadyFliesEnemy1 = false;
										}
										case isEnemy2: {
											BulletAlreadyFliesEnemy2 = false;
										}
										case isEnemy3: {
											BulletAlreadyFliesEnemy3 = false;
										}
										}
										return;
									}
									else
										MoveLeft(); // move left
								}
							}
						}
					}
				}
			}

			break;
		}
		case Right: {
			if (m_posX == (playfieldWidth - 1)) { // if the bullet is on the edge of the playfield, stop the movement
				switch (m_WhoShot) {
				case isPlayer: {
					BulletAlreadyFliesPlayer = false;
				}
				case isEnemy1: {
					BulletAlreadyFliesEnemy1 = false;
				}
				case isEnemy2: {
					BulletAlreadyFliesEnemy2 = false;
				}
				case isEnemy3: {
					BulletAlreadyFliesEnemy3 = false;
				}
				}
				return;
			}
			else {
				// If the bullet hits a concrete or an aher bullet, stop the movement
				if (Playfield[m_posY][m_posX + 1].HasConcrete() || Playfield[m_posY][m_posX + 1].HasBullet() || Playfield[m_posY][m_posX + 1].HasLava()) {
					switch (m_WhoShot) {
					case isPlayer: {
						BulletAlreadyFliesPlayer = false;
					}
					case isEnemy1: {
						BulletAlreadyFliesEnemy1 = false;
					}
					case isEnemy2: {
						BulletAlreadyFliesEnemy2 = false;
					}
					case isEnemy3: {
						BulletAlreadyFliesEnemy3 = false;
					}
					}
					return;
				}
				else {
					if (Playfield[m_posY][m_posX + 1].HasBrick()) {
						// Removes the block hit by the bullet
						Playfield[m_posY][m_posX + 1].SetNotBrick();

						// Stops the movement
						switch (m_WhoShot) {
						case isPlayer: {
							BulletAlreadyFliesPlayer = false;
						}
						case isEnemy1: {
							BulletAlreadyFliesEnemy1 = false;
						}
						case isEnemy2: {
							BulletAlreadyFliesEnemy2 = false;
						}
						case isEnemy3: {
							BulletAlreadyFliesEnemy3 = false;
						}
						}
						return;
					}
					else {
						// If there is a player or enemies, respawn them and stop movement
						if (Playfield[m_posY][m_posX + 1].HasPlayer()) {
							// Stops the movement and respawns the player if it was any of enemies shooting
							switch (m_WhoShot) {
							case isPlayer: {
								BulletAlreadyFliesPlayer = false;
							}
							case isEnemy1: {
								Player.Respawn();
								BulletAlreadyFliesEnemy1 = false;
							}
							case isEnemy2: {
								Player.Respawn();
								BulletAlreadyFliesEnemy2 = false;
							}
							case isEnemy3: {
								Player.Respawn();
								BulletAlreadyFliesEnemy3 = false;
							}
							}

							return;
						}
						else {
							if (Playfield[m_posY][m_posX + 1].HasEnemy1()) {
								// Stops the movement and respawns the 1st enemy if it was player shooting
								switch (m_WhoShot) {
								case isPlayer: {
									Enemy1.Respawn();
									BulletAlreadyFliesPlayer = false;
								}
								case isEnemy1: {
									BulletAlreadyFliesEnemy1 = false;
								}
								case isEnemy2: {
									BulletAlreadyFliesEnemy2 = false;
								}
								case isEnemy3: {
									BulletAlreadyFliesEnemy3 = false;
								}
								}

								return;
							}
							else {
								if (Playfield[m_posY][m_posX + 1].HasEnemy2()) {
									// Stops the movement and respawns the 2nd enemy if it was player shooting
									switch (m_WhoShot) {
									case isPlayer: {
										Enemy2.Respawn();
										BulletAlreadyFliesPlayer = false;
									}
									case isEnemy1: {
										BulletAlreadyFliesEnemy1 = false;
									}
									case isEnemy2: {
										BulletAlreadyFliesEnemy2 = false;
									}
									case isEnemy3: {
										BulletAlreadyFliesEnemy3 = false;
									}
									}

									return;
								}
								else {
									if (Playfield[m_posY][m_posX + 1].HasEnemy3()) {
										// Stops the movement and respawns the 3rd enemy if it was player shooting
										switch (m_WhoShot) {
										case isPlayer: {
											Enemy3.Respawn();
											BulletAlreadyFliesPlayer = false;
										}
										case isEnemy1: {
											BulletAlreadyFliesEnemy1 = false;
										}
										case isEnemy2: {
											BulletAlreadyFliesEnemy2 = false;
										}
										case isEnemy3: {
											BulletAlreadyFliesEnemy3 = false;
										}
										}

										return;
									}
									else
										MoveRight(); // move right
								}
							}
						}
					}
				}
			}

			break;
		}
		}
		*/

		/*
				// Metal machanics
				for (int i = 0; i < playfieldHeight; i++) {
					for (int j = 0; j < playfieldWidth; j++) {
						if (Playfield[i][j].HasMetal()) {
							switch (Playfield[i][j].MetalType()) {
							// Regular block
							case Block: {
								if (Playfield[i][j].HasBulletPlayer()) {
									switch (bulletPlayer.FlyDirection()) {
									case Up: {
										bulletPlayer.SetFlyDirection(Down);
										break;
									}
									case Down: {
										bulletPlayer.SetFlyDirection(Up);
										break;
									}
									case Left: {
										bulletPlayer.SetFlyDirection(Right);
										break;
									}
									case Right: {
										bulletPlayer.SetFlyDirection(Down);
										break;
									}
									}
								}

								if (Playfield[i][j].HasBulletEnemy1()) {
									switch (bulletEnemy1.FlyDirection()) {
									case Up: {
										bulletEnemy1.SetFlyDirection(Down);
										break;
									}
									case Down: {
										bulletEnemy1.SetFlyDirection(Up);
										break;
									}
									case Left: {
										bulletEnemy1.SetFlyDirection(Right);
										break;
									}
									case Right: {
										bulletEnemy1.SetFlyDirection(Down);
										break;
									}
									}
								}

								if (Playfield[i][j].HasBulletEnemy2()) {
									switch (bulletEnemy2.FlyDirection()) {
									case Up: {
										bulletEnemy2.SetFlyDirection(Down);
										break;
									}
									case Down: {
										bulletEnemy2.SetFlyDirection(Up);
										break;
									}
									case Left: {
										bulletEnemy2.SetFlyDirection(Right);
										break;
									}
									case Right: {
										bulletEnemy2.SetFlyDirection(Down);
										break;
									}
									}
								}

								if (Playfield[i][j].HasBulletEnemy3()) {
									switch (bulletEnemy3.FlyDirection()) {
									case Up: {
										bulletEnemy3.SetFlyDirection(Down);
										break;
									}
									case Down: {
										bulletEnemy3.SetFlyDirection(Up);
										break;
									}
									case Left: {
										bulletEnemy3.SetFlyDirection(Right);
										break;
									}
									case Right: {
										bulletEnemy3.SetFlyDirection(Down);
										break;
									}
									}
								}
								break;
							}
							// Slash (/)
							case Slash: {
								if (Playfield[i][j].HasBulletPlayer()) {
									switch (bulletPlayer.FlyDirection()) {
									case Up: {
										bulletPlayer.SetFlyDirection(Right);
										break;
									}
									case Down: {
										bulletPlayer.SetFlyDirection(Left);
										break;
									}
									case Left: {
										bulletPlayer.SetFlyDirection(Down);
										break;
									}
									case Right: {
										bulletPlayer.SetFlyDirection(Up);
										break;
									}
									}
								}

								if (Playfield[i][j].HasBulletEnemy1()) {
									switch (bulletEnemy1.FlyDirection()) {
									case Up: {
										bulletEnemy1.SetFlyDirection(Right);
										break;
									}
									case Down: {
										bulletEnemy1.SetFlyDirection(Left);
										break;
									}
									case Left: {
										bulletEnemy1.SetFlyDirection(Down);
										break;
									}
									case Right: {
										bulletEnemy1.SetFlyDirection(Up);
										break;
									}
									}
								}

								if (Playfield[i][j].HasBulletEnemy2()) {
									switch (bulletEnemy2.FlyDirection()) {
									case Up: {
										bulletEnemy2.SetFlyDirection(Right);
										break;
									}
									case Down: {
										bulletEnemy2.SetFlyDirection(Left);
										break;
									}
									case Left: {
										bulletEnemy2.SetFlyDirection(Down);
										break;
									}
									case Right: {
										bulletEnemy2.SetFlyDirection(Up);
										break;
									}
									}
								}

								if (Playfield[i][j].HasBulletEnemy3()) {
									switch (bulletEnemy3.FlyDirection()) {
									case Up: {
										bulletEnemy3.SetFlyDirection(Right);
										break;
									}
									case Down: {
										bulletEnemy3.SetFlyDirection(Left);
										break;
									}
									case Left: {
										bulletEnemy3.SetFlyDirection(Down);
										break;
									}
									case Right: {
										bulletEnemy3.SetFlyDirection(Up);
										break;
									}
									}
								}

								break;
							}
							// Backslash (\)
							case BackSlash: {
								if (Playfield[i][j].HasBulletPlayer()) {
									switch (bulletPlayer.FlyDirection()) {
									case Up: {
										bulletPlayer.SetFlyDirection(Left);
										break;
									}
									case Down: {
										bulletPlayer.SetFlyDirection(Right);
										break;
									}
									case Left: {
										bulletPlayer.SetFlyDirection(Up);
										break;
									}
									case Right: {
										bulletPlayer.SetFlyDirection(Down);
										break;
									}
									}
								}

								break;
							}
							}

						}
					}
				}*/
/*
void BotMovementS(Enemy& enemy) {
	srand((unsigned)time(0)); // automatically randomizes rand() values
	while (!GameOver) {
		int shootChance;
		int stepsAmount;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));

		stepsAmount = rand() % 10;

		switch (enemy.Number()) {
		case 1: {
			enemy.SetSightDirection(rand() % 4);
			break;
		}
		case 2: {
			enemy.SetSightDirection(rand() % 4);
			enemy.SetSightDirection(rand() % 4);
			break;
		}
		case 3: {
			enemy.SetSightDirection(rand() % 4);
			enemy.SetSightDirection(rand() % 4);
			enemy.SetSightDirection(rand() % 4);
			break;
		}
		}

		for (int i = 0; i < stepsAmount; i++) {
			std::this_thread::sleep_for(std::chrono::milliseconds(700));

			if (!enemy.CanMove(enemy.SightDirection()))
				enemy.SetSightDirection(rand() % 4);

			enemy.Move(enemy.SightDirection());

			shootChance = rand() % 10;
			if (shootChance < 3)
				enemy.Shoot();
		}


		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
}
/*
switch (enemy.Number()) {
case 1: {
	int shootChance;
	int stepsAmount;
	std::this_thread::sleep_for(std::chrono::milliseconds(500));

	stepsAmount = rand() % 10;

	enemy.SetSightDirection(rand() % 4);

	for (int i = 0; i < stepsAmount; i++) {
		std::this_thread::sleep_for(std::chrono::milliseconds(700));

		if (!enemy.CanMove(enemy.SightDirection()))
			enemy.SetSightDirection(rand() % 4);

		enemy.Move(enemy.SightDirection());

		shootChance = rand() % 10;
		if (shootChance < 3)
			enemy.Shoot();
	}


	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	break;
}
case 2: {
	int shootChance;
	int stepsAmount;
	std::this_thread::sleep_for(std::chrono::milliseconds(500));

	stepsAmount = rand() % 10;

	enemy.SetSightDirection(rand() % 4);
	enemy.SetSightDirection(rand() % 4);

	for (int i = 0; i < stepsAmount; i++) {
		std::this_thread::sleep_for(std::chrono::milliseconds(700));

		if (!enemy.CanMove(enemy.SightDirection()))
			enemy.SetSightDirection(rand() % 4);

		enemy.Move(enemy.SightDirection());

		shootChance = rand() % 10;
		if (shootChance < 3)
			enemy.Shoot();
	}


	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	break;
}
case 3: {
	int shootChance;
	int stepsAmount;
	std::this_thread::sleep_for(std::chrono::milliseconds(500));

	stepsAmount = rand() % 10;

	enemy.SetSightDirection(rand() % 4);
	enemy.SetSightDirection(rand() % 4);
	enemy.SetSightDirection(rand() % 4);

	for (int i = 0; i < stepsAmount; i++) {
		std::this_thread::sleep_for(std::chrono::milliseconds(700));

		if (!enemy.CanMove(enemy.SightDirection()))
			enemy.SetSightDirection(rand() % 4);

		enemy.Move(enemy.SightDirection());

		shootChance = rand() % 10;
		if (shootChance < 3)
			enemy.Shoot();
	}


	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	break;

}
}*/


/*
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));

		enemy.SetSightDirection(rand() % 4);

		for (int i = 0; i < 5; i++) {
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			enemy.Move(enemy.SightDirection());
			//std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(500));

		enemy.Shoot();

		std::this_thread::sleep_for(std::chrono::milliseconds(1000));

		enemy.SetSightDirection(rand() % 4);


		for (int i = 0; i < 5; i++) {
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			enemy.Move(enemy.SightDirection());
			//std::this_thread::sleep_for(std::chrono::milliseconds(1000));

		}
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	} */
	/*
	//int Direction = rand() % 4;
	enemy.SetSightDirection(rand() % 4);
	for (int i = 0; i < 5; i++) {
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		enemy.Move(enemy.SightDirection());
	}

	std::this_thread::sleep_for(std::chrono::milliseconds(500));

	enemy.Shoot();

	//Direction = rand() % 4;

	for (int i = 0; i < 5; i++) {
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		enemy.Move(enemy.SightDirection());

	}
	*/

	/*
	while (true) {
		int Direction = rand() % 4;
		switch (enemy.Number()) {
		case 1: {
			Direction = rand() % 4;
			break;
		}
		case 2: {
			Direction = rand() % 4;
			break;
		}
		case 3: {
			Direction = rand() % 4;
			break;
		}
		}


		for (int i = 0; i < 5; i++) {
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			enemy.Move(Direction);

			//enemy.Shoot();
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(500));

		enemy.Shoot();

		Direction = rand() % 4;

		for (int i = 0; i < 5; i++) {
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			enemy.Move(Direction);

		}
		enemy.Respawn();

		for (int i = 0; i < 5; i++) {
			std::this_thread::sleep_for(std::chrono::milliseconds(10000));
			enemy.Move(Right);
			enemy.Shoot();
		}

		for (int i = 0; i < 5; i++) {
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			MoveDown();

		}
		*/
		//break;


//}
/*
	// Draws up arrow
			else if (Playfield[i][j].HasArrowUp()) {
				// Draws a bullet on an up arrow
				if (Playfield[i][j].HasBullet()) {
					Draw((char)249, White);
				}
				// Draws a player on an up arrow
				else if (Playfield[i][j].HasPlayer()) {
					if (Player.SightDirection() == Up)
						Draw((char)30, Green, Brown); // up triangle
					if (Player.SightDirection() == Down)
						Draw((char)31, Green, Brown); // down triangle
					if (Player.SightDirection() == Right)
						Draw((char)16, Green, Brown); // right triangle
					if (Player.SightDirection() == Left)
						Draw((char)17, Green, Brown); // left triangle
				}
				// Draws the 1st enemy on an up arrow
				else if (Playfield[i][j].HasEnemy1()) {
					if (Enemy1.SightDirection() == Up)
						Draw((char)30, Red, Brown); // up triangle
					if (Enemy1.SightDirection() == Down)
						Draw((char)31, Red, Brown); // down triangle
					if (Enemy1.SightDirection() == Right)
						Draw((char)16, Red, Brown); // right triangle
					if (Enemy1.SightDirection() == Left)
						Draw((char)17, Red, Brown); // left triangle
				}
				// Draws the 2nd enemy on an up arrow
				else if (Playfield[i][j].HasEnemy2()) {
					if (Enemy2.SightDirection() == Up)
						Draw((char)30, Red, Brown); // up triangle
					if (Enemy2.SightDirection() == Down)
						Draw((char)31, Red, Brown); // down triangle
					if (Enemy2.SightDirection() == Right)
						Draw((char)16, Red, Brown); // right triangle
					if (Enemy2.SightDirection() == Left)
						Draw((char)17, Red, Brown); // left triangle
				}
				// Draws the 3rd enemy on an up arrow
				else if (Playfield[i][j].HasEnemy3()) {
					if (Enemy3.SightDirection() == Up)
						Draw((char)30, Red, Brown); // up triangle
					if (Enemy3.SightDirection() == Down)
						Draw((char)31, Red, Brown); // down triangle
					if (Enemy3.SightDirection() == Right)
						Draw((char)16, Red, Brown); // right triangle
					if (Enemy3.SightDirection() == Left)
						Draw((char)17, Red, Brown); // left triangle
				}
				// If the arrow is on first horizontal line of playfield, don't check the higher one
				else if (i == 0) {
					// Draw up triangle if there is another arrow block down
					if (Playfield[i + 1][j].HasArrowUp()) {
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
					if (Playfield[i - 1][j].HasArrowUp()) {
						Draw((char)179, White);
					}
					// Draws just an up arrow
					else {
						Draw((char)24, White);
					}
				}
				// Drows a vertical line if there is another arrow block up and down or just up
				else if ((Playfield[i + 1][j].HasArrowUp() && Playfield[i - 1][j].HasArrowUp()) || Playfield[i - 1][j].HasArrowUp())/*(Playfield[i - 1][j].HasArrowUp()) {
				Draw((char)179, White);
				}
// Draw up triangle if there is another arrow block down
				else if (Playfield[i + 1][j].HasArrowUp()) {
				Draw((char)30, White);
				}
				// Draws just an up arrow
				else {
				Draw((char)24, White);
				}
			}
			// Draws down arrow
			else if (Playfield[i][j].HasArrowDown()) {
			// Draws a bullet on a down arrow
			if (Playfield[i][j].HasBullet()) {
				Draw((char)249, White);
			}
			// Draws a player on a down arrow
			else if (Playfield[i][j].HasPlayer()) {
				if (Player.SightDirection() == Up)
					Draw((char)30, Green, Brown); // up triangle
				if (Player.SightDirection() == Down)
					Draw((char)31, Green, Brown); // down triangle
				if (Player.SightDirection() == Right)
					Draw((char)16, Green, Brown); // right triangle
				if (Player.SightDirection() == Left)
					Draw((char)17, Green, Brown); // left triangle
			}
			// Draws the 1st enemy on a down arrow
			else if (Playfield[i][j].HasEnemy1()) {
				if (Enemy1.SightDirection() == Up)
					Draw((char)30, Red, Brown); // up triangle
				if (Enemy1.SightDirection() == Down)
					Draw((char)31, Red, Brown); // down triangle
				if (Enemy1.SightDirection() == Right)
					Draw((char)16, Red, Brown); // right triangle
				if (Enemy1.SightDirection() == Left)
					Draw((char)17, Red, Brown); // left triangle
			}
			// Draws the 2nd enemy on a down arrow
			else if (Playfield[i][j].HasEnemy2()) {
				if (Enemy2.SightDirection() == Up)
					Draw((char)30, Red, Brown); // up triangle
				if (Enemy2.SightDirection() == Down)
					Draw((char)31, Red, Brown); // down triangle
				if (Enemy2.SightDirection() == Right)
					Draw((char)16, Red, Brown); // right triangle
				if (Enemy2.SightDirection() == Left)
					Draw((char)17, Red, Brown); // left triangle
			}
			// Draws the 3rd enemy on a down arrow
			else if (Playfield[i][j].HasEnemy3()) {
				if (Enemy3.SightDirection() == Up)
					Draw((char)30, Red, Brown); // up triangle
				if (Enemy3.SightDirection() == Down)
					Draw((char)31, Red, Brown); // down triangle
				if (Enemy3.SightDirection() == Right)
					Draw((char)16, Red, Brown); // right triangle
				if (Enemy3.SightDirection() == Left)
					Draw((char)17, Red, Brown); // left triangle
			}
			// If the arrow is on first horizontal line of playfield, don't check the higher one
			else if (i == 0) {
				// Draw vertical line if there is another arrow block down
				if (Playfield[i + 1][j].HasArrowDown()) {
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
				if (Playfield[i - 1][j].HasArrowDown()) {
					Draw((char)31, White);
				}
				// Draws just a down arrow
				else {
					Draw((char)25, White);
				}
			}
			// Draw vertical line if there are another arrow blocks down and up or just down
			else if ((Playfield[i + 1][j].HasArrowDown() && Playfield[i - 1][j].HasArrowDown()) || Playfield[i + 1][j].HasArrowDown()) {
				Draw((char)179, White);
			}
			// Drows down triangle if there is another arrow block up
			else if (Playfield[i - 1][j].HasArrowDown()) {
				Draw((char)31, White);
			}
			// Draws just a down arrow
			else {
				Draw((char)25, White);
			}
			}
			// Draws left arrow
			else if (Playfield[i][j].HasArrowLeft()) {
			// Draws a bullet on an left arrow
			if (Playfield[i][j].HasBullet()) {
				Draw((char)249, White);
			}
			// Draws a player on a left arrow
			else if (Playfield[i][j].HasPlayer()) {
				if (Player.SightDirection() == Up)
					Draw((char)30, Green, Brown); // up triangle
				if (Player.SightDirection() == Down)
					Draw((char)31, Green, Brown); // down triangle
				if (Player.SightDirection() == Right)
					Draw((char)16, Green, Brown); // right triangle
				if (Player.SightDirection() == Left)
					Draw((char)17, Green, Brown); // left triangle
			}
			// Draws the 1st enemy on a left arrow
			else if (Playfield[i][j].HasEnemy1()) {
				if (Enemy1.SightDirection() == Up)
					Draw((char)30, Red, Brown); // up triangle
				if (Enemy1.SightDirection() == Down)
					Draw((char)31, Red, Brown); // down triangle
				if (Enemy1.SightDirection() == Right)
					Draw((char)16, Red, Brown); // right triangle
				if (Enemy1.SightDirection() == Left)
					Draw((char)17, Red, Brown); // left triangle
			}
			// Draws the 2nd enemy on a left arrow
			else if (Playfield[i][j].HasEnemy2()) {
				if (Enemy2.SightDirection() == Up)
					Draw((char)30, Red, Brown); // up triangle
				if (Enemy2.SightDirection() == Down)
					Draw((char)31, Red, Brown); // down triangle
				if (Enemy2.SightDirection() == Right)
					Draw((char)16, Red, Brown); // right triangle
				if (Enemy2.SightDirection() == Left)
					Draw((char)17, Red, Brown); // left triangle
			}
			// Draws the 3rd enemy on a left arrow
			else if (Playfield[i][j].HasEnemy3()) {
				if (Enemy3.SightDirection() == Up)
					Draw((char)30, Red, Brown); // up triangle
				if (Enemy3.SightDirection() == Down)
					Draw((char)31, Red, Brown); // down triangle
				if (Enemy3.SightDirection() == Right)
					Draw((char)16, Red, Brown); // right triangle
				if (Enemy3.SightDirection() == Left)
					Draw((char)17, Red, Brown); // left triangle
			}
			// l196 t27 a17
			// If the arrow is on first horizontal line of playfield, don't check the left one
			else if (j == 0) {
				// Draw left triangle if there is another arrow block right
				if (Playfield[i][j + 1].HasArrowLeft()) {
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
				if (Playfield[i][j - 1].HasArrowLeft()) {
					Draw((char)196, White);
				}
				// Draws just a down arrow
				else {
					Draw((char)27, White);
				}
			}
			// Draw horizontal line if there are another arrow block left and right or just left
			else if ((Playfield[i][j + 1].HasArrowLeft() && Playfield[i][j - 1].HasArrowLeft()) || Playfield[i][j - 1].HasArrowLeft()) {
				Draw((char)196, White);
			}
			// Drows left triangle if there is another arrow block right
			else if (Playfield[i][j + 1].HasArrowLeft()) {
				Draw((char)17, White);
			}
			// Draws just a left arrow
			else {
				Draw((char)27, White);
			}
			}
			// Draws left arrow
			else if (Playfield[i][j].HasArrowRight()) {
			// Draws a bullet on an right arrow
			if (Playfield[i][j].HasBullet()) {
				Draw((char)249, White);
			}
			// Draws a player on a right arrow
			else if (Playfield[i][j].HasPlayer()) {
				if (Player.SightDirection() == Up)
					Draw((char)30, Green, Brown); // up triangle
				if (Player.SightDirection() == Down)
					Draw((char)31, Green, Brown); // down triangle
				if (Player.SightDirection() == Right)
					Draw((char)16, Green, Brown); // right triangle
				if (Player.SightDirection() == Left)
					Draw((char)17, Green, Brown); // left triangle
			}
			// Draws the 1st enemy on a right arrow
			else if (Playfield[i][j].HasEnemy1()) {
				if (Enemy1.SightDirection() == Up)
					Draw((char)30, Red, Brown); // up triangle
				if (Enemy1.SightDirection() == Down)
					Draw((char)31, Red, Brown); // down triangle
				if (Enemy1.SightDirection() == Right)
					Draw((char)16, Red, Brown); // right triangle
				if (Enemy1.SightDirection() == Left)
					Draw((char)17, Red, Brown); // left triangle
			}
			// Draws the 2nd enemy on a right arrow
			else if (Playfield[i][j].HasEnemy2()) {
				if (Enemy2.SightDirection() == Up)
					Draw((char)30, Red, Brown); // up triangle
				if (Enemy2.SightDirection() == Down)
					Draw((char)31, Red, Brown); // down triangle
				if (Enemy2.SightDirection() == Right)
					Draw((char)16, Red, Brown); // right triangle
				if (Enemy2.SightDirection() == Left)
					Draw((char)17, Red, Brown); // left triangle
			}
			// Draws the 3rd enemy on a right arrow
			else if (Playfield[i][j].HasEnemy3()) {
				if (Enemy3.SightDirection() == Up)
					Draw((char)30, Red, Brown); // up triangle
				if (Enemy3.SightDirection() == Down)
					Draw((char)31, Red, Brown); // down triangle
				if (Enemy3.SightDirection() == Right)
					Draw((char)16, Red, Brown); // right triangle
				if (Enemy3.SightDirection() == Left)
					Draw((char)17, Red, Brown); // left triangle
			}
			// If the arrow is on first horizontal line of playfield, don't check the left one
			else if (j == 0) {
				// Draw right triangle if there is another arrow block right
				if (Playfield[i][j + 1].HasArrowRight()) {
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
				if (Playfield[i][j - 1].HasArrowRight()) {
					Draw((char)16, White);
				}
				// Draws just a right arrow
				else {
					Draw((char)26, White);
				}
			}
			// Draw horizontal line if there are another arrow block left and right or just left
			else if ((Playfield[i][j + 1].HasArrowRight() && Playfield[i][j - 1].HasArrowRight()) || Playfield[i][j + 1].HasArrowRight()) {
				Draw((char)196, White);
			}
			// Drows right triangle if there is another arrow block left
			else if (Playfield[i][j - 1].HasArrowRight()) {
				Draw((char)16, White);
			}
			// Draws just a right arrow
			else {
				Draw((char)26, White);
			}
			}
	*/
	/*
	for (int i = 0; i < playfieldHeight; i++) {
		gotoxy(printOffsetWidth + 1, printOffsetHeight + i + 1); // moves console cursor to needed position
		for (int j = 0; j < playfieldWidth; j++) {
			// Draws nothing
			if (Playfield[i][j].HasNothing())
				Draw(' ', Black);

			// Draws a bullet
			if (Playfield[i][j].HasBullet()) {
				Draw((char)249, Yellow);
			}

			// Draws player
			if (Playfield[i][j].HasPlayer()) {
				if (Player.SightDirection() == Up)
					Draw((char)30, Green); // up triangle
				if (Player.SightDirection() == Down)
					Draw((char)31, Green); // down triangle
				if (Player.SightDirection() == Right)
					Draw((char)16, Green); // right triangle
				if (Player.SightDirection() == Left)
					Draw((char)17, Green); // left triangle
			}

			// Draws an enemy
			if (Playfield[i][j].HasEnemy()) {
				if (Enemy1.SightDirection() == Up)
					Draw((char)30, Red); // up triangle
				if (Enemy1.SightDirection() == Down)
					Draw((char)31, Red); // down triangle
				if (Enemy1.SightDirection() == Right)
					Draw((char)16, Red); // right triangle
				if (Enemy1.SightDirection() == Left)
					Draw((char)17, Red); // left triangle
			}

			// Drows bricks
			if (Playfield[i][j].HasBrick())
				Draw((char)177, DarkRed);

			// Drows concretes
			if (Playfield[i][j].HasConcrete())
				Draw((char)178, Gray);

			// Draws water
			if (Playfield[i][j].HasWater()) {
				// Draws bullets that go through
				if (Playfield[i][j].HasBullet()) {
					Draw((char)249, Yellow, Blue);
				}
				else
					// Draws just water block
					Draw(' ', Black, Blue);
			}

			// Drows grass
			if (Playfield[i][j].HasGrass()) {
				if (Playfield[i][j].HasGrassOpened()) {
					// Draws bullet in "opened" grass
					if (Playfield[i][j].HasBullet())
						Draw((char)249, Yellow, DarkGreen);

					// Draws player in grass
					if (Playfield[i][j].HasPlayer()) {
						if (Player.SightDirection() == Up)
							Draw((char)30, Green, DarkGreen); // up triangle
						if (Player.SightDirection() == Down)
							Draw((char)31, Green, DarkGreen); // down triangle
						if (Player.SightDirection() == Right)
							Draw((char)16, Green, DarkGreen); // right triangle
						if (Player.SightDirection() == Left)
							Draw((char)17, Green, DarkGreen); // left triangle
					}

					// Draws enemy in "opened" grass
					if (Playfield[i][j].HasEnemy()) {
						if (Enemy1.SightDirection() == Up)
							Draw((char)30, Red, DarkGreen); // up triangle
						if (Enemy1.SightDirection() == Down)
							Draw((char)31, Red, DarkGreen); // down triangle
						if (Enemy1.SightDirection() == Right)
							Draw((char)16, Red, DarkGreen); // right triangle
						if (Enemy1.SightDirection() == Left)
							Draw((char)17, Red, DarkGreen); // left triangle
					}
					else
						// Draws "opened" grass block
						Draw(' ', DarkGreen, DarkGreen);

				}
				else
					// Draws just grass block
					Draw((char)176, DarkGreen);
			}

			// Draws ice
			if (Playfield[i][j].HasIce()) {
				// Draws bullet on ice
				if (Playfield[i][j].HasBullet()) {
					Draw((char)249, Yellow, DarkCyan);
				}
				else {
					// Draws player on ice
					if (Playfield[i][j].HasPlayer()) {
						if (Player.SightDirection() == Up)
							Draw((char)30, Green, DarkCyan); // up triangle
						if (Player.SightDirection() == Down)
							Draw((char)31, Green, DarkCyan); // down triangle
						if (Player.SightDirection() == Right)
							Draw((char)16, Green, DarkCyan); // right triangle
						if (Player.SightDirection() == Left)
							Draw((char)17, Green, DarkCyan); // left triangle
					}
					else {

						// Draws enemy on ice
						if (Playfield[i][j].HasEnemy()) {
							if (Enemy1.SightDirection() == Up)
								Draw((char)30, Red, DarkCyan); // up triangle
							if (Enemy1.SightDirection() == Down)
								Draw((char)31, Red, DarkCyan); // down triangle
							if (Enemy1.SightDirection() == Right)
								Draw((char)16, Red, DarkCyan); // right triangle
							if (Enemy1.SightDirection() == Left)
								Draw((char)17, Red, DarkCyan); // left triangle
						}
						else
							// Draws just ice block
							Draw(' ', DarkCyan, DarkCyan);
					}
				}
			}


		}
		std::cout << std::endl;
	}*/
	/*
	for (int i = 0; i < playfieldHeight; i++) {
		gotoxy(printOffsetWidth + 1, printOffsetHeight + i + 1); // moves console cursor to needed position
		for (int j = 0; j < playfieldWidth; j++) {
			// Drows bricks
			if (Playfield[i][j].HasBrick())
				Draw((char)177, DarkRed);
			else {
				// Drows concretes
				if (Playfield[i][j].HasConcrete())
					Draw((char)178, LightGray);
				else {
					// Drows grass
					if (Playfield[i][j].HasGrass()) {
						if (Playfield[i][j].HasGrassOpened()) {
							// Draws player in grass
							if (Playfield[i][j].HasPlayer()) {
								if (Player.SightDirection() == Up)
									Draw((char)30, Green, DarkGreen); // up triangle
								if (Player.SightDirection() == Down)
									Draw((char)31, Green, DarkGreen); // down triangle
								if (Player.SightDirection() == Right)
									Draw((char)16, Green, DarkGreen); // right triangle
								if (Player.SightDirection() == Left)
									Draw((char)17, Green, DarkGreen); // left triangle
							}
							else {
								// Draws bullet in "opened" grass
								if (Playfield[i][j].HasBullet())
									Draw((char)249, Yellow, DarkGreen);
								else {
									// Draws enemy in "opened" grass
									if (Playfield[i][j].HasEnemy1()) {
										if (Enemy1.SightDirection() == Up)
											Draw((char)30, Red, DarkGreen); // up triangle
										if (Enemy1.SightDirection() == Down)
											Draw((char)31, Red, DarkGreen); // down triangle
										if (Enemy1.SightDirection() == Right)
											Draw((char)16, Red, DarkGreen); // right triangle
										if (Enemy1.SightDirection() == Left)
											Draw((char)17, Red, DarkGreen); // left triangle
									}
									else {
										if (Playfield[i][j].HasEnemy2()) {
											if (Enemy2.SightDirection() == Up)
												Draw((char)30, Red, DarkGreen); // up triangle
											if (Enemy2.SightDirection() == Down)
												Draw((char)31, Red, DarkGreen); // down triangle
											if (Enemy2.SightDirection() == Right)
												Draw((char)16, Red, DarkGreen); // right triangle
											if (Enemy2.SightDirection() == Left)
												Draw((char)17, Red, DarkGreen); // left triangle
										}
										else {
											if (Playfield[i][j].HasEnemy3()) {
												if (Enemy3.SightDirection() == Up)
													Draw((char)30, Red, DarkGreen); // up triangle
												if (Enemy3.SightDirection() == Down)
													Draw((char)31, Red, DarkGreen); // down triangle
												if (Enemy3.SightDirection() == Right)
													Draw((char)16, Red, DarkGreen); // right triangle
												if (Enemy3.SightDirection() == Left)
													Draw((char)17, Red, DarkGreen); // left triangle
											}
											else
												// Draws "opened" grass block
												Draw(' ', DarkGreen, DarkGreen);
										}
									}
								}
							}
						}
						else
							// Draws just grass block
							Draw((char)176, DarkGreen);
					}
					else {
						// Draws water
						if (Playfield[i][j].HasWater()) {
							// Draws bullets that go through
							if (Playfield[i][j].HasBullet()) {
								Draw((char)249, Yellow, Blue);
							}
							else
								// Draws just water block
								Draw(' ', Black, Blue);
						}
						else {
							// Draws ice
							if (Playfield[i][j].HasIce()) {
								// Draws player on ice
								if (Playfield[i][j].HasPlayer()) {
									if (Player.SightDirection() == Up)
										Draw((char)30, Green, DarkCyan); // up triangle
									if (Player.SightDirection() == Down)
										Draw((char)31, Green, DarkCyan); // down triangle
									if (Player.SightDirection() == Right)
										Draw((char)16, Green, DarkCyan); // right triangle
									if (Player.SightDirection() == Left)
										Draw((char)17, Green, DarkCyan); // left triangle
								}
								else {
									// Draws bullet on ice
									if (Playfield[i][j].HasBullet()) {
										Draw((char)249, Yellow, DarkCyan);
									}
									else {
										// Draws enemy on ice
										if (Playfield[i][j].HasEnemy1()) {
											if (Enemy1.SightDirection() == Up)
												Draw((char)30, Red, DarkCyan); // up triangle
											if (Enemy1.SightDirection() == Down)
												Draw((char)31, Red, DarkCyan); // down triangle
											if (Enemy1.SightDirection() == Right)
												Draw((char)16, Red, DarkCyan); // right triangle
											if (Enemy1.SightDirection() == Left)
												Draw((char)17, Red, DarkCyan); // left triangle
										}
										else {
											if (Playfield[i][j].HasEnemy2()) {
												if (Enemy2.SightDirection() == Up)
													Draw((char)30, Red, DarkCyan); // up triangle
												if (Enemy2.SightDirection() == Down)
													Draw((char)31, Red, DarkCyan); // down triangle
												if (Enemy2.SightDirection() == Right)
													Draw((char)16, Red, DarkCyan); // right triangle
												if (Enemy2.SightDirection() == Left)
													Draw((char)17, Red, DarkCyan); // left triangle
											}
											else {
												if (Playfield[i][j].HasEnemy3()) {
													if (Enemy3.SightDirection() == Up)
														Draw((char)30, Red, DarkCyan); // up triangle
													if (Enemy3.SightDirection() == Down)
														Draw((char)31, Red, DarkCyan); // down triangle
													if (Enemy3.SightDirection() == Right)
														Draw((char)16, Red, DarkCyan); // right triangle
													if (Enemy3.SightDirection() == Left)
														Draw((char)17, Red, DarkCyan); // left triangle
												}
												else
													// Draws just ice block
													Draw(' ', DarkCyan, DarkCyan);
											}
										}
									}
								}
							}
							else {
								// Draws player
								if (Playfield[i][j].HasPlayer()) {
									if (Player.SightDirection() == Up)
										Draw((char)30, Green); // up triangle
									if (Player.SightDirection() == Down)
										Draw((char)31, Green); // down triangle
									if (Player.SightDirection() == Right)
										Draw((char)16, Green); // right triangle
									if (Player.SightDirection() == Left)
										Draw((char)17, Green); // left triangle
								}
								else {
									// Draws a bullet
									if (Playfield[i][j].HasBullet()) {
										Draw((char)249, Yellow);
									}
									else {
										// Draws an enemy
										if (Playfield[i][j].HasEnemy1()) {
											if (Enemy1.SightDirection() == Up)
												Draw((char)30, Red); // up triangle
											if (Enemy1.SightDirection() == Down)
												Draw((char)31, Red); // down triangle
											if (Enemy1.SightDirection() == Right)
												Draw((char)16, Red); // right triangle
											if (Enemy1.SightDirection() == Left)
												Draw((char)17, Red); // left triangle
										}
										else {
											if (Playfield[i][j].HasEnemy2()) {
												if (Enemy2.SightDirection() == Up)
													Draw((char)30, Red); // up triangle
												if (Enemy2.SightDirection() == Down)
													Draw((char)31, Red); // down triangle
												if (Enemy2.SightDirection() == Right)
													Draw((char)16, Red); // right triangle
												if (Enemy2.SightDirection() == Left)
													Draw((char)17, Red); // left triangle
											}
											else {
												if (Playfield[i][j].HasEnemy3()) {
													if (Enemy3.SightDirection() == Up)
														Draw((char)30, Red); // up triangle
													if (Enemy3.SightDirection() == Down)
														Draw((char)31, Red); // down triangle
													if (Enemy3.SightDirection() == Right)
														Draw((char)16, Red); // right triangle
													if (Enemy3.SightDirection() == Left)
														Draw((char)17, Red); // left triangle
												}
												else
													// Draws nothing
													Draw(' ', Black);
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		std::cout << std::endl;
	}*/
	/*
			// Arrows mechanic
			for (int i = 0; i < playfieldHeight; i++) {
				for (int j = 0; j < playfieldWidth; j++) {
					// If there is an up arrow, move up very fast
					if (Playfield[i][j].HasArrowUp()) {
						if (Playfield[i][j].HasPlayer()) {
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Player.Move(Up);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Player.Move(Up);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Player.Move(Up);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Player.Move(Up);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));
						}

						if (Playfield[i][j].HasEnemy1()) {
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Enemy1.Move(Up);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Enemy1.Move(Up);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Enemy1.Move(Up);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Enemy1.Move(Up);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));
						}

						if (Playfield[i][j].HasEnemy2()) {
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Enemy2.Move(Up);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Enemy2.Move(Up);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Enemy2.Move(Up);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Enemy2.Move(Up);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));
						}

						if (Playfield[i][j].HasEnemy3()) {
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Enemy3.Move(Up);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Enemy3.Move(Up);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Enemy3.Move(Up);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Enemy3.Move(Up);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));
						}
					}

					// If there is a down arrow, move down very fast
					if (Playfield[i][j].HasArrowDown()) {
						if (Playfield[i][j].HasPlayer()) {
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Player.Move(Down);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Player.Move(Down);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Player.Move(Down);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Player.Move(Down);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));
						}

						if (Playfield[i][j].HasEnemy1()) {
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Enemy1.Move(Down);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Enemy1.Move(Down);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Enemy1.Move(Down);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Enemy1.Move(Down);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));
						}

						if (Playfield[i][j].HasEnemy2()) {
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Enemy2.Move(Down);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Enemy2.Move(Down);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Enemy2.Move(Down);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Enemy2.Move(Down);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));
						}

						if (Playfield[i][j].HasEnemy3()) {
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Enemy3.Move(Down);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Enemy3.Move(Down);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Enemy3.Move(Down);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Enemy3.Move(Down);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));
						}
					}

					// If there is an left arrow, move left very fast
					if (Playfield[i][j].HasArrowLeft()) {
						if (Playfield[i][j].HasPlayer()) {
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Player.Move(Left);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Player.Move(Left);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Player.Move(Left);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Player.Move(Left);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));
						}

						if (Playfield[i][j].HasEnemy1()) {
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Enemy1.Move(Left);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Enemy1.Move(Left);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Enemy1.Move(Left);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Enemy1.Move(Left);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));
						}

						if (Playfield[i][j].HasEnemy2()) {
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Enemy2.Move(Left);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Enemy2.Move(Left);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Enemy2.Move(Left);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Enemy2.Move(Left);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));
						}

						if (Playfield[i][j].HasEnemy3()) {
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Enemy3.Move(Left);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Enemy3.Move(Left);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Enemy3.Move(Left);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Enemy3.Move(Left);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));
						}
					}

					// If there is an right arrow, move right very fast
					if (Playfield[i][j].HasArrowRight()) {
						if (Playfield[i][j].HasPlayer()) {
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Player.Move(Right);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Player.Move(Right);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Player.Move(Right);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Player.Move(Right);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));
						}

						if (Playfield[i][j].HasEnemy1()) {
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Enemy1.Move(Right);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Enemy1.Move(Right);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Enemy1.Move(Right);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Enemy1.Move(Right);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));
						}

						if (Playfield[i][j].HasEnemy2()) {
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Enemy2.Move(Right);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Enemy2.Move(Right);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Enemy2.Move(Right);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Enemy2.Move(Right);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));
						}

						if (Playfield[i][j].HasEnemy3()) {
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Enemy3.Move(Right);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Enemy3.Move(Right);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Enemy3.Move(Right);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));

							Enemy3.Move(Right);
							std::this_thread::sleep_for(std::chrono::milliseconds(30));
						}
					}
				}
			}
	*/
	/*
	// Characters blocks interactions
	// Arrows mechanic
	for (int i = 0; i < playfieldHeight; i++) {
		for (int j = 0; j < playfieldWidth; j++) {
			// If there is an up arrow, move up very fast
			if (Playfield[i][j].HasArrowUp()) {
				if (Playfield[i][j].HasPlayer()) {
					std::this_thread::sleep_for(std::chrono::milliseconds(100));

					Player.Move(Up);

					std::this_thread::sleep_for(std::chrono::milliseconds(100));
				}

				if (Playfield[i][j].HasEnemy1()) {
					std::this_thread::sleep_for(std::chrono::milliseconds(100));

					Enemy1.Move(Up);

					std::this_thread::sleep_for(std::chrono::milliseconds(100));
				}

				if (Playfield[i][j].HasEnemy2()) {
					std::this_thread::sleep_for(std::chrono::milliseconds(100));

					Enemy2.Move(Up);

					std::this_thread::sleep_for(std::chrono::milliseconds(100));
				}

				if (Playfield[i][j].HasEnemy3()) {
					std::this_thread::sleep_for(std::chrono::milliseconds(100));

					Enemy3.Move(Up);

					std::this_thread::sleep_for(std::chrono::milliseconds(100));
				}
			}

			// If there is a down arrow, move down very fast
			if (Playfield[i][j].HasArrowDown()) {
				if (Playfield[i][j].HasPlayer()) {
					std::this_thread::sleep_for(std::chrono::milliseconds(100));

					Player.Move(Down);

					std::this_thread::sleep_for(std::chrono::milliseconds(100));
				}

				if (Playfield[i][j].HasEnemy1()) {
					std::this_thread::sleep_for(std::chrono::milliseconds(100));

					Enemy1.Move(Down);

					std::this_thread::sleep_for(std::chrono::milliseconds(100));
				}

				if (Playfield[i][j].HasEnemy2()) {
					std::this_thread::sleep_for(std::chrono::milliseconds(100));

					Enemy2.Move(Down);

					std::this_thread::sleep_for(std::chrono::milliseconds(100));
				}

				if (Playfield[i][j].HasEnemy3()) {
					std::this_thread::sleep_for(std::chrono::milliseconds(100));

					Enemy3.Move(Down);

					std::this_thread::sleep_for(std::chrono::milliseconds(100));
				}
			}

			// If there is an left arrow, move left very fast
			if (Playfield[i][j].HasArrowLeft()) {
				if (Playfield[i][j].HasPlayer()) {
					std::this_thread::sleep_for(std::chrono::milliseconds(100));

					Player.Move(Left);

					std::this_thread::sleep_for(std::chrono::milliseconds(100));
				}

				if (Playfield[i][j].HasEnemy1()) {
					std::this_thread::sleep_for(std::chrono::milliseconds(100));

					Enemy1.Move(Left);

					std::this_thread::sleep_for(std::chrono::milliseconds(100));
				}

				if (Playfield[i][j].HasEnemy2()) {
					std::this_thread::sleep_for(std::chrono::milliseconds(100));

					Enemy2.Move(Left);

					std::this_thread::sleep_for(std::chrono::milliseconds(100));
				}

				if (Playfield[i][j].HasEnemy3()) {
					std::this_thread::sleep_for(std::chrono::milliseconds(100));

					Enemy3.Move(Left);

					std::this_thread::sleep_for(std::chrono::milliseconds(100));
				}
			}

			// If there is an right arrow, move right very fast
			if (Playfield[i][j].HasArrowRight()) {
				if (Playfield[i][j].HasPlayer()) {
					std::this_thread::sleep_for(std::chrono::milliseconds(100));

					Player.Move(Right);

					std::this_thread::sleep_for(std::chrono::milliseconds(100));
				}

				if (Playfield[i][j].HasEnemy1()) {
					std::this_thread::sleep_for(std::chrono::milliseconds(100));

					Enemy1.Move(Right);

					std::this_thread::sleep_for(std::chrono::milliseconds(100));
				}

				if (Playfield[i][j].HasEnemy2()) {
					std::this_thread::sleep_for(std::chrono::milliseconds(100));

					Enemy2.Move(Right);

					std::this_thread::sleep_for(std::chrono::milliseconds(100));
				}

				if (Playfield[i][j].HasEnemy3()) {
					std::this_thread::sleep_for(std::chrono::milliseconds(100));

					Enemy3.Move(Right);

					std::this_thread::sleep_for(std::chrono::milliseconds(100));
				}
			}
		}
	}

	// Grass mechanic
	// Opens every grass block around the player
	for (int i = 0; i < playfieldHeight; i++) {
		for (int j = 0; j < playfieldWidth; j++) {
			if (Playfield[i][j].HasPlayer() && Playfield[i][j].HasGrass()) {
				// Special cases for block what are on the edges or last lines
				// so the don't use a block that doesn't exist
				Playfield[i][j].SetGrassOpened();
				if (i == 0) { // first vertical line, can't do left
					if (j == 0) {// 0-0 tile
						if (Playfield[i + 1][j].HasGrass())
							Playfield[i + 1][j].SetGrassOpened();
						if (Playfield[i + 1][j + 1].HasGrass())
							Playfield[i + 1][j + 1].SetGrassOpened();
						if (Playfield[i][j + 1].HasGrass())
							Playfield[i][j + 1].SetGrassOpened();
					}
					else {
						if (j == (playfieldWidth - 1)) { // 0-last tile
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
				}
				else {
					if (i == (playfieldHeight - 1)) { // last vertical line, can't do right
						if (j == 0) { // last-0 tile
							if (Playfield[i - 1][j].HasGrass())
								Playfield[i - 1][j].SetGrassOpened();
							if (Playfield[i - 1][j + 1].HasGrass())
								Playfield[i - 1][j + 1].SetGrassOpened();
							if (Playfield[i][j + 1].HasGrass())
								Playfield[i][j + 1].SetGrassOpened();
						}
						else {
							if (j == (playfieldWidth - 1)) { // last-last tile
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
					}
					else {
						if (j == 0) { // only first horizontal line, can't do up
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
						else {
							if (j == (playfieldWidth - 1)) { // only last horizontal line, can't do down
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
					}
				}
			}
		}
	}

	// Closes every grass block that's isn't close to a player
	for (int i = 0; i < playfieldHeight; i++) {
		for (int j = 0; j < playfieldWidth; j++) {
			if (Playfield[i][j].HasGrassOpened()) {
				// Special cases for blocks what are on the edges or last lines
				// so the don't use a block that doesn't exist
				// If the player isn't near the grass block, "close" it
				if (i == 0) { // first vertical line, can't do left
					if (j == 0) {// 0-0 tile
						if (Playfield[i + 1][j].HasPlayer() && Playfield[i + 1][j].HasGrass())
							continue;
						if (Playfield[i + 1][j + 1].HasPlayer() && Playfield[i + 1][j + 1].HasGrass())
							continue;
						if (Playfield[i][j + 1].HasPlayer() && Playfield[i][j + 1].HasGrass())
							continue;
					}
					else {
						if (j == (playfieldWidth - 1)) { // 0-last tile
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
				}
				else {
					if (i == (playfieldHeight - 1)) { // last vertical line, can't do right
						if (j == 0) { // last-0 tile
							if (Playfield[i - 1][j].HasPlayer() && Playfield[i - 1][j].HasGrass())
								continue;
							if (Playfield[i - 1][j + 1].HasPlayer() && Playfield[i - 1][j + 1].HasGrass())
								continue;
							if (Playfield[i][j + 1].HasPlayer() && Playfield[i][j + 1].HasGrass())
								continue;
						}
						else {
							if (j == (playfieldWidth - 1)) { // last-last tile
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
					}
					else {
						if (j == 0) { // only first horizontal line, can't do up
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
						else {
							if (j == (playfieldWidth - 1)) { // only last horizontal line, can't do down
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
						}
					}
				}
				Playfield[i][j].SetGrassNotOpened();
			}
		}
	}*/


	/*
	void Bullet::Fly() {
		while (!GameOver) {
			// Sleeps for some time to make changes visible
			std::this_thread::sleep_for(std::chrono::milliseconds(100));

			// Unsets the old position
			switch (mWhoShot) {
			case isPlayer: {
				Playfield[mPosY][mPosX].SetNotBulletPlayer();
				break;
			}
			case isEnemy1: {
				Playfield[mPosY][mPosX].SetNotBulletEnemy1();
				break;
			}
			case isEnemy2: {
				Playfield[mPosY][mPosX].SetNotBulletEnemy2();
				break;
			}
			case isEnemy3: {
				Playfield[mPosY][mPosX].SetNotBulletEnemy3();
				break;
			}
			}

			// Moves the bullet accroding to the direction
			switch (mFlyDirection) {
			case Up: {
				// If the bullet is on the edge of the playfield, stop the movement
				if (mPosY == 0
					// If the bullet hits a concrete, other bullet, stop the movement
					|| Playfield[mPosY - 1][mPosX].HasConcrete()
					|| Playfield[mPosY - 1][mPosX].HasBullets()
					|| Playfield[mPosY - 1][mPosX].HasLava()) {

					switch (mWhoShot) {
					case isPlayer: {
						BulletAlreadyFliesPlayer = false;
						break;
					}
					case isEnemy1: {
						BulletAlreadyFliesEnemy1 = false;
						break;
					}
					case isEnemy2: {
						BulletAlreadyFliesEnemy2 = false;
						break;
					}
					case isEnemy3: {
						BulletAlreadyFliesEnemy3 = false;
						break;
					}
					}
					return;
				}
				else if (Playfield[mPosY - 1][mPosX].HasBrick()) {
					// Removes the block hit by the bullet
					Playfield[mPosY - 1][mPosX].SetNotBrick();

					// Stops the movement
					switch (mWhoShot) {
					case isPlayer: {
						BulletAlreadyFliesPlayer = false;
						break;
					}
					case isEnemy1: {
						BulletAlreadyFliesEnemy1 = false;
						break;
					}
					case isEnemy2: {
						BulletAlreadyFliesEnemy2 = false;
						break;
					}
					case isEnemy3: {
						BulletAlreadyFliesEnemy3 = false;
						break;
					}
					}
					return;
				}
				// If there is a player or enemies, respawn themand stop movement
				else if (Playfield[mPosY - 1][mPosX].HasPlayer()) {
					// Stops the movement and respawns the player if it was any of enemies shooting
					switch (mWhoShot) {
					case isPlayer: {
						BulletAlreadyFliesPlayer = false;
						break;
					}
					case isEnemy1: {
						Player1.Respawn();
						BulletAlreadyFliesEnemy1 = false;
						break;
					}
					case isEnemy2: {
						Player1.Respawn();
						BulletAlreadyFliesEnemy2 = false;
						break;
					}
					case isEnemy3: {
						Player1.Respawn();
						BulletAlreadyFliesEnemy3 = false;
						break;
					}
					}
					return;
				}
				else if (Playfield[mPosY - 1][mPosX].HasEnemy1()) {
					// Stops the movement and respawns the 1st enemy if it was player shooting
					switch (mWhoShot) {
					case isPlayer: {
						Enemy1.Respawn();
						BulletAlreadyFliesPlayer = false;
						break;
					}
					case isEnemy1: {
						BulletAlreadyFliesEnemy1 = false;
						break;
					}
					case isEnemy2: {
						BulletAlreadyFliesEnemy2 = false;
						break;
					}
					case isEnemy3: {
						BulletAlreadyFliesEnemy3 = false;
						break;
					}
					}
					return;
				}
				else if (Playfield[mPosY - 1][mPosX].HasEnemy2()) {
					// Stops the movement and respawns the 2nd enemy if it was player shooting
					switch (mWhoShot) {
					case isPlayer: {
						Enemy2.Respawn();
						BulletAlreadyFliesPlayer = false;
						break;
					}
					case isEnemy1: {
						BulletAlreadyFliesEnemy1 = false;
						break;
					}
					case isEnemy2: {
						BulletAlreadyFliesEnemy2 = false;
						break;
					}
					case isEnemy3: {
						BulletAlreadyFliesEnemy3 = false;
						break;
					}
					}
					return;
				}
				else if (Playfield[mPosY - 1][mPosX].HasEnemy3()) {
					// Stops the movement and respawns the 3rd enemy if it was player shooting
					switch (mWhoShot) {
					case isPlayer: {
						Enemy3.Respawn();
						BulletAlreadyFliesPlayer = false;
						break;
					}
					case isEnemy1: {
						BulletAlreadyFliesEnemy1 = false;
						break;
					}
					case isEnemy2: {
						BulletAlreadyFliesEnemy2 = false;
						break;
					}
					case isEnemy3: {
						BulletAlreadyFliesEnemy3 = false;
						break;
					}
					}
					return;
				}
				else {
					mPosY--; // move up
				}
				break;
			}
			case Down: {
				// If the bullet is on the edge of the playfield, stop the movement
				if (mPosY == (playfieldHeight - 1)
					// If the bullet hits a concrete, other bullet, stop the movement
					|| Playfield[mPosY + 1][mPosX].HasConcrete()
					|| Playfield[mPosY + 1][mPosX].HasBullets()
					|| Playfield[mPosY + 1][mPosX].HasLava()) {
					switch (mWhoShot) {
					case isPlayer: {
						BulletAlreadyFliesPlayer = false;
						break;
					}
					case isEnemy1: {
						BulletAlreadyFliesEnemy1 = false;
						break;
					}
					case isEnemy2: {
						BulletAlreadyFliesEnemy2 = false;
						break;
					}
					case isEnemy3: {
						BulletAlreadyFliesEnemy3 = false;
						break;
					}
					}
					return;
				}
				else if (Playfield[mPosY + 1][mPosX].HasBrick()) {
					// Removes the block hit by the bullet
					Playfield[mPosY + 1][mPosX].SetNotBrick();

					// Stops the movement
					switch (mWhoShot) {
					case isPlayer: {
						BulletAlreadyFliesPlayer = false;
						break;
					}
					case isEnemy1: {
						BulletAlreadyFliesEnemy1 = false;
						break;
					}
					case isEnemy2: {
						BulletAlreadyFliesEnemy2 = false;
						break;
					}
					case isEnemy3: {
						BulletAlreadyFliesEnemy3 = false;
						break;
					}
					}
					return;
				}
				// If there is a player or enemies, respawn themand stop movement
				else if (Playfield[mPosY + 1][mPosX].HasPlayer()) {
					// Stops the movement and respawns the player if it was any of enemies shooting
					switch (mWhoShot) {
					case isPlayer: {
						BulletAlreadyFliesPlayer = false;
						break;
					}
					case isEnemy1: {
						Player1.Respawn();
						BulletAlreadyFliesEnemy1 = false;
						break;
					}
					case isEnemy2: {
						Player1.Respawn();
						BulletAlreadyFliesEnemy2 = false;
						break;
					}
					case isEnemy3: {
						Player1.Respawn();
						BulletAlreadyFliesEnemy3 = false;
						break;
					}
					}
					return;
				}
				else if (Playfield[mPosY + 1][mPosX].HasEnemy1()) {
					// Stops the movement and respawns the 1st enemy if it was player shooting
					switch (mWhoShot) {
					case isPlayer: {
						Enemy1.Respawn();
						BulletAlreadyFliesPlayer = false;
						break;
					}
					case isEnemy1: {
						BulletAlreadyFliesEnemy1 = false;
						break;
					}
					case isEnemy2: {
						BulletAlreadyFliesEnemy2 = false;
						break;
					}
					case isEnemy3: {
						BulletAlreadyFliesEnemy3 = false;
						break;
					}
					}
					return;
				}
				else if (Playfield[mPosY + 1][mPosX].HasEnemy2()) {
					// Stops the movement and respawns the 2nd enemy if it was player shooting
					switch (mWhoShot) {
					case isPlayer: {
						Enemy2.Respawn();
						BulletAlreadyFliesPlayer = false;
						break;
					}
					case isEnemy1: {
						BulletAlreadyFliesEnemy1 = false;
						break;
					}
					case isEnemy2: {
						BulletAlreadyFliesEnemy2 = false;
						break;
					}
					case isEnemy3: {
						BulletAlreadyFliesEnemy3 = false;
						break;
					}
					}
					return;
				}
				else if (Playfield[mPosY + 1][mPosX].HasEnemy3()) {
					// Stops the movement and respawns the 3rd enemy if it was player shooting
					switch (mWhoShot) {
					case isPlayer: {
						Enemy3.Respawn();
						BulletAlreadyFliesPlayer = false;
						break;
					}
					case isEnemy1: {
						BulletAlreadyFliesEnemy1 = false;
						break;
					}
					case isEnemy2: {
						BulletAlreadyFliesEnemy2 = false;
						break;
					}
					case isEnemy3: {
						BulletAlreadyFliesEnemy3 = false;
						break;
					}
					}
					return;
				}
				else {
					mPosY++; // move down
				}
				break;
			}
			case Left: {
				// If the bullet is on the edge of the playfield, stop the movement
				if (mPosX == 0
					// If the bullet hits a concrete, other bullet, stop the movement
					|| Playfield[mPosY][mPosX - 1].HasConcrete()
					|| Playfield[mPosY][mPosX - 1].HasBullets()
					|| Playfield[mPosY][mPosX - 1].HasLava()) {
					switch (mWhoShot) {
					case isPlayer: {
						BulletAlreadyFliesPlayer = false;
						break;
					}
					case isEnemy1: {
						BulletAlreadyFliesEnemy1 = false;
						break;
					}
					case isEnemy2: {
						BulletAlreadyFliesEnemy2 = false;
						break;
					}
					case isEnemy3: {
						BulletAlreadyFliesEnemy3 = false;
						break;
					}
					}
					return;
				}
				else if (Playfield[mPosY][mPosX - 1].HasBrick()) {
					// Removes the block hit by the bullet
					Playfield[mPosY][mPosX - 1].SetNotBrick();

					// Stops the movement
					switch (mWhoShot) {
					case isPlayer: {
						BulletAlreadyFliesPlayer = false;
						break;
					}
					case isEnemy1: {
						BulletAlreadyFliesEnemy1 = false;
						break;
					}
					case isEnemy2: {
						BulletAlreadyFliesEnemy2 = false;
						break;
					}
					case isEnemy3: {
						BulletAlreadyFliesEnemy3 = false;
						break;
					}
					}
					return;
				}
				// If there is a player or enemies, respawn themand stop movement
				else if (Playfield[mPosY][mPosX - 1].HasPlayer()) {
					// Stops the movement and respawns the player if it was any of enemies shooting
					switch (mWhoShot) {
					case isPlayer: {
						BulletAlreadyFliesPlayer = false;
						break;
					}
					case isEnemy1: {
						Player1.Respawn();
						BulletAlreadyFliesEnemy1 = false;
						break;
					}
					case isEnemy2: {
						Player1.Respawn();
						BulletAlreadyFliesEnemy2 = false;
						break;
					}
					case isEnemy3: {
						Player1.Respawn();
						BulletAlreadyFliesEnemy3 = false;
						break;
					}
					}
					return;
				}
				else if (Playfield[mPosY][mPosX - 1].HasEnemy1()) {
					// Stops the movement and respawns the 1st enemy if it was player shooting
					switch (mWhoShot) {
					case isPlayer: {
						Enemy1.Respawn();
						BulletAlreadyFliesPlayer = false;
						break;
					}
					case isEnemy1: {
						BulletAlreadyFliesEnemy1 = false;
						break;
					}
					case isEnemy2: {
						BulletAlreadyFliesEnemy2 = false;
						break;
					}
					case isEnemy3: {
						BulletAlreadyFliesEnemy3 = false;
						break;
					}
					}
					return;
				}
				else if (Playfield[mPosY][mPosX - 1].HasEnemy2()) {
					// Stops the movement and respawns the 2nd enemy if it was player shooting
					switch (mWhoShot) {
					case isPlayer: {
						Enemy2.Respawn();
						BulletAlreadyFliesPlayer = false;
						break;
					}
					case isEnemy1: {
						BulletAlreadyFliesEnemy1 = false;
						break;
					}
					case isEnemy2: {
						BulletAlreadyFliesEnemy2 = false;
						break;
					}
					case isEnemy3: {
						BulletAlreadyFliesEnemy3 = false;
						break;
					}
					}
					return;
				}
				else if (Playfield[mPosY][mPosX - 1].HasEnemy3()) {
					// Stops the movement and respawns the 3rd enemy if it was player shooting
					switch (mWhoShot) {
					case isPlayer: {
						Enemy3.Respawn();
						BulletAlreadyFliesPlayer = false;
						break;
					}
					case isEnemy1: {
						BulletAlreadyFliesEnemy1 = false;
						break;
					}
					case isEnemy2: {
						BulletAlreadyFliesEnemy2 = false;
						break;
					}
					case isEnemy3: {
						BulletAlreadyFliesEnemy3 = false;
						break;
					}
					}
					return;
				}
				else {
					mPosX--; // move down
				}
				break;
			}
			case Right: {
				// If the bullet is on the edge of the playfield, stop the movement
				if (mPosX == (playfieldWidth - 1)
					// If the bullet hits a concrete, other bullet, stop the movement
					|| Playfield[mPosY][mPosX + 1].HasConcrete()
					|| Playfield[mPosY][mPosX + 1].HasBullets()
					|| Playfield[mPosY][mPosX + 1].HasLava()) {
					switch (mWhoShot) {
					case isPlayer: {
						BulletAlreadyFliesPlayer = false;
						break;
					}
					case isEnemy1: {
						BulletAlreadyFliesEnemy1 = false;
						break;
					}
					case isEnemy2: {
						BulletAlreadyFliesEnemy2 = false;
						break;
					}
					case isEnemy3: {
						BulletAlreadyFliesEnemy3 = false;
						break;
					}
					}
					return;
				}
				else if (Playfield[mPosY][mPosX + 1].HasBrick()) {
					// Removes the block hit by the bullet
					Playfield[mPosY][mPosX + 1].SetNotBrick();

					// Stops the movement
					switch (mWhoShot) {
					case isPlayer: {
						BulletAlreadyFliesPlayer = false;
						break;
					}
					case isEnemy1: {
						BulletAlreadyFliesEnemy1 = false;
						break;
					}
					case isEnemy2: {
						BulletAlreadyFliesEnemy2 = false;
						break;
					}
					case isEnemy3: {
						BulletAlreadyFliesEnemy3 = false;
						break;
					}
					}
					return;
				}
				// If there is a player or enemies, respawn them and stop movement
				else if (Playfield[mPosY][mPosX + 1].HasPlayer()) {
					// Stops the movement and respawns the player if it was any of enemies shooting
					switch (mWhoShot) {
					case isPlayer: {
						BulletAlreadyFliesPlayer = false;
						break;
					}
					case isEnemy1: {
						Player1.Respawn();
						BulletAlreadyFliesEnemy1 = false;
						break;
					}
					case isEnemy2: {
						Player1.Respawn();
						BulletAlreadyFliesEnemy2 = false;
						break;
					}
					case isEnemy3: {
						Player1.Respawn();
						BulletAlreadyFliesEnemy3 = false;
						break;
					}
					}
					return;
				}
				else if (Playfield[mPosY][mPosX + 1].HasEnemy1()) {
					// Stops the movement and respawns the 1st enemy if it was player shooting
					switch (mWhoShot) {
					case isPlayer: {
						Enemy1.Respawn();
						BulletAlreadyFliesPlayer = false;
						break;
					}
					case isEnemy1: {
						BulletAlreadyFliesEnemy1 = false;
						break;
					}
					case isEnemy2: {
						BulletAlreadyFliesEnemy2 = false;
						break;
					}
					case isEnemy3: {
						BulletAlreadyFliesEnemy3 = false;
						break;
					}
					}
					return;
				}
				else if (Playfield[mPosY][mPosX + 1].HasEnemy2()) {
					// Stops the movement and respawns the 2nd enemy if it was player shooting
					switch (mWhoShot) {
					case isPlayer: {
						Enemy2.Respawn();
						BulletAlreadyFliesPlayer = false;
						break;
					}
					case isEnemy1: {
						BulletAlreadyFliesEnemy1 = false;
						break;
					}
					case isEnemy2: {
						BulletAlreadyFliesEnemy2 = false;
						break;
					}
					case isEnemy3: {
						BulletAlreadyFliesEnemy3 = false;
						break;
					}
					}
					return;
				}
				// Stops the movement and respawns the 3rd enemy if it was player shooting
				else if (Playfield[mPosY][mPosX + 1].HasEnemy3()) {
					switch (mWhoShot) {
					case isPlayer: {
						Enemy3.Respawn();
						BulletAlreadyFliesPlayer = false;
						break;
					}
					case isEnemy1: {
						BulletAlreadyFliesEnemy1 = false;
						break;
					}
					case isEnemy2: {
						BulletAlreadyFliesEnemy2 = false;
						break;
					}
					case isEnemy3: {
						BulletAlreadyFliesEnemy3 = false;
						break;
					}
					}
					return;
				}
				// Move right
				else {
					mPosX++;
				}
				break;
			}
			}

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

			// Sets the new position
			switch (mWhoShot) {
			case isPlayer: {
				Playfield[mPosY][mPosX].SetBulletPlayer();
				break;
			}
			case isEnemy1: {
				Playfield[mPosY][mPosX].SetBulletEnemy1();
				break;
			}
			case isEnemy2: {
				Playfield[mPosY][mPosX].SetBulletEnemy2();
				break;
			}
			case isEnemy3: {
				Playfield[mPosY][mPosX].SetBulletEnemy3();
				break;
			}
			}
		}
	} */

/*
// Move functions
void Character::MoveUp() {
	// Sets previous position to non-player
	Playfield[mPosY][mPosX].SetNotPlayer();

	// Makes the tank look up
	mSightDirection = Up;

	// Collision detection
	if (mPosY == 0) {} // if the tank is on the edge of the playfield, do nothing
	else {
		// If there is a brick or concrete or water or enemy, do nothing
		if (Playfield[mPosY - 1][mPosX].HasBrick() || Playfield[mPosY - 1][mPosX].HasConcrete() || Playfield[mPosY - 1][mPosX].HasWater() || Playfield[mPosY - 1][mPosX].HasPlayer() || Playfield[mPosY - 1][mPosX].HasEnemy2() || Playfield[mPosY - 1][mPosX].HasEnemy3()) {}
		else {
			// If there is an ice, move twice with a delay to make "uncomfortable" movement
			if (Playfield[mPosY][mPosX].HasIce()) {
				// If the next place isn't ice, move once with a delay to make "uncomfortable" movement
				if (!Playfield[mPosY - 1][mPosX].HasIce()) {
					std::this_thread::sleep_for(std::chrono::milliseconds(100));

					mPosY--;
				}
				else {
					// If there is a brick or concrete or water or enemy 2 blocks near, move once with a delay to make "uncomfortable" movement
					if (Playfield[mPosY - 2][mPosX].HasBrick() || Playfield[mPosY - 2][mPosX].HasConcrete() || Playfield[mPosY - 2][mPosX].HasWater() || Playfield[mPosY - 2][mPosX].HasPlayer() || Playfield[mPosY - 2][mPosX].HasEnemy2() || Playfield[mPosY - 2][mPosX].HasEnemy3()) {
						std::this_thread::sleep_for(std::chrono::milliseconds(100));

						mPosY--;
					}
					else { // move twice
						mPosY--;

						std::this_thread::sleep_for(std::chrono::milliseconds(100));

						mPosY--;
					}
				}
			}
			else
				mPosY--; // move up
		}
	}

	// Sets the player to the new position
	Playfield[mPosY][mPosX].SetPlayer();
}

void Character::MoveRight() {
	// Sets previous position to non-player
	Playfield[mPosY][mPosX].SetNotPlayer();

	// Makes the tank look right
	mSightDirection = Right;

	// Collision detection
	if (mPosX == (playfieldWidth - 1)) {} // if the tank is on the edge of the playfield, do nothing
	else {
		// If there is a brick or concrete or water or enemy, do nothing
		if (Playfield[mPosY][mPosX + 1].HasBrick() || Playfield[mPosY][mPosX + 1].HasConcrete() || Playfield[mPosY][mPosX + 1].HasWater() || Playfield[mPosY][mPosX + 1].HasPlayer() || Playfield[mPosY][mPosX + 1].HasEnemy2() || Playfield[mPosY][mPosX + 1].HasEnemy3()) {}
		else {
			// If there is an ice, move twice with a delay to make "uncomfortable" movement
			if (Playfield[mPosY][mPosX].HasIce()) {
				if (!Playfield[mPosY][mPosX + 1].HasIce()) {
					std::this_thread::sleep_for(std::chrono::milliseconds(100));

					mPosX++;
				}
				else {
					// If there is a brick or concrete or water or enemy 2 blocks near, move once with a delay to make "uncomfortable" movement
					if (Playfield[mPosY][mPosX + 2].HasBrick() || Playfield[mPosY][mPosX + 2].HasConcrete() || Playfield[mPosY][mPosX + 2].HasWater() || Playfield[mPosY][mPosX + 2].HasPlayer() || Playfield[mPosY][mPosX + 2].HasEnemy2() || Playfield[mPosY][mPosX + 2].HasEnemy3()) {
						std::this_thread::sleep_for(std::chrono::milliseconds(100));

						mPosX++;
					}
					else { // move twice
						mPosX++;

						std::this_thread::sleep_for(std::chrono::milliseconds(100));

						mPosX++;
					}
				}
			}
			else
				mPosX++; // move right
		}
	}

	// Sets the player to the new position
	Playfield[mPosY][mPosX].SetPlayer();
}

void Character::MoveDown() {
	// Sets previous position to non-player
	Playfield[mPosY][mPosX].SetNotPlayer();

	// Makes the tank look down 
	mSightDirection = Down;

	// Collision detection
	if (mPosY == (playfieldHeight - 1)) {} // if the tank is on the edge of the playfield, do nothing
	else {
		// If there is a brick or concrete or water or enemy, do nothing
		if (Playfield[mPosY + 1][mPosX].HasBrick() || Playfield[mPosY + 1][mPosX].HasConcrete() || Playfield[mPosY + 1][mPosX].HasWater() || Playfield[mPosY + 1][mPosX].HasPlayer() || Playfield[mPosY + 1][mPosX].HasEnemy2() || Playfield[mPosY + 1][mPosX].HasEnemy3()) {}
		else {
			// If there is an ice, move twice with a delay to make "uncomfortable" movement
			if (Playfield[mPosY][mPosX].HasIce()) {
				if (!Playfield[mPosY + 1][mPosX].HasIce()) {
					std::this_thread::sleep_for(std::chrono::milliseconds(100));

					mPosY++;
				}
				else {
					// If there is a brick or concrete or water or enemy 2 blocks near, move once with a delay to make "uncomfortable" movement
					if (Playfield[mPosY + 2][mPosX].HasBrick() || Playfield[mPosY + 2][mPosX].HasConcrete() || Playfield[mPosY + 2][mPosX].HasWater() || Playfield[mPosY + 2][mPosX].HasPlayer() || Playfield[mPosY + 2][mPosX].HasEnemy2() || Playfield[mPosY + 2][mPosX].HasEnemy3()) {
						std::this_thread::sleep_for(std::chrono::milliseconds(100));

						mPosY++;
					}
					else { // move twice
						mPosY++;

						std::this_thread::sleep_for(std::chrono::milliseconds(100));

						mPosY++;
					}
				}
			}
			else
				mPosY++; // move down
		}
	}

	// Sets the player to the new position
	Playfield[mPosY][mPosX].SetPlayer();
}

void Character::MoveLeft() {
	// Sets previous position to non-player
	Playfield[mPosY][mPosX].SetNotPlayer();

	// Makes the tank look left
	mSightDirection = Left;

	// Collision detection
	if (mPosX == 0) {} // if the tank is on the edge of the playfield, do nothing
	else {
		// If there is a brick or concrete or water or enemy, do nothing
		if (Playfield[mPosY][mPosX - 1].HasBrick() || Playfield[mPosY][mPosX - 1].HasConcrete() || Playfield[mPosY][mPosX - 1].HasWater() || Playfield[mPosY][mPosX - 1].HasPlayer() || Playfield[mPosY][mPosX - 1].HasEnemy2() || Playfield[mPosY][mPosX - 1].HasEnemy3()) {}
		else {
			// If there is an ice, move twice with a delay to make "uncomfortable" movement
			if (Playfield[mPosY][mPosX].HasIce()) {
				if (!Playfield[mPosY][mPosX - 1].HasIce()) {
					std::this_thread::sleep_for(std::chrono::milliseconds(100));

					mPosX--;
				}
				else {
					// If there is a brick or concrete or water or enemy 2 blocks near, move once with a delay to make "uncomfortable" movement
					if (Playfield[mPosY][mPosX - 2].HasBrick() || Playfield[mPosY][mPosX - 2].HasConcrete() || Playfield[mPosY][mPosX - 2].HasWater() || Playfield[mPosY][mPosX - 2].HasPlayer() || Playfield[mPosY][mPosX - 2].HasEnemy2() || Playfield[mPosY][mPosX - 2].HasEnemy3()) {
						std::this_thread::sleep_for(std::chrono::milliseconds(100));

						mPosX--;
					}
					else { // move twice
						mPosX--;

						std::this_thread::sleep_for(std::chrono::milliseconds(100));

						mPosX--;
					}
				}
			}
			else
				mPosX--; // move left
		}
	}

	// Sets the player to the new position
	Playfield[mPosY][mPosX].SetPlayer();
}*/

/*
// Grass mechanic
// Opens every grass block around the player
for (int i = 0; i < playfieldHeight; i++) {
	for (int j = 0; j < playfieldWidth; j++) {
		if (Playfield[i][j].HasPlayer() && Playfield[i][j].HasGrass()) {
			// Special cases for block what are on the edges or last lines
			// so the don't use a block that doesn't exist
			Playfield[i][j].SetGrassOpened();
			if (i == 0) { // first vertical line, can't do left
				if (j == 0) {// 0-0 tile
					if (Playfield[i + 1][j].HasGrass())
						Playfield[i + 1][j].SetGrassOpened();
					if (Playfield[i + 1][j + 1].HasGrass())
						Playfield[i + 1][j + 1].SetGrassOpened();
					if (Playfield[i][j + 1].HasGrass())
						Playfield[i][j + 1].SetGrassOpened();
				}
				else {
					if (j == (playfieldWidth - 1)) { // 0-last tile
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
			}
			else {
				if (i == (playfieldHeight - 1)) { // last vertical line, can't do right
					if (j == 0) { // last-0 tile
						if (Playfield[i - 1][j].HasGrass())
							Playfield[i - 1][j].SetGrassOpened();
						if (Playfield[i - 1][j + 1].HasGrass())
							Playfield[i - 1][j + 1].SetGrassOpened();
						if (Playfield[i][j + 1].HasGrass())
							Playfield[i][j + 1].SetGrassOpened();
					}
					else {
						if (j == (playfieldWidth - 1)) { // last-last tile
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
				}
				else {
					if (j == 0) { // only first horizontal line, can't do up
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
					else {
						if (j == (playfieldWidth - 1)) { // only last horizontal line, can't do down
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
				}
			}
		}
	}
}

// Closes every grass block that's isn't close to a player
for (int i = 0; i < playfieldHeight; i++) {
	for (int j = 0; j < playfieldWidth; j++) {
		if (Playfield[i][j].HasGrassOpened()) {
			// Special cases for blocks what are on the edges or last lines
			// so the don't use a block that doesn't exist
			// If the player isn't near the grass block, "close" it
			if (i == 0) { // first vertical line, can't do left
				if (j == 0) {// 0-0 tile
					if (Playfield[i + 1][j].HasPlayer() && Playfield[i + 1][j].HasGrass())
						continue;
					if (Playfield[i + 1][j + 1].HasPlayer() && Playfield[i + 1][j + 1].HasGrass())
						continue;
					if (Playfield[i][j + 1].HasPlayer() && Playfield[i][j + 1].HasGrass())
						continue;
				}
				else {
					if (j == (playfieldWidth - 1)) { // 0-last tile
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
			}
			else {
				if (i == (playfieldHeight - 1)) { // last vertical line, can't do right
					if (j == 0) { // last-0 tile
						if (Playfield[i - 1][j].HasPlayer() && Playfield[i - 1][j].HasGrass())
							continue;
						if (Playfield[i - 1][j + 1].HasPlayer() && Playfield[i - 1][j + 1].HasGrass())
							continue;
						if (Playfield[i][j + 1].HasPlayer() && Playfield[i][j + 1].HasGrass())
							continue;
					}
					else {
						if (j == (playfieldWidth - 1)) { // last-last tile
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
				}
				else {
					if (j == 0) { // only first horizontal line, can't do up
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
					else {
						if (j == (playfieldWidth - 1)) { // only last horizontal line, can't do down
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
					}
				}
			}
			Playfield[i][j].SetGrassNotOpened();
		}
	}
}
*/