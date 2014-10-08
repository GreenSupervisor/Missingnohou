/*
 * GameManager.h
 *
 *  Created on: Jun 20, 2014
 *      Author: brian
 */

#ifndef GAME_HPP_
#define GAME_HPP_

#include "Resources.hpp"
#include "Entities.hpp"

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"


#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <deque>

using namespace std;


class Game {
public:
	Game();
	virtual ~Game();

	void start();

private:
	int gameWidth;
	int gameHeight;





	//Entity Manager manages entity instances
	//since there will be a lot of them
	//each a part of a different group, which will be
	//differentiated by what


};

#endif /* GAME_HPP_ */
