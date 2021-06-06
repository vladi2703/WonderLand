#pragma once
#include "Action.h"
#include "cstring"

using std::string;
class Weapon
{
private:
protected: 

	string descripition;
	string name;
	int damage; 
	static const Action* ability;
	
	Weapon(int damage, string name, string descripition); 

	int getDamage(); 
	string getDescription();	
	string getName();

	void setDamage(int value); 

};

class TeleportPotion : private Weapon
{
public: 
	TeleportPotion();	
};
 
class PotionDrinkMe :private Weapon
{
public:
	PotionDrinkMe();
};
class CookieEatMe :private Weapon
{
public:
	CookieEatMe();
};

class MagicFan : private Weapon
{
public:
	MagicFan();
};
class InvisibleHat : private Weapon
{
public:
	InvisibleHat();
};
class Rose : private Weapon
{
public:
	Rose();
};


