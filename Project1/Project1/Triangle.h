#include <string>;
#include "TriangleType.h";

using namespace std;

class Triangle
{

private:

	int sides[3];
	TriangleType triangleType;

	void setTriangleType()
	{
		int longest;
		int middle;
		int shortest;
		//TODO
	}


public:

	// constructor - initializes the sides
	Triangle(int side1, int side2, int side3)
	{
		// initialize sides
		sides[0] = side1;
		sides[1] = side2;
		sides[2] = side3;

		// TODO: set triangle type

	}

	// what type is this triangle?
	TriangleType getType() {
		triangleType;
	}

	// what is the area of the triangle?
	double getPerimeter()
	{
		return 0.0;
	}



	bool operator>(Triangle& t)
	{
		return this->getPerimeter() > t.getPerimeter();
	}

	bool operator<(Triangle& t)
	{
		return this->getPerimeter() < t.getPerimeter();
	}
	
	bool operator==(Triangle& t)
	{
		return this->getPerimeter() == t.getPerimeter();
	}

	bool operator!=(Triangle& t)
	{
		return this->getPerimeter() != t.getPerimeter();
	}
};