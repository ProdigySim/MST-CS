//////////////////////////////////////////////////////////////////////
/// @file test_list.cpp
/// @author Michael Busby CS153 1B
/// @brief Declarations for Test_list class
////////////////////////////////////////////////////////////////////// 
#ifndef TEST_LIST_H
#define TEST_LIST_H

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/config/SourcePrefix.h>
#include "list.h"

//////////////////////////////////////////////////////////////////////
/// @class Test_list
/// @brief This class uses CPPUNIT to test List class functions
////////////////////////////////////////////////////////////////////// 

//////////////////////////////////////////////////////////////////////
/// @fn Test_list::test_push_front()
/// @brief This function tests the List push_front function
////////////////////////////////////////////////////////////////////// 

//////////////////////////////////////////////////////////////////////
/// @fn Test_list::test_push_back()
/// @brief This function tests the List push_back function
////////////////////////////////////////////////////////////////////// 

//////////////////////////////////////////////////////////////////////
/// @fn Test_list::test_pop_front()
/// @brief This function tests the List pop_front function
////////////////////////////////////////////////////////////////////// 

//////////////////////////////////////////////////////////////////////
/// @fn Test_list::test_pop_back()
/// @brief This function tests the List pop_back function
////////////////////////////////////////////////////////////////////// 

//////////////////////////////////////////////////////////////////////
/// @fn Test_list::test_front()
/// @brief This function tests the List front function
////////////////////////////////////////////////////////////////////// 

//////////////////////////////////////////////////////////////////////
/// @fn Test_list::test_back()
/// @brief This function tests the List back function
////////////////////////////////////////////////////////////////////// 

//////////////////////////////////////////////////////////////////////
/// @fn Test_list::test_remove()
/// @brief This function tests the List remove function
////////////////////////////////////////////////////////////////////// 

//////////////////////////////////////////////////////////////////////
/// @fn Test_list::test_clear()
/// @brief This function tests the List clear function
////////////////////////////////////////////////////////////////////// 

class Test_list : public CPPUNIT_NS::TestFixture
{
  private:
    CPPUNIT_TEST_SUITE( Test_list );
      CPPUNIT_TEST( test_push_front );
      CPPUNIT_TEST( test_push_back );
      CPPUNIT_TEST( test_pop_front );
      CPPUNIT_TEST( test_pop_back );
      CPPUNIT_TEST( test_front );
      CPPUNIT_TEST( test_back );
      CPPUNIT_TEST( test_remove );
      CPPUNIT_TEST( test_clear );
    CPPUNIT_TEST_SUITE_END();

  protected:
    void test_push_front();
    void test_push_back();
    void test_pop_front();
    void test_pop_back();
    void test_front();
    void test_back();
    void test_remove();
    void test_clear();
};

#endif