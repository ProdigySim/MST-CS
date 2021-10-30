//////////////////////////////////////////////////////////////////////
/// @file test_list.cpp
/// @author Michael Busby CS153 1B
/// @brief Definitions of member functions for Test_list class
////////////////////////////////////////////////////////////////////// 
#include <iostream>

#include "test_list.h"
CPPUNIT_TEST_SUITE_REGISTRATION( Test_list );

#define VERBOSE

#define TEST_ITERATIONS 10000

//////////////////////////////////////////////////////////////////////
/// @fn Test_list::test_push_front()
/// @brief This function tests the List push_front function
////////////////////////////////////////////////////////////////////// 

void Test_list::test_push_front()
{
	List<int> b;
	
	#ifdef VERBOSE
	std::cout << std::endl << "test_push_front: Constructor check" << std::endl;
	#endif
	
	CPPUNIT_ASSERT(b.size() == 0);
	CPPUNIT_ASSERT(b.empty());
	
	#ifdef VERBOSE
	std::cout << "test_push_front: Push one item into the list" << std::endl;
	#endif
	
	b.push_front(0);
	CPPUNIT_ASSERT(b.front()== 0);
	CPPUNIT_ASSERT(b.size() == 1);
		
	#ifdef VERBOSE
	std::cout << "test_push_front: Push multiple items into the list" << std::endl;
	#endif
	
	for (int i = b.size(); i < TEST_ITERATIONS; i++)
	{
		b.push_front( i );
		CPPUNIT_ASSERT( b.size() == i+1);
		CPPUNIT_ASSERT(b.front() == i);
	}
	
	/* Skipping bad_alloc check this time */
}

//////////////////////////////////////////////////////////////////////
/// @fn Test_list::test_push_back()
/// @brief This function tests the List push_back function
////////////////////////////////////////////////////////////////////// 

void Test_list::test_push_back()
{
	List<int> b;
	
	#ifdef VERBOSE
	std::cout << std::endl << "test_push_back: Constructor check" << std::endl;
	#endif
	
	CPPUNIT_ASSERT(b.size() == 0);
	CPPUNIT_ASSERT(b.empty());
	
	#ifdef VERBOSE
	std::cout << "test_push_back: Push one item into the list" << std::endl;
	#endif
	
	b.push_back(0);
	CPPUNIT_ASSERT(b.back()== 0);
	CPPUNIT_ASSERT(b.size() == 1);
		
	#ifdef VERBOSE
	std::cout << "test_push_back: Push multiple items into the list" << std::endl;
	#endif
	
	for (int i = b.size(); i < TEST_ITERATIONS; i++)
	{
		b.push_back( i );
		CPPUNIT_ASSERT( b.size() == i+1);
		CPPUNIT_ASSERT(b.back() == i);
	}
	
	/* Skipping bad_alloc check this time */
}

//////////////////////////////////////////////////////////////////////
/// @fn Test_list::test_pop_front()
/// @brief This function tests the List pop_front function
////////////////////////////////////////////////////////////////////// 

void Test_list::test_pop_front()
{
	List<int> b;
	
	#ifdef VERBOSE
	std::cout << std::endl << "test_pop_front: Constructor check" << std::endl;
	#endif
	
	CPPUNIT_ASSERT(b.size() == 0);
	CPPUNIT_ASSERT(b.empty());
	
	#ifdef VERBOSE
	std::cout << "test_pop_front: Push and pop one item in the list" << std::endl;
	#endif
	
	b.push_front(0);
	b.pop_front();
	CPPUNIT_ASSERT(b.size() == 0);
	CPPUNIT_ASSERT(b.empty());
	
	#ifdef VERBOSE
	std::cout << "test_pop_front: Pop front multiple items from the list" << std::endl;
	#endif
	
	for (int i = b.size(); i < TEST_ITERATIONS; i++)
	{
		b.push_front( i );
	}
	for (int i = b.size(); i > 0; i--)
	{
		CPPUNIT_ASSERT(b.front() == i-1);
		CPPUNIT_ASSERT(b.size() == i);
		b.pop_front();
	}
	CPPUNIT_ASSERT(b.size() == 0);
	CPPUNIT_ASSERT(b.empty());
	
	#ifdef VERBOSE
	std::cout << "test_pop_front: Test pop front error handling" << std::endl;
	#endif
	
	try
	{
		b.pop_front(); 
		CPPUNIT_ASSERT( false );  
	}
	catch (const exception &e )
	{ 
		CPPUNIT_ASSERT(b.size() == 0);
		CPPUNIT_ASSERT(b.empty());
		CPPUNIT_ASSERT(e.get_message() == std::string ("List is empty, no elements to remove from the list."));
	}	
}

