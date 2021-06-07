#include <iostream>
#include "Alice.h"
#include "Weapon.h"
int main()
{
	Position pos(0, 0); 
	Alice* a = new Alice(pos);
	Rose* w = new Rose(a); 
	a->addWeapon(w);
	a->showInventory(); 
	w->ability->execute();
	std::cout << a->getDamage(); 
}
