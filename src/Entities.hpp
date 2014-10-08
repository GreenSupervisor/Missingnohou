/*
 * Entities.h
 *
 *  Created on: Jul 29, 2014
 *      Author: brian
 */

#ifndef ENTITIES_HPP_
#define ENTITIES_HPP_

#include "Player.hpp"
#include "Resources.hpp"
#include "Enemy.hpp"

#include <cstdlib>
#include <vector>


class Player;

using namespace std;


namespace Entities{

extern Player* getPlayer();
extern void setPlayer(Player *en);

extern vector<Entity*>& getEntities(EntityType et);
extern void addEntity(EntityType et, Entity* en);

extern void drawEntities(EntityType et);

extern void updateEntities(EntityType et);

}



#endif /* ENTITIES_HPP_ */
