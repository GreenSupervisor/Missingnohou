/*
 * Entity.h
 *
 *  Created on: Jun 22, 2014
 *      Author: brian
 */

#ifndef ENTITY_HPP_
#define ENTITY_HPP_


#include <iostream>
#include <string>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

using namespace std;

enum Direction { UP, DOWN, LEFT, RIGHT };

enum EntityType { PLAYER_PROJECTILES, ENEMY, ENEMY_PROJECTILES };

class Entity : public sf::Drawable{
public:
	Entity();
	Entity(sf::Vector2f pos);
	virtual ~Entity();

	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f pos);

	virtual sf::Vector2f getSize();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	//updates entity to how it should be in 1 tick given current state
	virtual void update();

	bool isMarkedToDelete();

	void markToDelete();

	bool isMarkedToExplode();

	void markToExplode();

	bool isColliding(Entity* en);


protected:
	string spriteStr = "missing";



	sf::Vector2f position;

	bool markedToDelete = false;

	bool markedToExplode = false;

};

#endif /* ENTITY_HPP_ */
