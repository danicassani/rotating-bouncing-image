#include "DVDWalker.h"
#include <iostream>


DVDWalker::DVDWalker()
{
	x = rand()%300;
	y = rand()%300;
	xspeed = 5.0f;
	yspeed = 5.0f;
	if(!texture.loadFromFile("pacopa.png"))
		std::cout<<"error loading image";
	
	sprite.setTexture(texture);
	SetColor();
	sprite.setPosition(x,y);

	std::cout << "Centro x " << texture.getSize().x << " centro y " << texture.getSize().y << std::endl;
	// sprite.setScale(scale, scale);
}

void DVDWalker::MoveSprite()
{
	x += xspeed;
	y += yspeed; 

}
void DVDWalker::CheckBoundary(sf::Vector2i WindowCoordinate)
{
	if(x + texture.getSize().x * scale>= WindowCoordinate.x)
	{
		xspeed = -xspeed;
		SetColor();
	}
	if(x <= 0)
	{
		xspeed = -xspeed;
		SetColor();
	}
	if(y + texture.getSize().y * scale >= WindowCoordinate.y)
	{
		yspeed = -yspeed;
		SetColor();
	}
	if(y <= 0)
	{
		yspeed = -yspeed;
		SetColor();
	}
}
void DVDWalker::SetColor()
{
	auto Random = rand()%10;
	sprite.setColor(sf::Color(colorArray[Random]));
}

void DVDWalker::Display()
{
	sprite.setPosition(x,y);
}

sf::Sprite& DVDWalker::Draw()
{
	return sprite;
}
