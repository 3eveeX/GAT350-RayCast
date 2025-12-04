#pragma once
#include <glm/glm.hpp>
#include "Color.h"

struct Ray
{
	glm::vec3 origin;
	glm::vec3 direction;

	Ray() = default;
	Ray(glm::vec3 origin, glm::vec3 direction) : origin(origin), direction(direction) {}

	glm::vec3 at(float t) const {
		return origin + t * direction;
	}

	glm::vec3 operator * (float t) const {
		return at(t);
	}
};

struct rayCastHit {
	glm::vec3 point;
	glm::vec3 normal;
	float distance;

	color3_t color;
};