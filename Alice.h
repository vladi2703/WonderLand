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
public: 
	void pickWeapon();
	void showInventory(); 
	void addWeapon(const Weapon* newWeapon); 
	
};

