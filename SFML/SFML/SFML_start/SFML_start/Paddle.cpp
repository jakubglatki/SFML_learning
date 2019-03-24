#include "Paddle.h"



Paddle::Paddle(float X, float Y)
{
	shape.setPosition(X, Y);
	shape.setSize({ this->paddleWidth, this->paddleHeight });
	shape.setFillColor(sf::Color::Yellow);
	shape.setOrigin(this->paddleWidth / 2, this->paddleHeight / 2);
}

void Paddle::draw(sf::RenderTarget & target, sf::RenderStates state) const
{
	target.draw(this->shape, state);
}

void Paddle::update() {
	this->shape.move(this->velocity);	
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && this->left()>0)
	{
		velocity.x = -paddleVelocity;
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && this->right() < WIDTH)
	{
		velocity.x = paddleVelocity;
	}
	else {
		velocity.x = 0;
	}
	

}

float Paddle::left()
{
	return this->shape.getPosition().x - shape.getSize().x/2;
}

float Paddle::right()
{
	return this->shape.getPosition().x + shape.getSize().x / 2;
}

float Paddle::top()
{
	return this->shape.getPosition().y - shape.getSize().y / 2;
}

float Paddle::bottom()
{
	return this->shape.getPosition().y + shape.getSize().y / 2;
}


sf::Vector2f Paddle::getPosition()
{
	return shape.getPosition();
}