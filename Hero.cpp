#include "Hero.h"

Hero::Hero(int hp, int damage, Position& pos, char sign)
    :hitpoints(hp), damage(damage), pos(pos), sign(sign)
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
