#include "Action.h"
#include <cstdlib>
#include <ctime>

void EmptySpace::execute() const
{
	//do nothing
}


//Take a rose
TakeARose::TakeARose(Hero* champion)
	:champion(champion)
{ }
void TakeARose::execute() const
{ 
	srand(time(NULL));
	bool roseIsRed = (rand() % 2 == 1);
	if (roseIsRed)
	{
	champion->setDamage(30); 
	}
	else
	{
	champion->setDamage(10); 
	}
}


SkipNextMonster::SkipNextMonster(Hero* owner)
	:owner(owner)
{ }

void SkipNextMonster::execute() const
{
	//owner->addFreeMoves(3); 
}


SetDamage::SetDamage(Hero* enemy, int damageToSet)
	:champion(enemy), damageToSet(damageToSet)
{ }

void SetDamage::execute() const
{
	champion->setDamage(damageToSet);
}

Teleport::Teleport(Position& toPort, Hero* champion)
	:toPort(toPort), champion(champion)
{  }

void Teleport::execute() const
{
	champion->setPosition(toPort);
}

Attack::Attack(Hero* enemy, const Hero* attacker, int damage = 0)
	:enemy(enemy), attacker(attacker), damage(damage)
{
	if (damage == 0)
	{
		damage = attacker->getDamage();
	}
}

void Attack::execute() const
{
	enemy->takeDamage(damage);
}