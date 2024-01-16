#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Game Over");

    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        // handle error
    }

    sf::Text gameOverText;
    gameOverText.setFont(font);
    gameOverText.setString("Game Over");
    gameOverText.setCharacterSize(50);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setStyle(sf::Text::Bold);
    gameOverText.setPosition(window.getSize().x / 2 - gameOverText.getGlobalBounds().width / 2, window.getSize().y / 2 - gameOverText.getGlobalBounds().height / 2);

    sf::Text nickText;
    nickText.setFont(font);
    nickText.setCharacterSize(24);
    nickText.setFillColor(sf::Color::White);
    nickText.setStyle(sf::Text::Bold);
    nickText.setPosition(window.getSize().x / 2 - nickText.getGlobalBounds().width / 2, gameOverText.getPosition().y + gameOverText.getGlobalBounds().height + 20);

    std::string nick;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode == '\b' && nick.size() > 0) {
                    nick.pop_back();
                }
                else if (event.text.unicode < 128 && event.text.unicode != '\r') {
                    nick += static_cast<char>(event.text.unicode);
                }
            }
        }

        window.clear();
        window.draw(gameOverText);
        nickText.setString("Enter your nickname: " + nick);
        window.draw(nickText);
        window.display();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            std::ofstream file("scores.txt", std::ios::app);
            if (file.is_open()) {
                file << nick << " " << score << std::endl;
                file.close();
            }
            break;
        }
    }

    return 0;
}

/*
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Asteroid {
protected:
    sf::Texture texture;
    sf::Sprite sprite;

public:
    Asteroid(const std::string& texturePath) {
        if (!texture.loadFromFile(texturePath)) {
            std::cout << "Could not load a file from assets folder" << std::endl;
        }

        sprite.setTexture(texture);
        sprite.setScale(sf::Vector2f(0.1f, 0.1f));
    }

    const sf::Sprite& getSprite() const {
        return sprite;
    }

    virtual void move(float x, float y) {
        sprite.move(x, y);
    }

    virtual ~Asteroid() {}
};

class ColorfulAsteroid : public Asteroid {
private:
    sf::Color color;

public:
    ColorfulAsteroid(const std::string& texturePath, const sf::Color& asteroidColor)
        : Asteroid(texturePath), color(asteroidColor) {
        sprite.setColor(color);
    }

    void rotate(float angle) {
        sprite.rotate(angle);
    }

    ~ColorfulAsteroid() {}
};

class Asteroids : public Asteroid {
private:
    float spawnTimerMax;
    float spawnTimer;
    int maxAsteroids;
    int speed;
    std::vector<Asteroid*> asteroids;

public:
    Asteroids() {
        spawnTimerMax = 100.f;
        spawnTimer = spawnTimerMax;
        maxAsteroids = 10;
        speed = 3;
    }

    void spawnAsteroids() {
        if (asteroids.size() < maxAsteroids) {
            if (spawnTimer >= spawnTimerMax) {
                if (rand() % 2 == 0) {
                    asteroids.push_back(new Asteroid("Assets/asteroid1.png"));
                } else {
                    asteroids.push_back(new ColorfulAsteroid("Assets/asteroid2.png", sf::Color::Red));
                }

                asteroids.back()->move(static_cast<float>(rand() % static_cast<int>(1200)), -80.f);
                spawnTimer = 0.f;
            } else {
                spawnTimer += 1.f;
            }
        }

        for (int i = 0; i < asteroids.size(); i++) {
            asteroids[i]->move(0.f, speed);

            if (asteroids[i]->getSprite().getPosition().y > 800) {
                delete asteroids[i];
                asteroids.erase(asteroids.begin() + i);
            }
        }
    }

    void renderAsteroids(sf::RenderTarget* target) {
        for (auto& asteroid : asteroids) {
            target->draw(asteroid->getSprite());
        }
    }

    ~Asteroids() {
        for (auto& asteroid : asteroids) {
            delete asteroid;
        }
    }
};

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Asteroid Game");

    Asteroids asteroids;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        asteroids.spawnAsteroids();

        window.clear();
        asteroids.renderAsteroids(&window);
        window.display();
    }

    return 0;
}

*/
