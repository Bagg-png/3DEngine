//#pragma once
//#include "Object/Actor.h"
//#include <string>
//
//namespace ag {
//
//	class Enemy : public Actor {
//		//class Texture;
//	public:
//		Enemy(const ag::Transform& transform, std::shared_ptr<Texture> texture, std::string color, float speed) : Actor{ transform}, color{ color }, speed{ speed } {}
//		void Update(float dt) override;
//
//		void OnCollision(Actor* actor) override;
//	private:
//		std::string color;
//		float speed = 70;
//		float fireTimer = 0;
//		float fireRate = 3.0f;
//	};
//}