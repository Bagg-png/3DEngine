#pragma once
#include "Framework/System.h"
#include "Math/MathTypes.h"
#include <SDL.h>
#include <vector>
#include <array>

namespace ag {
	enum class eKeyState {
		IDLE,
		PRESSED,
		HELD,
		RELEASE
	};
	enum class eMouseButton {
		LEFT,
		MIDDLE,
		RIGHT
	};

	class InputSystem : public System {
	public:
		virtual void StartUp();
		virtual void ShutDown();
		virtual void Update(float dt);

		//const Uint8* SDL_GetKeyboardState(int* numkeys);

		eKeyState GetKeyState(int id);

		bool IsKeyDown(int id) const;
		bool IsPreviousKeyDown(int id) const;

		const glm::vec3& GetMousePosition() const { return mousePosition; }
		bool IsButtonDown(int id) { return mouseButtonState[id]; }
		bool IsPreviousButtonDown(int id) { return prevMouseButtonState[id]; }
		eKeyState GetButtonState(int id);
	private:
		std::vector<Uint8> keyboardState;
		std::vector<Uint8> prevKeyboardState;
		int numKeys;

		glm::vec3 mousePosition;
		std::array<Uint8, 3> mouseButtonState;
		std::array<Uint8, 3> prevMouseButtonState;
	};
}
