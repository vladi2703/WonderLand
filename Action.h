#pragma once
#include "Hero.h"
#include "Alice.h"
#include "Weapon.h"
class Action
{

public: 
	virtual void execute() = 0;
};

class EmptySpace : public Action
{
	void execute() override; 
};
class Move : public Action //TODO
{
	void execute() override;
};
class TakeARose : public Action
{
private:
public:
	TakeARose();
	int getDamage(); 
	void execute() override;
};

class SkipNextMonster : public Action
{
	void execute() override;
}; // TODO

class AddDamage : public Action
{
private:
	Hero* enemy;
public:
	AddDamage(Hero* enemy); 
	void execute() override;
};
class Teleport : public Action
{
	void execute() override;
}; //TODO

class Attack : public Action
{
	Hero* enemy; 
public:
	Attack(Hero* enemy, const Hero* attacker);
	void execute() override;
}; 

class CollectWeapon : public Action
{
private:
	Weapon* weaponToCollect; 
	Alice currentPlayer; 
public:
	CollectWeapon(Weapon* weaponToCollect, Alice currentPlayer);
	void execute() override;
};