//////////////////////////////////////////////////////////////////////
/// @fn Test_list::test_pop_back()
/// @brief This function tests the List pop_back function
////////////////////////////////////////////////////////////////////// 

void Test_list::test_pop_back()
{
	List<int> b;
	
	#ifdef VERBOSE
	std::cout << std::endl << "test_pop_back: Constructor check" << std::endl;
	#endif
	
	CPPUNIT_ASSERT(b.size() == 0);
	CPPUNIT_ASSERT(b.empty());
	
	#ifdef VERBOSE
	std::cout << "test_pop_back: Push and pop one item in the list" << std::endl;
	#endif
	
	b.push_back(0);
	b.pop_back();
	CPPUNIT_ASSERT(b.size() == 0);
	CPPUNIT_ASSERT(b.empty());
	
	#ifdef VERBOSE
	std::cout << "test_pop_back: Pop back multiple items from the list" << std::endl;
	#endif
	
	for (int i = b.size(); i < TEST_ITERATIONS; i++)
	{
		b.push_back( i );
	}
	for (int i = b.size(); i > 0; i--)
	{
		CPPUNIT_ASSERT(b.back() == i-1);
		CPPUNIT_ASSERT(b.size() == i);
		b.pop_back();
	}
	CPPUNIT_ASSERT(b.size() == 0);
	CPPUNIT_ASSERT(b.empty());
	
	#ifdef VERBOSE
	std::cout << "test_pop_back: Test pop back error handling" << std::endl;
	#endif
	
	try
	{
		b.pop_back(); 
		CPPUNIT_ASSERT( false );  
	}
	catch (const exception &e )
	{ 
		CPPUNIT_ASSERT(b.size() == 0);
		CPPUNIT_ASSERT(b.empty());
		CPPUNIT_ASSERT(e.get_message() == std::string ("List is empty, no elements to remove from the list."));
	}
	
}


//////////////////////////////////////////////////////////////////////
/// @fn Test_list::test_front()
/// @brief This function tests the List front function
////////////////////////////////////////////////////////////////////// 

void Test_list::test_front()
{
	List<int> b;
	
	#ifdef VERBOSE
	std::cout << std::endl << "test_front: Constructor check" << std::endl;
	#endif
	
	CPPUNIT_ASSERT(b.size() == 0);
	CPPUNIT_ASSERT(b.empty());
	
	#ifdef VERBOSE
	std::cout << "test_front: Add an element to the list and acccess it with front" << std::endl;
	#endif
	
	b.push_front(0);
	CPPUNIT_ASSERT(b.front() == 0);
	
	#ifdef VERBOSE
	std::cout << "test_front: Add multiple elements to the list and acccess them with front" << std::endl;
	#endif
	
	for (int i = b.size(); i < TEST_ITERATIONS; i++)
	{
		b.push_front( i );
		CPPUNIT_ASSERT(b.front() == i);
	}
	CPPUNIT_ASSERT(b.size() == TEST_ITERATIONS);
	
	#ifdef VERBOSE
	std::cout << "test_remove: Test front error handling (EISNULL)" << std::endl;
	#endif	
	
	b.clear();
	try
	{
		(void)b.front();
		CPPUNIT_ASSERT(false);
	}
	catch (const exception &e)
	{
		CPPUNIT_ASSERT(b.size() == 0);
		CPPUNIT_ASSERT(b.empty());
		CPPUNIT_ASSERT(e.get_message() == std::string ("List is empty, front element is null"));
	}
}


//////////////////////////////////////////////////////////////////////
/// @fn Test_list::test_back()
/// @brief This function tests the List back function
////////////////////////////////////////////////////////////////////// 

