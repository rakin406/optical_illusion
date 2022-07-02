#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(1024, 768), "Optical illusion");

    sf::Texture image;
    if (image.loadFromFile(
            "../src/spiral.jpg", sf::IntRect(0, 0, 1000, 1000))) {
        image.setSmooth(true);
    } else {
        window.close();
    }

    sf::Sprite spiral;
    spiral.setTexture(image);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Resized) {
                // Fill spiral sprite in window
                sf::Vector2f newSize(window.getView().getSize());
                spiral.setScale(
                    newSize.x / spiral.getLocalBounds().width,
                    newSize.y / spiral.getLocalBounds().height);
            }
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(spiral);
        window.display();
    }

    return 0;
}
