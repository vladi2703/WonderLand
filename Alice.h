#pragma once
#include <iostream>
#include <vector>
#include "Hero.h"
#include "Weapon.h"

using std::vector; 

class Alice : public Hero
{
private:
	int freeMoves;

	vector<Weapon*> inventory; 
	Weapon* currentWeapon; 
	
	
public: 
	Alice(Position& startingPos, char sign = 'A');
	void pickWeapon();
	void showInventory(); 
	void collectWeapon(Weapon* newWeapon); 
	void useWeapon(); 
	void revertDamage(); 
	void rebirth();

	void castAbility() override;
	void addFreeMoves(int value);
	int getFreeMoves() const;

	Hero* clone() const override;
	bool isAlice() const override;
};

