#include "Triangle.h"
#include "NotTriangleException.cpp"


void Triangle::setTriangleType()
{
	int longest = getLongestSide();
	int middle = getMiddleSide();
	int shortest = getShortestSide();

	if (shortest == middle && middle == longest)
		triangleType = Equilateral;
	else if (longest == middle || middle == shortest)
		triangleType = Isosceles;
	else
		triangleType = Scalene;


}

// constructor - initializes the sides
Triangle::Triangle(int side1, int side2, int side3)
{
	// ensure these values make a triangle
	if (side1 + side2 >= side3 || side1 + side3 >= side2 || side2 + side3 >= side1)
	{
		throw new NotTriangleException; // throw an exception if this is not a triangle
	}
	else
	{
		// initialize sides
		sides[0] = side1;
		sides[1] = side2;
		sides[2] = side3;

		// initializes the type of the triangle
		setTriangleType();
	}

}

// what type is this triangle?
TriangleType Triangle::getType() {
	return triangleType;
}

// what is the perimeter of the triangle?
double Triangle::getPerimeter()
{
	return sides[0] + sides[1] + sides[2];
}

// what is the longest side on the triangle?
int Triangle::getLongestSide()
{
	int longest;

	if (sides[0] > sides[1] && sides[0] > sides[2])
		longest = sides[0];
	else if (sides[1] > sides[2])
		longest = sides[1];
	else
		longest = sides[2];

	return longest;
}

// what is the shortest side on the triangle?
int Triangle::getShortestSide()
{
	int shortest;

	if (sides[0] < sides[1] && sides[0] < sides[2])
		shortest = sides[0];
	else if (sides[1] < sides[2])
		shortest = sides[1];
	else
		shortest = sides[2];

	return shortest;
}

// what is the middle side?
int Triangle::getMiddleSide()
{
	int middle;

	if (sides[0] >= sides[1] && sides[0] <= sides[2])
		middle = sides[0];
	else if (sides[1] >= sides[0] && sides[1] <= sides[2])
		middle = sides[1];
	else
		middle = sides[2];

	return middle;
}


/* Overloaded Operators - compare triangles based on perimeter */

bool operator>(Triangle& t1, Triangle& t2)
{
	return t1.getPerimeter() > t2.getPerimeter();
}

bool operator<(Triangle& t1, Triangle& t2)
{
	return t1.getPerimeter() < t2.getPerimeter();
}

bool operator==(Triangle& t1, Triangle& t2)
{
	return t1.getPerimeter() == t2.getPerimeter();
}

bool operator!=(Triangle& t1, Triangle& t2)
{
	return t1.getPerimeter() != t2.getPerimeter();
}
