#include "SFML/Graphics.hpp"

#include <iostream>
#include <math.h>
#include <ctime>
#include "DVDWalker.h"

int main()
{	
	srand(time(0));	
	sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
	sf::RenderWindow window(desktopMode, "DVD", sf::Style::Fullscreen);
	
	//window.setFramerateLimit(60);
	
	DVDWalker DvD;

	while(window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				window.close();
		}
		DvD.MoveSprite();
		DvD.CheckBoundary(sf::Vector2i(window.getSize().x,window.getSize().y));
		DvD.Display();
		window.clear(sf::Color::Transparent);
		
		window.draw(DvD.Draw());

		window.display();
	}
	return 0;
}