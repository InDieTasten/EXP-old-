#ifndef _Responsive_hpp_
#define _Responsive_hpp_

#include <SFML\Graphics.hpp>
#include <Assets\AssetManager.hpp>

#include <Utilities\Logger.hpp>
#include <Utilities\Conversion.hpp>

class Responsive
{
protected:
	AssetManager* assets;
public:
	Responsive(AssetManager* _assets);
	~Responsive();

	virtual void handleEvent(sf::RenderWindow& target, sf::Event* _event) = 0;
};

#endif // !_Responsive_hpp_
