#include <GUI\Elements\InputField.hpp>

InputField::InputField(AssetManager* _assets) : GUIElement(_assets)
{
	type = ElementType::InputField;
	EXP::log("[Info]InputField has been constructed: " + utils::tostring(this));
}
InputField::~InputField()
{
	EXP::log("[Info]Destructing InputField... " + utils::tostring(this));
	EXP::log("[Info]InputField has been destructed: " + utils::tostring(this));
}

void InputField::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	//WORK
}
void InputField::handleEvent(sf::RenderWindow& target, sf::Event* _event)
{
	//WORK
}

void InputField::setWidth(int _width)
{
	width = _width;
}
void InputField::setHeight(int _height)
{
	height = _height;
}
void InputField::setContent(std::string _content)
{
	content = _content;
}
int InputField::getWidth()
{
	return width;
}
int InputField::getHeight()
{
	return height;
}
std::string InputField::getContent()
{
	return content;
}
