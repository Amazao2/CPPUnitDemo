#include <cppunit\TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../Project1/Triangle.h"


class TriangleTestFixture : public CppUnit::TestFixture
{
private:
	std::unique_ptr<Triangle> scal;
	std::unique_ptr<Triangle> isos;
	std::unique_ptr<Triangle> equi;

public:
	void setUp()
	{
		scal = std::make_unique<Triangle>(3, 4, 5);
		isos = std::make_unique<Triangle>(1, 2, 2);
		equi = std::make_unique<Triangle>(5, 5, 5);
	};

	void tearDown()
	{
		/* Unique ptrs deletes themselves */
	};

	void testIdentification()
	{
		CPPUNIT_ASSERT(scal->getType() == TriangleType::Scalene);
		CPPUNIT_ASSERT(isos->getType() == TriangleType::Isosceles);
		CPPUNIT_ASSERT(equi->getType() == TriangleType::Equilateral);
	}

	static CppUnit::Test* suite()
	{
		// Create test suite
		CppUnit::TestSuite* suiteOfTests = new CppUnit::TestSuite("TriangleTest");

		// Add tests
		suiteOfTests->addTest(new CppUnit::TestCaller<TriangleTestFixture>( 
			"testEquality",	&TriangleTestFixture::testIdentification));

		return suiteOfTests;
	}
		
};