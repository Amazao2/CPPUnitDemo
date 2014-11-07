

class Square
{

private:

	int sideLength;

public:

	Square(int sideLength);

	int getPerimeter();

	int getSideLength();

	bool operator>(Square& other);
	bool operator<(Square& other);
	bool operator==(Square& other);
	bool operator!=(Square& other);
};