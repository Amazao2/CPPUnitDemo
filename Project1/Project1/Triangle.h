#include "TriangleType.h"

/*
	Requirements for Triangles:

		- triangles must have three sides
		- any two side of a triangle must sum to a length greater than the third side to be
		a valid triangle
		- triangles are of three types:
			- Scalene: all three sides of different lengths
			- Isosceles: two sides are the same length, one is of different length
			- Equilateral: all three sides are the same length
		- triangles must be compared based on their perimeters
*/
class Triangle
{
private:

	int sides[3];
	TriangleType triangleType;

	void setTriangleType();

public:

	Triangle(int side1, int side2, int side3);

	TriangleType getType();
	double getPerimeter();

	int getLongestSide();
	int getMiddleSide();
	int getShortestSide();

	bool operator>(Triangle& other);
	bool operator<(Triangle& other);
	bool operator==(Triangle& other);
	bool operator!=(Triangle& other);
};