#include "Weapon.h"
#include "ConstantsNamesAndDescriptions.h"
Weapon::Weapon(int damage, string name, string description,char sign, Position startingPos)
	:damage(damage), name(name), descripition(description), sign(sign), startPos(startingPos), ability(nullptr)
{ }
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
	damage = value;
}


//Teleport potion
TeleportPotion::TeleportPotion(Position startingPos, Hero* owner, Position& toPort)
	:Weapon(teleportPotionDamage, name, teleportPotionDescription, teleportSign, startingPos), owner(owner), toPort(toPort)
{
	ability = new Teleport(toPort, owner);
}
Weapon* TeleportPotion::clone() const 
{
	TeleportPotion* copy = new TeleportPotion (*this);
	return copy;
}

//Potion "Drink me" 
PotionDrinkMe::PotionDrinkMe(Position startPos, Hero* owner)
	:Weapon(potionDrinkMeDamage, potionDrinkMeName, potionDrinkMeDescription, potionDrinkMeSign, startPos), owner(owner)
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
	:Weapon(cookieEatMeDamage, cookieEatMeName, cookieEatMeDescription, cookieEatMeSign, startPos), owner(owner)
{
	ability = new SetDamage(owner, 40);
}
Weapon* CookieEatMe::clone() const
{
	CookieEatMe* copy = new CookieEatMe(*this);
	return copy;
}

//Magic fan
MagicFan::MagicFan(Position startPos)
	:Weapon(magicFanDamage, magicFanName, MagicFanDescription, magicFanSign, startPos)
{
	ability = nullptr;
}
Weapon* MagicFan::clone() const
{
	MagicFan* copy = new MagicFan(*this);
	return copy;
}


//Inbisible hat
InvisibleHat::InvisibleHat(Position startPos)
	:Weapon(invisibleHatDamage, invisibleHatName, invisibleHatDescription, invisibleHatSign, startPos)
{
	ability = new SkipNextMonster();
}
Weapon* InvisibleHat::clone() const
{
	InvisibleHat* copy = new InvisibleHat(*this);
	return copy;
}


//Take a rose 
Rose::Rose(Position startPos, Hero* owner)
	:Weapon(defaultValue, takeARoseName, takeARoseDescription, takeARoseSign, startPos), owner(owner)
{
	ability = new TakeARose(owner);
}
Weapon* Rose::clone() const
{
	Rose* copy = new Rose(*this);
	return copy;
}



