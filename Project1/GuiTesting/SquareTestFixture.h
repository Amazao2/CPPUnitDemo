#include <cppunit\TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../Project1/Square.h"


class SquareTestFixture : public CppUnit::TestFixture
{
private:
	std::unique_ptr<Square> square;
	int sideLength;

public:
	void setUp();
	void tearDown();

	void testSideLength();
	void testPerimeter();

	static CppUnit::Test* suite();
};