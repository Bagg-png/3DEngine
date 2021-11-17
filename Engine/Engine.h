#pragma once

#define REGISTER_CLASS(class) ag::ObjectFactory::Instance().Register<class>(#class);

//Systems
#include "Input/InputSystem.h"
#include "Audio/AudioSystem.h"
#include "Resource/ResourceSystem.h"
//Core
#include "Core/FileSystem.h"
#include "Core/Timer.h"
#include "Core/Utilities.h"
#include "Core/json.h"
#include "Core/Serializable.h"
//Framework
#include "Framework/EventSystem.h"
#include "Framework/Singleton.h"
#include "Framework/Factory.h"
//Math
#include "Math/Random.h"
#include "Math/MathUtils.h"
#include "Math/Transform.h"
#include "Math/MathTypes.h"
//Graphics
#include "Graphics/Renderer.h"
#include "Graphics/Texture.h"
//Objects
#include "Object/Actor.h"
#include "Object/Player.h"
#include "Object/Upgrade.h"
#include "Object/Enemy.h"
#include "Object/Scene.h"
//Components
#include "Component/AudioComponent.h"
#include "Component/PhysicsComponent.h"

//#include <algorithm>
//#include <vector>
#include <memory>

namespace ag 
{
	using ObjectFactory = Singleton<Factory<std::string, Object>>;
	class Engine 
	{
	public:
		void StartUp();
		void ShutDown();

		void Update();
		void Draw(Renderer* renderer);

		template<typename T>
		T* Get();

	public:
		FrameTimer time;

	private:
		std::vector<std::unique_ptr<System>> systems;
	};
	template<typename T>
	inline T* Engine::Get()
	{
		for (auto& system : systems) 
		{
			if (dynamic_cast<T*>(system.get())) return dynamic_cast<T*>(system.get());
		}
		return nullptr;
	}
}