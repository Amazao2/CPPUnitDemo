#include "TriangleType.h"


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

	/*bool operator>(Triangle& t1, Triangle& t2);
	bool operator<(Triangle& t1, Triangle& t2);
	bool operator==(Triangle& t1, Triangle& t2);
	bool operator!=(Triangle& t1, Triangle& t2);*/


};