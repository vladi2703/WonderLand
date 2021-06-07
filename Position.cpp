#include "Position.h"

Position::Position(const int row, const int column, bool hasEnemy, bool hasWeapon, bool hasWall)
    :row(row), column(column), hasEnemy(hasEnemy),hasWeapon(hasWeapon), hasWall(hasWall)
{
}

bool Position::operator==(const Position rhs) const
{
    return row == (rhs.row && column == rhs.column);
}

int Position::getRow() const
{
    return row;
}

int Position::getCol() const
{
    return column;
}

Position getRandomPos(int size)
{
    srand(time(NULL));
    return Position(rand() % size, rand() % size);
}
