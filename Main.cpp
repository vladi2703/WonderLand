#include <iostream>
#include "Alice.h"
#include "Weapon.h"
#include "Board.h"
int main()
{
	Position pos(0, 0); 
	Alice* a = new Alice(pos);
	Rose* w = new Rose(pos, a); 
	//a->addWeapon(w);
	//a->showInventory(); 
	//w->ability->execute();
	//std::cout << a->getDamage(); 

	Board map1; 
	map1.setSize(10);
	map1.addWeapon(w); 
	Position entrancePortalPos(3, 1);
	Position exitPortalPos(4, 7);
	map1.setEntrancePortal(entrancePortalPos);
	map1.setExitPortal(exitPortalPos);
	map1.setAliceToBegin(*a);
	map1.buildBoard(*a); 
	map1.visualize();
	map1.moveUp(a);
	system("CLS");
	map1.buildBoard(*a);
	map1.visualize(); 



}
