#pragma once
#include "Ball.h"
#include<SFML/Graphics.hpp>

class Paddle : public sf::Drawable
{
private:
	sf::RectangleShape shape;
	const float paddleWidth = 80.0f;
	const float paddleHeight = 20.0f;
	const float paddleVelocity = 6.0f;

	sf::Vector2f velocity{ paddleVelocity, 0.0f };
	void draw(sf::RenderTarget & target, sf::RenderStates state) const;
public:
	Paddle(float X, float Y);
	Paddle() = delete;
	~Paddle() = default;
	void update();
	float left();
	float right();
	float top();
	float bottom();

	sf::Vector2f getPosition();

};

