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
	vector<char> overlapedHeroesAndWeapons; //when a non-alice hero overlaps hero/weapon we should return it 
	vector<Position> overlapedCoord;  //not to go through the whole vectors, well save them here
	Position entrancePortal; 
	Position exitPortal; 
	string filename; 

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
	void setFilename(string filename); 

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

	void moveUp(Hero* hero, Alice& alice); 
	void moveDown(Hero* hero, Alice& alice);
	void moveLeft(Hero* hero, Alice& alice);
	void moveRight(Hero* hero, Alice& alice);

	bool canWalk(Position pos); 

	void checkForWeapon(Alice& alice);
	void checkForHero(Alice& alice);
	bool onExitPortal(Alice& alice);

	void removeHero(const Hero& killedHero); 
	void removeWeapon(const Weapon& collectedWeapon);

	char operator[](Position& pos) const;
	char& operator[](Position& pos);

	void printHeroes();
	Hero* choseHero(); 

	void fight(Alice& alice, Hero* enemy); 


};

