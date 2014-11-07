#include <cppunit\TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../Project1/Triangle.h"
#include "../Project1/NotTriangleException.cpp"


class TriangleTestFixture : public CppUnit::TestFixture
{
private:
	std::unique_ptr<Triangle> scal;
	std::unique_ptr<Triangle> isos;
	std::unique_ptr<Triangle> equi;

	/* Predicate Testing 
	===================================
	From Triangle Constructor:
	if (side2 + side3 < side1 
		|| side1 + side2 < side3 
		|| side1 + side3 < side2)

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
	void setUp();
	void tearDown();

	void testIdentification();
	void predicateTesting();

	static CppUnit::Test* suite();
		
};