#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/WIndow.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

class HitBox : public sf::Sprite
{
private:
	//Variables
	sf::FloatRect m_hitbox;
public:
	//functions
	void setHitbox(const sf::FloatRect& hitbox);
	//hitbox
	sf::FloatRect getGlobalHitbox() const;
};

