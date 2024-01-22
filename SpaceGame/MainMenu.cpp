#include "MainMenu.h"
#include <fstream>
#include <sstream>
#include <algorithm>

MainMenu::MainMenu(float height, float width)
{
    if (!font.loadFromFile("Assets/ariblk.ttf")) {
        std::cout << "Could not load a font" << std::endl;
    }

    mainMenu[0].setFont(font);
    mainMenu[0].setFillColor(sf::Color::White);
    mainMenu[0].setString("Play");
    mainMenu[0].setCharacterSize(70);
    mainMenu[0].setPosition(400, 200);

    mainMenu[1].setFont(font);
    mainMenu[1].setFillColor(sf::Color::White);
    mainMenu[1].setString("Highscores");
    mainMenu[1].setCharacterSize(70);
    mainMenu[1].setPosition(400, 300);

    mainMenu[2].setFont(font);
    mainMenu[2].setFillColor(sf::Color::White);
    mainMenu[2].setString("About");
    mainMenu[2].setCharacterSize(70);
    mainMenu[2].setPosition(400, 400);

    mainMenu[3].setFont(font);
    mainMenu[3].setFillColor(sf::Color::White);
    mainMenu[3].setString("Exit");
    mainMenu[3].setCharacterSize(70);
    mainMenu[3].setPosition(400, 500);

    MainMenuSelected = -1;
}

void MainMenu::Render(sf::RenderWindow& window)
{
    for (int i = 0; i < Max_main_menu; i++)
    {
        window.draw(mainMenu[i]);
    }
}

void MainMenu::MoveUp()
{
    if (MainMenuSelected - 1 >= 0)
    {
        mainMenu[MainMenuSelected].setFillColor(sf::Color::White);
        MainMenuSelected--;
        if (MainMenuSelected == -1)
        {
            MainMenuSelected = 2;
        }
        mainMenu[MainMenuSelected].setFillColor(sf::Color::Red);
    }
}

void MainMenu::MoveDown()
{
    if (MainMenuSelected + 1 <= Max_main_menu)
    {
        mainMenu[MainMenuSelected].setFillColor(sf::Color::White);
        MainMenuSelected++;
        if (MainMenuSelected == 4)
        {
            MainMenuSelected = 0;
        }
        mainMenu[MainMenuSelected].setFillColor(sf::Color::Red);
    }
}

void MainMenu::LoadHighscoresFromFile(const std::string& filename, sf::RenderWindow& window)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cout << "Could not open the file: " << filename << std::endl;
        return;
    }

    std::vector<std::pair<std::string, int>> players;

    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string playerName;
        int playerScore;

        if (iss >> playerName >> playerScore)
        {
            players.push_back(std::make_pair(playerName, playerScore));
        }
    }

    file.close();

    std::sort(players.begin(), players.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
        });

    for (int i = 0; i < Max_highscores && i < players.size(); i++)
    {
        std::string playerInfo = std::to_string(i+1) + ". " + players[i].first + ": " + std::to_string(players[i].second);
        this->highscoresText[i].setFont(font);
        this->highscoresText[i].setFillColor(sf::Color::White);
        this->highscoresText[i].setCharacterSize(60);
        this->highscoresText[i].setString(playerInfo);
        this->highscoresText[i].setPosition(200, 100 + i * 70);
        window.draw(this->highscoresText[i]);

    }
    window.display();
}

void MainMenu::ShowAbout(sf::RenderWindow& window)
{
    sf::Font aboutFont;
    if (!aboutFont.loadFromFile("Assets/ariblk.ttf")) {
        std::cout << "Could not load a font" << std::endl;
        return;
    }

    sf::Text authorsText;
    authorsText.setFont(aboutFont);
    authorsText.setFillColor(sf::Color::White);
    authorsText.setString("Authors:\n \nDawid Brach\nKrystian Cieloch");
    authorsText.setCharacterSize(45);
    authorsText.setPosition(400, 75);

    sf::Text returnText;
    returnText.setFont(aboutFont);
    returnText.setFillColor(sf::Color::White);
    returnText.setString("Press 'Escape' to return");
    returnText.setCharacterSize(30);
    returnText.setPosition(200, 650);

    aboutOpen = true;
    aboutWindow = new sf::RenderWindow(sf::VideoMode(1200, 800), "About");

    while (aboutOpen && aboutWindow->isOpen())
    {
        sf::Event event;
        while (aboutWindow->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                aboutWindow->close();
                aboutOpen = false;
            }
            else if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                {
                    aboutWindow->close();
                    aboutOpen = false;
                }
            }
        }

        aboutWindow->clear();
        aboutWindow->draw(authorsText);
        aboutWindow->draw(returnText);
        aboutWindow->display();
    }

    delete aboutWindow;
}

MainMenu::~MainMenu()
{

}
