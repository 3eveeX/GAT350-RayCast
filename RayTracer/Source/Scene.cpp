#include "Scene.h"
#include "Framebuffer.h"
#include "Camera.h"
#include "Color.h"
#include <iostream>
#include <glm/glm.hpp>

void Scene::Render(Framebuffer& framebuffer, const Camera& camera) {
	// trace ray for every framebuffer pixel
	for (int y = 0; y < framebuffer.height; y++) {
		for (int x = 0; x < framebuffer.width; x++)	{
		
			// set pixel (x,y) coordinates)
			glm::vec2 pixel = { x, y };
			// normalize (0 <-> 1) the pixel value (pixel / { framebuffer.width, framebuffer.height }
			glm::vec2 point = pixel / glm::vec2{ framebuffer.width - 1, framebuffer.height - 1 };
			// flip the y value (bottom = 0, top = 1)
			point.y = 1 - point.y;

			// get ray from camera
			 Ray ray = camera.GetRay(point);
			// trace ray
			 if (x == framebuffer.width / 2) {
				 if (y == 0 || y == framebuffer.height / 2 || y == framebuffer.height - 1) {
					 std::cout << "ray.direction.y = " << ray.direction.y << "\n";
				 }
			 }
			color3_t color = Trace(ray);

			auto c = ColorConvert(color);

			// draw pixel (x,y) to frame buffer using color (make sure to convert color)
			framebuffer.DrawPoint(x, y, ColorConvert(color));
		}
	}
}

color3_t Scene::Trace(const Ray& ray) {
	// draw sky colors based on the ray y position
	glm::vec3 direction = ray.direction;
	// shift direction y from -1 <-> 1 to 0 <-> 1
	float t = 0.5f * (ray.direction.y + 1.0f);

	// interpolate between sky bottom (0) to sky top (1)
	skyBottom = glm::clamp(skyBottom, glm::vec3{ 0 }, glm::vec3{ 1 });
	skyTop = glm::clamp(skyTop, glm::vec3{ 0 }, glm::vec3{ 1 });

	// mix is the same as lerp, interpolates between values using t (0-1)
	color3_t color = glm::mix(skyBottom, skyTop, t);

	return color;
}
