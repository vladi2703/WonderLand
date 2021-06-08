#include "Alice.h"
const int ALICE_BASE_DAMAGE = 15;
const int ALICE_BASE_HEALTH = 100;
const string ALICE_NAME = "Alice";

Alice::Alice(Position& startingPos, char sign)
	:Hero(ALICE_NAME, ALICE_BASE_HEALTH, ALICE_BASE_DAMAGE, startingPos, sign), currentWeapon(nullptr)
{
}

void Alice::pickWeapon() //pick a weapon - 0 to cancel; after fight - destroy weapon
{
	int index = -1;
	if (inventory.size() == 0)
	{
		return;
	}
	while(true)
	{
	index--; //player sees the index + 1 
		if (index == -1)
		{
			return; 
		}
		if ( index < -1 || index >= inventory.size())
		{
			std::cout << "Enter a valid index and a 0 to cancel: ";
			std::cin >> index; 
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

void Alice::collectWeapon(Weapon* newWeapon)
{
	if (newWeapon == nullptr)
	{
		throw std::invalid_argument("Invalid weapon to collect");
	}
	inventory.push_back(newWeapon);
}

void Alice::useWeapon()
{
	if (currentWeapon != nullptr)
	{
		char useWeapon;
		std::cout << "Do you want to use weapon?(y/N) ";
		do
		{
			std::cin >> useWeapon;
		} while (useWeapon != 'y' && useWeapon != 'N');
		if (useWeapon == 'y')
		{
			currentWeapon->ability->execute(); 
		}
		else if(useWeapon == 'N')
		{
			return;
		}
		else
		{
			throw std::invalid_argument("Invalid command read");
		}
	}
	else
	{
		std::cout << "No weapon chosen" << std::endl;
		return;
	}
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