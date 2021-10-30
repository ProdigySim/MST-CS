//////////////////////////////////////////////////////////////////////
/// @file test_bag.cpp
/// @author Michael Busby CS153 1B
/// @brief Definitions of member functions for Test_bag class
////////////////////////////////////////////////////////////////////// 
#include <iostream>

#include "test_bag.h"
CPPUNIT_TEST_SUITE_REGISTRATION( Test_bag );

//////////////////////////////////////////////////////////////////////
/// @fn Test_bag::test_push_back()
/// @brief tests Bag push_back function
////////////////////////////////////////////////////////////////////// 
void Test_bag::test_push_back()
{
    Bag<int> b;
    
    std::cout << std::endl << "test_push_back: Constructor check" << std::endl;
    CPPUNIT_ASSERT(b.size() == 0);
    CPPUNIT_ASSERT(b.max_size() == 20);
    
    std::cout << "test_push_back: Push one item into the bag" << std::endl;
    b.push_back(23);
    CPPUNIT_ASSERT(b[0] == 23);
    CPPUNIT_ASSERT(b.size() == 1);
    CPPUNIT_ASSERT(b.max_size() == 20);
    
    std::cout << "test_push_back: Push multiple items into the bag" << std::endl;
    for (int i = b.size(); i < b.max_size(); i++)
    {
        b.push_back( i );
        CPPUNIT_ASSERT( b[i] == i );
        CPPUNIT_ASSERT( b.size() == i+1);
        CPPUNIT_ASSERT(b.max_size() == 20);
    }
    
    std::cout << "test_push_back: Test push back error handling" << std::endl;
    try{ b.push_back( 200 ); }
    catch ( exception &e ){ return; }
    CPPUNIT_ASSERT( false );        
}

//////////////////////////////////////////////////////////////////////
/// @fn Test_bag::test_pop_back()
/// @brief tests Bag pop_back function
////////////////////////////////////////////////////////////////////// 
void Test_bag::test_pop_back()
{
    Bag<int> b;
    
    std::cout << std::endl << "test_pop_back: Constructor check" << std::endl;
    CPPUNIT_ASSERT(b.size() == 0);
    CPPUNIT_ASSERT(b.max_size() == 20);
    
    std::cout << "test_pop_back: Push and pop one item in the bag" << std::endl;
    b.push_back(23);
    b.pop_back();
    CPPUNIT_ASSERT(b.size() == 0);
    CPPUNIT_ASSERT(b.max_size() == 20);
    
    std::cout << "test_pop_back: pop back multiple items from the bag" << std::endl;
    for (int i = b.size(); i < b.max_size(); i++)
    {
        b.push_back( i );
    }
    for (int i = b.size(); i > 0; i--)
    {
        b.pop_back();
        CPPUNIT_ASSERT(b.size() == i-1);
        CPPUNIT_ASSERT(b.max_size() == 20);
    }
    
    std::cout << "test_pop_back: Test pop back error handling" << std::endl;
    try{ b.pop_back(); }
    catch ( exception &e ){ return; }
    CPPUNIT_ASSERT( false );   
    
}

//////////////////////////////////////////////////////////////////////
/// @fn Test_bag::test_bracket()
/// @brief tests Bag bracket operator
////////////////////////////////////////////////////////////////////// 
void Test_bag::test_bracket()
{
    Bag<int> b;
    
    std::cout << std::endl << "test_bracket: Constructor check" << std::endl;
    CPPUNIT_ASSERT(b.size() == 0);
    CPPUNIT_ASSERT(b.max_size() == 20);
    
    std::cout << "test_bracket: Read one item with brackets" << std::endl;
    b.push_back(23);
    CPPUNIT_ASSERT( b[0] == 23 );    
    CPPUNIT_ASSERT(b.max_size() == 20);
    
    std::cout << "test_bracket: Read multiple items with brackets" << std::endl;
    for (int i = b.size(); i < b.max_size(); i++)
    {
        b.push_back( i );
        CPPUNIT_ASSERT( b[i] == i );
        CPPUNIT_ASSERT(b.max_size() == 20);
    }
    
    
    std::cout << "test_bracket: Test bracket error handling" << std::endl;
    try{ b[20]; }
    catch ( exception &e ){ return; }
    CPPUNIT_ASSERT( false );   
}

//////////////////////////////////////////////////////////////////////
/// @fn Test_bag::test_clear()
/// @brief tests Bag clear function
////////////////////////////////////////////////////////////////////// 
void Test_bag::test_clear()
{
    Bag<int> b;
    
    std::cout << std::endl << "test_clear: Constructor check" << std::endl;
    CPPUNIT_ASSERT(b.size() == 0);
    CPPUNIT_ASSERT(b.max_size() == 20);
    
    std::cout << "test_clear: Add elements to the bag and clear them" << std::endl;
    for (int i = b.size(); i < b.max_size(); i++)
    {
        b.push_back( i );
    }
    CPPUNIT_ASSERT(b.max_size() == 20);
    CPPUNIT_ASSERT(b.size() == b.max_size());
    b.clear();
    CPPUNIT_ASSERT(b.size() == 0);
    CPPUNIT_ASSERT(b.max_size() == 20);
}
