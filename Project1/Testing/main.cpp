#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

#include "TriangleTestFixture.h"
#include "SquareTestFixture.h"

int main()
{
	CppUnit::TextUi::TestRunner runner;
	runner.addTest(TriangleTestFixture::suite());
	runner.addTest(SquareTestFixture::suite());
	runner.run();

	cin.get();
	return 0;
}