#ifndef _Logger_hpp_
#define _Logger_hpp_

#include <iostream>
#include <time.h>
#include <string>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include <SFML\System.hpp>

namespace EXP
{
	void log(std::string msg);
	void init();
}

#endif
