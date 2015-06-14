#ifndef _GameEngine_hpp_
#define _GameEngine_hpp_

#include <Utilities\VERSION.hpp>

#include <SFML\Graphics.hpp>
#include <Data\System.hpp>
#include <Input\EventManager.hpp>
#include <Processing\Renderer.hpp>
#include <Processing\Simulator.hpp>

#include <Utilities\Conversion.hpp>
#include <Utilities\Logger.hpp>

class GameEngine
{
private:
	sf::RenderWindow* gameWindow;
	EventManager* eventManager;
	Renderer* renderer;
	Simulator* simulator;

	System* level;

public:
	GameEngine();
	~GameEngine();

	void launch();
};

#endif // !_GameEngine_hpp_