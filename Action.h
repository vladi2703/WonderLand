#pragma once
#include "Hero.h"
//#include "Weapon.h"
class Action
{

public: 
	virtual void execute() const = 0 ;
};

class EmptySpace : public Action
{
	void execute() const override;
};

class TakeARose : public Action
{
private:
	Hero* champion;
public:
	TakeARose(Hero* champion);
	void execute() const override;
};

class SkipNextMonster : public Action
{
private:
	Hero* heroToKill;
	Hero* owner;
public:
	SkipNextMonster(Hero* owner, Hero* heroToKill);
	void execute() const override;
}; 

class SetDamage : public Action
{
private:
	Hero* champion;
	int damageToSet; 
public:
	SetDamage(Hero* champion, int damageToAdd);
	void execute() const override;
};
class Teleport : public Action
{
private:
	Position& toPort; 
	Hero* champion; 
public:
	Teleport(Position& toPort, Hero* champion);
	void execute() const override;
}; 

class Attack : public Action
{
	Hero* enemy;
	const Hero* attacker; 
	int damage; 
public:
	Attack(Hero* enemy, const Hero* attacker, int damage);
	void execute() const override;
};
