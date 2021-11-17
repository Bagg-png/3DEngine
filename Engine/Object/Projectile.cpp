//#include "Projectile.h"
//#include "Player.h"
//#include "Engine.h"
//
//namespace ag {
//
//	void Projectile::Update(float dt)
//	{
//		Actor::Update(dt);
//
//		lifetime -= dt;
//		//if (lifetime <= 0) destroy = true;   OR |
//		destroy = (lifetime <= 0);			//	  V
//
//		transform.position += ag::Vector2::Rotate(ag::Vector2::right, transform.rotation) * speed * dt;
//		transform.position.x = ag::Wrap(transform.position.x, 0.0f, 800.0f);
//		transform.position.y = ag::Wrap(transform.position.y, 0.0f, 600.0f);
//
//
//		//std::vector<Color> colors = { Color::white, Color::red, Color::green, nc::Color::blue, nc::Color::purple, nc::Color::orange, nc::Color::yellow, nc::Color::cyan };
//		scene->engine->Get<ParticleSystem>()->Create(transform.position, 10, 1, this->texture, 10);
//
//		transform.Update();
//	}
//}
