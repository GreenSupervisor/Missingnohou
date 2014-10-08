/*
 * Player.cpp
 *
 *  Created on: Jul 28, 2014
 *      Author: brian
 */

#include "Player.hpp"



Player::Player() {

	tick = 0;

	spriteStr = "missingno";

	// TODO Auto-generated constructor stub
	//hardcoded for now
	//display dimensions
	//width is 22
	//height is 56
	//displayBox.width = 22;
	//displayBox.height = 56;

	//hitbox dimensions
	//width is 11
	//height is 28
	//hitBox.width = 11;
	//hitBox.height = 28;

	setPosition(sf::Vector2f(239, 600));

}

Player::~Player() {
	// TODO Auto-generated destructor stub
}

void Player::setPosition(sf::Vector2f pos){

	position.x = pos.x;
	position.y = pos.y;


}

void Player::move(Direction direction, float amount){

	if (direction == UP && position.y < 0){
		return;
	}
	if (direction == RIGHT && (position.x+11) > 500){
		return;
	}
	if (direction == DOWN && (position.y+28) > 700){
		return;
	}
	if (direction == LEFT && position.x < 0){
		return;
	}


	float dx, dy;

	dx = (direction == RIGHT) ? amount : (direction == LEFT) ? (-1 * amount) : 0;

	dy = (direction == DOWN) ? amount : (direction == UP) ? (-1 * amount) : 0;

	sf::Vector2f v2 = getPosition();

	setPosition(sf::Vector2f(v2.x + dx, v2.y + dy));


}

void Player::shoot(){



	if (timeSinceLastShoot > 2){
		Entities::addEntity(PLAYER_PROJECTILES, new Bullet(getPosition(), sf::Vector2f(0,16)));
		timeSinceLastShoot = 0;
	}



}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	sf::Sprite spr(Resources::getTexture(spriteStr));

	spr.setPosition(position.x - 5, position.y - 14);

	target.draw(spr);
}


void Player::update(){

	tick = (tick + 1) % 128;

	timeSinceLastShoot += 1;


}

int Player::getTick(){
	return tick;
}

