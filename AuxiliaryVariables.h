#pragma once
class Constants
{
public:
	static const unsigned WindowHeigth;
	static const unsigned WindowWidth;

	static const unsigned gridSizeU;
	static const float gridSizeF;

	static const unsigned mapSizeX;
	static const unsigned mapSizeY;

	static const int spikeDamage;

	static const float pi;

	static const float playerSizeX;
	static const float playerSizeY;
};

class RealeseDetection
{
public:
	static bool Escape;
	static bool escapeRealese();

	static bool mouseLeftButton;
	static bool mouseRealese();
};

class deltaTime
{
public:
	static float timePerFrame;
};

int getRandomInt(int min, int max);

