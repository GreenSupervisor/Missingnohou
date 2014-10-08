/*
 * Bullet.cpp
 *
 *  Created on: Jul 29, 2014
 *      Author: brian
 */

#include "Bullet.hpp"

Bullet::Bullet() {
	// TODO Auto-generated constructor stub
	spriteStr = "bullet";
}

Bullet::Bullet(sf::Vector2f pos):Entity(pos){
	spriteStr = "bullet";

}

Bullet::Bullet(sf::Vector2f pos, sf::Vector2f vel) : Bullet(pos) {

	velocity = sf::Vector2f(vel.x, vel.y * -1);
}


Bullet::~Bullet() {
	// TODO Auto-generated destructor stub
}

void Bullet::update(){

	//check if bullet is off screen
	//if so, delete

	sf::FloatRect displayBox(getPosition(), getSize());

	if (displayBox.left > 500 || displayBox.top > 700 || (displayBox.left + displayBox.width) < 0 || displayBox.top + displayBox.height < 0){
		markedToDelete = true;
		return;
	}

	sf::Vector2f v = getPosition();

	setPosition(sf::Vector2f(v.x + velocity.x, v.y + velocity.y));


}

