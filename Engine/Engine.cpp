#include "Engine.h"

namespace ag {

	void Engine::StartUp()
	{
		systems.push_back(std::make_unique<Renderer>());
		systems.push_back(std::make_unique<EventSystem>());
		systems.push_back(std::make_unique<ResourceSystem>());
		systems.push_back(std::make_unique<InputSystem>());
		systems.push_back(std::make_unique<AudioSystem>());

		std::for_each(systems.begin(), systems.end(), [](auto& system) {system->StartUp(); });
		
		REGISTER_CLASS(Actor)
		REGISTER_CLASS(PhysicsComponent)
		REGISTER_CLASS(AudioComponent)
	}

	void Engine::ShutDown()
	{
		std::for_each(systems.begin(), systems.end(), [](auto& system) {system->ShutDown(); });
	}

	void Engine::Update()
	{
		time.Tick();
		std::for_each(systems.begin(), systems.end(), [this](auto& system) {system->Update(this->time.deltaTime); });
	}

	void Engine::Draw(Renderer* renderer)
	{
		//

	}
}