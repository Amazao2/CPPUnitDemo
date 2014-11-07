#include <cppunit\TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../Project1/Triangle.h"
#include "../Project1/NotTriangleException.h"


class TriangleTestFixture : public CppUnit::TestFixture
{
private:
	std::unique_ptr<Triangle> scal;
	std::unique_ptr<Triangle> isos;
	std::unique_ptr<Triangle> equi;

	/* Predicate Testing 
	===================================
	From Triangle Constructor:
	if (side1 + side2 <= side3 
		|| side1 + side3 <= side2 
		|| side2 + side3 <= side1)

				         || 
					    /  \  
			           /    \
			          /      \
			         /        \
			        /          \
				   /            \
		          ||		 2 + 3 <= 1
	             /  \  
	            /    \
	           /      \
	          /        \
	         /          \
	        /            \
	  1 + 2 <= 3     1 + 3 <= 2				*/

	// 1 + 2 > 3
	// 1 + 3 > 2
	// 2 + 3 > 1
	// f, f, f => t, f, f / f, t, f / f, f, t
	std::unique_ptr<Triangle> predicate1;

	// 1 + 2 <= 3 && 1 + 3 <= 2
	// f, t, f => should pass, but would fail

	// 1 + 2 <= 3 || 1 + 3 <= 2 && 2 + 3 <= 1
	// f, f, t
	std::unique_ptr<Triangle> predicate2;
	

public:
	void setUp()
	{
		scal = std::make_unique<Triangle>(5, 7, 8);
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

	void predicateTesting()
	{
		// Shouldn't throw an error, unless <= predicate was flipped
		CPPUNIT_ASSERT_NO_THROW(predicate1 = std::make_unique<Triangle>(3, 4, 5));

		// Should throw an error, unless an || was flipped
		CPPUNIT_ASSERT_THROW(predicate2 = std::make_unique<Triangle>(1, 1, 3), NotTriangleException);
	}

	static CppUnit::Test* suite()
	{
		// Create test suite
		CppUnit::TestSuite* suiteOfTests = new CppUnit::TestSuite("TriangleTest");

		// Add tests
		suiteOfTests->addTest(new CppUnit::TestCaller<TriangleTestFixture>( 
			"testEquality",	&TriangleTestFixture::testIdentification));

		suiteOfTests->addTest(new CppUnit::TestCaller<TriangleTestFixture>(
			"predicateTesting", &TriangleTestFixture::predicateTesting));

		return suiteOfTests;
	}
		
};