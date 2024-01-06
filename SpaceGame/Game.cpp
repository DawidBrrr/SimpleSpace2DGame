
#include "Game.h"

//Private functions
void Game::initializeVariables()
{
	this->window = nullptr;
	this->AsteroidSpawnTimerMax = 100.f;
	this->AsteroidSpawnTimer = this->AsteroidSpawnTimerMax;
	this->maxAsteroids = 30;
	this->AsteroidSpeed = 3;
	this->BulletSpeed = 10;
	this->points = 0;
	

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
	
}
void Game::initializebullet()
{
	this->bullet.setSize(sf::Vector2f(2.f, 6.f));
	this->bullet.setFillColor(sf::Color::Red);
	
}
//Constructors / Destructors
Game::Game()
{
	this->initializeVariables();
	this->initializeWindow();
	this->initializeBackground();
	this->initializeAsteroid1();
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
	this->bullet.setPosition(player.getSprite().getPosition().x+23, player.getSprite().getPosition().y);

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



void Game::spawnAsteroids()
{
	/*
	* @return void
	*
	* Spawns asteroids and sets their positions,
	* -sets a random position
	* -adds asteroids to the vector
	*/
	this->Asteroid1.setPosition(
		static_cast<float>(rand() % static_cast<int>(1200)),
		-80.f
	);

	//Spawn Asteroid
	this->Asteroids1.push_back(this->Asteroid1);

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
	if (this->Asteroids1.size() < this->maxAsteroids)
	{
		if (this->AsteroidSpawnTimer >= this->AsteroidSpawnTimerMax)
		{
			//Spawn asteroid and reset the timer
			this->spawnAsteroids();
			this->AsteroidSpawnTimer = 0.f;
			
		}
		else
		{
			this->AsteroidSpawnTimer += 1;
			this->AsteroidSpawnTimerMax -= 0.05;
		}
	}

	//Move asteroids
	for (int i = 0; i < this->Asteroids1.size(); i++)
	{
		bool deleted = false;
		this->Asteroids1[i].move(0.f, this->AsteroidSpeed);
		//Asteroid below screen remove it
		//this->window->getSize().y
		if (this->Asteroids1[i].getPosition().y > 800)
		{
			deleted = true;
		}
		//Final delete
		if (deleted) {
			this->Asteroids1.erase(this->Asteroids1.begin() + i);
			
		}
	}

}
//Colisions
void Game::updateCollisions()
{
	for (size_t i = 0; i < this->Asteroids1.size(); i++)
	{
		if (this->player.getSprite().getGlobalBounds().intersects(this->Asteroids1[i].getGlobalBounds()))
		{
			this->Asteroids1.erase(this->Asteroids1.begin() + i);
			this->updateGameOver();
			this->AsteroidSpeed = 0;
		}
	}
	for (size_t j = 0; j < this->bullets.size(); j++)
	{
		for (size_t k = 0; k < this->Asteroids1.size(); k++)
		{
			if (this->bullets[j].getGlobalBounds().intersects(this->Asteroids1[k].getGlobalBounds()))
			{
				this->Asteroids1.erase(this->Asteroids1.begin() + k);
				points += 1;
			}
		}
	}

}
void Game::updateGameOver()
{
	
	this->OverText.setString("Game Over");
}
void Game::updateGui()
{
	std::stringstream ss;

	ss << "Points: " << this->points;

	this->Points.setString(ss.str());

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

	for (auto Ast : this->Asteroids1)
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

