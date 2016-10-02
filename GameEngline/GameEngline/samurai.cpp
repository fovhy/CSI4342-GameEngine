


#include "samurai.h"

void Samurai::init(){
	myCharacter_.setSize(glm::vec2(70, 70));
	myCharacter_.setColliSize(glm::vec2(70, 70));
    idle.resize(4);
    idle[0] = characterManager_.getTexture("../YOLO/texture/samurai/idle_0.png");
    idle[1] = characterManager_.getTexture("../YOLO/texture/samurai/idle_1.png");
    idle[2] = characterManager_.getTexture("../YOLO/texture/samurai/idle_2.png");
    idle[3] = characterManager_.getTexture("../YOLO/texture/samurai/idle_3.png");
    idleC = 0.1;
    run.resize(6);
    run[0] = characterManager_.getTexture("../YOLO/texture/samurai/run_0.png");
    run[1] = characterManager_.getTexture("../YOLO/texture/samurai/run_1.png");
    run[2] = characterManager_.getTexture("../YOLO/texture/samurai/run_2.png");
    run[3] = characterManager_.getTexture("../YOLO/texture/samurai/run_3.png");
    run[4] = characterManager_.getTexture("../YOLO/texture/samurai/run_4.png");
    run[4] = characterManager_.getTexture("../YOLO/texture/samurai/run_5.png");
    runC = 0.2;

    jump.resize(1);
    jump[0] = characterManager_.getTexture("../YOLO/texture/samurai/jump_0.png");
    jumpC = 0.0;

    fall.resize(1);
    fall[0] = characterManager_.getTexture("../YOLO/texture/samurai/jump_2.png");
    fallC = 0.1;

    attack.resize(3);
    attack[0] = characterManager_.getTexture("../YOLO/texture/samurai/attack_4.png");
    attack[1] = characterManager_.getTexture("../YOLO/texture/samurai/attack_6.png");
    attack[2] = characterManager_.getTexture("../YOLO/texture/samurai/attack_7.png");
    attackC = 0.1;

    jumpAttack.resize(2);

    jumpAttack[0] = characterManager_.getTexture("../YOLO/texture/samurai/attack_7.png");
    jumpAttack[1] = characterManager_.getTexture("../YOLO/texture/samurai/attack_7.png");
    jumpAttackC = 0.1;

    stunned.resize(1);
    stunned[0] = characterManager_.getTexture("../YOLO/texture/samurai/x_1.png");
    stunnedC = 0.01;

    attackWidth = 70;
    attackHeight = 70;

}



void Samurai::spawnSpecialAttackBox(const glm::vec2& pos, int direction){

}

void Samurai::drawSpecialAttack(int direction,SpriteBatch& spriteBatch){

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
