#pragma once

#include<iostream>
#include<vector>
#include<ctime>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>


class Asteroids
{
protected:
	//Variables
	sf::Texture AsteroidTexture;
	sf::Sprite AsteroidSprite;
	int AsteroidSpeed;

	//Private Functions


public:
	//Konstruktor
	Asteroids();
	
	
	//Destruktor
	virtual ~Asteroids() = default;

	//Funkcje
	sf::Sprite& getSprite();
	virtual float getSpeed(float x) = 0;
	void AsteroidSpeedIncrease();
	//void initializeAsteroids();

};

class SmallAsteroids : public Asteroids
{
private:
	void initializeSmallAsteroids();

public:
	SmallAsteroids();
	~SmallAsteroids() = default;

	float getSpeed(float x) override;


};
class MediumAsteroids : public Asteroids
{
private:
	void initializeMediumAsteroids();

public:
	MediumAsteroids();
	~MediumAsteroids() = default;

	float getSpeed(float x) override;

};
class LargeAsteroids : public Asteroids
{
private:
	void initializeLargeAsteroids();
public:
	LargeAsteroids();
	~LargeAsteroids() = default;

	float getSpeed(float x) override;

};