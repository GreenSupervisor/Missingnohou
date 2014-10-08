/*
 * Enemy.h
 *
 *  Created on: Jul 29, 2014
 *      Author: brian
 */

#ifndef ENEMY_H_
#define ENEMY_H_

#include "Entity.hpp"



class Enemy : public Entity{
public:
	Enemy();
	Enemy(sf::Vector2f pos);

	virtual ~Enemy();


private:


	//virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};

#endif /* ENEMY_H_ */
