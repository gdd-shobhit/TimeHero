#pragma once
#include <SDL.h>

enum class AnimState
{
	AnimError,
	Idle,
	Walk,
	Running,
	PrimaryAttack,
	SecondaryAttack,
};

class Character
{
	
public:
	Character(SDL_Surface* texture);
	~Character();
	void GetHit(float damage);
	AnimState currentState;
	SDL_Surface* texture;
	float attack;
	bool  isStunned;
	bool  inAir;
	bool  isAttacking;
	bool  canSuperAttack;
private:
	float health;
};

Character::Character(SDL_Surface* texture) {
	this->texture = texture;

	health = 100.0f;
	attack = 2.0f;
	currentState = (AnimState)1;			// This seems wrong. Ask utsab
	isStunned = false;
	inAir = false;
	isAttacking = false;
	canSuperAttack = false;
}

Character::~Character()
{
	
}
