#include "Player.h"
#include <SDL/SDL.h>
#include "EventManager.h"
#include <iostream>

ResourceManager Player::playerManager;

void Player::init(const glm::vec2& pos){
    setPosition(pos);
    heart.resize(6);
    heart[0] = playerManager.getTexture("../YOLO/texture/icons/Heart_01.png");
    heart[1] = playerManager.getTexture("../YOLO/texture/icons/Heart_02.png");
    heart[2] = playerManager.getTexture("../YOLO/texture/icons/Heart_03.png");
    heart[3] = playerManager.getTexture("../YOLO/texture/icons/Heart_04.png");
    heart[4] = playerManager.getTexture("../YOLO/texture/icons/Heart_05.png");
    heart[5] = playerManager.getTexture("../YOLO/texture/icons/Heart_06.png");
    characters.resize(CHARACTER_NUMBERS);
    characters[0] = new Bald();
    characters[0]->init();
    characters[1] = new Maiden();
    characters[1]->init();
    characters[2] = new Ninja();
    characters[2]->init();
    characters[3] = new Samurai();
    characters[3]->init();
}

void Player::checkDeath(){
    if(playerPosition_.x > 1240
            || playerPosition_.x < -30
            || playerPosition_.y > 400
            || playerPosition_.y < -410
            || hp <= 0){
		notifyAll(*this, "playerDeath");
        isDead = true;
		needToCheckDeath_ = false;
        hp = 0;
    }
}
void Player::youDead(){
    playerPosition_.x = -200;
    playerPosition_.y = -100;
}

void Player::drawAvatar(SpriteBatch &SpriteBatch){

}

void Player::respawn(){
    hp = 5;
    isDead = false;
	needToCheckDeath_ = true;
    velocityX_ = 0;
    velocityY_ = 0;
    playerPosition_.x = 600;
    playerPosition_.y = 200;
}

void Player::drawHP(SpriteBatch &spriteBatch){
    Color solidColor;
    solidColor.r = 255;
    solidColor.g = 255;
    solidColor.b = 255;
    solidColor.a = 255;
    glm::vec4 drawingPos(100, 300, 150, 30);
    glm::vec4 uv(0, 0, 1, 1);
    if(playerType_ == PLAYER_ONE){
        switch(hp){
        case 5:
            spriteBatch.draw(drawingPos, uv, heart[0].id, 2.0, solidColor);
            break;
        case 4:
            spriteBatch.draw(drawingPos, uv, heart[1].id, 2.0, solidColor);
            break;
        case 3:
            spriteBatch.draw(drawingPos, uv, heart[2].id, 2.0, solidColor);
            break;
        case 2:
            spriteBatch.draw(drawingPos, uv, heart[3].id, 2.0, solidColor);
            break;
        case 1:
            spriteBatch.draw(drawingPos, uv, heart[4].id, 2.0, solidColor);
            break;
        case 0:
            spriteBatch.draw(drawingPos, uv, heart[5].id, 2.0, solidColor);
            break;
        }
    }else{
        uv = glm::vec4(0, 0, -1, 1);
        drawingPos = glm::vec4 (950, 300, 150, 30);
        switch(hp){
        case 5:
            spriteBatch.draw(drawingPos, uv, heart[0].id, 2.0, solidColor);
            break;
        case 4:
            spriteBatch.draw(drawingPos, uv, heart[1].id, 2.0, solidColor);
            break;
        case 3:
            spriteBatch.draw(drawingPos, uv, heart[2].id, 2.0, solidColor);
            break;
        case 2:
            spriteBatch.draw(drawingPos, uv, heart[3].id, 2.0, solidColor);
            break;
        case 1:
            spriteBatch.draw(drawingPos, uv, heart[4].id, 2.0, solidColor);
            break;
        case 0:
            spriteBatch.draw(drawingPos, uv, heart[5].id, 2.0, solidColor);
            break;
        }
    }
}

void Player::limitSpeed(float& speed){
	float PUMod = 1;
	if (currentPU && currentPU->getType() == SPEED_DOWN)
	{
		PUMod = 0.5;
	}
	if (currentPU && currentPU->getType() == SPEED_UP)
	{
		PUMod = 1.5;
	}
    if(speed < -MAX_VELOCITY * PUMod)
        speed = -MAX_VELOCITY * PUMod;
    if(speed > MAX_VELOCITY * PUMod)
        speed = MAX_VELOCITY * PUMod;
}

