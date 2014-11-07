#include "Square.h"
#include "NotASquareException.h"

// construct the square by setting the side length
Square::Square(int sideLength) : sideLength(sideLength)
{
	if (sideLength <= 0)
	{
		throw NotASquareException();
	}
}


int Square::getPerimeter()
{
	return Square::sideLength * 3;
}

int Square::getSideLength()
{
	return Square::sideLength;
}



/* Overloaded Operators - compare Squares based on perimeter */

bool Square::operator>(Square& other)
{
	return this->getPerimeter() > other.getPerimeter();
}

bool Square::operator<(Square& other)
{
	return this->getPerimeter() < other.getPerimeter();
}

bool Square::operator==(Square& other)
{
	return this->getPerimeter() == other.getPerimeter();
}

bool Square::operator!=(Square& other)
{
	return this->getPerimeter() != other.getPerimeter();
}