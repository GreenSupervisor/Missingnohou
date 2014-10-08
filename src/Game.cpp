/*
 * Game.cpp
 *
 *  Created on: Jun 20, 2014
 *      Author: brian
 */

#include "Game.hpp"


enum gameMode { PAUSED, PLAYING };

static gameMode currentMode;

Game::Game() {
	//random seed
	std::srand(static_cast<unsigned int>(std::time(NULL)));



	//Load Fonts
	Resources::addFont("default", "resources/fonts/FiraSans-Light.ttf");
	Resources::addFont("fun", "resources/fonts/chinacatthin.ttf");


	//Load Textures
	string texPath = "resources/textures/";
	Resources::addTexture("missing", texPath + "missing.png");
	Resources::addTexture("missingno", texPath + "missingno.png");
	Resources::addTexture("bullet", texPath + "bullet.png");
	Resources::addTexture("pidgey", texPath + "pidgey.png");



	//some values
	gameWidth = 500;
	gameHeight = 700;


	//init window
	Resources::getWindow().create(sf::VideoMode(gameWidth, gameHeight, 32), "Missingnohou");




	cout << "Initialization Successful" << endl;

}

Game::~Game() {
	// TODO Auto-generated destructor stub
}

void Game::start(){

	cout << "Game Start" <<  endl;

	//Start "Menu"
	sf::Text startMessage;
	startMessage.setFont(Resources::getFont("fun"));
	startMessage.setCharacterSize(30);
	startMessage.setPosition(90.0f, 200.0f);
	startMessage.setColor(sf::Color::Red);
	startMessage.setString("Welcome to Missingnohou\nPress Space to start");

	Entities::setPlayer(new Player());

	sf::Clock sfmlClock;
	float dt = 1;
	std::deque<float> fpsQueue;
	fpsQueue.push_front(1.0f);
	float avgFPS;

	sf::Text fpsLabel;
	fpsLabel.setFont(Resources::getFont("fun"));
	fpsLabel.setCharacterSize(20);
	fpsLabel.setPosition(0,0);
	fpsLabel.setColor(sf::Color::White);
	fpsLabel.setString("None");


	Entities::addEntity(ENEMY, new Enemy(sf::Vector2f(50, 50)));

	cout << "Window Starting Now:" << endl;

	while(Resources::getWindow().isOpen()){
		//handle some events
		sf::Event event;
		while(Resources::getWindow().pollEvent(event)){
			//close window on close button, or pressing escape on the keyboard
			if ( (event.type == sf::Event::Closed) || ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))){
				Resources::getWindow().close();
				cout << "Window close event recieved" <<  endl;
				break;
			}
			if ( (event.type == sf::Event::KeyPressed)  ){
				if (event.key.code == sf::Keyboard::Space){
					if (currentMode==PLAYING) currentMode=PAUSED; else currentMode=PLAYING;
				}

			}
		}

		//==================================================


		if (currentMode == PLAYING){
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
				Entities::getPlayer()->shoot();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
				Entities::getPlayer()->move(UP);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
				Entities::getPlayer()->move(RIGHT);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
				Entities::getPlayer()->move(DOWN);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
				Entities::getPlayer()->move(LEFT);
			}
		}
		//==================================================



		if (currentMode == PLAYING){

			dt = sfmlClock.getElapsedTime().asSeconds();
			sfmlClock.restart();
			fpsQueue.push_front(1.0/dt);
			if (fpsQueue.size() > 16) fpsQueue.pop_back();
			avgFPS = 0;
			for (uint i = 0; i < fpsQueue.size(); i++) avgFPS += fpsQueue.at(i);
			avgFPS /= fpsQueue.size();



			//===Updating Entities===
			//-player
			Entities::getPlayer()->update();



			////-player projectiles
			vector<Entity*> *playerProjVect= &(Entities::getEntities(PLAYER_PROJECTILES));
			//loop for updates
			for (std::vector<Entity*>::size_type i = 0; i != playerProjVect->size(); i++) (*playerProjVect)[i]->update();
			//loop again for deletions
			std::vector<Entity*>::size_type delCount = 0;
			while ( delCount < playerProjVect->size() ) {
				if ( playerProjVect->at(delCount)->isMarkedToDelete() ) {
					delete playerProjVect->at(delCount);
					playerProjVect->erase( playerProjVect->begin() + delCount );
				} else {
					++delCount;
				}
			}

			vector<Entity*> *enemiesVect= &(Entities::getEntities(ENEMY));

			//check colissions with enemies
			for (std::vector<Entity*>::size_type p = 0; p != playerProjVect->size(); p++){
				for (std::vector<Entity*>::size_type e = 0; e != enemiesVect->size(); e++){

					if (enemiesVect->at(e)->isMarkedToDelete()) continue;
					if (playerProjVect->at(p)->isColliding(enemiesVect->at(e))){

						sf::Vector2f p1 = playerProjVect->at(p)->getPosition(),
								p2 = enemiesVect->at(e)->getPosition(),
								d1 = playerProjVect->at(p)->getSize(),
								d2 = enemiesVect->at(e)->getSize();

						cout <<  p1.x << "," << p1.y << " with " << d1.x << "x" << d1.y
								<< " colliding with "
								<< p2.x << "," << p2.y << " with " << d2.x << "x" << d2.y
								<< endl;

						cout << "Explosion" << endl;
						enemiesVect->at(e)->markToExplode();
					}


				}
			}

			//TODO make "effects" class, instances are for non-interacting entities
			//make the instance here, before the marked for deletion and explosion entity is just deleted

			////-enemies
			//loop first for deletions - stop further offense
			delCount = 0;
			while ( delCount < enemiesVect->size() ) {
				if ( enemiesVect->at(delCount)->isMarkedToDelete() ) {
					delete enemiesVect->at(delCount);
					enemiesVect->erase( enemiesVect->begin() + delCount );
				} else {
					++delCount;
				}
			}
			//loop for updates
			for (std::vector<Entity*>::size_type i = 0; i != enemiesVect->size(); i++) (*enemiesVect)[i]->update();





		}else{

		}








		//==================================================
		//painting
		Resources::getWindow().clear(sf::Color(20, 20 ,20));
		//if (currentMode == PLAYING){
		Entities::drawEntities(ENEMY);

		Entities::drawEntities(PLAYER_PROJECTILES);



		Resources::draw(*(Entities::getPlayer()));

		std::ostringstream ss;
		ss << "FPS: " << roundf(avgFPS);
		fpsLabel.setString(ss.str());
		Resources::draw(fpsLabel);
		//}
		if (currentMode == PAUSED){
			Resources::draw(startMessage);


		}




		Resources::getWindow().display();

	}
	cout << "Game Ending" << endl;
}





