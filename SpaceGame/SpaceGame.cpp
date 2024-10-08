﻿
#include "Game.h"
#include "MainMenu.h"

int main()
{
	//Initialize srand
	std::srand(static_cast<unsigned>(time(NULL)));
	//Initialize Game Engine
	Game game;

	//Initialize Main Menu
	sf::RenderWindow Menu(sf::VideoMode(1200, 800), "Main Menu", sf::Style::Default);
	MainMenu mainmenu(Menu.getSize().x, Menu.getSize().y);

	while (Menu.isOpen())
	{
		sf::Event event1;
		while (Menu.pollEvent(event1))
		{
			if (event1.type == sf::Event::Closed)
			{
				Menu.close();
			}
			if (event1.type == sf::Event::KeyReleased)
			{
				if (event1.key.code == sf::Keyboard::Up)
				{
					mainmenu.MoveUp();
					break;
				}
				if (event1.key.code == sf::Keyboard::Down)
				{
					mainmenu.MoveDown();
					break;
				}
				if (event1.key.code == sf::Keyboard::Return)
				{

					sf::RenderWindow Highscores(sf::VideoMode(1200, 800), "Highscores");
					sf::RenderWindow About(sf::VideoMode(1200, 800), "About");

					int x = mainmenu.MainMenuPressed();
					//Actions with Play button
					if (x == 0)
					{
						game.writeReport("Player choose Play.");
						Highscores.close();
						About.close();
						Menu.close();
						//Game
						do {
							while (game.running())
							{
								//Update
								game.update();
								//Render
								game.render();
							}

							
						} while (game.playAgain);
						break;
					}
					//Action with Highscores open
					if (x == 1)
					{
						game.writeReport("Player choose Highscores.");
						while (Highscores.isOpen())
						{
							mainmenu.LoadHighscoresFromFile("wyniki.txt", Highscores);
							sf::Event event2;
							while (Highscores.pollEvent(event2))
							{
								if (event2.type == sf::Event::Closed)
								{
									Highscores.close();
								}
								if (event2.type == sf::Event::KeyPressed)
								{
									if (event2.key.code == sf::Keyboard::Escape)
									{
										Highscores.close();
									}
								}


							}
							//Play.close();
							Highscores.clear();
							About.close();

							//Highscores.display();
						}

					}
					//Actions with About open
					if (x == 2)
					{
						game.writeReport("Player choose About.");
						mainmenu.ShowAbout(Menu);
						About.close();
						while (About.isOpen())
						{
							/*
							sf::Event event2;
							while (About.pollEvent(event2))
							{
								if (event2.type == sf::Event::Closed)
								{
									About.close();

								}
								if (event2.type == sf::Event::KeyPressed)
								{
									if (event2.key.code == sf::Keyboard::Escape)
									{
										About.close();
									}

								}
							}
							*/
							Highscores.clear();
							About.clear();
							About.display();
						}
					}
					//Exiting the game
					if (x == 3)
					{
						game.writeReport("Player choose Exit.");
						Menu.close();
						break;
					}
				}
			}
		}
		Menu.clear();
		mainmenu.Render(Menu);
		Menu.display();

	}
	//GameLoop
	/*
	while (game.running())
	{
		//Update
		game.update();
		//Render
		game.render();
	}
	*/


	//End of application
	
	return 0;
}



