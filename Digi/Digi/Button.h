#pragma once
#include "SFML/Graphics.hpp"
#include <functional>

class Button
{
public:
	Button(std::function<void()> foo);
	~Button();
	void SetOnClick(std::function<void()> foo);
	void OnClick();
	sf::Sprite icon;	
private:
	std::function<void()> function;

};

