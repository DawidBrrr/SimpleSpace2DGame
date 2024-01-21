#include "Asteroids.h"
//Main Class
Asteroids::Asteroids()
{
	this->AsteroidSprite.setPosition(100.f, 100.f);
	this->AsteroidSpeed = 3;
}

sf::Sprite& Asteroids::getSprite()
{
	return this->AsteroidSprite;
}
float Asteroids::getSpeed(float x) 
{
	return this->AsteroidSpeed*x;
}

void Asteroids::AsteroidSpeedIncrease()
{
	this->AsteroidSpeed += 0.005;
}

//SmallAsteroids

void SmallAsteroids::initializeSmallAsteroids()
{
	if (!this->AsteroidTexture.loadFromFile("Assets/asteroid1.png"))
	{
		std::cout << "Could not load a file from assets folder" << std::endl;

	}
	this->AsteroidSprite.setTexture(this->AsteroidTexture);
	this->AsteroidSprite.setScale(sf::Vector2f(0.05f, 0.05f));

}

SmallAsteroids::SmallAsteroids() : Asteroids()
{
	this->initializeSmallAsteroids();
}
float SmallAsteroids::getSpeed(float x) 
{
	return AsteroidSpeed*x;
}
//Medium Asteroids
void MediumAsteroids::initializeMediumAsteroids()
{
	if (!this->AsteroidTexture.loadFromFile("Assets/asteroid1.png"))
	{
		std::cout << "Could not load a file from assets folder" << std::endl;

	}
	this->AsteroidSprite.setTexture(this->AsteroidTexture);
	this->AsteroidSprite.setScale(sf::Vector2f(0.1f, 0.1f));

}

MediumAsteroids::MediumAsteroids() : Asteroids()
{
	this->initializeMediumAsteroids();
}
float MediumAsteroids::getSpeed(float x) 
{
	return AsteroidSpeed*x;
}
//Large Asteroids
void LargeAsteroids::initializeLargeAsteroids()
{
	if (!this->AsteroidTexture.loadFromFile("Assets/asteroid1.png"))
	{
		std::cout << "Could not load a file from assets folder" << std::endl;

	}
	this->AsteroidSprite.setTexture(this->AsteroidTexture);
	this->AsteroidSprite.setScale(sf::Vector2f(0.3f, 0.3f));
}

LargeAsteroids::LargeAsteroids() : Asteroids()
{
	this->initializeLargeAsteroids();
}

float LargeAsteroids::getSpeed(float x) 
{
	return AsteroidSpeed*x;
}
