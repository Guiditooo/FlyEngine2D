#ifndef TRANSFORM_ELEMENT_H
#define TRANSFORM_ELEMENT_H

#include <mat4x4.hpp>
#include <vec3.hpp>
#include <gtc/quaternion.hpp>
#include <gtx/quaternion.hpp>

#include "Exports.h"

namespace FlyEngine
{
	struct FLY_API TransformElement
	{
	public:
		glm::mat4 matrix = glm::mat4();
		glm::vec3 vector = glm::vec3();

	protected:
		glm::quat EulerToQuat(glm::vec3 euler);
		glm::mat4 EulerToMat4(glm::vec3 euler);
		glm::vec3 Mat4ToEuler(glm::mat4 matrix);
		glm::vec3 QuaternionToEuler(glm::quat quat);
		glm::vec3 QuatToVec(glm::quat quat, glm::vec3 vec);
		glm::quat QuaternionLookRotation(glm::vec3 forward, glm::vec3 upwards);
	};
}

#endif // !TRANSFORM_ELEMENT_H