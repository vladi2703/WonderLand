#include "Hero.h"

Hero::Hero(int hp, int damage)
    :hitpoints(hp), damage(damage)
{ }

void Hero::attack(Hero& enemy)
{
    enemy.takeDamage(damage); 
}

void Hero::takeDamage(int damage)
{
    hitpoints -= damage;
}

void Hero::writeToFile(string filename) const
{

}

int Hero::getDamage() const
{
    return damage;
}

int Hero::getHp() const
{
    return hitpoints;
}

void Hero::setDamage(const int value)  
{ 
    this->damage = damage;
}
