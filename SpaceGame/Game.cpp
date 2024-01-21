
#include "Game.h"



//Private functions
void Game::initializeVariables()
{
	this->window = nullptr;
	this->AsteroidSpawnTimerMax = 200.f;
	this->AsteroidSpawnTimer = this->AsteroidSpawnTimerMax;
	this->maxAsteroids = 10;
	//this->AsteroidSpeed = 3;
	this->BulletSpeed = 10;
	this->points = 0;
	this->PlayerLives = 3;
	
	this->playAgain = false;
	

}

void Game::initializeWindow()
{
	this->videomode.height = 800;
	this->videomode.width = 1200;

	this->window = new sf::RenderWindow(this->videomode, "SpaceGame", sf::Style::Titlebar | sf::Style::Close);
	this->window->setView(sf::View(sf::FloatRect(0.0f, 0.0f, 1200.0f, 800.0f)));
	this->window->setFramerateLimit(60);
}
void Game::initializeBackground()
{
	if (!this->BackgroundTexture.loadFromFile("Assets/Background.png"))
	{
		std::cout << "Could not load a file from assets folder" << std::endl;

	}
	this->Background.setTexture(this->BackgroundTexture);

	this->Background.setPosition(0.f, 0.f);
	//this->PlanetCornerBackground.setScale(sf::Vector2f(0.1f, 0.1f));
}
void Game::initializeFont()
{
	if (!this->font.loadFromFile("Assets/ariblk.ttf"))
	{
		std::cout << "Couldnt load a font" << std::endl;
	}
}
void Game::initializeGameOverText()
{
	this->OverText.setFont(this->font);
	this->OverText.setFillColor(sf::Color::Red);
	this->OverText.setCharacterSize(112);
	this->OverText.setString("");
	this->OverText.setPosition(250,0);
}
void Game::initializeGui()
{
	this->Points.setFont(this->font);
	this->Points.setFillColor(sf::Color::White);
	this->Points.setCharacterSize(35);

	this->Lives.setFont(this->font);
	this->Lives.setFillColor(sf::Color::White);
	this->Lives.setCharacterSize(35);
	this->Lives.setPosition(0,50);
	
}
void Game::initializebullet()
{
	this->bullet.setSize(sf::Vector2f(3.f, 8.f));
	this->bullet.setFillColor(sf::Color::Red);
	
}
//Constructors / Destructors
Game::Game()
{
	this->initializeVariables();
	this->initializeWindow();
	this->initializeBackground();
	//this->initializeAsteroid1();
	this->initializeFont();
	this->initializeGameOverText();
	this->initializebullet();
	this->initializeGui();

	

}
Game::~Game()
{
	delete this->window;
}
//Accesors
const bool Game::running() const
{
	return this->window->isOpen();
}
//functions

void Game::pollEvents()
{
	//Event polling
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
			case sf::Event::Closed:
				this->window->close();
				break;
			case::sf::Event::KeyPressed:
				if (this->ev.key.code == sf::Keyboard::Escape)
					this->window->close();
				break;
				//spawnd bullets
			case sf::Event::KeyReleased:
				if (this->ev.key.code == sf::Keyboard::Space) {
					this->spawnBullet();
				}
				break;

		}
	}
}
void Game::spawnBullet()
{
	this->bullet.setPosition(player.getSprite().getPosition().x+13, player.getSprite().getPosition().y);

	//Spawn Asteroid
	this->bullets.push_back(this->bullet);
}
//Initializang Asteroid
void Game::updateBullet()
{
	//move bullets
	for (int i = 0; i < this->bullets.size(); i++)
	{
		bool deletedb = false;
		this->bullets[i].move(0.f, -this->BulletSpeed);
		if (this->bullets[i].getPosition().y < 0)
		{
			deletedb = true;
		}
		if (deletedb)
		{
			this->bullets.erase(this->bullets.begin() + i);
		}
	}
	
}
/*
void Game::initializeAsteroid1()
{

	if (!this->Asteroid1Texture.loadFromFile("Assets/asteroid1.png"))
	{
		std::cout << "Could not load a file from assets folder" << std::endl;

	}
	this->Asteroid1.setTexture(this->Asteroid1Texture);

	this->Asteroid1.setPosition(100.f, 100.f);
	this->Asteroid1.setScale(sf::Vector2f(0.1f, 0.1f));

}
*/


