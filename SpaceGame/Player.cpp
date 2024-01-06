#include "Player.h"



//Private functions
void Player::initializePlayer()
{
	if (!this->ShipTexture.loadFromFile("Assets/Ship01.png"))
	{
		std::cout << "Could not load a file from assets folder" << std::endl;

	}
	this->Ship.setTexture(this->ShipTexture);

	this->Ship.setPosition(550.f, 700.f);
	this->Ship.setScale(sf::Vector2f(0.05f, 0.05f));
	
}

//Constructor
Player::Player()
{
	this->initializePlayer();
}
//Destructor
Player::~Player()
{
}

const sf::Sprite& Player::getSprite() const
{
	return this->Ship;
}

void Player::updatePlayerInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		this->Ship.move(-10.f, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		this->Ship.move(10.f, 0.f);
	}
}
void Player::updateWindowBoundCollisions(const sf::RenderTarget* target)
{
	//Left
	sf::FloatRect playerBounds = this->Ship.getGlobalBounds();
	if (playerBounds.left <= 0.f)
	{
		this->Ship.setPosition(0.f,playerBounds.top);
	}
	//Right
	else if (playerBounds.left + playerBounds.width >= target->getSize().x)
	{
		this->Ship.setPosition(target->getSize().x - playerBounds.width, playerBounds.top);
	}

}
void Player::updatePlayer(const sf::RenderTarget* target)
{
	//keyboard movement
	this->updatePlayerInput();
	//Window bounds collision
	this->updateWindowBoundCollisions(target);
	
	
}

void Player::renderPlayer(sf::RenderTarget* target)
{
	target->draw(this->Ship);
}
