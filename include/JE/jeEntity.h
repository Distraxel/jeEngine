#pragma once
#include "jePoint.h"
#include <cstddef>
#include <vector>
#include <memory>
namespace JE{
class Group;
class World;
class Entity : public Point, public std::enable_shared_from_this<Entity>
{
	friend Group;
	public:
		Entity(float x = 0, float y = 0);
		virtual ~Entity();
		int layer;

		virtual void OnCreate();/**< \brief Called when the entity is created. */
		virtual void OnDraw();/**< \brief Called when the entity is drawn. */
		virtual void OnAdd(JE::Group& group);/**< \brief Called when the entity is added to the world. */
		virtual void OnRemove(JE::Group& group);/**< \brief Called when the entity is removed from the world. */
		virtual void OnUpdate(JE::Group& group, float dt);/**< \brief Called when the entity is updated. */
		
		virtual void moveBy(float move_x, float move_y);
		virtual void moveTo(float move_x, float move_y, bool force = false);
};
};
