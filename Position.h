#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
	bool isFree() const;
	bool operator==(const Position rhs) const; 
	int getRow() const;
	int getCol() const;

	friend Position getRandomPos(int size); 
};

