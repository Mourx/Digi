#include "Button.h"



Button::Button(std::function<void()>foo)
{
	function = foo;

}


Button::~Button()
{
}

void Button::SetOnClick(std::function<void()> foo) {
	function = foo;
}

void Button::OnClick() {
	function();
}