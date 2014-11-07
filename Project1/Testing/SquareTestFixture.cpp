#include "SquareTestFixture.h"


void SquareTestFixture::setUp()
{
	sideLength = 10;
	square = std::make_unique<Square>(sideLength);
}

void SquareTestFixture::tearDown()
{
	// unique ptrs delete themselves
}

void SquareTestFixture::testSideLength()
{
	CPPUNIT_ASSERT(square->getSideLength() == sideLength);
}

void SquareTestFixture::testPerimeter()
{
	CPPUNIT_ASSERT(square->getPerimeter() == sideLength * 4);
}

CppUnit::Test* SquareTestFixture::suite()
{
	// Create test suite
	CppUnit::TestSuite* suiteOfTests = new CppUnit::TestSuite("TriangleTest");

	// Add tests
	suiteOfTests->addTest(new CppUnit::TestCaller<SquareTestFixture>(
		"testSideLength", &SquareTestFixture::testSideLength));

	suiteOfTests->addTest(new CppUnit::TestCaller<SquareTestFixture>(
		"testPerimeter", &SquareTestFixture::testPerimeter));

	return suiteOfTests;
}