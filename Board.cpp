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
	:size(0), map(nullptr), entrancePortal(Position()), exitPortal(Position())
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

void Board::setFilename(string filename)
{
	this->filename = filename;
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

void Board::addAliceOnMap(Alice& alice)
{
	Position pos = alice.getPos();
	if (pos.getRow() >= size || pos.getRow() < 0 || pos.getCol() >= size || pos.getCol() < 0)
	{
		throw std::invalid_argument("Invalid position of a weapon");
	}
	map[pos.getRow()][pos.getCol()] = alice.getSign();
}

void Board::addPortalOnMap(Position& toAdd, char sign)
{
	if (toAdd.getRow() >= size || toAdd.getRow() < 0 || toAdd.getCol() >= size || toAdd.getCol() < 0)
	{
		throw std::invalid_argument("Invalid position of a weapon");
	}
	map[toAdd.getRow()][toAdd.getCol()] = sign;

}

void Board::buildBoard(Alice& alice)
{
	
	map = new char* [size];
	for (int i = 0; i < size; i++)
	{
		map[i] = new char[size];
		for (int j = 0; j < size; j++)
		{
			bool isWall = (rand() % 4 == 1);
			if (isWall)
			{
				map[i][j] = '#';
			}
			else
			{
				map[i][j] = '.';
			}
		}
	}

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
	addPortalOnMap(entrancePortal, 'e');
	addPortalOnMap(exitPortal, '0');
	addAliceOnMap(alice);

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
	Position pos = alice.getPos();
	if (pos.getRow() >= size || pos.getRow() < 0 || pos.getCol() >= size || pos.getCol() < 0)
	{
		throw std::invalid_argument("Invalid position of a hero");
	}
	alice.setPosition(entrancePortal);
}

void Board::moveUp(Hero* hero, Alice& alice)
{
	//check for walls
	Position pos = hero->getPos();
	//if (hero->isAlice())
	//{
	//	map[pos.getRow()][pos.getCol()] = '.';
	//}
	//else
	//{
	//	/*int size = overlapedCoord.size();
	//	for (int i = 0; i < size; i++)
	//	{
	//		if (pos == overlapedCoord[i])
	//		{
	//			map[pos.getRow()][pos.getCol()] = overlapedHeroesAndWeapons[i];
	//		}
	//		overlapedCoord.erase(overlapedCoord.begin() + i - 1);
	//		overlapedHeroesAndWeapons.erase(overlapedHeroesAndWeapons.begin() + i - 1);
	//	}*/
	//}
	hero->moveUp(size);
	if (!canWalk(hero->getPos()))
	{
		hero->moveDown(size); 
		return;
	}

	addPortalOnMap(entrancePortal, 'e'); //if the hero was on the ent portal
	addPortalOnMap(exitPortal, '0');
	map[pos.getRow()][pos.getCol()] = '.';
	if (hero->isAlice())
	{
		checkForWeapon(alice);
		checkForHero(alice);
	}
	addHeroOnMap(hero); //no matter if the move was done, the hero would be at the right spot and will override a dot
	if (!hero->isAlice())
	{
		int weaponsSize = freeWeapons.size();
		for (int i = 0; i < weaponsSize; i++)
		{
			if (pos == freeWeapons[i]->getPos())
			{
				addWeaponOnMap(freeWeapons[i]);
			}
		}
		int heroesSize = heroes.size();
		for (int i = 0; i < heroesSize; i++)
		{
			if (pos == heroes[i]->getPos() && heroes[i] != hero)
			{
				addHeroOnMap(heroes[i]);
			}
		}
	}



}

void Board::moveDown(Hero* hero, Alice& alice)
{
	//check for walls
	Position pos = hero->getPos();
	//map[pos.getRow()][pos.getCol()] = '.';
	hero->moveDown(size);
	if (!canWalk(hero->getPos()))
	{
		hero->moveUp(size);
		return;
	}
	addPortalOnMap(entrancePortal, 'e'); //if the hero was on the ent portal
	if (hero->isAlice())
	{
		checkForWeapon(alice);
		checkForHero(alice);

	}
	map[pos.getRow()][pos.getCol()] = '.';
	addHeroOnMap(hero); //no matter if the move was done, the hero would be at the right spot and will override a dot
	if (!hero->isAlice())
	{
		int weaponsSize = freeWeapons.size();
		for (int i = 0; i < weaponsSize; i++)
		{
			if (pos == freeWeapons[i]->getPos())
			{
				addWeaponOnMap(freeWeapons[i]);
			}
		}
		int heroesSize = heroes.size();
		for (int i = 0; i < heroesSize; i++)
		{
			if (pos == heroes[i]->getPos() && heroes[i] != hero)
			{
				addHeroOnMap(heroes[i]);
			}
		}
	}
}

void Board::moveLeft(Hero* hero, Alice& alice)
{
	//check for walls
	Position pos = hero->getPos();
	//map[pos.getRow()][pos.getCol()] = '.';
	hero->moveLeft(size);
	if (!canWalk(hero->getPos()))
	{
		hero->moveRight(size);
		return;
	}
	addPortalOnMap(entrancePortal, 'e'); //if the hero was on the ent portal
	if (hero->isAlice())
	{
		checkForWeapon(alice);
		checkForHero(alice);
	}

	map[pos.getRow()][pos.getCol()] = '.';
	addHeroOnMap(hero); //no matter if the move was done, the hero would be at the right spot and will override a dot
	if (!hero->isAlice())
	{
		int weaponsSize = freeWeapons.size();
		for (int i = 0; i < weaponsSize; i++)
		{
			if (pos == freeWeapons[i]->getPos())
			{
				addWeaponOnMap(freeWeapons[i]);
			}
		}
		int heroesSize = heroes.size();
		for (int i = 0; i < heroesSize; i++)
		{
			if (pos == heroes[i]->getPos() && heroes[i] != hero)
			{
				addHeroOnMap(heroes[i]);
			}
		}
	}
}

void Board::moveRight(Hero* hero, Alice& alice)
{
	//check for walls
	Position pos = hero->getPos();
	//map[pos.getRow()][pos.getCol()] = '.';
	hero->moveRight(size);
	if (!canWalk(hero->getPos()))
	{
		hero->moveLeft(size);
		return;
	}
	addPortalOnMap(entrancePortal, 'e'); //if the hero was on the ent portal
	if (hero->isAlice())
	{
		checkForWeapon(alice);
		checkForHero(alice);
	}
	map[pos.getRow()][pos.getCol()] = '.';
	addHeroOnMap(hero); //no matter if the move was done, the hero would be at the right spot and will override a dot
	if (!hero->isAlice())
	{
	int weaponsSize = freeWeapons.size();
		for (int i = 0; i < weaponsSize; i++)
		{
			if (pos == freeWeapons[i]->getPos())
			{
				addWeaponOnMap(freeWeapons[i]);
			}
		}
		int heroesSize = heroes.size();
		for (int i = 0; i < heroesSize; i++)
		{
			if (pos == heroes[i]->getPos() && heroes[i] != hero)
			{
				addHeroOnMap(heroes[i]);
			}
		}
	}
}

bool Board::canWalk(Position pos)
{
	return (operator[](pos) != '#');
}

void Board::checkForWeapon(Alice& alice)
{
	int weaponsCount = freeWeapons.size(); 
	for (int i = 0; i < weaponsCount; i++)
	{
		if (alice.getPos() == freeWeapons[i]->getPos())
		{
			std::cout << "Found a " << freeWeapons[i]->getName(); 
			alice.collectWeapon(freeWeapons[i]);
			freeWeapons.erase(freeWeapons.begin() + i);
			return;
		}
	}
}

void Board::checkForHero(Alice& alice)
{
	int heroesCount = heroes.size();
	for (int i = 0; i < heroesCount; i++)
	{
		if (alice.getPos() == heroes[i]->getPos())
		{
			std::cout << "Encountered the " << heroes[i]->getName() << std::endl;
			fight(alice, heroes[i]);
			
 			return;
		}
	}
}

bool Board::onExitPortal(Alice& alice)
{
	return (alice.getPos() == exitPortal);
}

void Board::removeHero(const Hero& killedHero)
{
	//primitive Method - overlaping
	/*int heroCount = heroes.size();
	if (heroCount == 1 && *heroes[0] == killedHero)
	{
		heroes.pop_back();	
		return;
	}
	bool found = false;
	for (int i = 0; i < heroCount; i++)
	{
		if (*heroes[i] != killedHero && !found) //after found not needed to check
		{
			found = true;
		}
		heroes[i] = heroes[i + 1];
		if (found)
		{
			heroes[i] = heroes[i + 1]; 
		}
		heroes.pop_back();
	}*/
	int heroCount = heroes.size();
	for (int i = 0; i < heroCount; i++)
	{
		if (*heroes[i] != killedHero) 
		{
			heroes.erase(heroes.begin() + i);
			return; 
		}
	}
	throw std::out_of_range("No such hero found");

}
void Board::removeWeapon(const Weapon& collectedWeapon)
{
	//primitive Method - overlaping
	/*bool found = false;
	int weaponsCount = freeWeapons.size();
	if (weaponsCount == 1 && *freeWeapons[0] == collectedWeapon) //not to delete the last weapon, when wrong weapon is added
	{
		freeWeapons.pop_back(); 
	}
	for (int i = 0; i < weaponsCount; i++)
	{
		if (*freeWeapons[i] != collectedWeapon && !found) //after found not needed to check
		{
			found = true;
		}
		if (found) //from this index till end
		{
			freeWeapons[i] = freeWeapons[i + 1];
		}
		freeWeapons.pop_back(); 
	}
	if (!found)
	{
		throw std::out_of_range("No such weapon found");
	}
	*/
	
	int weaponCount = freeWeapons.size();
	for (int i = 0; i < weaponCount; i++)
	{
		if (*freeWeapons[i] != collectedWeapon)
		{
			freeWeapons.erase(freeWeapons.begin() + i);
			return;
		}
	}
	throw std::out_of_range("No such hero found");

}

char Board::operator[](Position& pos) const
{
	if (pos.getRow() < 0 || pos.getRow() >=  size || pos.getCol() < 0 || pos.getCol() >= size)
	{
		throw std::invalid_argument("No such position on current board");
	}
	return map[pos.getRow()][pos.getCol()];
}

char& Board::operator[](Position& pos)
{
	if (pos.getRow() < 0 || pos.getRow() >= size || pos.getCol() < 0 || pos.getCol() >= size)
	{
		throw std::invalid_argument("No such position on current board");
	}
	return map[pos.getRow()][pos.getCol()];
}


void Board::printHeroes()
{
	int countOfHeroes = heroes.size();
	if (countOfHeroes == 0)
	{
		std::cout << "No heroes alive" << std::endl;
	}
	for (int i = 0; i < countOfHeroes; i++)
	{
		std::cout << i + 1 << ". " << heroes[i]->getName() << std::endl;
	}
	std::cout << '\n';
}

Hero* Board::choseHero()
{
	int index = -1;
	if (heroes.size() == 0)
	{
		std::cout << "No heroes alive" << std::endl;
		return nullptr;
	}
	while (true)
	{
		index--;
		if (index == -1)
		{
			return nullptr;
		}
		if (index < -1 || index > heroes.size())
		{
			std::cout << "Enter a valid index and a 0 to cancel: ";
			std::cin >> index;
			continue;
		}
		std::cout << "You chose: " << heroes[index]->getName() << std::endl;
		return heroes[index];
	}
}

void Board::fight(Alice& alice, Hero* enemy)
{
	while (alice.getHp() > 0 && enemy->getHp() > 0)
	{
		std::cout << "Your hp: " << alice.getHp() << " your damage: " << alice.getDamage() << std::endl;
		std::cout << enemy->getName() << "'s hp: " << enemy->getHp() << ' ' << enemy->getName() << "'s damage: " << enemy->getDamage() << std::endl;
		alice.revertDamage(); 
		char flag = ' ';
		do
		{
		std::cout << "Do you need a weapon?(y/N): ";
			std::cin >> flag; 
			if (flag == 'y')
			{
				alice.showInventory(); 
				alice.pickWeapon();
				alice.useWeapon();
				break;
			}
			else if (flag == 'N')
			{
				break;
			}
		} while (flag != 'y' && flag != 'N');
		alice.attack(*enemy); 

		enemy->attack(alice);
		enemy->castAbility(); 
		if (alice.getHp() <= 0)
		{
			std::cout << "You DIED!" << std::endl;
		}
		else if (enemy->getHp() <= 0)
		{
			std::cout << "You Won!" << std::endl;
		}
	}
		visualize();
}

