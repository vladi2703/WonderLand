#include <iostream>
#include <Windows.h>
#include "Alice.h"
#include "Weapon.h"
#include "Board.h"
#include "Enemy.h"

const string filename = "DataBase.txt";

//void mapCreator(vector<Board>& maps, Alice* a)
//{
//		//Map1 setting
//	//positions + size
//		const int size = 10;
//
//		Position positions[size][size]; 
//		for (int i = 0; i < size; i++)
//		{
//			for (int j= 0; j < size; j++)
//			{
//				positions[i][j] = Position(i, j);
//			}
//		}
//	
//
//		//weapons
//		Rose* r = new Rose(positions[0][0], a);
//		PotionDrinkMe* pot = new PotionDrinkMe(positions[4][0], a);
//		CookieEatMe* cet = new CookieEatMe(positions[9][0], a);
//		MagicFan* mf = new MagicFan(positions[0][0], a); 
//		InvisibleHat* ih = new InvisibleHat(positions[9][0], a, nullptr); 
//		TeleportPotion* tp = new TeleportPotion(positions[1][0], a, positions[0][0]);
//		//enemies
//		CheshireCat* k = new CheshireCat(positions[2][0], a, positions[4][0]);
//		CrazyHatter* h = new CrazyHatter(positions[4][0]);
//		WhiteRabbit* rab = new WhiteRabbit(positions[7][0]);
//		QueenOfHearts* q = new QueenOfHearts(positions[1][0]);
//
//
//		//board
//		Board map1(filename); 
//		map1.setSize(size);
//		map1.addWeapon(r);
//		map1.addHero(k);
//		map1.addHero(h);
//		map1.setEntrancePortal(pos31);
//		map1.setExitPortal(pos47);
//		map1.setAliceToBegin(*a);
//		map1.buildBoard(*a);
//		maps.push_back(map1); 
//		maps[0].setFilename(filename);
//
//}
int main()
{
	Position defaultPos(0,0); 
	vector<Board> maps;
	//Alice
	Alice* a = new Alice(defaultPos);
	//Map1 setting
	//positions + size
	int size = 10;

	Position** positions = new Position*[size];
	for (int i = 0; i < size; i++)
	{
		positions[i] = new Position [size];
		for (int j = 0; j < size; j++)
		{
			positions[i][j] = Position(i, j);
		}
	}
	//weapons
	Rose* r1 = new Rose(positions[0][0], a);
	//enemies

	CheshireCat* k1 = new CheshireCat(positions[2][2], a, positions[4][0]);
	QueenOfHearts* q1 = new QueenOfHearts(positions[1][0]);

	//board
	Board map1(filename, true);
	map1.addHero(k1);
	maps.push_back(map1);
	maps[0].setSize(size);
	maps[0].addWeapon(r1);
	maps[0].addHero(k1);
	maps[0].addHero(q1);
	maps[0].setEntrancePortal(positions[3][1]);
	maps[0].setExitPortal(positions[4][7]);
	maps[0].setAliceToBegin(*a);
	maps[0].buildBoard(*a);
	//Map2 setting
	//weapons
	PotionDrinkMe* pot2 = new PotionDrinkMe(positions[3][2], a);
	CookieEatMe* cet2 = new CookieEatMe(positions[6][8], a);
	MagicFan* mf2 = new MagicFan(positions[5][5], a);
	//enemies
	CrazyHatter* h2 = new CrazyHatter(positions[4][6]);
	WhiteRabbit* rab2 = new WhiteRabbit(positions[7][0]);



	Board map2(filename); 
	maps.push_back(map2);
	maps[1].setSize(size);
	maps[1].addWeapon(pot2);
	maps[1].addWeapon(cet2);
	maps[1].addWeapon(mf2);
	maps[1].addHero(h2);
	maps[1].addHero(rab2);
	maps[1].setEntrancePortal(positions[9][9]);
	maps[1].setExitPortal(positions[1][1]);


	//mapCreator(maps, a);
	const int countOfLevels = maps.size();
	int index = 0;
	Board* currentMap = &maps[0];
	Board* currentMapCopy = currentMap->clone(); 
	currentMap->visualize();
	Hero* currentHero = a;

	while (true)
	{
		if (!currentMap->checkAliceIsAlive(*a))
		{
			std::cout << "YOU DIED" << std::endl;
			a->rebirth();
			currentMap = currentMapCopy->clone();
			currentMap->reviveAllEnemies(); 
			currentMap->setAliceToBegin(*a); 
			currentMap->buildBoard(*a);
			Sleep(500);
			system("CLS");
			currentMap->visualize();

		}
		if (currentMap->onExitPortal(*a))
		{
			if (index < countOfLevels - 1)
			{
				currentMap = &maps[++index];
				Board::writeToFile("Map2 \n", filename);
				maps[index].setAliceToBegin(*a);
				maps[index].buildBoard(*a);
				currentMapCopy = currentMap->clone();
				system("CLS");
				currentMap->visualize();
			}	
			else if (index == countOfLevels - 1)
			{
				std::cout << "CONGRATULATIONS! You won!" << std::endl;
				break; 
			}
		}
		
		if (GetAsyncKeyState(VK_UP))
		{
			currentMap->moveUp(currentHero, *a); 
			system("CLS");
			currentMap->visualize();
		}
		else if (GetAsyncKeyState(VK_DOWN))
		{
			currentMap->moveDown(currentHero, *a);
			system("CLS");
			currentMap->visualize();
		}
		else if (GetAsyncKeyState(VK_LEFT))
		{
			currentMap->moveLeft(currentHero, *a);
			system("CLS");
			currentMap->visualize();
		}
		else if (GetAsyncKeyState(VK_RIGHT))
		{
			currentMap->moveRight(currentHero, *a);
			system("CLS");
			currentMap->visualize();
		}
		else if (GetAsyncKeyState(VK_RSHIFT))
		{
			a->showInventory();
			a->pickWeapon();
			a->useWeapon();
		}

		else if (GetAsyncKeyState(VK_ESCAPE))
		{
			system("PAUSE");
			system("CLS");
			currentMap->visualize();
		}
		else if (GetAsyncKeyState(VK_TAB))
		{
			std::cout << "Choose a character to command: " << std::endl;
			currentMap->printHeroes();
			Hero* choice = currentMap->choseHero();
			if (choice != nullptr)
			{
				currentHero = choice;
				std::cout << "To command Alice again - press left CTRL";
			}
		}
		else if(GetAsyncKeyState(VK_LCONTROL))
		{
			currentHero = a;
			std::cout << "You command Alice again";

		}
		else if (GetAsyncKeyState(VK_BACK))
		{
			a->takeDamage(100); 
		}
		else if (GetAsyncKeyState(VK_END))
		{
			std::cout << "You gave up!" << std::endl; 
			break;
		}
		Sleep(200);
	}
	//free
	delete a;
	delete k1;
	delete q1;
	delete pot2;
	delete cet2;
	delete mf2;
	delete h2;
	delete rab2;
	for (int i = 0; i < size; i++)
	{
		delete positions[i];
	}
	delete[] positions;
	
}

