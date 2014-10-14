#ifndef _Level_hpp_
#define _Level_hpp_

#include "SolarSystem.hpp"
#include "SpaceObject.hpp"
#include <fstream>

class Level
{
private:
public:
    // MEMBERS
    std::string name;
    std::string description;

    SolarSystem activeSystem;

    std::list<SolarSystem> inactiveSystems;

    //CONSTRUCTORS
    Level();
    //DESTRUCTORS
    //METHODS

    void saveToStream(std::ofstream* output);
};

#endif // _Level_hpp_