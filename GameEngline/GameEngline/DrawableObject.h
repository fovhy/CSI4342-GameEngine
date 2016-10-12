#pragma once
#include <string>
#include <glm/glm.hpp>
#include "spriteBatch.h"
#include "GLTexture.h"
#include "Physic.h"
#include <boost/serialization/string.hpp>
#include <boost/serialization/access.hpp>
#include <boost/serialization/base_object.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
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
	glm::vec2 getPosition() const;
	glm::vec2 getSize() const;
	glm::vec2 getColliSize() const;
	virtual void  setPosition(const glm::vec2&);
	void setSize(const glm::vec2&);
	void setColliSize(const glm::vec2&);
	virtual std::vector<quadrant> getQuadrant() {
		return std::vector<quadrant> {quadrant::first};
	}
	void calculateQuadrants();
	static int screenHeight;
	static int screenWidth;
	friend class boost::serialization::access;
	friend std::ostream& operator<<(std::ostream& os, const DrawableObject& UO);
	template <class Archive>
	void serialize(Archive &ar, const unsigned int version) {
		ar & pos_.x & pos_.y & size_.x & size_.y & colliSize_.x & colliSize_.y;
		ar & depth_;
		ar & quadrants_;
		ar & screenWidth & screenHeight;
	}

protected:
	glm::vec2 pos_;
	glm::vec2 size_;                     // the length and width being drawn on the screen
	glm::vec2 colliSize_;                // the length and width for detecing physic interaction.
	double depth_;                       // how deep the object is
	std::vector<quadrant> quadrants_;
	shape shape_ = SQAURE;
};

