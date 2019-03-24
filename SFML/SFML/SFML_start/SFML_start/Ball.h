#pragma once
#include<SFML/Graphics.hpp>

#define WIDTH 800
#define HEIGHT 600

class Ball : public sf::Drawable
{
private:
	sf::CircleShape shape;
	const float ballRadius=10.0f;
	const float ballVelocity = 4.0f;
	sf::Vector2f velocity{ ballVelocity, ballVelocity };
	void draw(sf::RenderTarget & target, sf::RenderStates state) const;
	
public:
	Ball(float X, float Y);
	Ball() = delete;
	~Ball() = default;

	void update();
	
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

	sf::Vector2f getPosition();

	float left();
	float right();
	float top();
	float bottom();
};

