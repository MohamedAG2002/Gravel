#pragma once 

#include "defines.h"
#include "math/transform.h"
#include "physics/collider.h"

#include <glm/vec3.hpp>

// PhysicsBodyType
/////////////////////////////////////////////////////////////////////////////////
enum PhysicsBodyType {
  PHYSICS_BODY_DYNAMIC, 
  PHYSICS_BODY_KINEMATIC, 
  PHYSICS_BODY_STATIC, 
};
/////////////////////////////////////////////////////////////////////////////////

// PhysicsBodyDesc
/////////////////////////////////////////////////////////////////////////////////
struct PhysicsBodyDesc {
  glm::vec3 position;
  PhysicsBodyType type;

  // Defaulted values. Can be changed if needed
  void* user_data; 
  f32 mass = 1.0f;
  bool is_active = true;
};
/////////////////////////////////////////////////////////////////////////////////

// PhysicsBody
/////////////////////////////////////////////////////////////////////////////////
struct PhysicsBody {
  Transform transform;
  PhysicsBodyType type;
  Collider collider;

  glm::vec3 force, acceleration; 
  glm::vec3 linear_velocity, angular_velocity;

  f32 mass, inverse_mass;
  bool is_active;

  void* user_data;
};
/////////////////////////////////////////////////////////////////////////////////

// Public functions 
/////////////////////////////////////////////////////////////////////////////////
PhysicsBody* physics_body_create(const PhysicsBodyDesc& desc);
void physics_body_destroy(PhysicsBody* body);
void physics_body_add_collider(PhysicsBody* body, ColliderType type, void* collider);
void physics_body_apply_force(PhysicsBody* body, const glm::vec3& force);
/////////////////////////////////////////////////////////////////////////////////