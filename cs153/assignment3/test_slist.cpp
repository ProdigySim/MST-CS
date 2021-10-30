//////////////////////////////////////////////////////////////////////
/// @file test_slist.cpp
/// @author Michael Busby CS153 1B
/// @brief Definitions of member functions for Test_slist class
////////////////////////////////////////////////////////////////////// 
#include <iostream>

#include "test_slist.h"
CPPUNIT_TEST_SUITE_REGISTRATION( Test_slist );

#define VERBOSE

//////////////////////////////////////////////////////////////////////
/// @fn Test_slist::test_push_front()
/// @brief This function tests the Slist push_front function
////////////////////////////////////////////////////////////////////// 

void Test_slist::test_push_front()
{
	Slist<int> b;
	
	#ifdef VERBOSE
	std::cout << std::endl << "test_push_front: Constructor check" << std::endl;
	#endif
	
	CPPUNIT_ASSERT(b.size() == 0);
	CPPUNIT_ASSERT(b.empty());
	
	#ifdef VERBOSE
	std::cout << "test_push_front: Push one item into the slist" << std::endl;
	#endif
	
	b.push_front(0);
	CPPUNIT_ASSERT(b.front()== 0);
	CPPUNIT_ASSERT(b.size() == 1);
		
	#ifdef VERBOSE
	std::cout << "test_push_front: Push multiple items into the slist" << std::endl;
	#endif
	
	for (int i = b.size(); i < 20; i++)
	{
		b.push_front( i );
		CPPUNIT_ASSERT( b.size() == i+1);
		CPPUNIT_ASSERT(b.front() == i);
	}
	
	/* Skipping bad_alloc check this time */
}

//////////////////////////////////////////////////////////////////////
/// @fn Test_slist::test_pop_front()
/// @brief This function tests the Slist pop_front function
////////////////////////////////////////////////////////////////////// 

void Test_slist::test_pop_front()
{
	Slist<int> b;
	
	#ifdef VERBOSE
	std::cout << std::endl << "test_pop_front: Constructor check" << std::endl;
	#endif
	
	CPPUNIT_ASSERT(b.size() == 0);
	CPPUNIT_ASSERT(b.empty());
	
	#ifdef VERBOSE
	std::cout << "test_pop_front: Push and pop one item in the slist" << std::endl;
	#endif
	
	b.push_front(0);
	b.pop_front();
	CPPUNIT_ASSERT(b.size() == 0);
	CPPUNIT_ASSERT(b.empty());
	
	#ifdef VERBOSE
	std::cout << "test_pop_front: Pop front multiple items from the slist" << std::endl;
	#endif
	
	for (int i = b.size(); i < 20; i++)
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
/// @fn Test_slist::test_remove()
/// @brief This function tests the Slist remove function
////////////////////////////////////////////////////////////////////// 

void Test_slist::test_remove()
{
	Slist<int> b;
	
	#ifdef VERBOSE
	std::cout << std::endl << "test_remove: Constructor check" << std::endl;
	#endif
	
	CPPUNIT_ASSERT(b.size() == 0);
	CPPUNIT_ASSERT(b.empty());
	
	#ifdef VERBOSE
	std::cout << "test_remove: Add elements to the slist and remove one" << std::endl;
	#endif
	
	for (int i = b.size(); i < 20; i++)
	{
		b.push_front( i );
	}
	CPPUNIT_ASSERT(b.size() == 20);
	CPPUNIT_ASSERT(b.front() == 19);
	try{	b.remove(19); }
	catch ( const exception &e) { std::cout << "Exception: " << e.get_message() << std::endl; }
	CPPUNIT_ASSERT(b.size() == 19);
	CPPUNIT_ASSERT(b.front() == 18);
	
	#ifdef VERBOSE
	std::cout << "test_remove: Add similar elements to the slist and remove them" << std::endl;
	#endif
	
	b.push_front(18);
	CPPUNIT_ASSERT(b.size() == 20);
	CPPUNIT_ASSERT(b.front() == 18);
	b.remove(18);
	CPPUNIT_ASSERT(b.size() == 18);
	CPPUNIT_ASSERT(b.front() == 17);
	
	#ifdef VERBOSE
	std::cout << "test_remove: Test remove error handling (ENOENT)" << std::endl;
	#endif	
	
	try
	{
		b.remove(90);
		CPPUNIT_ASSERT(false);
	}
	catch (const exception &e)
	{
		CPPUNIT_ASSERT(b.size() == 18);
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
/// @fn Test_slist::test_front()
/// @brief This function tests the Slist front function
////////////////////////////////////////////////////////////////////// 

void Test_slist::test_front()
{
	Slist<int> b;
	
	#ifdef VERBOSE
	std::cout << std::endl << "test_front: Constructor check" << std::endl;
	#endif
	
	CPPUNIT_ASSERT(b.size() == 0);
	CPPUNIT_ASSERT(b.empty());
	
	#ifdef VERBOSE
	std::cout << "test_front: Add an element to the slist and acccess it with front" << std::endl;
	#endif
	
	b.push_front(0);
	CPPUNIT_ASSERT(b.front() == 0);
	
	#ifdef VERBOSE
	std::cout << "test_front: Add multiple elements to the slist and acccess them with front" << std::endl;
	#endif
	
	for (int i = b.size(); i < 20; i++)
	{
		b.push_front( i );
		CPPUNIT_ASSERT(b.front() == i);
	}
	CPPUNIT_ASSERT(b.size() == 20);
	
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
/// @fn Test_slist::test_clear()
/// @brief This function tests the Slist clear function
////////////////////////////////////////////////////////////////////// 

void Test_slist::test_clear()
{
	Slist<int> b;
	
	#ifdef VERBOSE
	std::cout << std::endl << "test_clear: Constructor check" << std::endl;
	#endif
	
	CPPUNIT_ASSERT(b.size() == 0);
	CPPUNIT_ASSERT(b.empty());
	
	#ifdef VERBOSE
	std::cout << "test_clear: Add elements to the slist and clear them" << std::endl;
	#endif
	
	for (int i = b.size(); i < 20; i++)
	{
		b.push_front( i );
	}
	CPPUNIT_ASSERT(b.size() == 20);
	b.clear();
	CPPUNIT_ASSERT(b.size() == 0);
	CPPUNIT_ASSERT(b.empty());
}
