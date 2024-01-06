#pragma once
#include<iostream>
#include<vector>
#include<ctime>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>



class Player 
{
private:
	//Variables
	
	
	//Player objects
	sf::Sprite Ship;
	sf::Texture ShipTexture;
	//functions
	void initializePlayer();
public:
	//Constructor and destructor
	Player();
	virtual ~Player();
	//functions
	const sf::Sprite& getSprite() const;
	void updatePlayerInput();
	void updateWindowBoundCollisions(const sf::RenderTarget* target);
	void updatePlayer(const sf::RenderTarget* target);
	void renderPlayer(sf::RenderTarget* target);
};

