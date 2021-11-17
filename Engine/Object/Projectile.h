//#pragma once
//#include "Actor.h"
//#include "Graphics/Texture.h"
//
//namespace ag {
//
//	class Projectile : public Actor {
//	public:
//		Projectile(const Transform& transform, std::shared_ptr<Texture> texture, float speed) : Actor{ transform, texture }, speed{ speed } {}
//		Projectile(const Transform& transform, std::shared_ptr<Texture> texture, float speed, float lifetime) : Actor{ transform, texture }, speed{ speed }, lifetime{ lifetime } {}
//
//		void Update(float dt) override;
//	private:
//		float lifetime{ 2 };
//		float speed = 100;
//	};
//}