#pragma once


namespace Geometry
{
	//Cztery prze�adowane funkcje dla r�wnych typ�w (int i float)
	int getAngleRelativelyToGround(
		const sf::Vector2i& pointOne, const sf::Vector2i& pointTwo);

	int getAngleRelativelyToGround(
		const sf::Vector2f& pointOne, const sf::Vector2f& pointTwo);

	int getAngleRelativelyToGround(
		const sf::Vector2f& pointOne, const sf::Vector2i& pointTwo);

	int getAngleRelativelyToGround(
		const sf::Vector2i& pointOne, const sf::Vector2f& pointTwo);
}

