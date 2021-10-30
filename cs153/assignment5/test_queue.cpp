//////////////////////////////////////////////////////////////////////
/// @file test_Queue.cpp
/// @author Michael Busby CS153 1B
/// @brief Definitions of member functions for Test_queue class
////////////////////////////////////////////////////////////////////// 
#include <iostream>
#include <string>

#include "test_queue.h"
CPPUNIT_TEST_SUITE_REGISTRATION( Test_queue );

#define VERBOSE

#define TEST_ITERATIONS 10000

using std::cout;
using std::endl;
using std::string;

void Test_queue::test_push()
{
	Queue<int> b;
	
	#ifdef VERBOSE
	cout << endl << "test_push: Constructor check" << endl;
	#endif
	
	CPPUNIT_ASSERT(b.size() == 0);
	CPPUNIT_ASSERT(b.empty());
	
	#ifdef VERBOSE
	cout << "test_push: Push one item into the Queue" << endl;
	#endif
	
	b.push(0);
	CPPUNIT_ASSERT(b.back()== 0);
	CPPUNIT_ASSERT(b.size() == 1);
		
	#ifdef VERBOSE
	cout << "test_push: Push multiple items into the Queue" << endl;
	#endif
	
	for (unsigned int i = b.size(); i < TEST_ITERATIONS; i++)
	{
		b.push( i );
		CPPUNIT_ASSERT( b.size() == i+1);
		CPPUNIT_ASSERT(b.back() == i);
	}
	
	/* Skipping bad_alloc check this time */
}

//////////////////////////////////////////////////////////////////////
/// @fn Test_queue::test_pop()
/// @brief This function tests the Queue pop function
////////////////////////////////////////////////////////////////////// 

void Test_queue::test_pop()
{
	Queue<int> b;
	
	#ifdef VERBOSE
	cout << endl << "test_pop: Constructor check" << endl;
	#endif
	
	CPPUNIT_ASSERT(b.size() == 0);
	CPPUNIT_ASSERT(b.empty());
	
	#ifdef VERBOSE
	cout << "test_pop: Push and pop one item in the Queue" << endl;
	#endif
	
	b.push(0);
	b.pop();
	CPPUNIT_ASSERT(b.size() == 0);
	CPPUNIT_ASSERT(b.empty());
	
	#ifdef VERBOSE
	cout << "test_pop: Pop front multiple items from the Queue" << endl;
	#endif
	for (unsigned int i = 0; i < TEST_ITERATIONS; i++)
	{
		b.push( i );
	}
	for (unsigned int i = b.size(); i ; i--)
	{
		CPPUNIT_ASSERT(b.front() == TEST_ITERATIONS-i);
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
/// @fn Test_queue::test_front()
/// @brief This function tests the Queue front function
////////////////////////////////////////////////////////////////////// 

void Test_queue::test_front()
{
	Queue<int> b;
	
	#ifdef VERBOSE
	cout << endl << "test_front: Constructor check" << endl;
	#endif
	
	CPPUNIT_ASSERT(b.size() == 0);
	CPPUNIT_ASSERT(b.empty());
	
	#ifdef VERBOSE
	cout << "test_front: Add an element to the Queue and acccess it with front" << endl;
	#endif
	
	b.push(0);
	CPPUNIT_ASSERT(b.back() == 0);
	
	#ifdef VERBOSE
	cout << "test_front: Add multiple elements to the Queue and acccess them with front" << endl;
	#endif
	
	for (unsigned int i = b.size(); i < TEST_ITERATIONS; i++)
	{
		b.push( i );
		CPPUNIT_ASSERT(b.front() == 0);
	}
	CPPUNIT_ASSERT(b.size() == TEST_ITERATIONS);
	
	#ifdef VERBOSE
	cout << "test_front: Test front error handling (EISNULL)" << endl;
	#endif	
	
	for (unsigned int i = b.size(); i; i--)
	{
		b.pop();
	}
	try
	{
		(void)b.front();
		CPPUNIT_ASSERT(false);
	}
	
	catch (const exception &e)
	{
		CPPUNIT_ASSERT(b.size() == 0);
		CPPUNIT_ASSERT(b.empty());
		CPPUNIT_ASSERT(e.get_message() == string ("Container is empty, requested element does not exist"));
	}
}


//////////////////////////////////////////////////////////////////////
/// @fn Test_queue::test_back()
/// @brief This function tests the Queue back function
////////////////////////////////////////////////////////////////////// 

void Test_queue::test_back()
{
	Queue<int> b;
	
	#ifdef VERBOSE
	cout << endl << "test_back: Constructor check" << endl;
	#endif
	
	CPPUNIT_ASSERT(b.size() == 0);
	CPPUNIT_ASSERT(b.empty());
	
	#ifdef VERBOSE
	cout << "test_back: Add an element to the Queue and acccess it with back" << endl;
	#endif
	
	b.push(0);
	CPPUNIT_ASSERT(b.back() == 0);
	
	#ifdef VERBOSE
	cout << "test_back: Add multiple elements to the Queue and acccess them with back" << endl;
	#endif
	
	for (unsigned int i = b.size(); i < TEST_ITERATIONS; i++)
	{
		b.push( i );
		CPPUNIT_ASSERT(b.back() == i);
	}
	CPPUNIT_ASSERT(b.size() == TEST_ITERATIONS);
	
	#ifdef VERBOSE
	cout << "test_back: Test back error handling (EISNULL)" << endl;
	#endif	
	
	for (unsigned int i = b.size(); i; i--)
	{
		b.pop();
	}
	try
	{
		(void)b.back();
		CPPUNIT_ASSERT(false);
	}
	catch (const exception &e)
	{
		CPPUNIT_ASSERT(b.size() == 0);
		CPPUNIT_ASSERT(b.empty());
		CPPUNIT_ASSERT(e.get_message() == string ("Container is empty, requested element does not exist"));
	}
}
