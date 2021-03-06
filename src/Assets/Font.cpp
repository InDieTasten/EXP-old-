#include <Assets\Font.hpp>

Font::Font(const std::string* _id, std::string _path)
{
	EXP::log("[Info]Constructing Font... " + utils::tostring(this));

	if (!_id)
	{
		EXP::log("[Error]Trying to construct Font with null-pointer ID");
		return;
	}
	id = _id;
	path = _path;
	data = nullptr;

	//check
	load();
	unload();

	EXP::log("[Info]Font has been constructed: " + *id);
}
Font::~Font()
{
	EXP::log("[Info]Destructing Font... " + utils::tostring(this));
	std::string tmp = *id;
	if (data)
	{
		EXP::log("[Info]Forcefully unloading Font: " + tmp);
		unload();
	}
	id = nullptr;
	EXP::log("[Info]Font has been destructed: " + tmp);
}
void Font::load()
{
	if (data)
	{
		EXP::log("[Warning]Tried to load already loaded Font: " + *id);
		return;
	}
	data = new sf::Font();
	if (!data->loadFromFile(path))
	{
		EXP::log("[Error]Cannot find Font: " + *id);
		return;
	}
	EXP::log("[Info]Font has been loaded: " + *id);
}
void Font::unload()
{
	if (!data)
	{
		EXP::log("[Warning]Tried to unload already unloaded Font: " + *id);
		return;
	}
	delete data;
	data = nullptr;
	EXP::log("[Info]Font has been unloaded: " + *id);
}
sf::Font* Font::get()
{
	if (!data)
	{
		EXP::log("[Warning]Tried retrieving unloaded Font: " + *id);
		load();
		if (!data)
		{
			EXP::log("[Error]Could not load Font!!: " + *id);
			return nullptr;
		}
	}
	return data;
}
std::string Font::getID()
{
	return *id;
}
std::string Font::getPath()
{
	return path;
}
