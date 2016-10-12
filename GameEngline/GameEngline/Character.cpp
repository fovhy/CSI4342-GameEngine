#include "Character.h"

ResourceManager Character::characterManager_;
void Character::drawAnimation(const glm::vec2 &pos, int direction,
                              Action aAction, SpriteBatch& spriteBatch){
	myCharacter_.setPosition(pos);
    switch(aAction){
    case Action::STAND_STILL:
        drawIdle(direction, spriteBatch);
        break;
    case Action::JUMP:
        drawJump(direction, spriteBatch);
        break;
    case Action::ATTACK:
        drawAttack(direction, spriteBatch);
        break;
    case Action::JUMP_ATTACK:
        drawJumpAttack(direction, spriteBatch);
        break;
    case Action::RUN:
        drawRun(direction, spriteBatch);
        break;
    case Action::STUNNED:
        drawStunned(direction, spriteBatch);
        break;
    case Action::SPECIAL_ATTACK:
        drawSpecialAttack(direction, spriteBatch);
        break;
    case Action::FALL:
        drawfall(direction, spriteBatch);
        break;
    }

}

void Character::drawfall(int direction,SpriteBatch& spriteBatch){
    Color solidColor;
    solidColor.r = 255;
    solidColor.g = 255;
    solidColor.b = 255;
    solidColor.a = 255;

    if(fallS > fall.size() -1){
        fallS = 0;
    }
    glm::vec4 uv;
    if(direction == 1){
        uv = glm::vec4(0, 0, 1, 1);
    }else{
        uv = glm::vec4 (0, 0, -1, 1);
    }
    spriteBatch.draw(glm::vec4(myCharacter_.getPosition(), myCharacter_.getSize()),
                     uv, fall[(int)fallS].id, 1.0, solidColor);
    fallS += fallC;

}

void Character::drawAttack(int direction,SpriteBatch& spriteBatch){
    if(attackDone){
        attackDone = false;
    }
    Color solidColor;
    solidColor.r = 255;
    solidColor.g = 255;
    solidColor.b = 255;
    solidColor.a = 255;

    if(attackS > attack.size() -1){
        attackS = 0;
        attackDone = true;
		attackBox = glm::vec4();
    }
    glm::vec4 uv;
    if(direction == 1){
        uv = glm::vec4(0, 0, 1, 1);
    }else{
        uv = glm::vec4 (0, 0, -1, 1);
    }
    spriteBatch.draw(glm::vec4(myCharacter_.getPosition(), myCharacter_.getSize()),
                     uv, attack[(int)attackS].id, 1.0, solidColor);
    attackS += attackC;
}

void Character::drawIdle(int direction,SpriteBatch& spriteBatch){
    Color solidColor;
    solidColor.r = 255;
    solidColor.g = 255;
    solidColor.b = 255;
    solidColor.a = 255;

    if(idleS > idle.size() -1){
        idleS = 0;
    }
    glm::vec4 uv;
    if(direction == 1){
        uv = glm::vec4(0, 0, 1, 1);
    }else{
        uv = glm::vec4 (0, 0, -1, 1);
    }
    spriteBatch.draw(glm::vec4(myCharacter_.getPosition(), myCharacter_.getSize()),
                     uv, idle[(int)idleS].id, 1.0, solidColor);
    idleS += idleC;
}

void Character::drawJump(int direction,SpriteBatch& spriteBatch){

    Color solidColor;
    solidColor.r = 255;
    solidColor.g = 255;
    solidColor.b = 255;
    solidColor.a = 255;

    if(jumpS > jump.size() -1){
        jumpS = 0;
    }
    glm::vec4 uv;
    if(direction == 1){
        uv = glm::vec4(0, 0, 1, 1);
    }else{
        uv = glm::vec4 (0, 0, -1, 1);
    }
    spriteBatch.draw(glm::vec4(myCharacter_.getPosition(), myCharacter_.getSize()),
                     uv, jump[(int)jumpS].id, 1.0, solidColor);
    jumpS += jumpC;
}
void Character::spawnAttackBox(const glm::vec2 &pos, int direction){
    if(direction < 0){
        attackBox = glm::vec4(pos.x, pos.y, attackWidth, attackHeight);
    }else{
        attackBox = glm::vec4(pos.x , pos.y, attackWidth, attackHeight);
    }
}

void Character::drawJumpAttack(int direction,SpriteBatch& spriteBatch){
    if(jumpAttackDone)
        jumpAttackDone = false;
    Color solidColor;
    solidColor.r = 255;
    solidColor.g = 255;
    solidColor.b = 255;
    solidColor.a = 255;

    if(jumpAttackS > jumpAttack.size() -1){
        jumpAttackS = 0;
        jumpAttackDone = true;
    }
    glm::vec4 uv;
    if(direction == 1){
        uv = glm::vec4(0, 0, 1, 1);
    }else{
        uv = glm::vec4 (0, 0, -1, 1);
    }
    spriteBatch.draw(glm::vec4(myCharacter_.getPosition(), myCharacter_.getSize()),
                     uv, jumpAttack[(int)jumpAttackS].id, 1.0, solidColor);
    jumpAttackS += jumpAttackC;
}

void Character::drawRun(int direction,SpriteBatch& spriteBatch){
    Color solidColor;
    solidColor.r = 255;
    solidColor.g = 255;
    solidColor.b = 255;
    solidColor.a = 255;

    if(runS > run.size() -1){
        runS = 0;
    }
    glm::vec4 uv;
    if(direction == 1){
        uv = glm::vec4(0, 0, 1, 1);
    }else{
        uv = glm::vec4 (0, 0, -1, 1);
    }
    spriteBatch.draw(glm::vec4(myCharacter_.getPosition(), myCharacter_.getSize()),
                     uv, run[(int)runS].id, 1.0f, solidColor);
    runS += runC;
}


void Character::drawStunned(int direction,SpriteBatch& spriteBatch){
    if(stunDone){
        stunDone = false;
    }
    Color solidColor;
    solidColor.r = 255;
    solidColor.g = 255;
    solidColor.b = 255;
    solidColor.a = 255;

    if(stunnedS > stunned.size() -1){
        stunnedS = 0;
        stunDone = true;
    }
    glm::vec4 uv;
    if(direction == 1){
        uv = glm::vec4(0, 0, 1, 1);
    }else{
        uv = glm::vec4 (0, 0, -1, 1);
    }
    spriteBatch.draw(glm::vec4(myCharacter_.getPosition(), myCharacter_.getSize()),
                     uv, stunned[(int)stunnedS].id, 1.0, solidColor);
    stunnedS += stunnedC;
}

void Character::setCharacterSize(const glm::vec2& size) {
	myCharacter_.setSize(size);
}
