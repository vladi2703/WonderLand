#pragma once
#include "Action.h"
#include "cstring"

using std::string;
class Weapon
{
public:
protected: 

	string descripition;
	string name;
	int damage; 
	
	Weapon(int damage, string name, string descripition); 

	void setDamage(int value); 
	
public:
	const Action* ability;
	virtual ~Weapon(); 
	int getDamage(); 
	string getDescription();	
	string getName();
	

};

class TeleportPotion : public Weapon 
{
private:
	Hero* owner; //owner of the potion
	Position toPort; //position we want to teleport the "owner" 
public: 
	TeleportPotion(Hero* owner, Position& toPort);
	Weapon* clone();
};
 
class PotionDrinkMe :public Weapon
{
private:
	Hero* owner; //owner of the potion
public:
	PotionDrinkMe(Hero* owner);
	Weapon* clone();

};
class CookieEatMe :public Weapon
{
private:
	Hero* owner; //owner of the cookie
public:
	CookieEatMe(Hero* owner);
	Weapon* clone();

};

class MagicFan : public Weapon
{
public:
	MagicFan();
	Weapon* clone();
};

class InvisibleHat : public Weapon
{
public:
	InvisibleHat();
	Weapon* clone();
};

class Rose : public Weapon
{
private:
	Hero* owner;
public:
	Rose(Hero* owner);
	Weapon* clone();
};


