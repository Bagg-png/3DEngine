#include "InputSystem.h"
#include <algorithm>

void ag::InputSystem::StartUp()
{
	const Uint8* keyboardStateSDL = SDL_GetKeyboardState(&numKeys);
	keyboardState.resize(numKeys);
	std::copy(keyboardStateSDL,keyboardStateSDL,keyboardState.begin());
	prevKeyboardState = keyboardState;
}

void ag::InputSystem::ShutDown()
{
	
}

void ag::InputSystem::Update(float dt)
{
	prevKeyboardState = keyboardState;
	//ERROR
	const Uint8* keyboardStateSDL = SDL_GetKeyboardState(nullptr);
	std::copy(keyboardStateSDL, keyboardStateSDL + numKeys, keyboardState.begin());
	prevMouseButtonState = mouseButtonState;
	int x, y;
	Uint32 buttons = SDL_GetMouseState(&x, &y);
	mousePosition = ag::Vector2{ x, y };
	mouseButtonState[0] = buttons & SDL_BUTTON_LMASK; //[0001]
	mouseButtonState[0] = buttons & SDL_BUTTON_RMASK; //[0010]
	mouseButtonState[0] = buttons & SDL_BUTTON_MMASK; //[0100]
}

bool ag::InputSystem::IsKeyDown(int id) const
{
	return keyboardState[id];
}

bool ag::InputSystem::IsPreviousKeyDown(int id) const
{
	return prevKeyboardState[id];
}

ag::eKeyState ag::InputSystem::GetButtonState(int id)
{
	eKeyState state = eKeyState::IDLE;
	bool keyDown = IsButtonDown(id);
	bool prevKeyDown = IsPreviousButtonDown(id);
	if (keyDown) {
		state = (prevKeyDown) ? eKeyState::HELD : eKeyState::PRESSED;
	}
	else {
		state = (prevKeyDown) ? eKeyState::RELEASE : eKeyState::IDLE;
	}
	return state;
}

ag::eKeyState ag::InputSystem::GetKeyState(int id)
{
	eKeyState state = eKeyState::IDLE;
	bool keyDown = IsKeyDown(id);
	bool prevKeyDown = IsPreviousKeyDown(id);
	if (keyDown) {
		state = (prevKeyDown) ? eKeyState::HELD : eKeyState::PRESSED;
	}
	else {
		state = (prevKeyDown) ? eKeyState::RELEASE : eKeyState::IDLE;
	}
	return state;
}