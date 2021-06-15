#pragma once
#include "Hero.h"
#include "Action.h"
class Enemy:public Hero
{

public:
	const Action* ability; 
	Enemy(string name, int hp, int damage, Position& pos, char sign);
	Enemy(const Enemy& other); 
	Enemy& operator= (const Enemy& other); 
	~Enemy(); 

	Hero* clone() const override;
	bool isAlice() const override;

	 virtual void castAbility();
};

class CheshireCat : public Enemy
{
private:
	Position& toPortEnemy;
public:
	void castAbility() override;
	CheshireCat(Position& startingPos, Hero* enemy, Position& toPortEnemy); //moje da ima i drugi vragove, ne samo alisa
	void setToPortPosition(Position& newPos);
};

class QueenOfHearts: public Enemy
{
public:
	QueenOfHearts(Position& startingPos);
};

class WhiteRabbit: public Enemy
{
public:
	WhiteRabbit(Position& startingPos);
};

class CrazyHatter: public Enemy
{
public:
	void castAbility() override; 
	CrazyHatter(Position& startingPos);
};
