#include "headers.h"
#include "GameState.h"

//Initialize functions
void GameState::initButtons()
{

}

void GameState::initPauseMenu()
{
	m_pauseMenu = new PauseMenu{};
}

void GameState::initPlayer()
{
	m_player = new Player{"Textures/playerTextureSheet.png"};
	m_player->setScale(sf::Vector2f{ 1.5f, 1.5f });
	m_creatures.push_back(m_player);
}

void GameState::initBackground()
{
	if (!m_backgroundTexture.loadFromFile("Textures/GameStateBackground.jpg"))
	{
		std::cout << "ERROR::GAMESTATE::Background texture could not load\n";
	}

	m_background.setSize(sf::Vector2f{
		static_cast<float>(Constants::WindowWidth), 
		static_cast<float>(Constants::WindowHeigth) 
		}
	);


	m_background.setTexture(&m_backgroundTexture);
}

void GameState::initTileMap()
{
	m_tileMap = new TileMap{};
}

//Constructors / Descructors
GameState::GameState(std::stack<State*>* states) : State{states}
{

	this->initButtons();
	this->initPauseMenu();
	this->initPlayer();
	this->initBackground();
	this->initTileMap();
}

GameState::~GameState()
{
	delete m_player;
	delete[] m_tileMap;
}


//Public functions
void GameState::update(sf::RenderWindow* window, const float& timePerFrame)
{
	this->updateKeyTime(timePerFrame);
	this->updateInput();
	this->updatePauseMenuButtons(window);
	this->updateMousePositions(window);
	m_tileMap->update(m_mouseGridPosition);
	this->updateCollision();

	if (m_isPaused == false)
	{
		this->updateCreatures(timePerFrame);
		this->updateButtons(window);
	}
	else
	{
		m_pauseMenu->update(window);
	}
}

void GameState::updateInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && this->getKeyTime() == true)
	{

		if (m_isPaused == true)
			this->pauseOFF();
		else
			this->pauseON();
	}
}

void GameState::updateButtons(sf::RenderWindow* window)
{
	this->updateButtonsHover(window);
	this->updateButtonsClickDetection(window);
}

void GameState::updateButtonsHover(sf::RenderWindow* window)
{

}

void GameState::updateButtonsClickDetection(sf::RenderWindow* window)
{
	
}

void GameState::updatePauseMenuButtons(sf::RenderWindow* window)
{
	if (m_pauseMenu->isButtonPressed("quitButton", window))
	{
		this->endState();
	}
	else if (m_pauseMenu->isButtonPressed("resumeButton", window))
	{
		this->pauseOFF();
	}
}

void GameState::updateCreatures(const float& timePerFrame)
{
	for (auto* creature : m_creatures)
	{
		creature->update(timePerFrame);
	}
}

void GameState::updateCollision()
{
	this->updateTilesMapCollision();
}

void GameState::updateTilesMapCollision()
{
	for (int iii{ 0 }; iii < m_tileMap->size(0); ++iii)
	{
		m_player->updateCollision(m_tileMap->getTile(0,iii)->m_tile);
	}
}

void GameState::render(sf::RenderTarget* target)
{
	target->draw(m_background);

	m_tileMap->render(target);
	this->renderButtons(target);
	this->renderCreatures(target);

	if (m_isPaused == true)
	{
		m_pauseMenu->render(target);
	}
}

void GameState::renderButtons(sf::RenderTarget* target)
{
	
}

void GameState::renderCreatures(sf::RenderTarget* target)
{
	for (auto* creature : m_creatures)
	{
		creature->render(target);
	}
}
