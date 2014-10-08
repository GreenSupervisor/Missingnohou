/*
 * Enemy.cpp
 *
 *  Created on: Jul 29, 2014
 *      Author: brian
 */

#include "Enemy.hpp"

Enemy::Enemy() {
	// TODO Auto-generated constructor stub
	spriteStr = "pidgey";
}

Enemy::Enemy(sf::Vector2f pos):Entity(pos){
	spriteStr = "pidgey";
}

Enemy::~Enemy() {
	// TODO Auto-generated destructor stub
}


//void Enemy::draw(sf::RenderTarget& target, sf::RenderStates states) const{}
