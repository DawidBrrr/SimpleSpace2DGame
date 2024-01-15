#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>


#define Max_main_menu 4
class MainMenu
{
private:
	int MainMenuSelected;
	sf::Font font;
	sf::Text mainMenu[Max_main_menu];


public:
	MainMenu(float height, float width);

	
	void MoveUp();
	void MoveDown();
	
	void Render(sf::RenderWindow& window);

	int MainMenuPressed() {
		return MainMenuSelected;
	}
	virtual ~MainMenu();
};

