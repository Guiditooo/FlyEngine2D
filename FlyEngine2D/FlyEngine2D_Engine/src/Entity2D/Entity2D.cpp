#include "Entity2D.h"

namespace FlyEngine
{
	namespace Entities
	{
		Entity2D::Entity2D(std::string name, int drawOrder) : Entity(name)
		{
			this->drawOrder = drawOrder;
		}
	}
}