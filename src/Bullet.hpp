/*
 * Bullet.h
 *
 *  Created on: Jul 29, 2014
 *      Author: brian
 */

#ifndef BULLET_H_
#define BULLET_H_

#include "Entity.hpp"
#include "Resources.hpp"


class Bullet : public Entity {
public:
	Bullet();
	Bullet(sf::Vector2f pos);
	Bullet(sf::Vector2f pos, sf::Vector2f vel);
	virtual ~Bullet();

	virtual void update();



private:

	sf::Vector2f velocity;

};

#endif /* BULLET_H_ */
