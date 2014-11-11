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
//we'll keep storing textures separately, although you could probably just
//store only animations as textures are only referenced for creating animations
map<string, Animation> animMap;
//animations and textures will be added simultaneously, with same string key.
//animatedSprites will be stored in the Entity itself


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

//TODO remove or private
sf::Texture& getTexture(string texName){


	if ( texMap.find(texName) == texMap.end() ) {
		// not found
		return texMap["missing"];
	} else {
		// found
		return texMap[texName];
	}


}
//TODO remove or private?
void addTexture(string texName, string texFile){

	sf::Texture f;
	f.loadFromFile(texFile);

	texMap.insert(make_pair(texName, f));
}

Animation& getAnimation(string animName){

	if ( animMap.find(animName) == animMap.end() ) {
		// not found
		return animMap["missing"];//TODO check missing animation (static image)
	} else {
		// found
		return animMap[animName];
	}

}
//animation is assumed to be a 1 frame tall and {numFrames} wide image
//the planned source frame images are taller, might edit, might not
//TODO credit sprites (from Pokemon Zeta/Omicron) or find orig source
void addAnimation(string animName, sf::Vector2i frameDim, int numFrames, string texFile){

	addTexture(animName, texFile);

	Animation a;
	a.setSpriteSheet(getTexture(animName));

	//add each 'frame' (box) from image to animation
	for (int i = 0; i < numFrames; i++){
		sf::IntRect spriteRect(i*frameDim.x, 0, frameDim.x, frameDim.y);
		a.addFrame(spriteRect);
	}

	animMap.insert(make_pair(animName, a));


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
