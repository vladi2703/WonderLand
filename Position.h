#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
class Position
{
private:
	int row; 
	int column; 
	bool hasEnemy; 
	bool hasWeapon; 
	bool hasWall; 
public:
	Position() = default;
	Position(const int column, const int row, bool hasEnemy = false, bool hasWeapon = false, bool hasWall = false);
	bool operator==(const Position rhs) const; 
	int getRow() const;
	int getCol() const;

	void moveUp(); 
	void moveDown(); 
	void moveLeft(); 
	void moveRight(); 

	
	friend Position getRandomPos(int size); 
	friend std::ostream& operator<< (std::ostream& o_stream, const Position& pos);
	
};

