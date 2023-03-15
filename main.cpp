#include <SFML/Window.hpp>
#include "Core/Game_State.h"
#include "Core/Main_menu.h"

bool quitGame = false;

int main() {
    sf::RenderWindow window(sf::VideoMode(1200, 800), "P!ng");
    Game_state& coreState = Game_state::instance();
    coreState.SetWindow(&window);
    std::shared_ptr<Main_menu> menu(new Main_menu());
    coreState.SetState(menu);

    sf::Clock timer;
    sf::Time elapsed;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        elapsed = timer.getElapsedTime();
        if (elapsed.asMicroseconds() > 16666) {
            coreState.Update();
            coreState.Render();
            window.display();
            if (quitGame) {
                window.close();
            }
            timer.restart();
        }
    }
    return 0;
}