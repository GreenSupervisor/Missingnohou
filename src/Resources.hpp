/*
 * Resources.h
 *
 *  Created on: Jul 28, 2014
 *      Author: brian
 */

#ifndef RESOURCES_HPP_
#define RESOURCES_HPP_

#include "Animation.hpp"

#include <iostream>
#include <string>

#include <libconfig.h++>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

using namespace libconfig;
using namespace std;

namespace Resources{

extern sf::Font& getFont(string fontName);
extern void addFont(string fontName, string fontFile);

extern sf::Texture& getTexture(string texName);
extern void addTexture(string texName, string texFile);



extern void draw(const sf::Drawable& drawable);

extern sf::RenderWindow& getWindow();


extern void setLvlCfg(const char *cfgFileName);

//TODO maybe lower the amount of variables allowed?
extern bool fillCfgVariable (string cfgVarName, bool &value);
extern bool fillCfgVariable (string cfgVarName, int &value);
extern bool fillCfgVariable (string cfgVarName, unsigned int &value);
extern bool fillCfgVariable (string cfgVarName, long long &value);
extern bool fillCfgVariable (string cfgVarName, unsigned long long &value);
extern bool fillCfgVariable (string cfgVarName, float &value);
extern bool fillCfgVariable (string cfgVarName, double &value);
extern bool fillCfgVariable (string cfgVarName, string &value);


}


#endif /* RESOURCES_HPP_ */
