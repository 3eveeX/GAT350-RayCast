#pragma once
#include "Object.h"

class Sphere : public Object
{
public:
	Sphere() = default;
	Sphere(const Transform& transform, float radius, std::shared_ptr<Material> material) :
		Object(transform, material),
		radius(radius),
		position(transform.position)
	{
	}

	bool Hit(const Ray& ray, float minDistance, float maxDistance, rayCastHit& raycastHit) override;

public:
	glm::vec3 position;
	float radius{ 0 };
};