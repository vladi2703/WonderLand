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
	Alice(Position& startingPos, char sign = 'A');
	void pickWeapon();
	void showInventory(); 
	void collectWeapon(Weapon* newWeapon); 
	void useWeapon(); 
	void revertDamage(); 

	Hero* clone() const override;
};

