#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include <vector>

#define Max_main_menu 4
#define Max_highscores 10

class MainMenu
{
private:
    int MainMenuSelected;
    sf::Font font;
    sf::Text mainMenu[Max_main_menu];
    sf::Text highscoresText[Max_highscores];

    bool aboutOpen;
    sf::RenderWindow* aboutWindow;

public:
    MainMenu(float height, float width);

    void MoveUp();
    void MoveDown();
    void Render(sf::RenderWindow& window);
    void LoadHighscoresFromFile(const std::string& filename, sf::RenderWindow& window);

    void ShowAbout(sf::RenderWindow& window);

    int MainMenuPressed() {
        return MainMenuSelected;
    }

    virtual ~MainMenu();
};