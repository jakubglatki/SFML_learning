#include "Ball.h"



Ball::Ball(float X, float Y)
{
	shape.setPosition(X, Y);
	shape.setRadius(this->ballRadius);
	shape.setFillColor(sf::Color::White);
	shape.setOrigin(this->ballRadius, this->ballRadius);
}


void Ball::draw(sf::RenderTarget & target, sf::RenderStates state) const
{
	target.draw(this->shape, state);
}

void Ball::update() 
{
	this->shape.move(this->velocity);
	if (this->left() < 0)
	{
		velocity.x = ballVelocity;
	}
	else if (this->right() > WIDTH) {
		velocity.x = -ballVelocity;
	}
	
	if (this->bottom() > HEIGHT) {
		velocity.y = -ballVelocity;
	}
	else if (this->top() < 0) {
		velocity.y = ballVelocity;
	}
}


float Ball::left()
{
	return this->shape.getPosition().x - shape.getRadius();
}

float Ball::right()
{
	return this->shape.getPosition().x + shape.getRadius();
}

float Ball::top()
{
	return this->shape.getPosition().y - shape.getRadius();
}

float Ball::bottom()
{
	return this->shape.getPosition().y + shape.getRadius();
}


void Ball::moveDown()
{
	this->velocity.y = ballVelocity;
}

void Ball::moveUp()
{
	this->velocity.y = -ballVelocity;
}

void Ball::moveRight()
{
	this->velocity.x = ballVelocity;
}


void Ball::moveLeft()
{
	this->velocity.x = -ballVelocity;
}

sf::Vector2f Ball::getPosition()
{
	return shape.getPosition();
}