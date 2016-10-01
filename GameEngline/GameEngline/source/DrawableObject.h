#pragma once
#include <string>
#include <glm/glm.hpp>
#include "spriteBatch.h"
#include "GLTexture.h"
class DrawableObject{
public:
	enum shape{
		SQAURE,
		CIRCLE
	};
	DrawableObject(glm::vec2 pos, glm::vec2 size, glm::vec2 collisionSize,
		double depth);
	DrawableObject() = default;
	virtual ~DrawableObject();
	void draw(SpriteBatch&, glm::vec4 uv, GLTexture texture);
	GLTexture getTexture();
	glm::vec2 getPosition();
	glm::vec2 getSize();
	glm::vec2 getColliSize();
	void setPosition(glm::vec2);
	void setSize(glm::vec2);
	void setColliSize(glm::vec2);
private:
	glm::vec2 pos_;
	glm::vec2 size_;                     // the length and width being drawn on the screen
	glm::vec2 colliSize_;                // the length and width for detecing physic interaction.
	double depth_; // how deep the object is
	GLTexture texture_;
	shape type_;
};

