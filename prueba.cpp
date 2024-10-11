#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>  // Para sf::Clock

int main() {
    // Crear una ventana de 800x600 píxeles
    sf::RenderWindow window(sf::VideoMode(800, 600), "Mostrar Imagen PNG");

    // Cargar la imagen desde un archivo PNG
    sf::Texture texture;
    if (!texture.loadFromFile("perfil.png")) {
        return -1; // Error si no se puede cargar la imagen
    }

    // Crear un sprite y asociarlo a la textura cargada
    sf::Sprite sprite;
    sprite.setTexture(texture);

    // Crear un reloj para medir el tiempo
    sf::Clock clock;

    // Bucle principal para mantener la ventana abierta
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // Cerrar la ventana si el usuario lo solicita
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Cerrar la ventana automáticamente después de 5 segundos
        if (clock.getElapsedTime().asSeconds() > 5) {
            window.close();
        }

        // Limpiar la ventana con un color de fondo (negro)
        window.clear(sf::Color::Black);

        // Dibujar el sprite (la imagen) en la ventana
        window.draw(sprite);

        // Mostrar lo que se ha dibujado
        window.display();
    }

    return 0;
}
