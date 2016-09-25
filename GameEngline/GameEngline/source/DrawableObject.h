#pragma once
#include <string>
#include <glm/glm.hpp>
class DrawableObject{
public:
	enum shape{
		SQAURE,
		CIRCLE
	};
	DrawableObject(glm::vec2 pos, glm::vec2 size, glm::vec2 collisionSize, std::string fileName);
	virtual ~DrawableObject();

	void draw();
private:
	glm::vec2 pos_;
	glm::vec2 size_;                     // the length and width being drawn on the screen
	glm::vec2 colliSize_;                // the length and width for detecing physic interaction.
	std::string textureFileName_;        // where to load the texture for this object
	shape type_;
};