void Player::processInput(){
    if(playerType_ == PLAYER_ONE){
        if(isDead){
            if(playerInputManager.isKeyPressed(SDLK_F1)){
				takingDamage = false;
				currentCharacter_->stunDone = true;
				respawn();
            }
        }
        if(playerInputManager.isKeyPressed(SDLK_1)){
            currentCharacter_ = characters[0];
            characterType = BALD;
        }
        if(playerInputManager.isKeyPressed(SDLK_2)){
            currentCharacter_ = characters[1];
            characterType = MAIDEN;
        }
        if(playerInputManager.isKeyPressed(SDLK_3)){
            currentCharacter_ = characters[2];
            characterType = NINJA;
        }
        if(playerInputManager.isKeyPressed(SDLK_4)){
            currentCharacter_ = characters[3];
            characterType = SAMURAI;
        }
    }
	else{
        if(isDead){
            if(playerInputManager.isKeyPressed(SDLK_F2)){
				takingDamage = false;
				currentCharacter_->stunDone = true;
                respawn();
            }
        }
        if(playerInputManager.isKeyPressed(SDLK_5)){
            currentCharacter_ = characters[0];
            characterType = BALD;
        }
        if(playerInputManager.isKeyPressed(SDLK_6)){
            currentCharacter_ = characters[1];
            characterType = MAIDEN;
        }
        if(playerInputManager.isKeyPressed(SDLK_7)){
            currentCharacter_ = characters[2];
            characterType = NINJA;
        }
        if(playerInputManager.isKeyPressed(SDLK_8)){
            currentCharacter_ = characters[3];
            characterType = SAMURAI;
        }
    }
    switch(currentState_){
    case STANDING:
        if(playerInputManager.isKeyPressed(preferences_.getUp()) && onTile){
            velocityY_ += 10;
            currentState_ = JUMPING;
        }
        if(playerInputManager.isKeyPressed(preferences_.getLeft())){
            currentState_ = RUNNING;
            if(velocityX_ > 0)
                velocityX_ -= speedChange * 0.7;
            else
                velocityX_ -= speedChange;
            direction = -1;
        }
        else if(playerInputManager.isKeyPressed(preferences_.getRight())){
            currentState_ = RUNNING;
            if(velocityX_ < 0)
                velocityX_ += speedChange * 0.7;
            else
                velocityX_ += speedChange;
            direction = 1;
        }
        /*if(playerInputManager.isKeyPressed(preferences_.getAttack())){
            currentState_ = ATTACKING;
            currentCharacter_->attackDone = false;
        }*/
        
        break;
    case RUNNING:
        if(playerInputManager.isKeyPressed(preferences_.getUp()) && onTile){
			float PUMod = 1;
			if (currentPU && currentPU->getType() == JUMP_DOWN)
			{
				PUMod = 0.5;
			}
			if (currentPU && currentPU->getType() == JUMP_UP)
			{
				PUMod = 1.5;
			}
            velocityY_ += 10 * PUMod;
            currentState_ = JUMPING;
        }
        if(playerInputManager.isKeyPressed(preferences_.getDown()) && !onTile){
            velocityY_ -= 0.3;
        }
        if(playerInputManager.isKeyPressed(preferences_.getLeft())){
            if(velocityX_ > 0)
                velocityX_ -= speedChange * 0.7;
            else
                velocityX_ -= speedChange;
            direction = -1;
        }else if(playerInputManager.isKeyPressed(preferences_.getRight())){
            if(velocityX_ < 0)
                velocityX_ += speedChange * 0.7;
            else
                velocityX_ += speedChange;
            direction = 1;
        }else{
            currentState_ = STANDING;
        }
        /*if(playerInputManager.isKeyPressed(preferences_.getAttack())){
            currentState_ = ATTACKING;
            currentCharacter_->attackDone = false;
        }*/
        break;
    case JUMPING:
        if(playerInputManager.isKeyPressed(preferences_.getLeft())){
            if(velocityX_ > 0)
                velocityX_ -= 0.08;
            else
                velocityX_ -= 0.10;
            direction = -1;
        }
        else if(playerInputManager.isKeyPressed(preferences_.getRight())){
            if(velocityX_ < 0)
                velocityX_ += 0.08;
            else
                velocityX_ += 0.10;
            direction = 1;
        }
        /*else if(playerInputManager.isKeyPressed(preferences_.getAttack())){
            currentCharacter_->jumpAttackDone = false;
            currentState_ = JUMP_ATTACKING;
        }*/    
        break;
    /*case ATTACKING:
        if(currentCharacter_->attackDone){
            if(velocityX_ > 0.5){
                currentState_ = RUNNING;
            }else{
                currentState_ = STANDING;
            }
        }
        break;*/
    case FALLING:
        if(velocityY_ == 0){
            currentState_ = STANDING;
            break;
        }
        if(playerInputManager.isKeyPressed(preferences_.getLeft())){
            if(velocityX_ > 0)
                velocityX_ -= 0.08;
            else
                velocityX_ -= 0.10;
            direction = -1;
        }
        else if(playerInputManager.isKeyPressed(preferences_.getRight())){
            if(velocityX_ < 0)
                velocityX_ += 0.08;
            else
                velocityX_ += 0.10;
            direction = 1;
        }
		break;
        
    }
}

