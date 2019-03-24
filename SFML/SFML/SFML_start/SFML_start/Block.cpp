#include "Block.h"



Block::Block(float X, float Y, float Width, float Height)
{
	shape.setPosition(X, Y);
	shape.setSize({Width, Height });
	shape.setFillColor(sf::Color::Magenta);
	shape.setOrigin(Width / 2, Height / 2);
}

void Block::draw(sf::RenderTarget & target, sf::RenderStates state) const
{
	target.draw(this->shape, state);
}

float Block::left()
{
	return this->shape.getPosition().x - shape.getSize().x / 2;
}

float Block::right()
{
	return this->shape.getPosition().x + shape.getSize().x / 2;
}

float Block::top()
{
	return this->shape.getPosition().y - shape.getSize().y / 2;
}

float Block::bottom()
{
	return this->shape.getPosition().y + shape.getSize().y / 2;
}


sf::Vector2f Block::getPosition()
{
	return shape.getPosition();
}



bool Block::isDestroyed() 
{
	return this->destroyed;
}

void Block::destroy()
{
	this->destroyed = true;
}

sf::Vector2f Block::getSize()
{
	return shape.getSize();
}

void Block::update()
{

}