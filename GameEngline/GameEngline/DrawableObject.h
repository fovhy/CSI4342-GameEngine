#pragma once
#include <string>
#include <glm/glm.hpp>
#include "spriteBatch.h"
#include "GLTexture.h"
#include "Physic.h"
enum shape {
	SQAURE,
	CIRCLE
};
enum class quadrant {
	first,
	second,
	third,
	fourth
};
class DrawableObject {
public:
	DrawableObject(const glm::vec2& pos, const glm::vec2& size, const glm::vec2& collisionSize,
		double depth);
	DrawableObject() = default;
	virtual ~DrawableObject();
	void draw(SpriteBatch&, glm::vec4 uv, GLTexture texture);
	GLTexture getTexture();
	glm::vec2 getPosition();
	glm::vec2 getSize();
	glm::vec2 getColliSize();
	virtual void  setPosition(const glm::vec2&);
	void setSize(const glm::vec2&);
	void setColliSize(const glm::vec2&);
	virtual std::vector<quadrant> getQuadrant() = 0;
	void calculateQuadrants();
	static int screenHeight;
	static int screenWidth;
protected:
	glm::vec2 pos_;
	glm::vec2 size_;                     // the length and width being drawn on the screen
	glm::vec2 colliSize_;                // the length and width for detecing physic interaction.
	double depth_;                       // how deep the object is
	GLTexture texture_;
	std::vector<quadrant> quadrants_;
	shape shape_ = SQAURE;
};