void Player::update(){

        limitSpeed(velocityX_);
        limitSpeed(velocityY_);

        playerPosition_.x += velocityX_;
        playerPosition_.y += velocityY_;
		if (needToCheckDeath_) {
			checkDeath();
		}
        if(isDead){
            youDead();
        }

        if(!currentCharacter_->attackDone){
            glm::vec2 midpoint = glm::vec2(playerPosition_.x + currentCharacter_->getWidth()/2,
                                           playerPosition_.y);
            currentCharacter_->spawnAttackBox(midpoint, direction);
        }else{
            takingDamage = false;
            currentState_ = STANDING;
        }
        if(takingDamage){
            currentState_ = TAKE_DAMAGE;
            damageTimer += 0.01;
            if(damageTimer > 1){
                damageTimer = 0;
                canTakeDamage = true;
            }
            if(canTakeDamage){
                hp -=  1;
                canTakeDamage = false;
            }
        }else{
            if(onTile && abs(velocityY_ ) < 0.1){
                if( std::abs(velocityX_ )< 0.3 && currentCharacter_->attackDone){
                    currentState_ = STANDING;
                }else if(currentCharacter_->attackDone){
                    currentState_ = RUNNING;
                }
            }

            if(currentCharacter_->jumpAttackDone){
                if(velocityY_ < 0){
                    currentState_ = FALLING;
                }else if(velocityY_ > 0){
                    currentState_ = JUMPING;
                }
            }
        }
}

void Player::drawPlayer(SpriteBatch &spriteBatch){
        if(currentCharacter_ == nullptr)
            exit(-1);
        switch(currentState_){
        case STANDING:
            currentCharacter_->drawAnimation(playerPosition_, direction, Action::STAND_STILL, spriteBatch);
            break;
        case RUNNING:
            currentCharacter_->drawAnimation(playerPosition_, direction, Action::RUN, spriteBatch);
            break;
        case JUMPING:
            currentCharacter_->drawAnimation(playerPosition_, direction, Action::JUMP, spriteBatch);
            break;
        case FALLING:
            currentCharacter_->drawAnimation(playerPosition_, direction, Action::FALL, spriteBatch);
            break;
        case ATTACKING:
            currentCharacter_->drawAnimation(playerPosition_, direction, Action::ATTACK, spriteBatch);
            break;
        case JUMP_ATTACKING:
            currentCharacter_->drawAnimation(playerPosition_, direction, Action::JUMP_ATTACK, spriteBatch);
            break;
        case TAKE_DAMAGE:
            currentCharacter_->drawAnimation(playerPosition_, direction, Action::STUNNED, spriteBatch);
            break;
        }
        drawHP(spriteBatch);
}

void Player::setNewControls(int* newControls) {
	preferences_.setLeft(newControls[0]);
	preferences_.setRight(newControls[1]);
	preferences_.setUp(newControls[2]);
	preferences_.setDown(newControls[3]);
	preferences_.savePref(playerNum_);
	//preferences_.setAttack(newControls[4]);
}