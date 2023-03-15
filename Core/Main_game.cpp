#include "Main_menu.h"

Main_game::Main_game(int mode) : Tiny_state() {
    this->difficulty = mode;
}

void Main_game::Initialize(sf::RenderWindow* window) {
    this->back = new Background("../Pong - Game/Graphics/cosmos.jpg");
    this->font = new sf::Font();
    this->font->loadFromFile("../Pong - Game/Graphics/font1.otf");
    this->pausedFont = new sf::Font();
    this->pausedFont->loadFromFile("../Pong - Game/Graphics/OuterspaceMilitia.otf");

    this->scoreFont = new sf::Font();
    this->scoreFont->loadFromFile("../Pong - Game/Graphics/ChosenceRegular.otf");
    this->score1 = new Score(*scoreFont, 64U);
    this->score1->setFillColor(sf::Color(204, 14, 197));
    this->score2 = new Score(*scoreFont, 64U);
    this->score2->setFillColor(sf::Color(219, 21, 21));
    this->score1->setPosition(70, 0);
    this->score2->setPosition(window->getSize().x - this->score2->getGlobalBounds().width - 110, 0);

    this->startDigits = new sf::Text("Ready?", *scoreFont, 64U);
    this->startDigits->setFillColor(sf::Color(211, 14, 204));

    this->pausedText = new sf::Text("       Paused\nPress Escape to Quit", *pausedFont, 30U);
    this->pausedText->setFillColor(sf::Color(193, 184, 193));
    this->pausedText->setOrigin(this->pausedText->getGlobalBounds().width / 2, this->pausedText->getGlobalBounds().height / 2);
    this->pausedText->setPosition(window->getSize().x / 2, window->getSize().y / 2);

    this->player1 = new Paddle_player(0);

    switch (this->difficulty) {
    case 0:
        this->player2 = new Paddle_ai(1, 1);
        break;
    case 1:
        this->player2 = new Paddle_ai(1, 2);
        break;
    default:
        this->player2 = new Paddle_ai(1, 3);
        break;
    }

    this->player1->setPosition(0, window->getSize().y / 3 + this->player1->getGlobalBounds().height / 2);
    this->player2->setPosition(window->getSize().x - this->player2->getGlobalBounds().width,
        window->getSize().y / 3 + this->player2->getGlobalBounds().height / 2);

    this->ballObject = new Ball(this->score1, this->score2, this->player1, this->player2);
    this->player2->setBall(this->ballObject);

    this->ballObject->Reset(window);

    this->paused = false;
    this->enterKey = false;
}

void Main_game::Update(sf::RenderWindow* window) {

    this->startElapsed = this->startTimer.getElapsedTime();
    if (this->startElapsed.asMilliseconds() > 1400) {
        if (this->paused) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return) && !this->enterKey) {
                this->paused = false;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
                Game_state& coreState = Game_state::instance();
                std::shared_ptr<Main_menu> menu(new Main_menu());
                coreState.SetState(menu);
            }
        }
        else {
            this->ballObject->Update(window);
            this->player1->Update();
            this->player2->Update();
            this->score1->Update();
            this->score2->Update();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return) && !this->enterKey) {
                this->paused = true;
                this->pausedText->setString("       Paused\nPress Escape to Quit");
                this->pausedText->setOrigin(this->pausedText->getGlobalBounds().width / 2, this->pausedText->getGlobalBounds().height / 2);
                this->pausedText->setPosition(600, 400);
            }
        }
    }
    else {
        if ((int)this->startElapsed.asSeconds() == 1) {
            this->startDigits->setString("Go!");
            this->startDigits->setFillColor(sf::Color(237, 28, 28));
        }
        this->startDigits->setOrigin(this->startDigits->getGlobalBounds().width / 2, this->startDigits->getGlobalBounds().height / 2);
        this->startDigits->setPosition(600, this->startDigits->getGlobalBounds().height / 2);
    }
    this->enterKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return);
}

void Main_game::Render(sf::RenderWindow* window) {
    window->draw(*this->back);
    window->draw(*this->player1);
    window->draw(*this->player2);
    window->draw(*this->score1);
    window->draw(*this->score2);
    window->draw(*this->ballObject);
    this->startElapsed = this->startTimer.getElapsedTime();

    if (this->startElapsed.asMilliseconds() < 1400) {
        window->draw(*this->startDigits);
    }
    if (this->paused) {
        window->draw(*this->pausedText);
    }
}

void Main_game::Destroy(sf::RenderWindow* window) {
    delete this->back;
    delete this->player1;
    delete this->player2;
    delete this->ballObject;
    delete this->score1;
    delete this->score2;
    delete this->font;
    delete this->pausedFont;
    delete this->scoreFont;
    delete this->pausedText;
    delete this->startDigits;
}