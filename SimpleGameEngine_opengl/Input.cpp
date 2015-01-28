#include "SFML\Window\Keyboard.hpp"
#include "SFML\Window\Mouse.hpp"
#include "SFML\Window\Window.hpp"

#include <vector>

#include "Input.h"
#include "MainComponent.h"

bool contains(const keyMap &vec, const int &value)
{
	return std::find(vec.begin(), vec.end(), value) != vec.end();
}


void Input::update()
{

	mouseUp.clear();

	for (int i = 0; i < NUM_MOUSE_KEYS; i++)
	{
		if (!getMouse(i) && contains(mouseCurrent, i))
		{
			mouseUp.push_back(i);
		}
	}

	mouseDown.clear();

	for (int i = 0; i < NUM_MOUSE_KEYS; i++)
	{
		if (getMouse(i) && !contains(mouseCurrent, i))
		{
			mouseDown.push_back(i);
		}
	}

	mouseCurrent.clear();

	for (int i = 0; i < NUM_MOUSE_KEYS; i++)
	{
		if (getMouse(i))
			mouseCurrent.push_back(i);
	}

	keyUp.clear();

	for (int i = 0; i < NUM_KEYS; i++)
	{
		if (!getKey(i) && contains(keyCurrent, i))
		{
			keyUp.push_back(i);
		}
	}

	keyDown.clear();

	for (int i = 0; i < NUM_KEYS; i++)
	{
		if (getKey(i) && !contains(keyCurrent, i))
		{
			keyDown.push_back(i);
		}
	}

	keyCurrent.clear();

	for (int i = 0; i < NUM_KEYS; i++)
	{
		if (getKey(i))
			keyCurrent.push_back(i);
	}
}

bool Input::getKey(const unsigned int keyCode)
{
	return sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(keyCode));
}

bool Input::getMouse(const unsigned int keyCode)
{
	return sf::Mouse::isButtonPressed(static_cast<sf::Mouse::Button>(keyCode));
}

sf::Vector2i Input::getMousePosition(const sf::Window* relativeTo)
{
	return sf::Mouse::getPosition(*relativeTo);
}


bool Input::getKeyUp(const unsigned int keyCode)
{
	return contains(keyUp, keyCode);
}

bool Input::getKeyDown(const unsigned int keyCode)
{
	return contains(keyDown, keyCode);
}


bool Input::getMouseUp(const unsigned int keyCode)
{
	return contains(mouseUp, keyCode);
}

bool Input::getMouseDown(const unsigned int keyCode)
{
	return contains(mouseDown, keyCode);
}

Input::Input()
{
}


Input::~Input()
{
}

void Input::setMousePosition(sf::Vector2i pos, const sf::Window* relativeTo)
{
	sf::Mouse::setPosition(sf::Vector2i(pos.x, pos.y), *relativeTo);
}

void Input::setCursorLock(sf::Window* window, bool isLocked)
{
	window->setMouseCursorVisible(!isLocked);
	mouseLocked = isLocked;
	sf::Vector2i centerPos = sf::Vector2i(window->getSize().x / 2, window->getSize().y / 2);
	setMousePosition(centerPos, window);
}

keyMap Input::keyCurrent;
keyMap Input::keyUp;
keyMap Input::keyDown;

keyMap Input::mouseCurrent;
keyMap Input::mouseUp;
keyMap Input::mouseDown;

bool Input::mouseLocked = false;