#pragma once
#include <iostream>
#include <vector>
#include "Hero.h"
#include "Weapon.h"

using std::vector; 

class Alice : public Hero
{
private:
	vector<Weapon*> inventory; 
	Weapon* currentWeapon; 
	
	
public: 
	Alice(Position& startingPos);
	void pickWeapon(int index);
	void showInventory(); 
	void addWeapon(Weapon* newWeapon); 
	void useWeapon(); 

	void revertDamage(); 
};