void Game::spawnSmallAsteroids()
{
	/*
	* @return void
	*
	* Spawns asteroids and sets their positions,
	* -sets a random position
	* -adds asteroids to the vector
	*/
	this->smallasteroid.getSprite().setPosition(
		static_cast<float>(rand() % static_cast<int>(1200)),
		-200.f
	);
	

	//Spawn Asteroid
	this->SmallAsteroidsVector.push_back(this->smallasteroid.getSprite());
	

	//Remove Asteroids at end of the screen
}
void Game::spawnMediumAsteroids()
{
	/*
	* @return void
	*
	* Spawns asteroids and sets their positions,
	* -sets a random position
	* -adds asteroids to the vector
	*/
	
	this->mediumasteroid.getSprite().setPosition(
		static_cast<float>(rand() % static_cast<int>(1200)),
		-200.f);
	

	//Spawn Asteroid
	
	this->MediumAsteroidsVector.push_back(this->mediumasteroid.getSprite());
	

	//Remove Asteroids at end of the screen
}
void Game::spawnLargeAsteroids()
{
	/*
	* @return void
	*
	* Spawns asteroids and sets their positions,
	* -sets a random position
	* -adds asteroids to the vector
	*/
	
	this->largeasteroid.getSprite().setPosition(
		static_cast<float>(rand() % static_cast<int>(1200)),
		-200.f
	);

	//Spawn Asteroid
	
	this->LargeAsteroidsVector.push_back(this->largeasteroid.getSprite());

	//Remove Asteroids at end of the screen
}
void Game::updateAsteroids()
{
	/**
	* @return void
	*
	* Updates asteroid spawn timer and spawns Asteroids\
	* when total amount is smaller than maximum
	* moves asteroid downwards
	* remove asteroids at edge of the screen
	*/
	// updating the timer for spawning asteroids
	if (this->SmallAsteroidsVector.size() < this->maxAsteroids)
	{
		if (this->AsteroidSpawnTimer >= this->AsteroidSpawnTimerMax)
		{
			//Spawn asteroid and reset the timer
			this->spawnSmallAsteroids();
			this->AsteroidSpawnTimer = 0.f;
			this->smallasteroid.AsteroidSpeedIncrease();
		}
		else
		{
			this->AsteroidSpawnTimer += 1;
			this->AsteroidSpawnTimerMax -= 0.05;
		}
	}
	if (this->MediumAsteroidsVector.size() < this->maxAsteroids)
	{
		if (this->AsteroidSpawnTimer >= this->AsteroidSpawnTimerMax)
		{
			//Spawn asteroid and reset the timer
			this->spawnMediumAsteroids();
			this->AsteroidSpawnTimer = 0.f;
			this->mediumasteroid.AsteroidSpeedIncrease();
		}
		else
		{
			this->AsteroidSpawnTimer += 1;
			this->AsteroidSpawnTimerMax -= 0.05;
		}
	}
	if (this->LargeAsteroidsVector.size() < this->maxAsteroids-5)
	{
		if (this->AsteroidSpawnTimer >= this->AsteroidSpawnTimerMax)
		{
			//Spawn asteroid and reset the timer
			this->spawnLargeAsteroids();
			this->AsteroidSpawnTimer = 0.f;
			this->largeasteroid.AsteroidSpeedIncrease();
		}
		else
		{
			this->AsteroidSpawnTimer += 1;
			this->AsteroidSpawnTimerMax -= 0.05;
		}
	}

	//Move asteroids
	for (int i = 0; i < this->SmallAsteroidsVector.size(); i++)
	{
		bool deleted = false;
		this->SmallAsteroidsVector[i].move(0.f, smallasteroid.getSpeed(2));
		//Asteroid below screen remove it
		//this->window->getSize().y
		if (this->SmallAsteroidsVector[i].getPosition().y > 800)
		{
			deleted = true;
		}
		//Final delete
		if (deleted) {
			this->SmallAsteroidsVector.erase(this->SmallAsteroidsVector.begin() + i);
			
		}
	}
	for (int i = 0; i < this->MediumAsteroidsVector.size(); i++)
	{
		bool deleted = false;
		this->MediumAsteroidsVector[i].move(0.f, mediumasteroid.getSpeed(1));
		//Asteroid below screen remove it
		//this->window->getSize().y
		if (this->MediumAsteroidsVector[i].getPosition().y > 800)
		{
			deleted = true;
		}
		//Final delete
		if (deleted) {
			this->MediumAsteroidsVector.erase(this->MediumAsteroidsVector.begin() + i);

		}
	}
	for (int i = 0; i < this->LargeAsteroidsVector.size(); i++)
	{
		bool deleted = false;
		this->LargeAsteroidsVector[i].move(0.f, mediumasteroid.getSpeed(0.5));
		//Asteroid below screen remove it
		//this->window->getSize().y
		if (this->LargeAsteroidsVector[i].getPosition().y > 800)
		{
			deleted = true;
		}
		//Final delete
		if (deleted) {
			this->LargeAsteroidsVector.erase(this->LargeAsteroidsVector.begin() + i);

		}
	}


}
//Colisions
void Game::updateCollisions()
{
	for (size_t i = 0; i < this->SmallAsteroidsVector.size(); i++)
	{
		if (this->player.getSprite().getGlobalBounds().intersects(this->SmallAsteroidsVector[i].getGlobalBounds()))
		{
			this->SmallAsteroidsVector.erase(this->SmallAsteroidsVector.begin() + i);
			this->PlayerLives--;
			//this->updateGameOver();
			//this->AsteroidSpeed = -0.05;
			
		}
		if (this->PlayerLives == 0)
		{
			//this->updateGameOver();
			this->AsteroidSpeed = -0.05;
		}
	}
	for (size_t i = 0; i < this->MediumAsteroidsVector.size(); i++)
	{
		if (this->player.getSprite().getGlobalBounds().intersects(this->MediumAsteroidsVector[i].getGlobalBounds()))
		{
			this->MediumAsteroidsVector.erase(this->MediumAsteroidsVector.begin() + i);
			this->PlayerLives--;
			//this->updateGameOver();
			//this->AsteroidSpeed = -0.05;

		}
		if (this->PlayerLives == 0)
		{
			//this->updateGameOver();
			this->AsteroidSpeed = -0.05;
		}
	}
	for (size_t i = 0; i < this->LargeAsteroidsVector.size(); i++)
	{
		if (this->player.getSprite().getGlobalBounds().intersects(this->LargeAsteroidsVector[i].getGlobalBounds()))
		{
			this->LargeAsteroidsVector.erase(this->LargeAsteroidsVector.begin() + i);
			this->PlayerLives--;
			//this->updateGameOver();
			//this->AsteroidSpeed = -0.05;

		}
		if (this->PlayerLives == 0)
		{
			//this->updateGameOver();
			this->AsteroidSpeed = -0.05;
		}
	}
	//Bullets collisions
	for (size_t j = 0; j < this->bullets.size(); j++)
	{
		for (size_t k = 0; k < this->SmallAsteroidsVector.size(); k++)
		{
			if (this->bullets[j].getGlobalBounds().intersects(this->SmallAsteroidsVector[k].getGlobalBounds()))
			{
				this->SmallAsteroidsVector.erase(this->SmallAsteroidsVector.begin() + k);
				points += 1;
			}
		}
	}
	for (size_t j = 0; j < this->bullets.size(); j++)
	{
		for (size_t k = 0; k < this->MediumAsteroidsVector.size(); k++)
		{
			if (this->bullets[j].getGlobalBounds().intersects(this->MediumAsteroidsVector[k].getGlobalBounds()))
			{
				this->MediumAsteroidsVector.erase(this->MediumAsteroidsVector.begin() + k);
				points += 1;
			}
		}
	}
	for (size_t j = 0; j < this->bullets.size(); j++)
	{
		for (size_t k = 0; k < this->LargeAsteroidsVector.size(); k++)
		{
			if (this->bullets[j].getGlobalBounds().intersects(this->LargeAsteroidsVector[k].getGlobalBounds()))
			{
				this->LargeAsteroidsVector.erase(this->LargeAsteroidsVector.begin() + k);
				points += 1;
			}
		}
	}


	if (this->PlayerLives == 0)
	{

		GameOver gameOverScreen(this->points);

		//while (gameOverScreen.running(this->window) && this->window->isOpen())
		while (this->window->isOpen() && this->playAgain == false)
		{
			this->window->clear();
			gameOverScreen.update(this->window);
			gameOverScreen.render(this->window);
			this->playAgain = gameOverScreen.isPlayAgainPressed();
			

			
			this->window->display();
		}
		this->PlayerLives += 3;
		this->playAgain = false;
	}

}
void Game::updateGameOver()
{
	
	this->OverText.setString("Game Over");
}
void Game::updateGui()
{
	std::stringstream ss;
	std::stringstream ss2;

	ss << "Points: " << this->points;

	this->Points.setString(ss.str());

	ss2 << "Lives " << this->PlayerLives;
	this->Lives.setString(ss2.str());

}

void Game::update()
{
	this->pollEvents();

	
	
	this->player.updatePlayer(this->window);

	this->updateAsteroids();

	this->updateBullet();

	this->updateCollisions();

	this->updateGui();
	

}
void Game::renderGameOver(sf::RenderTarget* target)
{
	target->draw(this->OverText);
}
void Game::renderGui(sf::RenderTarget* target)
{
	target->draw(this->Points);
	target->draw(this->Lives);
}


void Game::render()
{
	/*
	* @return void
	* -clear old frame
	* -redner objects
	* -display frame in the window
	* Renders the game objects
	*/
	this->window->clear();

	//Draw game objects
	this->window->draw(this->Background);

	for (auto Ast : this->SmallAsteroidsVector)
	{
		this->window->draw(Ast);
		
	}
	for (auto Ast : this->MediumAsteroidsVector)
	{
		this->window->draw(Ast);

	}
	for (auto Ast : this->LargeAsteroidsVector)
	{
		this->window->draw(Ast);

	}
	for (auto Bul : this->bullets)
	{
		this->window->draw(Bul);
	}
	
	this->player.renderPlayer(this->window);
	//render gui
	this->renderGameOver(this->window);
	this->renderGui(this->window);

	this->window->display();
}

