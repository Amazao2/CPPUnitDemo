#include "TriangleTestFixture.h"

void TriangleTestFixture::setUp()
{
	scal = std::make_unique<Triangle>(5, 7, 8);
	isos = std::make_unique<Triangle>(1, 2, 2);
	equi = std::make_unique<Triangle>(5, 5, 5);
};

void TriangleTestFixture::tearDown()
{
	/* Unique ptrs deletes themselves */
};

void TriangleTestFixture::testIdentification()
{
	CPPUNIT_ASSERT(scal->getType() == TriangleType::Scalene);
	CPPUNIT_ASSERT(isos->getType() == TriangleType::Isosceles);
	CPPUNIT_ASSERT(equi->getType() == TriangleType::Equilateral);
}

void TriangleTestFixture::predicateTesting()
{
	// Shouldn't throw an error, unless <= predicate was flipped
	CPPUNIT_ASSERT_NO_THROW(predicate1 = std::make_unique<Triangle>(3, 4, 5));

	// Should throw an error, unless an || was flipped
	CPPUNIT_ASSERT_THROW(predicate2 = std::make_unique<Triangle>(1, 1, 3), NotTriangleException);
}

CppUnit::Test* TriangleTestFixture::suite()
{
	// Create test suite
	CppUnit::TestSuite* suiteOfTests = new CppUnit::TestSuite("TriangleTest");

	// Add tests
	suiteOfTests->addTest(new CppUnit::TestCaller<TriangleTestFixture>(
		"testEquality", &TriangleTestFixture::testIdentification));

	suiteOfTests->addTest(new CppUnit::TestCaller<TriangleTestFixture>(
		"predicateTesting", &TriangleTestFixture::predicateTesting));

	return suiteOfTests;
}