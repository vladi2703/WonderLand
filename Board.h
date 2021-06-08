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
	
	void copyFrom(const Board& other);
	void free(); 
public:
	Board();
	Board(const Board& other); 
	Board& operator= (const Board& other); 
	~Board();
	


	void addHero(Hero* hero); 
	void addWeapon(Weapon* weapon);
	void setEntrancePortal(Position& toSet);
	void setExitPortal(Position& toSet); 
	void setSize(int newSize);

	Position getEntrancePortal() const; 
	Position getExitPortal() const;
	int getSize() const;
	vector<Hero*> getHeroes() const; 
	vector<Weapon*> getWeapons() const; 
	//bool isFree(Position& toCheck)const;

	void addHeroOnMap(Hero* toAdd); 
	void addWeaponOnMap(Weapon* toAdd);
	void addAliceOnMap(Alice& alice); 
	void addPortalOnMap(Position& toAdd, char sign);
	void buildBoard(Alice& alice);
	void visualize() const; 
	void setAliceToBegin(Alice& alice); 

	void moveUp(Hero* hero); 
	void moveDown(Hero* hero); 
	void moveLeft(Hero* hero); 
	void moveRight(Hero* hero); 

	void removeHero(const Hero& killedHero); 
	void removeWeapon(const Weapon& collectedWeapon);

};

