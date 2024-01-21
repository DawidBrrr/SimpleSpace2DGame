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
	//ships hitbox
	
	
	this->Hitbox.setPointCount(3);
	this->Hitbox.setRadius(15);
	this->Hitbox.setPosition(560.f, 725.f);
	//this->Hitbox.setFillColor(sf::Color::Red);
	
}

//Constructor : Hitbox(80.0f, 3)
Player::Player() : Hitbox(80.0f, 3)
{
	this->initializePlayer();
}
//Destructor
Player::~Player()
{
}

const sf::CircleShape& Player::getSprite() const
{
	return this->Hitbox;
}

void Player::updatePlayerInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		this->Ship.move(-10.f, 0.f);
		this->Hitbox.move(-10.f, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		this->Ship.move(10.f, 0.f);
		this->Hitbox.move(10.f, 0.f);
	}
}
void Player::updateWindowBoundCollisions(const sf::RenderTarget* target)
{
	//Left
	sf::FloatRect playerBounds = this->Ship.getGlobalBounds();
	if (playerBounds.left <= 0.f)
	{
		this->Ship.setPosition(0.f,playerBounds.top);
		this->Hitbox.setPosition(this->Ship.getPosition().x+10,this->Ship.getPosition().y+22);
	}
	//Right
	else if (playerBounds.left + playerBounds.width >= target->getSize().x)
	{
		this->Ship.setPosition(target->getSize().x - playerBounds.width, playerBounds.top);
		this->Hitbox.setPosition(this->Ship.getPosition().x+10, this->Ship.getPosition().y + 22);
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
	//uncomment for hitbox testing
	//target->draw(this->Hitbox);
}
