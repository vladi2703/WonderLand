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
class Move : public Action //TODO
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
	void execute() const override;
}; // TODO

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
}; //TODO

class Attack : public Action
{
	Hero* enemy;
public:
	Attack(Hero* enemy, const Hero* attacker, int damage);
	void execute() const override;
};

//class CollectWeapon : public Action
//{
//private:
//	Weapon* weaponToCollect;
//	Alice currentPlayer;
//public:
//	CollectWeapon(Weapon* weaponToCollect, Alice currentPlayer);
//	void execute() const override;
//};
