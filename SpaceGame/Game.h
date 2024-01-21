#pragma once
#include<sstream>
#include<iostream>
#include<vector>
#include<ctime>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>


#include "Player.h"
#include "MainMenu.h"
#include "GameOver.h"
#include "Asteroids.h"
/*
* Class that acts as the game engine.
* Wrapper class.
*/
class Game
{
private:
	//Variables
	float AsteroidSpawnTimer;
	float AsteroidSpawnTimerMax;
	int maxAsteroids;
	float AsteroidSpeed;
	int BulletSpeed;
	int points;

	int PlayerLives;
	

	sf::Font font;
	sf::Text OverText;
	sf::Text Points;
	sf::Text Lives;

	
	//Window
	sf::RenderWindow* window;
	sf::VideoMode videomode;
	sf::Event ev;

	GameOver gameOverScreen(int);

	//MainMenu mainmenu;
	//Game Objects
	Player player;
	SmallAsteroids smallasteroid;
	MediumAsteroids mediumasteroid;
	LargeAsteroids largeasteroid;
	//Asteroids asteroid1;
	//sf::Sprite Asteroid1;
	//sf::Texture Asteroid1Texture;
	std::vector<sf::Sprite> SmallAsteroidsVector;
	std::vector<sf::Sprite> MediumAsteroidsVector;
	std::vector<sf::Sprite> LargeAsteroidsVector;
	//Bullets
	sf::RectangleShape bullet;
	std::vector<sf::RectangleShape> bullets;
	//Background
	sf::Sprite Background;
	sf::Texture BackgroundTexture;

	//Private functions
	void initializeVariables();
	void initializeWindow();
	void initializeBackground();
	//void initializeAsteroid1();
	void initializeFont();
	void initializeGameOverText();
	void initializeGui();
	void initializebullet();
	

public:
	//Constructors / Destructors
	Game();
	virtual ~Game();
	//Accesors
	const bool running() const;
	//Functions
	bool playAgain;
	
	void pollEvents();
	void spawnBullet();
	void updateBullet();
	void spawnSmallAsteroids();
	void spawnMediumAsteroids();
	void spawnLargeAsteroids();
	void updateAsteroids();
	void updateCollisions();
	void updateGameOver();
	void updateGui();
	void update();
	
	void renderGui(sf::RenderTarget* target);
	void renderGameOver(sf::RenderTarget* target);
	void render();
};

