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

bool Hero::isValidPosition(Position& pos, int sizeOfMap)
{
    return (pos.getRow() >= 0 && pos.getRow() < sizeOfMap && pos.getCol() >= 0 && pos.getCol() < sizeOfMap);
}

void Hero::moveUp(int sizeOfMap)
{
    Position old = pos; 
    pos.moveUp(); 
    if (!isValidPosition(pos, sizeOfMap))
    {
        pos = old;
    }
}

void Hero::moveDown(int sizeOfMap)
{
    Position old = pos;
    pos.moveDown();
    if (!isValidPosition(pos, sizeOfMap))
    {
        pos = old;
    }
}

void Hero::moveRight(int sizeOfMap)
{
    Position old = pos;
    pos.moveRight();
    if (!isValidPosition(pos, sizeOfMap))
    {
        pos = old;
    }
}

void Hero::moveLeft(int sizeOfMap)
{
    Position old = pos;
    pos.moveLeft();
    if (!isValidPosition(pos, sizeOfMap))
    {
        pos = old;
    }
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
