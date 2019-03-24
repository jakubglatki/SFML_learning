#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Ball.h"
#include "Paddle.h"
#include "Block.h"

template <class T1, class T2> bool isIntersecting(T1& a, T2& b)
{
	return a.right() >= b.left() && a.left() <= b.right() && a.bottom() >= b.top() && a.top() <= b.bottom();
}

bool collisionTest(Paddle& paddle, Ball& ball)
{
	if (!isIntersecting(paddle, ball)) return false;
	
	ball.moveUp();

	if (ball.getPosition().x < paddle.getPosition().x)
	{
		ball.moveLeft();
	}
	else if (ball.getPosition().x > paddle.getPosition().x)
	{
		ball.moveRight();
	}

}

bool collisionTest(Block &block, Ball & ball)
{
	if (!isIntersecting(block, ball)) return false;

	block.destroy();

	float overlapLeft = ball.right() - block.left();
	float overlapRight = block.right() - ball.left();
	float overlapTop = ball.bottom() - block.top();
	float overlapBottom = block.bottom() - ball.top();

	bool ballFromLeft(abs(overlapLeft) < abs(overlapRight));
	bool ballFromTop(abs(overlapTop) < abs(overlapBottom));

	float minOverlapX = ballFromLeft ? overlapLeft : overlapRight;
	float minOverlapY = ballFromTop ? overlapTop : overlapRight;

	if (abs(minOverlapX) < abs(minOverlapY)) 
	{
		ballFromLeft ? ball.moveLeft() : ball.moveRight();
	
	}
	else {
		ballFromTop ? ball.moveUp() : ball.moveDown();
	}
}

int main()
{
	Ball ball(400, 300);
	Paddle paddle(400, 550);

	sf::RenderWindow window(sf::VideoMode{ WIDTH, HEIGHT }, "SFML works!");
	
	window.setFramerateLimit(60);
	sf::Event event;

	unsigned blocksX= 10 , blocksY= 4 , blockWidth= 60 , blockHeight= 20;
	std::vector<Block> blocks;
	
	for (int i = 0; i < blocksY;i++) {
		for (int j = 0;j < blocksX;j++) {
			blocks.emplace_back((j+1)*(blockWidth+10),(i+2)*(blockHeight+5),blockWidth,blockHeight);
		}
	}
	while (true)
	{
		window.clear(sf::Color::Black);
		window.pollEvent(event);

		if (event.type == sf::Event::Closed)
		{
			window.close();
			break;
		}
		ball.update();
		paddle.update();
		collisionTest(paddle, ball);

		for (auto &block : blocks) {
			if (collisionTest(block, ball)) break;
		}

		
		auto iterator= remove_if(begin(blocks), end(blocks), [](Block &block) {return block.isDestroyed();});
		blocks.erase(iterator, end(blocks));

		window.draw(ball);
		window.draw(paddle);

		for (auto& block : blocks)
		{
			window.draw(block);
		}

		window.display();

		if (blocks.empty()) {
			event.type = sf::Event::Closed;
		}
	}

	return 0;
}