#pragma once
#include "Color.h"
#include "Ray.h"
#include "Material.h"
#include "Transform.h"
#include <memory>

class Object
{
public:
	Object() = default;
	Object(const Transform& transform, std::shared_ptr<Material> material) :
		transform{ transform },
		material{ material }
	{
	}

	virtual bool Hit(const Ray& ray, float minDistance, float maxDistance, rayCastHit& raycastHit) = 0;

public:
	Transform transform;
	std::shared_ptr<Material> material;
};