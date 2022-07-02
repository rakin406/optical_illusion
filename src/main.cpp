#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main() {
    float screenWidth = 1000.f;
    float screenHeight = 1000.f;
    sf::RenderWindow window(
        sf::VideoMode(screenWidth, screenHeight), "Optical illusion");

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
        // rotate sprite from center
        sf::FloatRect spriteRect = spiral.getLocalBounds();
        spiral.setOrigin(
            spriteRect.left + spriteRect.width / 2.0f,
            spriteRect.top + spriteRect.height / 2.0f);
        spiral.setPosition(
            sf::Vector2f(screenWidth / 2.0f, screenHeight / 2.0f));
        spiral.rotate(1.f);
        window.draw(spiral);
        window.display();
    }

    return 0;
}
