#pragma once
#include "Character.h"
#include "inputManager.h"
#include "bald.h"
#include "maiden.h"
#include "ninja.h"
#include "samurai.h"
#include "Preferences.h"
#include <set>
#include "DrawableObject.h"

enum currentCharacterType{
    MAIDEN,
    SAMURAI,
    BALD,
    NINJA,
    POOR
};

enum PlayerStates{
    STANDING,
    TAKE_DAMAGE,
    ATTACKING,
    JUMP_ATTACKING,
    SPECIAL_ATTACKING,
    JUMPING,
    RUNNING,
    FALLING
};

enum PlayerType{
    PLAYER_ONE,
    PLAYER_TWO
};

class Player : public Subject{
public:
	Player() { thisType_ = type::PLAYER; }
    ~Player(){}


    void init(const glm::vec2& pos);
    void processInput();
    void update();
    void drawPlayer(SpriteBatch& spriteBatch);
    void setCurrentCharacters(Character* character){
        currentCharacter_ = character;
    }
    void setPosition(const glm::vec2& pos){
        playerPosition_ = pos;
    }

    void setPlayerType(PlayerType aType){
        playerType_ = aType;
		switch (aType) {
		case PLAYER_ONE:
			playerNum_ = '1';
			break;
		case PLAYER_TWO:
			playerNum_ = '2';
			break;
		}
		preferences_.init(playerNum_);
    }

    void setDirection(int direction){
        this->direction = direction;
    }

    void setPayerState(PlayerStates aState){
        currentState_ = aState;
    }

    void checkDeath();
    void respawn();
    void youDead();

    glm::vec4 getMatrix(){
        return glm::vec4(playerPosition_.x, playerPosition_.y,
                         currentCharacter_->getWidth(), currentCharacter_->getHeight());
    }

	void setNewControls(int*);

    void setVX(float vx){velocityX_ = vx;}
    void setVY(float vy){velocityY_ = vy;}

    void setX(float x){playerPosition_.x = x;}
    void setY(float y){playerPosition_.y = y;}

    float getX(){return playerPosition_.x;}
    float getY(){return playerPosition_.y;}

    float getVX(){return velocityX_;}
    float getVY(){return velocityY_;}
    Character* getCurr(){ return currentCharacter_;}

    void drawHP(SpriteBatch& SpriteBatch);
    void drawAvatar(SpriteBatch& SpriteBatch);

    inputManager playerInputManager;
    std::vector<Character*> characters;
    bool onTile = false;
    bool inAir = true;
    bool isDead = false;
    bool takingDamage = false;
    float speedChange = 0.25;
    int hp = 5;
    const float damageTimerMax = 2;
    float damageTimer = 0;
    bool canTakeDamage = true;
    float timer = 0;
    float ticking = 1.0/60.0;
    currentCharacterType characterType = BALD;
    Character* currentCharacter_ = nullptr;
private:
    static ResourceManager playerManager;
    std::vector<GLTexture> heart;
    std::vector<GLTexture> Avatar;
    void limitSpeed(float& speed);
    const float MAX_VELOCITY = 10;

    PlayerType playerType_;
    PlayerStates currentState_;

    const int CHARACTER_NUMBERS = 4;
    int direction = 0;

    float accelerationX_ = 0;
    float accelerationY_ = 0;
    float velocityX_ = 0;
    float velocityY_ = 0;

	Pref preferences_;
	char playerNum_;
	bool needToCheckDeath_ = true;
    glm::vec2 playerPosition_ = glm::vec2(0.0f);
};
