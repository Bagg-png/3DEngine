//#include "Player.h"
//#include "Projectile.h"
//#include "engine.h"
//#include "Enemy.h"
//#include "Upgrade.h"
//#include <memory>
//
//namespace ag {
//
//	Player::Player(const ag::Transform& transform, std::shared_ptr<Texture> texture, std::shared_ptr<Texture> bulletR, std::shared_ptr<Texture> bulletB, std::shared_ptr<Texture> bulletY, float speed)
//	{
//		this->transform = transform;
//		/*this->texture = texture;
//		this->bulletR = bulletR;
//		this->bulletB = bulletB;
//		this->bulletY = bulletY;*/
//		this->speed = speed;
//	}
//
//	void Player::Initialize() {
//		std::unique_ptr locator = std::make_unique<Actor>();
//		locator->transform.localPosition = ag::Vector2{ 10,0 };
//		AddChild(std::move(locator));
//
//		locator = std::make_unique<Actor>();
//		locator->transform.localPosition = ag::Vector2{ 0,5 };
//		AddChild(std::move(locator));
//
//		locator = std::make_unique<Actor>();
//		locator->transform.localPosition = ag::Vector2{ 0,-5 };
//		AddChild(std::move(locator));
//
//		//Create 3 cores for all the colors
//		/*std::unique_ptr powerCore1 = std::make_unique<Actor>(ag::Transform{ ag::Vector2{400.0f, 300.0f}, 0.0f, 20.0f }, scene->engine->Get<ag::ResourceSystem>()->Get<ag::Shape>("powerCoreB.txt"));
//		std::unique_ptr powerCore2 = std::make_unique<Actor>(ag::Transform{ ag::Vector2{400.0f, 300.0f}, 90.0f, 20.0f }, scene->engine->Get<ag::ResourceSystem>()->Get<ag::Shape>("powerCoreB.txt"));
//
//		powerCore1->transform.localPosition = ag::Vector2{ -5,0 };
//		AddChild(std::move(powerCore1));
//
//		powerCore2->transform.localPosition = ag::Vector2{ -5,0 };
//		AddChild(std::move(powerCore2));*/
//	}
//
//	void Player::Update(float dt)
//	{
//		Actor::Update(dt);
//
//		//movement
//		float thrust = 0;
//		colorTimer -= dt;
//
//		if (scene->engine->Get<ag::InputSystem>()->GetKeyState(SDL_SCANCODE_D) == ag::eKeyState::HELD) transform.rotation -= -4 * dt;
//		if (scene->engine->Get<ag::InputSystem>()->GetKeyState(SDL_SCANCODE_A) == ag::eKeyState::HELD) transform.rotation += -4 * dt;
//		if (scene->engine->Get<ag::InputSystem>()->GetKeyState(SDL_SCANCODE_W) == ag::eKeyState::HELD) thrust = speed;
//		if (scene->engine->Get<ag::InputSystem>()->GetKeyState(SDL_SCANCODE_S) == ag::eKeyState::HELD && colorTimer <= 0) {
//			colorTimer = colorRate;
//			SwapColor();
//		}
//			std::unique_ptr powerCore1 = std::make_unique<Actor>();
//			std::unique_ptr powerCore2 = std::make_unique<Actor>();
//			//	switch (currentColor)
//			//	{
//			//	case 0:
//			//		powerCore1 = std::make_unique<Actor>(ag::Transform{ ag::Vector2{400.0f, 300.0f}, 0.0f, 20.0f }, scene->engine->Get<ag::ResourceSystem>()->Get<ag::Shape>("powerCoreB.txt"));
//			//		powerCore2 = std::make_unique<Actor>(ag::Transform{ ag::Vector2{400.0f, 300.0f}, 90.0f, 20.0f }, scene->engine->Get<ag::ResourceSystem>()->Get<ag::Shape>("powerCoreB.txt"));
//			//		break;
//			//	case 1:
//			//		powerCore1 = std::make_unique<Actor>(ag::Transform{ ag::Vector2{400.0f, 300.0f}, 0.0f, 20.0f }, scene->engine->Get<ag::ResourceSystem>()->Get<ag::Shape>("powerCoreY.txt"));
//			//		powerCore2 = std::make_unique<Actor>(ag::Transform{ ag::Vector2{400.0f, 300.0f}, 90.0f, 20.0f }, scene->engine->Get<ag::ResourceSystem>()->Get<ag::Shape>("powerCoreY.txt"));
//			//		break;
//			//	case 2:
//			//		powerCore1 = std::make_unique<Actor>(ag::Transform{ ag::Vector2{400.0f, 300.0f}, 0.0f, 20.0f }, scene->engine->Get<ag::ResourceSystem>()->Get<ag::Shape>("powerCoreG.txt"));
//			//		powerCore2 = std::make_unique<Actor>(ag::Transform{ ag::Vector2{400.0f, 300.0f}, 90.0f, 20.0f }, scene->engine->Get<ag::ResourceSystem>()->Get<ag::Shape>("powerCoreG.txt"));
//			//		break;
//			//	default:
//			//		break;
//			//	}
//			//	powerCore1->transform.localPosition = ag::Vector2{ -5,0 };
//			//	AddChild(std::move(powerCore1));
//
//			//	powerCore2->transform.localPosition = ag::Vector2{ -5,0 };
//			//	AddChild(std::move(powerCore2));
//			//}
//
//
//			ag::Vector2 acceleration;
//			acceleration = ag::Vector2::Rotate(ag::Vector2::right, transform.rotation) * thrust * dt;
//			////ag::Vector2 gravity = (ag::Vector2{ 400,300 } - transform.position).Normalized() * 50;
//			////ag::Vector2 gravity = ag::Vector2::down * 50;
//			////acceleration += gravity;
//
//			velocity += acceleration * dt;
//			////transform.position += velocity * dt;
//			transform.position += ag::Vector2::Rotate(ag::Vector2::right, transform.rotation) * thrust * dt;
//
//			////velocity *= 0.975f;
//
//			transform.position.x = ag::Wrap(transform.position.x, 0.0f, 800.0f);
//			transform.position.y = ag::Wrap(transform.position.y, 0.0f, 600.0f);
//
//			//hurtTimer -= dt;
//			//fire
//			fireTimer -= dt;
//			if (fireTimer <= 0 && scene->engine->Get<ag::InputSystem>()->GetKeyState(SDL_SCANCODE_SPACE) == ag::eKeyState::PRESSED) {
//				fireTimer = fireRate;
//				//std::vector<ag::Vector2> points = { {-5,-5},{5,-5},{0,10},{-5,-5} };
//				//std::shared_ptr<ag::Shape> shape = std::make_shared<ag::Shape>(points, ag::Color{ 1,0,0 });
//				//{
//					Transform t = this->transform;
//					switch (weaponLevel)
//					{
//					case 1:
//						t.scale = 1.0f;
//						break;
//					case 2:
//						t.scale = 2.0f;
//						break;
//					case 3:
//						t.scale = 3.0f;
//						break;
//					case 4:
//						t.scale = 4.0f;
//						break;
//					case 5:
//						t.scale = 5.0f;
//						break;
//					case 6:
//						t.scale = 6.0f;
//						break;
//					default:
//						t.scale = 7.0f;
//					}
//
//					//std::unique_ptr<Projectile> projectile;
//					switch (currentColor)
//					{
//					case 0:
//						//Blue
//						//projectile = std::make_unique<Projectile>(t, bulletB, 100.0f);
//						projectile->tag = "blue";
//						break;
//					case 1:
//						//Yellow
//						//projectile = std::make_unique<Projectile>(t, bulletY, 100.0f);
//						projectile->tag = "yellow";
//						break;
//					case 2:
//						//Red
//						//projectile = std::make_unique<Projectile>(t, bulletR, 100.0f);
//						projectile->tag = "red";
//						break;
//					}
//					scene->AddActor(std::move(projectile));
//			}
//				//scene->engine->Get<ag::AudioSystem>()->PlayAudio("playerFire");
//			//}
//
//			//std::vector<ag::Color> colors = { ag::Color::white, ag::Color::blue, ag::Color::red };
//			//scene->engine->Get<ag::ParticleSystem>()->Create(children[0]->transform.position, 3, 2, colors, 10, children[0]->transform.rotation, ag::DegToRad(30));
//	}
//
//		void Player::OnCollision(Actor * actor)
//		{
//			//if (dynamic_cast<Upgrade*>(actor)) {
//			//	weaponLevel += 1;
//			//}
//			//if (dynamic_cast<Enemy*>(actor)) {
//			//	destroy = true;
//			//	//scene->engine->Get<ag::ParticleSystem>()->Create(transform.position, 200, 1, ag::Color::white, 50);
//			//	//scene->engine->Get<ag::AudioSystem>()->PlayAudio("explosion");
//
//			//	ag::Event event;
//			//	event.name = "PlayerDead";
//			//	event.data = std::string("yes I'm dead!");
//			//	scene->engine->Get<ag::EventSystem>()->Notify(event);
//			//}
//		}
//
//		void Player::SwapColor() {
//			currentColor += 1;
//			if (currentColor > 2) {
//				currentColor = 0;
//			}
//		}
//	}
