//////////////////////////////////////////////////////////////////////
/// @file test_Stack.cpp
/// @author Michael Busby CS153 1B
/// @brief Definitions of member functions for Test_stack class
////////////////////////////////////////////////////////////////////// 
#include <iostream>
#include <string>

#include "test_stack.h"
CPPUNIT_TEST_SUITE_REGISTRATION( Test_stack );

#define VERBOSE

#define TEST_ITERATIONS 10000

using std::cout;
using std::endl;
using std::string;

//////////////////////////////////////////////////////////////////////
/// @fn Test_stack::test_push()
/// @brief This function tests the Stack push function
////////////////////////////////////////////////////////////////////// 

void Test_stack::test_push()
{
	Stack<int> b;
	
	#ifdef VERBOSE
	cout << endl << "test_push: Constructor check" << endl;
	#endif
	
	CPPUNIT_ASSERT(b.size() == 0);
	CPPUNIT_ASSERT(b.empty());
	
	#ifdef VERBOSE
	cout << "test_push: Push one item into the Stack" << endl;
	#endif
	
	b.push(0);
	CPPUNIT_ASSERT(b.top()== 0);
	CPPUNIT_ASSERT(b.size() == 1);
		
	#ifdef VERBOSE
	cout << "test_push: Push multiple items into the Stack" << endl;
	#endif
	
	for (unsigned int i = b.size(); i < TEST_ITERATIONS; i++)
	{
		b.push( i );
		CPPUNIT_ASSERT( b.size() == i+1);
		CPPUNIT_ASSERT(b.top() == i);
	}
	
	/* Skipping bad_alloc check this time */
}

//////////////////////////////////////////////////////////////////////
/// @fn Test_stack::test_pop()
/// @brief This function tests the Stack pop function
////////////////////////////////////////////////////////////////////// 

void Test_stack::test_pop()
{
	Stack<int> b;
	
	#ifdef VERBOSE
	cout << endl << "test_pop: Constructor check" << endl;
	#endif
	
	CPPUNIT_ASSERT(b.size() == 0);
	CPPUNIT_ASSERT(b.empty());
	
	#ifdef VERBOSE
	cout << "test_pop: Push and pop one item in the Stack" << endl;
	#endif
	
	b.push(0);
	b.pop();
	CPPUNIT_ASSERT(b.size() == 0);
	CPPUNIT_ASSERT(b.empty());
	
	#ifdef VERBOSE
	cout << "test_pop: Pop front multiple items from the Stack" << endl;
	#endif
	
	for (unsigned int i = b.size(); i < TEST_ITERATIONS; i++)
	{
		b.push( i );
	}
	for (unsigned int i = b.size(); i; i--)
	{
		CPPUNIT_ASSERT(b.top() == i-1);
		CPPUNIT_ASSERT(b.size() == i);
		b.pop();
	}
	CPPUNIT_ASSERT(b.size() == 0);
	CPPUNIT_ASSERT(b.empty());
	
	#ifdef VERBOSE
	cout << "test_pop: Test pop front error handling" << endl;
	#endif
	
	try
	{
		b.pop(); 
		CPPUNIT_ASSERT( false );  
	}
	catch (const exception &e )
	{ 
		CPPUNIT_ASSERT(b.size() == 0);
		CPPUNIT_ASSERT(b.empty());
		CPPUNIT_ASSERT(e.get_message() == string ("Container is empty, no elements to remove"));
	}
	
}

//////////////////////////////////////////////////////////////////////
/// @fn Test_stack::test_top()
/// @brief This function tests the Stack top function
////////////////////////////////////////////////////////////////////// 

void Test_stack::test_top()
{
	Stack<int> b;
	
	#ifdef VERBOSE
	cout << endl << "test_front: Constructor check" << endl;
	#endif
	
	CPPUNIT_ASSERT(b.size() == 0);
	CPPUNIT_ASSERT(b.empty());
	
	#ifdef VERBOSE
	cout << "test_front: Add an element to the Stack and acccess it with front" << endl;
	#endif
	
	b.push(0);
	CPPUNIT_ASSERT(b.top() == 0);
	
	#ifdef VERBOSE
	cout << "test_front: Add multiple elements to the Stack and acccess them with front" << endl;
	#endif
	
	for (unsigned int i = b.size(); i < TEST_ITERATIONS; i++)
	{
		b.push( i );
		CPPUNIT_ASSERT(b.top() == i);
	}
	CPPUNIT_ASSERT(b.size() == TEST_ITERATIONS);
	
	#ifdef VERBOSE
	cout << "test_front: Test front error handling (EISNULL)" << endl;
	#endif	
	
	for(unsigned int i = b.size(); i; i--)
	{
		b.pop();
	}
	try
	{
		(void)b.top();
		CPPUNIT_ASSERT(false);
	}
	catch (const exception &e)
	{
		CPPUNIT_ASSERT(b.size() == 0);
		CPPUNIT_ASSERT(b.empty());
		CPPUNIT_ASSERT(e.get_message() == string ("Container is empty, requested element does not exist"));
	}
}
