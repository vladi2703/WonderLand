#include "Weapon.h"

Weapon::Weapon(int damage, string name, string description)
	:damage(damage), name(name), descripition(descripition)
{ }

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
const int teleportPotionDamage = 0;
const string name = "Teleport potion"; 
const string teleportPotionDescription = "Moves Alice 3 fields forward, or to the first free field. If the exit portal is less than 3 fields away - stay at current position";
TeleportPotion::TeleportPotion()
	:Weapon(teleportPotionDamage, name, teleportPotionDescription)
{ }
const Teleport* TeleportPotion::ability = new Teleport();
//Potion "Drink me" 
const int potionDrinkMeDamage = 10;
const string potionDrinkMeName = "Potion - Drink me ";
const string potionDrinkMeDescription = "Decreases Alice's damage";
PotionDrinkMe::PotionDrinkMe()
	:Weapon(teleportPotionDamage, potionDrinkMeName, teleportPotionDescription)
{}
const Action* PotionDrinkMe::ability = nullptr;

//Cookie "Eat Me"
const int cookieEatMeDamage = 40;
const string cookieEatMeName = "Cookie - eat me ";
const string cookieEatMeDescription = "Increases Alice's damage";
CookieEatMe::CookieEatMe()
	:Weapon(cookieEatMeDamage, cookieEatMeName, cookieEatMeDescription)
{}
const Action* PotionDrinkMe::ability = nullptr;

//Magic fan
const int magicFanDamage = 35;
const string magicFanName = "Magic Fan"; 
const string MagicFanDescription = "Decreases enemy and gives Alice advantage"; 
MagicFan::MagicFan()
	:Weapon(magicFanDamage, magicFanName, MagicFanDescription)
{}
const Action* CookieEatMe::ability = nullptr;

//Inbisible hat
const int invisibleHatDamage = 0; 
const string invisibleHatName = "Invisible Hat";
const string invisibleHatDescription = "Makes Alice invisible - she moves 2 fields forward, automatically defeating the rival."; 
InvisibleHat::InvisibleHat()
	:Weapon(invisibleHatDamage, invisibleHatName, invisibleHatDescription)
{ }
const SkipNextMonster* InvisibleHat::ability = new SkipNextMonster();

//Take a rose 
const int defaultValue = 0;
const string takeARoseName = "Toss a rose";
const string takeARoseDescription = "Alice tosses a rose. Red - 40 damage, White - 10 damage";
Rose::Rose()
	:Weapon(defaultValue, takeARoseName, takeARoseDescription)
{
	TakeARose* a = new TakeARose(); 
	damage = a->getDamage();
const TakeARose* Rose::ability = a; //in order to use takearose function 
}


