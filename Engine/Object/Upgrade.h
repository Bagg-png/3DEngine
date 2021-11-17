//#pragma once
//#include "Actor.h"
//
//namespace ag {
//
//	class Upgrade : public Actor {
//	public:
//		Upgrade(const Transform& transform, std::shared_ptr<Texture> texture) : Actor{ transform, texture } {}
//		Upgrade(const Transform& transform, std::shared_ptr<Texture> texture, float lifetime) : Actor{ transform, texture }, lifetime{ lifetime } {}
//
//		void OnCollision(Actor* actor) override;
//
//		void Update(float dt) override;
//	private:
//		float lifetime{ 20 };
//	};
//}
