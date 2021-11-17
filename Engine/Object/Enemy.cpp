//#include "Enemy.h"
//#include "Player.h"
//#include "Engine.h"
//#include "Projectile.h"
//
//namespace ag {
//
//	void Enemy::Update(float dt)
//	{
//		Actor::Update(dt);
//
//		if (scene->GetActor<Player>()) {
//			ag::Vector2 direction = scene->GetActor<Player>()->transform.position - transform.position;
//			ag::Vector2 forward = ag::Vector2::Rotate(ag::Vector2::right, transform.rotation);
//
//			float turnAngle = ag::Vector2::SignedAngle(forward, direction.Normalized());
//			transform.rotation = transform.rotation + turnAngle * (2 * dt);
//			//transform.rotation = ag::Lerp(transform.rotation, transform.rotation + turnAngle, dt * 2);
//
//			float angle = ag::Vector2::Angle(forward, direction.Normalized());
//
//			/*fireTimer -= dt;
//			if (fireTimer <= 0 && angle <= ag::DegToRad(10)) {
//				fireTimer = fireRate;
//				std::vector<ag::Vector2> points = { {-5,-5},{5,-5},{0,10},{-5,-5} };
//				std::shared_ptr<ag::Shape> shape = std::make_shared<ag::Shape>(points, ag::Color{ 1,0,0 });
//
//				ag::Transform t = transform;
//				t.scale = 1.0f;
//				scene->AddActor(std::make_unique<Projectile>(t, scene->engine->Get<ag::ResourceSystem>()->Get<ag::Shape>("bomb.txt"), 80.0f));
//				scene->engine->Get<ag::AudioSystem>()->PlayAudio("enemyFire");
//			}*/
//		}
//
//		transform.position += ag::Vector2::Rotate(ag::Vector2::right, transform.rotation) * speed * dt;
//		transform.position.x = ag::Wrap(transform.position.x, 0.0f, 800.0f);
//		transform.position.y = ag::Wrap(transform.position.y, 0.0f, 600.0f);
//	}
//
//	void Enemy::OnCollision(Actor* actor)
//	{
//		if (dynamic_cast<Projectile*>(actor) && actor->tag == color) {
//			actor->destroy = true;
//			destroy = true;
//			scene->engine->Get<ag::ParticleSystem>()->Create(transform.position, 200, 1, this->texture, 50);
//			//scene->engine->Get<ag::AudioSystem>()->PlayAudio("explosion");
//
//			ag::Event event;
//			event.name = "AddPoints";
//			event.data = 300;
//			scene->engine->Get<ag::EventSystem>()->Notify(event);
//		}
//	}
//}