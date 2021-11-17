#include "Graphics/Renderer.h"
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <iostream>

namespace ag {
	void Renderer::StartUp()
	{
		if (SDL_Init(SDL_INIT_VIDEO) != 0) {
			std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		}

		IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
		TTF_Init();
	}
	void Renderer::ShutDown()
	{
		SDL_GL_DeleteContext(context);
		SDL_DestroyWindow(window);
		IMG_Quit();
		TTF_QUIT();
		SDL_QUIT();
	}
	void Renderer::Update(float dt)
	{
	}
	void Renderer::Create(const std::string& name, int width, int height)
	{
		int result = SDL_Init(SDL_INIT_VIDEO);
		if (result != 0)
		{
			SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		}



		SDL_Window* window = SDL_CreateWindow("OpenGL", 100, 100, 800, 600, SDL_WINDOW_OPENGL);
		if (window == nullptr)
		{
			SDL_Log("Failed to create window: %s", SDL_GetError());
		}



		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);



		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
		SDL_GL_SetSwapInterval(1);

		 window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);

		/*if (window == nullptr) {
			std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
			SDL_Quit();
		}*/

	 renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
	}
	void Renderer::BeginFrame()
	{
		SDL_RenderClear(renderer);
		glClearColor(0, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);
	}
	void Renderer::EndFrame()
	{
		SDL_RenderPresent(renderer);
		SDL_GL_SwapWindow(window);
	}

	
}