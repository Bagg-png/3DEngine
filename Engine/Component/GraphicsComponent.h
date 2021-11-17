#pragma once
#include "Component.h"

namespace ag {
	class Renderer;

	class GraphicsComponent : public Component {
	public:
		virtual void Draw(Renderer* renderer) = 0;
	};
}