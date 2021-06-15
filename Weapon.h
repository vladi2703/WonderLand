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
	char sign; 
	Position startPos; 
	Hero* owner; 
	Weapon(int damage, string name, string descripition, char sign, Position startPos, Hero* owner); 

	void setDamage(int value); 
	
public:
	const Action* ability;
	virtual ~Weapon(); 

	int getDamage() const;  
	string getDescription() const;	
	string getName() const;
	char getSign() const;
	Position getPos() const; 
	Hero* getOwner() const; //owner of the weapon
	
	void setPos(Position& pos); 
	void setOwner(Hero* newOwner); 

	bool operator==(const Weapon& rhs);
	bool operator!=(const Weapon& rhs);

	virtual Weapon* clone() const = 0; 
};

class TeleportPotion : public Weapon 
{
private:
	Position toPort; //position we want to teleport the "owner" 
public: 
	TeleportPotion(Position startPos, Hero* owner, Position& toPort);
	Weapon* clone() const override;
};
 
class PotionDrinkMe :public Weapon
{
public:
	PotionDrinkMe(Position startPos, Hero* owner);
	Weapon* clone() const override;

};
class CookieEatMe :public Weapon
{
public:
	CookieEatMe(Position startPos, Hero* owner);
	Weapon* clone() const override;

};

class MagicFan : public Weapon
{
public:
	MagicFan(Position startPos, Hero* owner);
	Weapon* clone() const override;
};

class InvisibleHat : public Weapon
{

	Hero* enemy;
public:
	InvisibleHat(Position startPos, Hero* owner, Hero* enemy);
	void setEnemy(Hero* enemy); 
	Weapon* clone() const override;

};

class Rose : public Weapon
{
public:
	Rose(Position startPos, Hero* owner);
	Weapon* clone() const override;
};


