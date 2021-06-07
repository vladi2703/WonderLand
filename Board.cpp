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

	entrancePortal = other.entrancePortal;
	exitPortal = other.exitPortal;


}

void Board::free()
{
	for (int i = 0; i < size; i++)
	{
		delete map[i]; 
	}
	delete[] map; 
	int heroesCount = heroes.size();
	for (int i = 0; i < heroesCount; i++)
	{
		delete heroes[i];
	}
	heroes.clear(); 
	int weaponsCount = freeWeapons.size();
	for (int i = 0; i < weaponsCount; i++)
	{
		delete freeWeapons[i];
	}
	freeWeapons.clear(); 
}

Board::Board()
	:size(0), map(nullptr)
{
}

Board::Board(const Board& other)
{
	copyFrom(other); 
}

Board& Board::operator=(const Board& other)
{
	if (this != &other)
	{
		free(); 
		copyFrom(other); 
	}
	return *this; 
}

Board::~Board()
{
	free();
}

void Board::addHero(Hero* hero)
{
	heroes.push_back(hero); 
}

void Board::addWeapon(Weapon* weapon)
{
	freeWeapons.push_back(weapon);
}

void Board::setEntrancePortal(Position& toSet)
{
	entrancePortal = toSet; 
}

void Board::setExitPortal(Position& toSet)
{
	exitPortal = toSet;
}

void Board::setSize(int newSize)
{
	size = newSize;
}

Position Board::getEntrancePortal() const
{
	return entrancePortal;
}

Position Board::getExitPortal() const
{
	return exitPortal;
}

int Board::getSize() const
{
	return size;
}

vector<Hero*> Board::getHeroes() const
{
	return heroes;
}

vector<Weapon*> Board::getWeapons() const
{
	return freeWeapons;
}

//bool Board::isFree(Position& toCheck) const
//{
//	return toCheck.isFree();
//}

void Board::addHeroOnMap(Hero* toAdd)
{
	Position pos = toAdd->getPos();
	if (pos.getRow() >= size || pos.getRow() < 0 || pos.getCol() >= size || pos.getCol() < 0)
	{
		throw std::invalid_argument("Invalid position of a hero");
	}
	map[pos.getRow()][pos.getCol()] = toAdd->getSign();
}

void Board::addWeaponOnMap(Weapon* toAdd)
{
	Position pos = toAdd->getPos();
	if (pos.getRow() >= size || pos.getRow() < 0 || pos.getCol() >= size || pos.getCol() < 0)
	{
		throw std::invalid_argument("Invalid position of a weapon");
	}
	map[pos.getRow()][pos.getCol()] = toAdd->getSign();
}

void Board::buildBoard()
{
	int heroCount = heroes.size();
	int weaponsCount = freeWeapons.size(); 
	for (int i = 0; i < heroCount; i++)
	{
		addHeroOnMap(heroes[i]);
	}
	for (int i = 0; i < weaponsCount; i++)
	{
		addWeaponOnMap(freeWeapons[i]);
	}
}

void Board::visualize() const
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			std::cout << map[i][j] << ' '; 
		}
		std::cout << std::endl;
	}
}

void Board::setAliceToBegin(Alice& alice)
{
	alice.setPosition(entrancePortal); 
}

