#pragma once

#include "defines.h"
#include "math/transform.h"
#include "physics/collider.h"

#include <glm/vec3.hpp>

// RayIntersection
/////////////////////////////////////////////////////////////////////////////////
struct RayIntersection {
  glm::vec3 intersection_point;
  f32 distance;
  bool has_intersected;
};
/////////////////////////////////////////////////////////////////////////////////

// Ray 
/////////////////////////////////////////////////////////////////////////////////
struct Ray {
  glm::vec3 position, direction;
};
/////////////////////////////////////////////////////////////////////////////////

// Public functions
/////////////////////////////////////////////////////////////////////////////////
const RayIntersection ray_intersect(const Ray* ray, const Transform* transform, BoxCollider* box);
const RayIntersection ray_intersect(const Ray* ray, const Transform* transform, SphereCollider* sphere);
/////////////////////////////////////////////////////////////////////////////////
