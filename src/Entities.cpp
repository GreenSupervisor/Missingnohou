/*
 * Entities.cpp
 *
 *  Created on: Jul 29, 2014
 *      Author: brian
 */

#include "Entities.hpp"

namespace Entities{

Player* player;
vector<Entity*> playerProjectiles;
vector<Entity*> enemies;
vector<Entity*> enemyProjectiles;


Player* getPlayer(){
	return player;
}



void setPlayer(Player *en){
	player = en;
}

vector<Entity*>& getEntities(EntityType et){
	switch (et){
	case PLAYER_PROJECTILES:
		return playerProjectiles;
		break;
	case ENEMY:
		return enemies;
		break;
	case ENEMY_PROJECTILES:
		return enemyProjectiles;
		break;

	default:
		cerr << "Error getEntities, deciding type" << endl;
	}

	vector<Entity*> v;

	return v;

}
void addEntity(EntityType et, Entity* en){

	switch (et){
	case PLAYER_PROJECTILES:
		playerProjectiles.push_back(en);
		break;
	case ENEMY:
		enemies.push_back(en);
		break;
	case ENEMY_PROJECTILES:
		enemyProjectiles.push_back(en);
		break;

	default:
		cerr << "Error addEntity, deciding type" << endl;
	}

}

void drawEntities(EntityType et){

	vector<Entity*> *v;

	switch(et){
	case PLAYER_PROJECTILES:
		v = &playerProjectiles;
		break;
	case ENEMY:
		v = &enemies;
		break;
	case ENEMY_PROJECTILES:
		v = &enemyProjectiles;
		break;

	default:
		cerr << "Error renderEntities, deciding type" << endl;
	}

	for (std::vector<Entity*>::size_type i = 0; i != v->size(); i++){
		Resources::draw(*((*v)[i]));
	}


}


void updateEntities(EntityType et){
	//tells entities  to update, or removes them if out of bounds



}




}


