#include "Asteroids.h"

//Private function
/*
void Asteroids::initializeAsteroid1()
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
//GameLogic
/*
void Asteroids::initializeVariables() {
	this->AsteroidSpawnTimerMax = 100.f;
	this->AsteroidSpawnTimer = this->AsteroidSpawnTimerMax;
	this->maxAsteroids = 10;
	this->Speed = 3;
	
}
*/
//Constructor
/*
Asteroids::Asteroids()
{
	this->initializeAsteroid1();
	
}
//Destructor
Asteroids::~Asteroids()
{
}
//functions


/*
const sf::Sprite& Asteroids::getSprite() const
{
	return this->Asteroid1;
}

const std::vector<sf::Sprite>& Asteroids::getVector() const
{
	return this->Asteroids1;
}


void Asteroids::SpawnAsteroids()
{
	/*
	* @return void
	*
	* Spawns asteroids and sets their positions,
	* -sets a random position
	* -adds asteroids to the vector
	
	this->Asteroid1.setPosition(
		static_cast<float>(rand() % static_cast<int>(1200)),
		-80.f
	);

	//Spawn Asteroid
	this->Asteroids1.push_back(this->Asteroid1);

	//Remove Asteroids at end of the screen
}

void Asteroids::updateAsteroids(const sf::RenderTarget* target)
{
	/**
	* @return void
	*
	* Updates asteroid spawn timer and spawns Asteroids\
	* when total amount is smaller than maximum
	* moves asteroid downwards
	* remove asteroids at edge of the screen
	
	// updating the timer for spawning asteroids
	if (this->Asteroids1.size() < this->maxAsteroids)
	{
		if (this->AsteroidSpawnTimer >= this->AsteroidSpawnTimerMax)
		{
			//Spawn asteroid and reset the timer
			this->SpawnAsteroids();
			this->AsteroidSpawnTimer = 0.f;
		}
		else
			this->AsteroidSpawnTimer += 1.f;
	}

	//Move asteroids
	for (int i = 0; i < this->Asteroids1.size(); i++)
	{
		bool deleted = false;
		this->Asteroids1[i].move(0.f, this->Speed);
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
void Asteroids::renderAsteroids(sf::RenderTarget* target)
{
	//rendering asteroids
	for (auto& Ast : this->Asteroids1)
	{
		target->draw(Ast);
	}
}
*/