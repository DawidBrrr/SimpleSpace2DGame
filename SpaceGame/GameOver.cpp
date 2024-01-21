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
    this->allowInput = true;
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


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        this->playAgainPressed = true;
        window->clear();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        window->close();
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

    sf::Text playAgainText;
    playAgainText.setFont(this->font);
    playAgainText.setFillColor(sf::Color::White);
    playAgainText.setCharacterSize(30);
    playAgainText.setString("Press Space to play again");
    playAgainText.setPosition(250, 430);
    target->draw(playAgainText);

    sf::Text exitText;
    exitText.setFont(this->font);
    exitText.setFillColor(sf::Color::White);
    exitText.setCharacterSize(30);
    exitText.setString("Press Esc to exit");
    exitText.setPosition(250, 460);
    target->draw(exitText);

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
        file << this->playerName << " " << this->score << std::endl;
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
        if (event.type == sf::Event::TextEntered && this->allowInput)
        {
            if (event.text.unicode < 128)
            {
                if (event.text.unicode == 8 && !this->playerName.empty())
                {
                    // Backspace pressed, remove last character
                    this->playerName.erase(this->playerName.size() - 1);
                    
                }
                else if (event.text.unicode != 8)
                {
                    // Add character to the player name
                    this->playerName += static_cast<char>(event.text.unicode);
                }
                if (event.text.unicode == 13)
                {
                    this->saveToFile("wyniki.txt");
                    this->playerName.append(" :has been entered");
                    this->playerNameText.setString(this->playerName);
                    this->allowInput = false;
                    
                }
                
                // Update player name text
                //this->playerNameText.setString(this->playerName);
                
            }
        }
    }
}

void GameOver::renderPlayerNameInput(sf::RenderTarget* target)
{
    
    this->playerNameText.setString(this->playerName);
    this->playerNameText.setPosition(250, 300);
    target->draw(this->playerNameText);
}