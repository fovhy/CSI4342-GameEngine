#include "bald.h"

void Bald::init(){
	myCharacter_.setSize(glm::vec2(70, 70));
	myCharacter_.setColliSize(glm::vec2(70, 70));
    idle.resize(4);
    idle[0] = characterManager_.getTexture("../YOLO/texture/bald/idle_0.png");
    idle[1] = characterManager_.getTexture("../YOLO/texture/bald/idle_1.png");
    idle[2] = characterManager_.getTexture("../YOLO/texture/bald/idle_2.png");
    idle[3] = characterManager_.getTexture("../YOLO/texture/bald/idle_3.png");
    idleC = 0.1;
    run.resize(6);
    run[0] = characterManager_.getTexture("../YOLO/texture/bald/run_0.png");
    run[1] = characterManager_.getTexture("../YOLO/texture/bald/run_1.png");
    run[2] = characterManager_.getTexture("../YOLO/texture/bald/run_2.png");
    run[3] = characterManager_.getTexture("../YOLO/texture/bald/run_3.png");
    run[4] = characterManager_.getTexture("../YOLO/texture/bald/run_4.png");
    run[4] = characterManager_.getTexture("../YOLO/texture/bald/run_5.png");
    runC = 0.2;

    jump.resize(1);
    jump[0] = characterManager_.getTexture("../YOLO/texture/bald/jump_0.png");
    jumpC = 0.0;

    fall.resize(1);
    fall[0] = characterManager_.getTexture("../YOLO/texture/bald/jump_2.png");
    fallC = 0.1;

    attack.resize(3);
    attack[0] = characterManager_.getTexture("../YOLO/texture/bald/attack_0.png");
    attack[1] = characterManager_.getTexture("../YOLO/texture/bald/attack_1.png");
    attack[2] = characterManager_.getTexture("../YOLO/texture/bald/attack_2.png");
    attackC = 0.1;

    jumpAttack.resize(2);

    jumpAttack[0] = characterManager_.getTexture("../YOLO/texture/bald/jump_3.png");
    jumpAttack[0] = characterManager_.getTexture("../YOLO/texture/bald/jump_3.png");
    jumpAttackC = 0.1;

    stunned.resize(2);
    stunned[0] = characterManager_.getTexture("../YOLO/texture/bald/x_1.png");
    stunned[1] = characterManager_.getTexture("../YOLO/texture/bald/x_1.png");
    stunnedC = 0.05;

    attackWidth = 40;
    attackHeight = 100;


}

void Bald::spawnSpecialAttackBox(const glm::vec2& pos, int direction){

}

void Bald::drawSpecialAttack(int direction,SpriteBatch& spriteBatch){

    Color solidColor;
    solidColor.r = 255;
    solidColor.g = 255;
    solidColor.b = 255;
    solidColor.a = 255;

    if(specialAttackS > specialAttack.size() -1){
        specialAttackS = 0;
    }
    glm::vec4 uv;
    if(direction == 1){
        uv = glm::vec4(0, 0, 1, 1);
    }else{
        uv = glm::vec4 (0, 0, -1, 1);
    }
    spriteBatch.draw(glm::vec4(myCharacter_.getPosition(), myCharacter_.getSize()),
                     uv, specialAttack[(int)specialAttackS].id, 1.0, solidColor);
    specialAttackS += specialAttackC;
}

