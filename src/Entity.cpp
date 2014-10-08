/*
 * Entity.cpp
 *
 *  Created on: Jun 22, 2014
 *      Author: brian
 */

#include "Resources.hpp"
#include "Entity.hpp"

Entity::Entity() {
	// TODO Auto-generated constructor stub

}

Entity::Entity(sf::Vector2f pos){
	setPosition(pos);
}

Entity::~Entity() {
	// TODO Auto-generated destructor stub
}

sf::Vector2f Entity::getPosition(){
	sf::Vector2f v2(position.x, position.y);

	return v2;
}

void Entity::setPosition(sf::Vector2f pos){

	position.x = pos.x;
	position.y = pos.y;
}

sf::Vector2f Entity::getSize(){

	sf::Vector2u v1 = Resources::getTexture(spriteStr).getSize();

	sf::Vector2f v2(v1.x, v1.y);

	return v2;
}




void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	sf::Sprite spr(Resources::getTexture(spriteStr));

	spr.setPosition(position.x, position.y);

	target.draw(spr);
}


void Entity::update(){

}

bool Entity::isMarkedToDelete(){
	return markedToDelete;
}

void Entity::markToDelete(){
	markedToDelete = true;
}

bool Entity::isMarkedToExplode(){
	return markedToExplode;
}

void Entity::markToExplode(){
	markedToExplode = true;
	markToDelete();
}

bool Entity::isColliding(Entity* en){

	sf::FloatRect one(getPosition(), getSize()), two(en->getPosition(), en->getSize());

	return one.intersects(two);

}

