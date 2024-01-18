#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <fstream>
#include <sstream>

class GameOver
{
private:
    sf::Font font;
    sf::Text gameOverText;
    sf::Text scoreText;
    sf::Text enterNameText;
    sf::Text playerNameText;
    std::string playerName;
    int score;
    bool playAgainPressed;

    void initializeFont();
    void initializeGameOverText();
    void initializeScoreText();
    void initializeEnterNameText();
    void initializePlayerNameText();

    void updatePlayerNameInput(sf::RenderWindow* window);
    void renderPlayerNameInput(sf::RenderTarget* target);

public:
    GameOver(int score);
    virtual ~GameOver();

    void update(sf::RenderWindow* window);
    void render(sf::RenderTarget* target);
    bool isPlayAgainPressed() const;
    //bool running();

    void saveToFile(const std::string& filename);
};