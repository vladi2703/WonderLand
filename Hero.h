#pragma once
#include <string>
#include "Position.h"
using std::string;

class Hero
{
private: 
protected:
	string name; 
	int hitpoints; 
	int damage; 
	Position pos; 
	Hero(string name, int hp, int damage, Position& pos, char sign);
	char sign;
public:

	void attack(Hero& enemy); 
	void takeDamage(int damage); 
	void writeToFile(string filename) const ; //TODO
	
	int getDamage() const;
	int getHp() const; 
	Position getPos() const;
	char getSign() const;
	string getName() const; 

	void setDamage(const int value); 
	void setPosition(Position& pos); 

	void moveUp();
	void moveDown();
	void moveRight(); 
	void moveLeft(); 

	void resetHP(int maxHP);

	virtual Hero* clone() const = 0 ;

	bool operator==(const Hero& rhs);
	bool operator!=(const Hero& rhs);
};


