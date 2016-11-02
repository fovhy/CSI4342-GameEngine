#include "Powerup.h"

Powerup::Powerup()
{
	position.z = WIDTH;
	position.w = HEIGHT;
	FU = powerUpManager_.getTexture("../YOLO/texture/JJU/power/pUP.png");
	FD = powerUpManager_.getTexture("../YOLO/texture/JJU/power/pDown.png");
	JU = powerUpManager_.getTexture("../YOLO/texture/JJU/power/jUP.png");
	JD = powerUpManager_.getTexture("../YOLO/texture/JJU/power/jDown.png");
	SU = powerUpManager_.getTexture("../YOLO/texture/JJU/power/sUP.png");
	SD = powerUpManager_.getTexture("../YOLO/texture/JJU/power/sDown.png");


}

PowerupType Powerup::getType()
{
	return type_;
}

void Powerup::spawn(const glm::vec4& it)
{
	srand(time(0));
	type_ = PowerupType(rand() % 6);
	position = it;
	position.z = WIDTH;
	position.w = HEIGHT;
}

glm::vec4 Powerup::getPos()
{
	return position;
}
void Powerup::drawFU(SpriteBatch& renderBatch) {
	Color solidColor;
	solidColor.r = 255;
	solidColor.g = 255;
	solidColor.b = 255;
	solidColor.a = 255;
	renderBatch.draw(glm::vec4(), glm::vec4(0, 0, 1, 1), FU.id, 1.0, solidColor);

}
void Powerup::drawFD(SpriteBatch& renderBatch) {

	Color solidColor;
	solidColor.r = 255;
	solidColor.g = 255;
	solidColor.b = 255;
	solidColor.a = 255;
	renderBatch.draw(glm::vec4(), glm::vec4(0, 0, 1, 1), FD.id, 1.0, solidColor);

}
void Powerup::drawSU(SpriteBatch& renderBatch) {

	Color solidColor;
	solidColor.r = 255;
	solidColor.g = 255;
	solidColor.b = 255;
	solidColor.a = 255;
	renderBatch.draw(glm::vec4(), glm::vec4(0, 0, 1, 1), SU.id, 1.0, solidColor);

}
void Powerup::drawSD(SpriteBatch& renderBatch) {

	Color solidColor;
	solidColor.r = 255;
	solidColor.g = 255;
	solidColor.b = 255;
	solidColor.a = 255;
	renderBatch.draw(glm::vec4(), glm::vec4(0, 0, 1, 1), SD.id, 1.0, solidColor);

}
void Powerup::drawJU(SpriteBatch& renderBatch) {

	Color solidColor;
	solidColor.r = 255;
	solidColor.g = 255;
	solidColor.b = 255;
	solidColor.a = 255;
	renderBatch.draw(glm::vec4(), glm::vec4(0, 0, 1, 1), JU.id, 1.0, solidColor);

}
void Powerup::drawJD(SpriteBatch& renderBatch) {

	Color solidColor;
	solidColor.r = 255;
	solidColor.g = 255;
	solidColor.b = 255;
	solidColor.a = 255;
	renderBatch.draw(glm::vec4(), glm::vec4(0, 0, 1, 1), JD.id, 1.0, solidColor);

}
