#pragma once
#include <chrono>
#include <SDL.h>

namespace ag {
	class Timer {
	public:
		using clock = std::chrono::high_resolution_clock;
		using clock_duration = clock::duration;
		using clock_tick_type = clock::rep;

		Timer() : timePoint{ clock::now() } {}
		void Reset() { timePoint = clock::now(); }
		clock_tick_type ElapsedTicks();
		float ElapsedSeconds();
	protected:
		
		//std::chrono::SDL_RENDERER_ACCELERATED::timePoint;
		clock::time_point timePoint;
	};

	class FrameTimer : public Timer {
	public:
		FrameTimer() : frameTimePoint{ clock::now() }, startTimePoint{clock::now()} {}
		void Tick();
	public:
		float timeScale{ 1 };
		float deltaTime{ 0 };
		float time{ 0 };
		bool quit = false;
		float start{ 0 };
		float now{ 0 };

	private:
		clock::time_point frameTimePoint;
		clock::time_point startTimePoint;
	};
}