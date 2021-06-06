#pragma once
#include <string>

using std::string;

class Hero
{
private: 
	int hitpoints; 
	int damage; 
protected:
	Hero(int hp, int damage);
public:
	void attack(Hero& enemy); 
	void takeDamage(int damage); 
	void writeToFile(string filename) const ; //TODO
	
	int getDamage() const;
	int getHp() const; 

	void setDamage(const int value); 
};


