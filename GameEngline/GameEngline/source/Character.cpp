#include "Character.h"


void Character::drawAnimation(const glm::vec2 &pos, int direction,
                              Action aAction, SpriteBatch& spriteBatch){
    switch(aAction){
    case Action::STAND_STILL:
        drawIdle(pos, direction, spriteBatch);
        break;
    case Action::JUMP:
        drawJump(pos, direction, spriteBatch);
        break;
    case Action::ATTACK:
        drawAttack(pos, direction, spriteBatch);
        break;
    case Action::JUMP_ATTACK:
        drawJumpAttack(pos, direction, spriteBatch);
        break;
    case Action::RUN:
        drawRun(pos, direction, spriteBatch);
        break;
    case Action::STUNNED:
        drawStunned(pos, direction, spriteBatch);
        break;
    case Action::SPECIAL_ATTACK:
        drawSpecialAttack(pos, direction, spriteBatch);
        break;
    case Action::FALL:
        drawfall(pos, direction, spriteBatch);
        break;
    }

}

void Character::drawfall(const glm::vec2& pos, int direction,SpriteBatch& spriteBatch){
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
    spriteBatch.draw(glm::vec4(pos.x, pos.y, characterWidth_, characterHeight_),
                     uv, fall[(int)fallS].id, 1.0, solidColor);
    fallS += fallC;

}

void Character::drawAttack(const glm::vec2& pos, int direction,SpriteBatch& spriteBatch){
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
    }
    glm::vec4 uv;
    if(direction == 1){
        uv = glm::vec4(0, 0, 1, 1);
    }else{
        uv = glm::vec4 (0, 0, -1, 1);
    }
    spriteBatch.draw(glm::vec4(pos.x, pos.y, characterWidth_, characterHeight_),
                     uv, attack[(int)attackS].id, 1.0, solidColor);
    attackS += attackC;
}

void Character::drawIdle(const glm::vec2& pos, int direction,SpriteBatch& spriteBatch){
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
    spriteBatch.draw(glm::vec4(pos.x, pos.y, characterWidth_, characterHeight_),
                     uv, idle[(int)idleS].id, 1.0, solidColor);
    idleS += idleC;
}

void Character::drawJump(const glm::vec2& pos, int direction,SpriteBatch& spriteBatch){

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
    spriteBatch.draw(glm::vec4(pos.x, pos.y, characterWidth_, characterHeight_),
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

void Character::drawJumpAttack(const glm::vec2& pos, int direction,SpriteBatch& spriteBatch){
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
    spriteBatch.draw(glm::vec4(pos.x, pos.y, characterWidth_, characterHeight_),
                     uv, jumpAttack[(int)jumpAttackS].id, 1.0, solidColor);
    jumpAttackS += jumpAttackC;
}

void Character::drawRun(const glm::vec2& pos, int direction,SpriteBatch& spriteBatch){
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
    spriteBatch.draw(glm::vec4(pos.x, pos.y, characterWidth_, characterHeight_),
                     uv, run[(int)runS].id, 1.0f, solidColor);
    runS += runC;
}


void Character::drawStunned(const glm::vec2& pos, int direction,SpriteBatch& spriteBatch){
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
    spriteBatch.draw(glm::vec4(pos.x, pos.y, characterWidth_, characterHeight_),
                     uv, stunned[(int)stunnedS].id, 1.0, solidColor);
    stunnedS += stunnedC;
}
