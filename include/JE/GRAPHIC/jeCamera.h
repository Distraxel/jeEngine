#pragma once
#include "../jePoint.h"
#include "../jeMain.h"
#include <SDL2/SDL_image.h>

#define GLM_FORCE_RADIANS
#include <glm/mat4x4.hpp>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace JE{namespace GRAPHICS{

class Camera : public JE::Point{
public:
	Camera(float x, float y);
	Camera(const Camera&);
	Camera();
	
	void setBounds(float left, float top, float right, float bottom);
	void setNear(float value);
	void setFar(float value);
	void setLeft(float value);
	void setRight(float value);
	void setTop(float value);
	void setBottom(float value);
	
	void setAngle(float value);
	void addAngle(float value);
	
	void setScale(float x, float y);
	void setScale(float value);
	void pushScale(float x, float y);
	void pushScale(float value);
	
	void centerTo(float x, float y);
	
	void letterBox(float target_width, float target_height, float x_offset = 0.5f, float y_offset = 0.5f, float zoom = 0.0f, bool do_clip = true);
	
	const glm::mat4& getTranform() const;
	void getPosition(float x, float y, float* ret_x, float* ret_y) const;
	void getMousePosition(float* ret_x, float* ret_y) const;
	float getLeft() const;
	float getRight() const;
	float getTop() const;
	float getBottom() const;
	float getWidth() const;
	float getHeight() const;
	
	void useViewport() const;
	void disableViewport() const;
	
	float getPixelSize() const;
	
	float getCenterX() const;
	float getCenterY() const;
	
	float getInternalLeft() const;
	float getInternalRight() const;
	float getInternalTop() const;
	float getInternalBottom() const;
	float getInternalWidth() const;
	float getInternalHeight() const;
	
	float getScaleX() const;
	float getScaleY() const;
	
	const SDL_Rect& getClip() const;
	bool isClipEnabled() const;
	
private:
	float angle;
	float scale_x;
	float scale_y;
	
	float origin_x;
	float origin_y;
	
	float left;
	float right;
	float top;
	float bottom;
	
	float m_near;
	float m_far;
	
	mutable bool need_update_transform;
	mutable glm::mat4 transform_cache;
	mutable float prev_x;
	mutable float prev_y;
	
	bool do_clip;
	SDL_Rect clip_rect;
};

};};
