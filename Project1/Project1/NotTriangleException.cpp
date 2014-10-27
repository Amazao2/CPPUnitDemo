#include <exception>

using namespace std;

class NotTriangleException : public exception
{
	virtual const char* what() const throw()
	{
		return "This cannot be a triangle!";
	}
};