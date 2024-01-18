#include "GameOver.h"

void GameOver::initializeFont()
{
    if (!this->font.loadFromFile("Assets/ariblk.ttf"))
    {
        std::cerr << "Could not load font file." << std::endl;
    }
}

void GameOver::initializeGameOverText()
{
    this->gameOverText.setFont(this->font);
    this->gameOverText.setFillColor(sf::Color::Red);
    this->gameOverText.setCharacterSize(112);
    this->gameOverText.setString("Game Over");
    this->gameOverText.setPosition(250, 0);
}

void GameOver::initializeScoreText()
{
    this->scoreText.setFont(this->font);
    this->scoreText.setFillColor(sf::Color::White);
    this->scoreText.setCharacterSize(35);

}

void GameOver::initializeEnterNameText()
{
    this->enterNameText.setFont(this->font);
    this->enterNameText.setFillColor(sf::Color::White);
    this->enterNameText.setCharacterSize(35);
    this->enterNameText.setString("Enter your name:");
    this->enterNameText.setPosition(250, 250);
}

void GameOver::initializePlayerNameText()
{
    this->playerNameText.setFont(this->font);
    this->playerNameText.setFillColor(sf::Color::White);
    this->playerNameText.setCharacterSize(35);
}

GameOver::GameOver(int score)
{
    this->score = score;
    this->playAgainPressed = false;
    this->initializeFont();
    this->initializeGameOverText();
    this->initializeScoreText();
    this->initializeEnterNameText();
    this->initializePlayerNameText();
}

GameOver::~GameOver()
{
}

void GameOver::update(sf::RenderWindow* window)
{
    this->updatePlayerNameInput(window);


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
    {

        this->saveToFile("wyniki.txt");
    }


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
    {
        this->playAgainPressed = true;
    }
}

void GameOver::render(sf::RenderTarget* target)
{
    target->draw(this->gameOverText);

    std::stringstream ss;
    ss << "Score: " << this->score;
    this->scoreText.setString(ss.str());
    this->scoreText.setPosition(250, 150);
    target->draw(this->scoreText);

    target->draw(this->enterNameText);
    this->renderPlayerNameInput(target);
}

bool GameOver::isPlayAgainPressed() const
{
    return this->playAgainPressed;
}
/*
bool GameOver::running()
{
    return true;
}
*/
void GameOver::saveToFile(const std::string& filename)
{
    std::ofstream file(filename, std::ios::app);

    if (file.is_open())
    {
        file << this->playerName << ": " << this->score << std::endl;
        file.close();
    }
    else
    {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}

void GameOver::updatePlayerNameInput(sf::RenderWindow* window)
{
    sf::Event event;
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::TextEntered)
        {
            if (event.text.unicode < 128)
            {
                if (event.text.unicode == 8 && !this->playerName.empty())
                {
                    // Backspace pressed, remove last character
                    this->playerName.pop_back();
                }
                else if (event.text.unicode != 8)
                {
                    // Add character to the player name
                    this->playerName += static_cast<char>(event.text.unicode);
                }

                // Update player name text
                this->playerNameText.setString(this->playerName);
            }
        }
    }
}

void GameOver::renderPlayerNameInput(sf::RenderTarget* target)
{
    this->playerNameText.setPosition(250, 300);
    target->draw(this->playerNameText);
}