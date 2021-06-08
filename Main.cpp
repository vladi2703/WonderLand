#include <iostream>
#include <Windows.h>
#include "Alice.h"
#include "Weapon.h"
#include "Board.h"
#include "Enemy.h"
int main()
{
	//a->addWeapon(w)
	//a->showInventory(); 
	//w->ability->execute();
	//std::cout << a->getDamage(); 
	

	vector<Board> maps;
	//Map1 setting
//positions + size
	const int size = 10; 

	Position pos00(0, 0);
	Position pos22(2, 2);
	Position pos31(3, 1);
	Position pos46(4, 6);
	Position pos47(4, 7);
	
//Alice
	Alice* a = new Alice(pos00);
//weapons
	Rose* r = new Rose(pos00, a);
//enemies
	CheshireCat* k = new CheshireCat(pos22, a, pos00);
	CrazyHatter* h = new CrazyHatter(pos46);
//board
	Board map1; 
	map1.setSize(size);
	map1.addWeapon(r); 
	map1.addHero(k);
	map1.addHero(h);
	map1.setEntrancePortal(pos31);
	map1.setExitPortal(pos47);
	map1.setAliceToBegin(*a);
	map1.buildBoard(*a); 
	map1.visualize();
	system("CLS");
	map1.buildBoard(*a);
	map1.visualize(); 

	Hero* currentHero = a;
	while (true)
	{
		if (GetAsyncKeyState(VK_UP))
		{
			map1.moveUp(currentHero, *a); 
			system("CLS");
			map1.visualize();
		}
		else if (GetAsyncKeyState(VK_DOWN))
		{
			map1.moveDown(currentHero, *a);
			system("CLS");
			map1.visualize();
		}
		else if (GetAsyncKeyState(VK_LEFT))
		{
			map1.moveLeft(currentHero, *a);
			system("CLS");
			map1.visualize();
		}
		else if (GetAsyncKeyState(VK_RIGHT))
		{
			map1.moveRight(currentHero, *a);
			system("CLS");
			map1.visualize();
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
			map1.visualize();
		}
		else if (GetAsyncKeyState(VK_LSHIFT))
		{
			std::cout << "Choose a character to command: " << std::endl;
			map1.printHeroes();
			Hero* choice = map1.choseHero();
			if (choice != nullptr)
			{
				currentHero = choice;
			}
			std::cout << "To command Alice again - press left CTRL"; 
		}
		else if(GetAsyncKeyState(VK_LCONTROL))
		{
			currentHero = a;
			std::cout << "You command Alice again";

		}
		Sleep(200);
	}



}
