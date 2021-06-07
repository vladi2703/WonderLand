#pragma once
#include "Position.h"
#include "Alice.h" 
#include "Weapon.h"
#include <vector> 

using std::vector; 

class Board
{
private:
	int size; 
	char** map; 
	vector<Hero*> heroes; 
	vector<Weapon*> freeWeapons; //not collected weapons
	Position entrancePortal; 
	Position exitPortal; 
	
	void copyFrom(const Board other);
	void free(); 
public:
	Board();
	Board(const Board& other); 
	Board& operator= (const Board& other); 
	~Board();
	


	void addHero(Hero& hero); 
	void addWeapon(Weapon& weapon);
	void setEntrancePortal(Position& toSet);
	void setExitPortal(Position& toSet); 
	void setSize(int newSize);

	Position getEntrancePortal() const; 
	Position getExitPortal() const;
	int getSize() const;
	vector<Hero&> getHeroes() const; 
	vector<Weapon&> getWeapons() const; 
	bool isFree(Position& toCheck)const;

	void buildMap(); 
	void visualize() const; 
	void setAliceToBegin(Alice& alice); 

	void removeHero(const Hero& killedHero); 
	void removeWeapon(const Weapon& collectedWeapon);

};

