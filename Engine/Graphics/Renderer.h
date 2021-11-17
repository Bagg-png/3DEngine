#pragma once
#include "Framework/System.h"
#include "Math/Transform.h"
#include "Math/MathUtils.h"
#include <glad/glad.h>
#include <SDL.h>
#include <string>

namespace ag {
	class Renderer : public System {
	public:
		void StartUp() override;
		void ShutDown() override;
		void Update(float dt) override;

		void Create(const std::string& name, int width, int height);
		void BeginFrame();
		void EndFrame();

		friend class Texture;
	private:
		SDL_GLContext context;
		SDL_Renderer* renderer = nullptr;
		SDL_Window* window = nullptr;
	};
}