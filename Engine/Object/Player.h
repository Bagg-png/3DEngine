//#pragma once
//#include "Object/Actor.h"
////#include "Graphics/Texture.h"
//
//namespace ag {
//	class Texture;
//
//	class Player : public Actor {
//
//	public:
//		Player(const ag::Transform& transform, std::shared_ptr<Texture> texture, std::shared_ptr<Texture> bulletR, std::shared_ptr<Texture> bulletB, std::shared_ptr<Texture> bulletY, float speed);
//
//		void Initialize() override;
//
//		void Update(float dt) override;
//		void OnCollision(Actor* actor) override;
//
//		void SwapColor();
//
//	public:
//		int currentColor = 0;
//	private:
//		int lives = 3;
//
//		int weaponLevel = 1;
//
//		float colorTimer = 0;
//		float colorRate = 1.0f;
//
//		float fireTimer = 0;
//		float fireRate = 0.5f;
//
//		float hurtTimer = 0;
//		float hurtRate = 20.5f;
//
//		float speed = 300;
//		ag::Vector2 velocity;
//	};
//}