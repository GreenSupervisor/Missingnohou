/*
 * Player.h
 *
 *  Created on: Jul 28, 2014
 *      Author: brian
 */

#ifndef PLAYER_HPP_
#define PLAYER_HPP_


#include "Entity.hpp"
#include "Entities.hpp"
#include "Bullet.hpp"


#include "SFML/Graphics.hpp"

using namespace std;

class Player : public Entity{
public:
	Player();
	virtual ~Player();

	void move(Direction direction, float amount = 4);

	void shoot();

	void setPosition(sf::Vector2f pos);

	sf::Vector2f getHitBox();

	virtual void update();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	int getTick();


private:

	int tick; //a number from 0-127 that increments and loops

	int timeSinceLastShoot;

};

#endif /* PLAYER_HPP_ */
