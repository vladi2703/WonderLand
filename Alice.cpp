#include "Alice.h"

void Alice::pickWeapon()
{

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
		std::cout << inventory[i] << ' ';
	}
	std::cout << '\n';
}

void Alice::addWeapon(const Weapon* newWeapon)
{
}
