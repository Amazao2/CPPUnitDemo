#include <exception>

using namespace std;

class NotASquareException : public exception
{
	virtual const char* what() const throw()
	{
		return "This cannot be a square!";
	}
};