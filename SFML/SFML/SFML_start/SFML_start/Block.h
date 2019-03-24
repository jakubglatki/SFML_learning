#pragma once
#include <SFML/Graphics.hpp>

class Block : public sf::Drawable
{
private:
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;
	sf::RectangleShape shape;
	bool destroyed = false;

public:
	Block(float X, float Y, float Width, float Height);
	Block() = delete;
	~Block() =default;

	void update();
	sf::Vector2f getPosition();
	
	float left();
	float right();
	float top();
	float bottom();

	bool isDestroyed();
	void destroy();
	sf::Vector2f getSize();

};

