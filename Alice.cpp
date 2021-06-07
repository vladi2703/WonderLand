#include "Alice.h"
const int ALICE_BASE_DAMAGE = 15;
const int ALICE_BASE_HEALTH = 100;


Alice::Alice(Position& startingPos)
	:Hero(ALICE_BASE_HEALTH, ALICE_BASE_DAMAGE, startingPos), currentWeapon(nullptr)
{
}

void Alice::pickWeapon(int index) //pick a weapon - 0 to cancel; after fight - destroy weapon
{
	
	index--; //player sees the index + 1 
	while(true)
	{
		if (index == -1)
		{
			return; 
		}
		if ( index < -1 || index >= inventory.size())
		{
			//cin new index
			continue;
		}
		currentWeapon = inventory[index];
		currentWeapon->ability->execute(); 
		break; 
	}
	
}
void Alice::showInventory()
{
	int countOfItems = inventory.size(); 
	if (countOfItems == 0)
	{
		std::cout << "Your inventory is empty" << std::endl; //intentionally not an exception
	}
	for (int i = 0; i < countOfItems; i++)
	{
		std::cout << i + 1 <<". "<< inventory[i]->getName() 
		<< " //" << inventory[i]->getDescription() << "// " << std::endl; //for every weapon stays a number >= 1
			//future feature -> help function to show description
	}
	std::cout << '\n';
}

void Alice::addWeapon(Weapon* newWeapon)
{
	inventory.push_back(newWeapon);
}

void Alice::revertDamage()
{
	this->setDamage(ALICE_BASE_DAMAGE);
}
Hero* Alice::clone() const
{
	Hero* copy = new Alice(*this); 
	return copy; 
}