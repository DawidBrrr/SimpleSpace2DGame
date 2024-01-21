Dodac w pliku Game.h

private:
    std::ofstream reportFile;

    void openReportFile();
    void closeReportFile();
    void writeReport(const std::string& action);

Dodac w pliku game.cpp

void Game::openReportFile()
{
    this->reportFile.open("raport.txt");
}

void Game::closeReportFile()
{
    if (this->reportFile.is_open())
    {
        this->reportFile.close();
    }
}

void Game::writeReport(const std::string& action)
{
    if (this->reportFile.is_open())
    {
        this->reportFile << action << std::endl;
    }
}


Dodac do konstruktora w pliku Game.cpp

this->openReportFile();

Dodac do destruktora w pliku Game.cpp

this->closeReportFile();


Game.cpp

Wiersz 135	this->writeReport("Player shot a bullet.");

Wiersz 250	this->writeReport("Player lost a life.")

Wiersz 255	this->writeReport("Player lost a game.");

Wiersz 270	this->writeReport("Player destroyed an asteroid.");

Spacegame.cpp

Wiersz 47	game.writeReport("Player choose Play.")

Wiersz 66	game.writeReport("Player choose Highscores.");

Wiersz 98	game.writeReport("Player choose About.");

Wiersz 130	game.writeReport("Player choose Exit.");