void Test_list::test_back()
{
	List<int> b;
	
	#ifdef VERBOSE
	std::cout << std::endl << "test_back: Constructor check" << std::endl;
	#endif
	
	CPPUNIT_ASSERT(b.size() == 0);
	CPPUNIT_ASSERT(b.empty());
	
	#ifdef VERBOSE
	std::cout << "test_back: Add an element to the list and acccess it with back" << std::endl;
	#endif
	
	b.push_back(0);
	CPPUNIT_ASSERT(b.back() == 0);
	
	#ifdef VERBOSE
	std::cout << "test_back: Add multiple elements to the list and acccess them with back" << std::endl;
	#endif
	
	for (int i = b.size(); i < TEST_ITERATIONS; i++)
	{
		b.push_back( i );
		CPPUNIT_ASSERT(b.back() == i);
	}
	CPPUNIT_ASSERT(b.size() == TEST_ITERATIONS);
	
	#ifdef VERBOSE
	std::cout << "test_remove: Test back error handling (EISNULL)" << std::endl;
	#endif	
	
	b.clear();
	try
	{
		(void)b.back();
		CPPUNIT_ASSERT(false);
	}
	catch (const exception &e)
	{
		CPPUNIT_ASSERT(b.size() == 0);
		CPPUNIT_ASSERT(b.empty());
		CPPUNIT_ASSERT(e.get_message() == std::string ("List is empty, back element is null"));
	}
}

//////////////////////////////////////////////////////////////////////
/// @fn Test_list::test_remove()
/// @brief This function tests the List remove function
////////////////////////////////////////////////////////////////////// 

void Test_list::test_remove()
{
	List<int> b;
	
	#ifdef VERBOSE
	std::cout << std::endl << "test_remove: Constructor check" << std::endl;
	#endif
	
	CPPUNIT_ASSERT(b.size() == 0);
	CPPUNIT_ASSERT(b.empty());
	
	#ifdef VERBOSE
	std::cout << "test_remove: Add elements to the list and remove one" << std::endl;
	#endif
	
	for (int i = b.size(); i < TEST_ITERATIONS; i++)
	{
		b.push_front( i );
	}
	CPPUNIT_ASSERT(b.size() == TEST_ITERATIONS);
	CPPUNIT_ASSERT(b.front() == TEST_ITERATIONS-1);
	try{	b.remove(TEST_ITERATIONS-1); }
	catch ( const exception &e) { std::cout << "Exception: " << e.get_message() << std::endl; }
	CPPUNIT_ASSERT(b.size() == TEST_ITERATIONS-1);
	CPPUNIT_ASSERT(b.front() == TEST_ITERATIONS-2);
	
	#ifdef VERBOSE
	std::cout << "test_remove: Add similar elements to the list and remove them" << std::endl;
	#endif
	
	b.push_front(TEST_ITERATIONS -5);
	CPPUNIT_ASSERT(b.size() == TEST_ITERATIONS);
	CPPUNIT_ASSERT(b.front() == TEST_ITERATIONS -5);
	b.remove(TEST_ITERATIONS -5);
	CPPUNIT_ASSERT(b.size() == TEST_ITERATIONS-2);
	CPPUNIT_ASSERT(b.front() == TEST_ITERATIONS-2);
	
	#ifdef VERBOSE
	std::cout << "test_remove: Test remove error handling (ENOENT)" << std::endl;
	#endif	
	
	try
	{
		b.remove(TEST_ITERATIONS + 10);
		CPPUNIT_ASSERT(false);
	}
	catch (const exception &e)
	{
		CPPUNIT_ASSERT(b.size() == TEST_ITERATIONS-2);
		CPPUNIT_ASSERT(!b.empty());
		CPPUNIT_ASSERT(e.get_message() == std::string("No such element found in the list."));
	}
	
	#ifdef VERBOSE
	std::cout << "test_remove: Test remove error handling (Empty list)" << std::endl;
	#endif	
	b.clear();
	try
	{
		b.remove(4);
		CPPUNIT_ASSERT(false);
	}
	catch (const exception &e)
	{
		CPPUNIT_ASSERT(b.size() == 0);
		CPPUNIT_ASSERT(b.empty());
		CPPUNIT_ASSERT(e.get_message() == std::string("No such element found in the list."));
	}
}

//////////////////////////////////////////////////////////////////////
/// @fn Test_list::test_clear()
/// @brief This function tests the List clear function
////////////////////////////////////////////////////////////////////// 

void Test_list::test_clear()
{
	List<int> b;
	
	#ifdef VERBOSE
	std::cout << std::endl << "test_clear: Constructor check" << std::endl;
	#endif
	
	CPPUNIT_ASSERT(b.size() == 0);
	CPPUNIT_ASSERT(b.empty());
	
	#ifdef VERBOSE
	std::cout << "test_clear: Add elements to the list and clear them" << std::endl;
	#endif
	
	for (int i = b.size(); i < TEST_ITERATIONS; i++)
	{
		b.push_front( i );
	}
	CPPUNIT_ASSERT(b.size() == TEST_ITERATIONS);
	b.clear();
	CPPUNIT_ASSERT(b.size() == 0);
	CPPUNIT_ASSERT(b.empty());
}
