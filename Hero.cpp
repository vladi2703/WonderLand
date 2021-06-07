#include "Hero.h"

Hero::Hero(string name, int hp, int damage, Position& pos, char sign)
    :hitpoints(hp), damage(damage), pos(pos), sign(sign), name(name)
{ }

void Hero::attack(Hero& enemy)
{
    enemy.takeDamage(damage); 
}

void Hero::takeDamage(int damage)
{
    hitpoints -= damage;
}

int Hero::getDamage() const
{
    return damage;
}

int Hero::getHp() const
{
    return hitpoints;
}

Position Hero::getPos() const
{
    return pos;
}

char Hero::getSign() const
{
    return sign;
}

string Hero::getName() const
{
    return name;
}

void Hero::setDamage(const int value)  
{ 
    this->damage = value;
}

void Hero::setPosition(Position& pos)
{ 
    this->pos = pos;
}

void Hero::resetHP(int maxHP)
{
    hitpoints = maxHP;
}

bool Hero::operator==(const Hero& rhs)
{
    return (name==name); //TODO: think of position -> will it change when heroes are moved
}

bool Hero::operator!=(const Hero& rhs)
{
    return !operator==(rhs);
}
