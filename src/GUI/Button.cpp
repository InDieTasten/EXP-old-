#include <GUI\Button.hpp>

Button::Button()
{
	width = 50;
	height = 14;
	text = "{no text}";
	EXP::log("[Info]Button has been constructed: " + utils::tostring(this));
}
Button::~Button()
{

	EXP::log("[Info]Button has been destructed: " + utils::tostring(this));
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states)
{
	//Button draw routine (WORK)
}
void Button::handleEvent(sf::Event* _event)
{
	//Button handling routine (WORK)
}

void Button::setWidth(int _width)
{
	width = _width;
}
void Button::setHeight(int _height)
{
	height = _height;
}
void Button::setText(std::string _text)
{
	text = _text;
}
int Button::getWidth()
{
	return width;
}
int Button::getHeight()
{
	return height;
}
std::string Button::getText()
{
	return text;
}