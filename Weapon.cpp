#include "Weapon.h"
#include "ConstantsNamesAndDescriptions.h"
Weapon::Weapon(int damage, string name, string description,char sign, Position startingPos, Hero* owner)
	:name(name), descripition(description), sign(sign), ability(nullptr)
{
	setDamage(damage); 
	setPos(startingPos); 
	setOwner(owner);
}
Weapon::~Weapon()
{
	delete[] ability; 
}
int Weapon::getDamage() const
{
	return damage;
}
string Weapon::getDescription() const
{
	return descripition; 
}
string Weapon::getName()const
{
	return name;
}
char Weapon::getSign()const 
{
	return sign;
}
Position Weapon::getPos() const
{
	return startPos;
}
Hero* Weapon::getOwner() const
{
	return owner;
}
void Weapon::setPos(Position& pos)
{
	if (pos.getCol() > 0 && pos.getRow() > 0)
	{
		startPos = pos; 
	}
}
void Weapon::setOwner(Hero* newOwner)
{
	owner = newOwner;
}
bool Weapon::operator==(const Weapon& rhs)
{
	return (descripition == rhs.descripition && name == rhs.name && startPos == rhs.startPos);
}
bool Weapon::operator!=(const Weapon& rhs)
{
	return !operator==(rhs);
}
void Weapon::setDamage(int value)
{
	if (value > 0)
	{
		damage = value;
	}
}


//Teleport potion
TeleportPotion::TeleportPotion(Position startingPos, Hero* owner)
	:Weapon(teleportPotionDamage, name, teleportPotionDescription, teleportSign, startingPos, owner)
{
	ability = new SkipNextMonster(owner);
}
Weapon* TeleportPotion::clone() const 
{
	TeleportPotion* copy = new TeleportPotion (*this);
	return copy;
}

//Potion "Drink me" 
PotionDrinkMe::PotionDrinkMe(Position startPos, Hero* owner)
	:Weapon(potionDrinkMeDamage, potionDrinkMeName, potionDrinkMeDescription, potionDrinkMeSign, startPos, owner)
{
	ability = new SetDamage(owner, 10);
}
Weapon* PotionDrinkMe::clone() const 
{
	PotionDrinkMe* copy = new PotionDrinkMe(*this);
	return copy;
}

//Cookie "Eat Me"
CookieEatMe::CookieEatMe(Position startPos, Hero* owner)
	:Weapon(cookieEatMeDamage, cookieEatMeName, cookieEatMeDescription, cookieEatMeSign, startPos, owner)
{
	ability = new SetDamage(owner, cookieEatMeDamage);
}
Weapon* CookieEatMe::clone() const
{
	CookieEatMe* copy = new CookieEatMe(*this);
	return copy;
}

//Magic fan
MagicFan::MagicFan(Position startPos, Hero* owner)
	:Weapon(magicFanDamage, magicFanName, magicFanDescription, magicFanSign, startPos, owner)
{
	ability = new SetDamage(owner, magicFanDamage);
}
Weapon* MagicFan::clone() const
{
	MagicFan* copy = new MagicFan(*this);
	return copy;
}


//Inbisible hat
InvisibleHat::InvisibleHat(Position startPos, Hero* owner, Hero* enemy)
	:Weapon(invisibleHatDamage, invisibleHatName, invisibleHatDescription, invisibleHatSign, startPos, owner)
{
	ability = new SkipNextMonster(owner);
}
Weapon* InvisibleHat::clone() const
{
	InvisibleHat* copy = new InvisibleHat(*this);
	return copy;
}


//Take a rose 
Rose::Rose(Position startPos, Hero* owner)
	:Weapon(defaultValue, takeARoseName, takeARoseDescription, takeARoseSign, startPos, owner)
{
	ability = new TakeARose(owner);
}
Weapon* Rose::clone() const
{
	Rose* copy = new Rose(*this);
	return copy;
}



