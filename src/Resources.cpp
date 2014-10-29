/*
 * Resources.cpp
 *
 *  Created on: Jul 28, 2014
 *      Author: brian
 */

#include "Resources.hpp"



namespace Resources{

map<string, sf::Font> fontMap;
map<string, sf::Texture> texMap;

sf::RenderWindow gameWindow;

Config *lvlCfg;

sf::Font& getFont(string fontName){
	return Resources::fontMap[fontName];
}

void addFont(string fontName, string fontFile){
	sf::Font f;
	f.loadFromFile(fontFile);

	fontMap.insert(make_pair(fontName, f));
}


sf::Texture& getTexture(string texName){


	if ( texMap.find(texName) == texMap.end() ) {
		// not found
		return texMap["missing"];
	} else {
		// found
		return texMap[texName];
	}


}
void addTexture(string texName, string texFile){

	sf::Texture f;
	f.loadFromFile(texFile);

	texMap.insert(make_pair(texName, f));
}




void draw(const sf::Drawable& drawable){

	gameWindow.draw(drawable);

}

sf::RenderWindow& getWindow(){
	return gameWindow;
}



extern Config* getLvlCfg(){
	return lvlCfg;
}

extern void setLvlCfg(const char *cfgFileName){
	Config *cfg = new Config();
	cfg->readFile(cfgFileName);
	lvlCfg = cfg;
}

bool fillCfgVariable (string cfgVarName, bool &value){
	return lvlCfg->lookupValue(cfgVarName, value);
}
bool fillCfgVariable (string cfgVarName, int &value){
	return lvlCfg->lookupValue(cfgVarName, value);
}
bool fillCfgVariable (string cfgVarName, unsigned int &value){
	return lvlCfg->lookupValue(cfgVarName, value);
}
bool fillCfgVariable (string cfgVarName, long long &value){
	return lvlCfg->lookupValue(cfgVarName, value);
}
bool fillCfgVariable (string cfgVarName, unsigned long long &value){
	return lvlCfg->lookupValue(cfgVarName, value);
}
bool fillCfgVariable (string cfgVarName, float &value){
	return lvlCfg->lookupValue(cfgVarName, value);
}
bool fillCfgVariable (string cfgVarName, double &value){
	return lvlCfg->lookupValue(cfgVarName, value);
}
bool fillCfgVariable (string cfgVarName, string &value){
	return lvlCfg->lookupValue(cfgVarName, value);
}



}
