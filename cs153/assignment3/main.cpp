//////////////////////////////////////////////////////////////////////
/// @file main.cpp
/// @author Michael Busby CS153 1B
/// @brief Main function for testing bag class
//////////////////////////////////////////////////////////////////////

#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

int main()
{
    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry & registry =
        CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );

    return runner.run( "", false );
} 

