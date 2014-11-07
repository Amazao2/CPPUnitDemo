#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

#include "TriangleTestFixture.h"

int main()
{
	CppUnit::TextUi::TestRunner runner;
	runner.addTest(TriangleTestFixture::suite());
	runner.run();

	cin.get();
	return 0;

	Triangle t(1, 2, 3), p(3, 4, 5);

	return t < p;
}