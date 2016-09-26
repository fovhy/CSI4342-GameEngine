#pragma once
#include "glm/glm.hpp"
#include "inputManager.h"
#include "GLTexture.h"
#include "GL/glew.h"
#include <string>
#include "spriteBatch.h"
#include <vector>
#include "Physic.h"
#include "fileManager.h"
#include <iostream>
#include "ResourceManager.h"
#include <cmath>
#include "Subject.h"
enum class Action{
    STAND_STILL,
    ATTACK,
    JUMP,
    JUMP_ATTACK,
    SPECIAL_ATTACK,
    STUNNED,
    FALL,
    RUN
};

class Character : public Subject{
public:
	Character() { thisType_ = type::CHARACTER; }
    ~Character(){}
    virtual void init() = 0;
    void drawAnimation(const glm::vec2& pos, int direction, Action aAction, SpriteBatch& spriteBatch);
    float getWidth(){ return characterWidth_ ;}
    float getHeight(){ return characterHeight_;}

    void spawnAttackBox(const glm::vec2& pos, int direction);
    virtual void spawnSpecialAttackBox(const glm::vec2& pos, int direction) = 0;
    bool attackDone = true;
    bool jumpAttackDone = true;
    bool specialAttackDone = true;
    bool stunDone = true;
    glm::vec4 attackBox;
    glm::vec4 specialAttackBox;
    float attackWidth = 0;
    float attackHeight = 0;

    float specialAttackWidth = 0;
    float specialAttackHeight = 0;

protected:
    void drawAttack(const glm::vec2& pos, int direction,SpriteBatch& spriteBatch);
    void drawIdle(const glm::vec2& pos, int direction,SpriteBatch& spriteBatch);
    void drawJump(const glm::vec2& pos, int direction,SpriteBatch& spriteBatch);
    void drawJumpAttack(const glm::vec2& pos, int direction,SpriteBatch& spriteBatch);
    virtual void drawSpecialAttack(const glm::vec2& pos, int direction,SpriteBatch& spriteBatch)=0;
    void drawRun(const glm::vec2& pos, int direction,SpriteBatch& spriteBatch);
    void drawStunned(const glm::vec2& pos, int direction,SpriteBatch& spriteBatch);
    void drawfall(const glm::vec2& pos, int direction,SpriteBatch& spriteBatch);

    std::vector<GLTexture> run;
    std::vector<GLTexture> attack;
    std::vector<GLTexture> idle;
    std::vector<GLTexture> jump;
    std::vector<GLTexture> jumpAttack;
    std::vector<GLTexture> specialAttack;
    std::vector<GLTexture> stunned;
    std::vector<GLTexture> fall;

    float runS = 0;
    float attackS = 0;
    float idleS= 0;
    float jumpS = 0;
    float jumpAttackS = 0;
    float specialAttackS = 0;
    float stunnedS = 0;
    float fallS = 0;

    float runC = 0;
    float attackC = 0;
    float idleC= 0;
    float jumpC = 0;
    float jumpAttackC = 0;
    float specialAttackC = 0;
    float stunnedC = 0;
    float fallC = 0;
    ResourceManager characterManager_;
    float characterWidth_ = 0;
    float characterHeight_ = 0;
};

