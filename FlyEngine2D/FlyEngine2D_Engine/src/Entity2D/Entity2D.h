#pragma once

#include "Entity/Entity.h"

namespace FlyEngine
{
	namespace Entities
	{
		class FLY_API Entity2D : public Entity
		{
		private:
			int drawOrder;
		public:
			Entity2D(std::string name, int drawOrder = 0);
		};
	}
}