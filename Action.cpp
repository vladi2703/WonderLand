#include "Action.h"
#include <cstdlib>
#include <ctime>

void EmptySpace::execute()
{
	//do nothing
}

void Move::execute()
{

}
//Take a rose
TakeARose::TakeARose()
{ }
void TakeARose::execute()
{ }
int TakeARose::getDamage()
{
	srand(time(NULL));
	bool roseIsRed = (rand() % 2 == 1);
	if (roseIsRed)
	{
		return 30;
	}
	else
	{
		return 10;
	}

}


void SkipNextMonster::execute()
{
	//move 2 positions forward outside monste
}


AddDamage::AddDamage(Hero* enemy)
	:enemy(enemy)
{ }

void AddDamage::execute()
{
	enemy->takeDamage(40);
}

void Teleport::execute()
{
}

Attack::Attack(Hero* enemy, const Hero* attacker )
{
	enemy->takeDamage(attacker->getDamage());
}

void Attack::execute()
{
	
}

CollectWeapon::CollectWeapon(Weapon* weaponToCollect, Alice currentPlayer)
	:weaponToCollect(weaponToCollect), currentPlayer(currentPlayer)
{ }

void CollectWeapon::execute()
{
	currentPlayer.addWeapon(weaponToCollect);
}
