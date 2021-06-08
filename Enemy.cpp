#include "Enemy.h"
#include "ConstantsNamesAndDescriptions.h"
Enemy::Enemy(string name, int hp, int damage, Position& pos, char sign)
	:Hero(name, hp, damage, pos, sign), ability(nullptr)
{
}

Enemy::Enemy(const Enemy& other)
	:Hero(other), ability(other.ability)
{
}
Enemy& Enemy::operator=(const Enemy& other)
{
	if (this != &other)
	{
		delete[] ability;
		name = name; 
		damage = damage; 
		pos = pos;
		sign = sign;
	}
	return *this;
}

Enemy::~Enemy()
{
	delete[] ability;
}

//Cat
CheshireCat::CheshireCat(Position& startingPos, Hero* enemy, Position& toPortEnemy)
	:Enemy(caeshireCatName, initialHp, caeshireCatDamage, startingPos, caeshireCatSign), toPortEnemy(toPortEnemy)
{
	ability = new Teleport(toPortEnemy, enemy); 
}
void CheshireCat::setToPortPosition(Position& newPos)
{
	toPortEnemy = newPos;
}
//Queen

QueenOfHearts::QueenOfHearts(Position& startingPos)
	:Enemy(queenOfHeartsName, initialHp, queenOfHeartsDamage, startingPos, queenOfHeartsSign)
{
	ability = nullptr;
}

WhiteRabbit::WhiteRabbit(Position& startingPos)
	: Enemy(whiteRabbitName, initialHp, whiteRabbitDamage, startingPos, whiteRabbitSign)
{
	ability = nullptr;
}
CrazyHatter::CrazyHatter(Position& startingPos)
	: Enemy(crazyHatterName, initialHp, crazyHatterDamage, startingPos, crazyHatterSign)
{
	ability = nullptr;
	
	srand(time(NULL));
	damage = rand() % 20 + 10;

}	