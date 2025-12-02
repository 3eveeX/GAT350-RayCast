#include "Camera.h"

void Camera::SetView(const glm::vec3& eye, const glm::vec3& target, const glm::vec3& up) {
	this->eye = eye;

	// create camera axis
	this->forward = glm::normalize(target - eye);
	this->right = glm::normalize(glm::cross(glm::vec3(0, 1, 0), forward));
	this->up = glm::cross(forward, right);

	CalculateViewPlane();
}

void Camera::CalculateViewPlane() {
    float theta = glm::radians(fov);
    float halfHeight = glm::tan(theta / 2.0f);
    float halfWidth = aspectRatio * halfHeight;

    horizontal = right * halfWidth * 2.0f;
    vertical = up * halfHeight * 2.0f;
    lowerLeft = eye + forward - right * halfWidth - up * halfHeight;
}

Ray Camera::GetRay(const glm::vec2& uv) const {
    Ray ray;
    ray.origin = eye;
    ray.direction = glm::normalize(lowerLeft + horizontal * uv.x + vertical * uv.y - eye);
    return ray;
}

