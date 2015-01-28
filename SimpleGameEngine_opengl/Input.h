#pragma once

#include <vector>
#include <xutility>
#include "SFML\Window\Window.hpp"

using keyMap = std::vector<int>;

class Input
{
private:
	static keyMap keyUp;
	static keyMap keyDown;
	static keyMap keyCurrent;

	static keyMap mouseUp;
	static keyMap mouseDown;
	static keyMap mouseCurrent;

public:

	static const unsigned int NUM_KEYS = 256;
	static const unsigned int NUM_MOUSE_KEYS = 10;

	static void update();

	static bool getKey(const unsigned int keyCode);
	static bool getMouse(const unsigned int keyCode);
	static sf::Vector2i getMousePosition(const sf::Window* relativeTo);

	static bool getKeyUp(const unsigned int keyCode);
	static bool getKeyDown(const unsigned int keyCode);
	static bool getMouseUp(const unsigned int keyCode);
	static bool getMouseDown(const unsigned int keyCode);


	Input();
	~Input();
};

