#pragma once

#include "defines.h"

#include <glm/vec3.hpp>

struct Collider; // Forward declaration because why not

// CollisionData
/////////////////////////////////////////////////////////////////////////////////
struct CollisionData {
  Collider* coll1;
  Collider* coll2;

  glm::vec3 normal; 
  f32 depth;
};
/////////////////////////////////////////////////////////////////////////////////
