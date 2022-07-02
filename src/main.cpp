#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Optical illusion");
    sf::CircleShape shape(5.f);
    shape.setFillColor(sf::Color::Black);

    // Put shape in center of the window
    shape.setPosition(
        (window.getSize().x / 2.f) - shape.getRadius(),
        (window.getSize().y / 2.f) - shape.getRadius());

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Resized) {
                // Don't resize objects on window resize
                sf::FloatRect view(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(view));
                shape.setPosition(
                        (window.getSize().x / 2.f) - shape.getRadius(),
                        (window.getSize().y / 2.f) - shape.getRadius());
            }
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        window.draw(shape);
        window.display();
    }

    return 0;
}
