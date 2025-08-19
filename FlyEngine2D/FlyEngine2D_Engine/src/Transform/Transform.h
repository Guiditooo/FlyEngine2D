#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <iostream>
#include <vector>

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

#include "Exports.h"

#include "TransformComponent/TransformComponent.h"
#include "BoundingBox/BoundingBox.h"

namespace FlyEngine
{
	namespace Entities
	{
		class Entity;
	}

	class FLY_API Transform
	{
	private:
		TransformComponent* worldTransform;
		TransformComponent* localTransform;

		std::vector<Transform*> children;
		Transform* parent;

		Entities::Entity* entity;

		bool dirty;

		void UpdateMatrices();
		void FreeLocalMatrix();

		void UpdateBoundingBox();

		void MarkDirty();
		void UpdateIfDirty();

	public:
		inline static const glm::vec3 WORLD_UP = glm::vec3(0, 1, 0);
		inline static const glm::vec3 WORLD_RIGHT = glm::vec3(1, 0, 0);
		inline static const glm::vec3 WORLD_FORWARD = glm::vec3(0, 0, 1);

		Transform(Entities::Entity* entity = nullptr);
		~Transform();

		void SetWorldPosition(float x, float y, float z);
		void SetLocalPosition(float x, float y, float z);

		void SetWorldRotation(float x, float y, float z);
		void SetWorldRotation(glm::quat rot);
		void SetLocalRotation(float x, float y, float z);
		void SetLocalRotation(glm::quat rot);

		void SetWorldScale(float x, float y, float z);
		void SetLocalScale(float x, float y, float z);

		void WorldTranslate(float x, float y, float z);
		void LocalTranslate(float x, float y, float z);
		void WorldTranslate(glm::vec3 amount);
		void LocalTranslate(glm::vec3 amount);

		void WorldRotate(float x, float y, float z);
		void LocalRotate(float x, float y, float z);

		void WorldRotateAround(float x, float y, float z);
		void LocalRotateAround(float x, float y, float z);

		void WorldScale(float x, float y, float z);
		void LocalScale(float x, float y, float z);

		glm::vec3 GetWorldPosition();
		glm::vec3 GetLocalPosition();

		glm::vec3 GetWorldRotation();
		glm::vec3 GetLocalRotation();

		glm::vec3 GetWorldScale();
		glm::vec3 GetLocalScale();

		void SetWorldFront(glm::vec3 front);
		void SetLocalFront(glm::vec3 front);
		void SetWorldUp(glm::vec3 up);
		void SetLocalUp(glm::vec3 up);
		void SetWorldRight(glm::vec3 right);
		void SetLocalRight(glm::vec3 right);

		glm::vec3 GetWorldFront();
		glm::vec3 GetLocalFront();
		glm::vec3 GetWorldUp();
		glm::vec3 GetLocalUp();
		glm::vec3 GetWorldRight();
		glm::vec3 GetLocalRight();

		void UpdateLocalMatrix();
		void UpdateWorldMatrix();

		Utils::BoundingBox GetWorldBoundingBox();

		glm::mat4 GetLocalTRS();
		glm::mat4 GetWorldTRS();

		Transform* GetParent();
		Transform* GetRoot();
		std::vector<Transform*> GetChildren();
		std::vector<Transform*> GetChildrenWithName(std::string childName);

		void AddChild(Transform* newChild);
		void SetParent(Transform* newParent);

		void RemoveChild(Transform* child);
		void RemoveParent();

		void SetEntity(Entities::Entity* entity);

		Entities::Entity* GetEntity();
	};
}

#endif // !TRANSFORM_H