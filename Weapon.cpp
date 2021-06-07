#include "Weapon.h"
#include "ConstantsNamesAndDescriptions.h"
Weapon::Weapon(int damage, string name, string description)
	:damage(damage), name(name), descripition(description)
{ }
Weapon::~Weapon()
{
	delete[] ability; 
}
int Weapon::getDamage()
{
	return damage;
}
string Weapon::getDescription()
{
	return descripition; 
}
string Weapon::getName()
{
	return name;
}
void Weapon::setDamage(int value)
{
	damage = value;
}


//Teleport potion
TeleportPotion::TeleportPotion(Hero* owner, Position& toPort)
	:Weapon(teleportPotionDamage, name, teleportPotionDescription), owner(owner), toPort(toPort)
{
	ability = new Teleport(toPort, owner);
}
Weapon* TeleportPotion::clone() const 
{
	TeleportPotion* copy = new TeleportPotion (*this);
	return copy;
}

//Potion "Drink me" 
PotionDrinkMe::PotionDrinkMe(Hero* owner)
	:Weapon(potionDrinkMeDamage, potionDrinkMeName, potionDrinkMeDescription), owner(owner)
{
	ability = new SetDamage(owner, 10);
}
Weapon* PotionDrinkMe::clone() const 
{
	PotionDrinkMe* copy = new PotionDrinkMe(*this);
	return copy;
}

//Cookie "Eat Me"
CookieEatMe::CookieEatMe(Hero* owner)
	:Weapon(cookieEatMeDamage, cookieEatMeName, cookieEatMeDescription), owner(owner)
{
	ability = new SetDamage(owner, 40);
}
Weapon* CookieEatMe::clone() const
{
	CookieEatMe* copy = new CookieEatMe(*this);
	return copy;
}

//Magic fan
MagicFan::MagicFan()
	:Weapon(magicFanDamage, magicFanName, MagicFanDescription)
{
	ability = nullptr;
}
Weapon* MagicFan::clone() const
{
	MagicFan* copy = new MagicFan(*this);
	return copy;
}


//Inbisible hat
InvisibleHat::InvisibleHat() 
	:Weapon(invisibleHatDamage, invisibleHatName, invisibleHatDescription)
{
	ability = new SkipNextMonster();
}
Weapon* InvisibleHat::clone() const
{
	InvisibleHat* copy = new InvisibleHat(*this);
	return copy;
}


//Take a rose 
Rose::Rose(Hero* owner)
	:Weapon(defaultValue, takeARoseName, takeARoseDescription), owner(owner)
{
	ability = new TakeARose(owner);
}
Weapon* Rose::clone() const
{
	Rose* copy = new Rose(*this);
	return copy;
}



