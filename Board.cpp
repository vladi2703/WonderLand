#include "Board.h"

void Board::copyFrom(const Board& other)
{
	size = other.size; 
	map = new char* [size]; 
	for (int i = 0; i < size; i++)
	{
		map[i] = new char[size];
		for (int j = 0; j < size; j++)
		{
			map[i][j] = other.map[i][j];
		}
	}
	int countOfHeroes = other.heroes.size();
	for (int i = 0; i < countOfHeroes; i++)
	{
		heroes.push_back(other.heroes[i]->clone());
	}
	int countOfWeapons = other.freeWeapons.size();
	for (int i = 0; i < countOfWeapons; i++)
	{
		freeWeapons.push_back(other.freeWeapons[i]->clone()); 
	}


}
