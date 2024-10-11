#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>  // Para sf::Clock

int main() {
    // Cargar la imagen desde un archivo PNG
    sf::Texture texture;
    if (!texture.loadFromFile("perfil.png")) {
        return -1; // Error si no se puede cargar la imagen
    }

    // Crear un sprite y asociarlo a la textura cargada
    sf::Sprite sprite;
    sprite.setTexture(texture);

    // Obtener el tamaño de la imagen
    sf::Vector2u imagenTamano = texture.getSize();

    // Escalar el sprite a la cuarta parte de su tamaño
    sprite.setScale(0.25f, 0.25f);  // Escala al 25% (1/4)

    // Establecer el origen del sprite al centro de la imagen escalada
    sprite.setOrigin((imagenTamano.x * 0.25f) * 0.5f, (imagenTamano.y * 0.25f) * 0.5f);

    // Crear una ventana con el tamaño escalado
    sf::RenderWindow window(sf::VideoMode(imagenTamano.x * 0.25f, imagenTamano.y * 0.25f), "Mostrar Imagen PNG", sf::Style::None);

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
        if (clock.getElapsedTime().asSeconds() > 3) {
            window.close();
        }

        // Calcular la rotación (0.5 vueltas por segundo)
        float elapsedTime = clock.getElapsedTime().asSeconds();
        float rotation = 0.5f * 360.0f * elapsedTime;
        sf::Transform transform;
        transform.rotate(rotation, {imagenTamano.x * 0.125f, imagenTamano.y * 0.125f});

        // Limpiar la ventana con color transparente
        window.clear(sf::Color::Transparent);

        // Dibujar el sprite (la imagen escalada y rotada) en la ventana
        window.draw(sprite, transform);

        // Mostrar lo que se ha dibujado
        window.display();
    }

    return 0;
}
