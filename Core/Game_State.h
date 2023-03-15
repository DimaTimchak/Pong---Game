#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

extern bool quitGame;

class Tiny_state {
public:
    Tiny_state() { }
    virtual void Initialize(sf::RenderWindow* window) { }
    virtual void Update(sf::RenderWindow* window) { }
    virtual void Render(sf::RenderWindow* window) { }
    virtual void Destroy(sf::RenderWindow* window) { }
};

class Game_state {
private:
    sf::RenderWindow* window;
    std::shared_ptr<Tiny_state> state;
    Game_state(Game_state const&) = delete;
    Game_state& operator= (Game_state const&) = delete;
    Game_state() {
        this->state = NULL;
    }
    ~Game_state() {
        if (this->state != NULL) {
            this->state->Destroy(this->window);
        }
    }
    
public:
    void SetWindow(sf::RenderWindow* window) {
        this->window = window;
    }
    void SetState(std::shared_ptr<Tiny_state> state) {
        if (this->state != NULL) {
            this->state->Destroy(this->window);
        }
        this->state = state;
        if (this->state != NULL) {
            this->state->Initialize(this->window);
        }
    }
    void Update() {
        if (this->state != NULL) {
            this->state->Update(this->window);
        }
    }
    void Render() {
        if (this->state != NULL) {
            this->state->Render(this->window);
        }
    }

    static Game_state& instance() {
        static Game_state instance;
        return instance;
    }

};