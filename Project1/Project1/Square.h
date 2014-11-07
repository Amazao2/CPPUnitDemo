
/*
	Requirements for Squares:

		- squares must be initialized with a single side length
		- side length must be a positive integer
		- squares have a perimeter
		- squares are compared based on their perimeter
*/
class Square
{

private:

	const int sideLength;

public:

	Square(int sideLength);

	int getPerimeter();

	int getSideLength();

	bool operator>(Square& other);
	bool operator<(Square& other);
	bool operator==(Square& other);
	bool operator!=(Square& other);
};