#pragma once

#include "State.h"
#include "PauseMenu.h"
#include "Creature.h"
#include "Player.h"

class GameState : public State
{
private:

	//GUI
	std::map<sf::String, Button*> m_buttons;
	PauseMenu* m_pauseMenu;

	//Creatures
	std::vector<Creature*> m_creatures;
	Player* m_player;

	sf::Texture m_backgroundTexture;
	sf::RectangleShape m_background;

	//Initialize Functions
	void initButtons();
	void initPauseMenu();
	void initPlayer();
	void initBackground();
public:
	//Constructors / Descructors
	GameState(std::stack<State*>* states);
	virtual ~GameState();

	//Update
	void update(sf::RenderWindow* window, const float& timePerFrame) override;
	void updateInput();
	void updateButtons(sf::RenderWindow* window);
	void updateButtonsHover(sf::RenderWindow* window);
	void updateButtonsClickDetection(sf::RenderWindow* window);
	void updatePauseMenuButtons(sf::RenderWindow* window);
	void updateCreatures(const float& timePerFrame);

	//Render
	void render(sf::RenderTarget* target = nullptr) override;
	void renderButtons(sf::RenderTarget* target);
	void renderCreatures(sf::RenderTarget* target);



};
