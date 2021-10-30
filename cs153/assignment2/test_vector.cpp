//////////////////////////////////////////////////////////////////////
/// @file test_vector.cpp
/// @author Michael Busby CS153 1B
/// @brief Definitions of member functions for Test_vector class
////////////////////////////////////////////////////////////////////// 
#include <iostream>

#include "test_vector.h"
CPPUNIT_TEST_SUITE_REGISTRATION( Test_vector );

//#define VERBOSE

//////////////////////////////////////////////////////////////////////
/// @fn Test_vector::test_push_back()
/// @brief tests Vector push_back function
////////////////////////////////////////////////////////////////////// 

void Test_vector::test_push_back()
{
	Vector<int> b;
	unsigned int max_size;
	bool memory_exception = false;
	
	#ifdef VERBOSE
	std::cout << std::endl << "test_push_back: Constructor check" << std::endl;
	#endif
	
	CPPUNIT_ASSERT(b.size() == 0);
	CPPUNIT_ASSERT(b.max_size() == 1);
	
	#ifdef VERBOSE
	std::cout << "test_push_back: Push one item into the vector" << std::endl;
	#endif
	
	b.push_back(23);
	CPPUNIT_ASSERT(b[0] == 23);
	CPPUNIT_ASSERT(b.size() == 1);
	CPPUNIT_ASSERT(b.max_size() == 1);
	
	max_size = b.max_size();
	
	#ifdef VERBOSE
	std::cout << "test_push_back: Push multiple items into the vector" << std::endl;
	#endif
	
	for (int i = b.size(); i < 20; i++)
	{
		b.push_back( i );
		CPPUNIT_ASSERT( b[i] == i );
		CPPUNIT_ASSERT( b.size() == i+1);
		CPPUNIT_ASSERT(max_size == b.max_size() 
			|| (b.max_size() == (max_size*=2) && b.max_size() == (b.size()-1) * 2) );
	}
	
	#ifdef VERBOSE
	std::cout << "test_push_back: Test push back error handling" << std::endl;
	#endif
	
	try	
	{ 
		while (1) {
			b.push_back(23); 
		}
	}
	catch ( exception &e )
	{ 
		memory_exception = true; 
	}
	CPPUNIT_ASSERT(memory_exception);
}

//////////////////////////////////////////////////////////////////////
/// @fn Test_vector::test_pop_back()
/// @brief tests Vector pop_back function
////////////////////////////////////////////////////////////////////// 

void Test_vector::test_pop_back()
{
	Vector<int> b;
	unsigned int max_size;
	
	#ifdef VERBOSE
	std::cout << std::endl << "test_pop_back: Constructor check" << std::endl;
	#endif
	
	CPPUNIT_ASSERT(b.size() == 0);
	CPPUNIT_ASSERT(b.max_size() == 1);
	
	#ifdef VERBOSE
	std::cout << "test_pop_back: Push and pop one item in the vector" << std::endl;
	#endif
	
	b.push_back(23);
	b.pop_back();
	CPPUNIT_ASSERT(b.size() == 0);
	CPPUNIT_ASSERT(b.max_size() == 1);
	
	#ifdef VERBOSE
	std::cout << "test_pop_back: pop back multiple items from the vector" << std::endl;
	#endif
	
	for (int i = b.size(); i < 20; i++)
	{
		b.push_back( i );
	}
	max_size = b.max_size();
	for (int i = b.size(); i > 0; i--)
	{
		b.pop_back();
		CPPUNIT_ASSERT(b.size() == i-1);
		CPPUNIT_ASSERT( max_size == b.max_size() 
			|| (b.max_size() == (max_size/=2) && b.max_size() == b.size() * 2)  );
	}
	
	#ifdef VERBOSE
	std::cout << "test_pop_back: Test pop back error handling" << std::endl;
	#endif
	
	try
	{
		b.pop_back(); 
		CPPUNIT_ASSERT( false );  
	}
	catch ( exception &e ){ }
	 
	
}

//////////////////////////////////////////////////////////////////////
/// @fn Test_vector::test_bracket()
/// @brief tests Vector bracket operator
////////////////////////////////////////////////////////////////////// 

void Test_vector::test_bracket()
{
	Vector<int> b;
	
	#ifdef VERBOSE
	std::cout << std::endl << "test_bracket: Constructor check" << std::endl;
	#endif
	
	CPPUNIT_ASSERT(b.size() == 0);
	CPPUNIT_ASSERT(b.max_size() == 1);
	
	#ifdef VERBOSE
	std::cout << "test_bracket: Read one item with brackets" << std::endl;
	#endif
	
	b.push_back(23);
	CPPUNIT_ASSERT( b[0] == 23 );	
	CPPUNIT_ASSERT(b.size() == 1);
	CPPUNIT_ASSERT(b.max_size() == 1);
	
	#ifdef VERBOSE
	std::cout << "test_bracket: Read multiple items with brackets" << std::endl;
	#endif
	
	for (int i = b.size(); i < 20; i++)
	{
		b.push_back( i );
		CPPUNIT_ASSERT( b[i] == i );
	}
	
	
	#ifdef VERBOSE
	std::cout << "test_bracket: Test bracket error handling" << std::endl;
	#endif
	
	try
	{
		b[500];
		CPPUNIT_ASSERT( false );  
	}
	catch ( exception &e ){ }
}

//////////////////////////////////////////////////////////////////////
/// @fn Test_vector::test_clear()
/// @brief tests Vector clear function
////////////////////////////////////////////////////////////////////// 

void Test_vector::test_clear()
{
	Vector<int> b;
	
	#ifdef VERBOSE
	std::cout << std::endl << "test_clear: Constructor check" << std::endl;
	#endif
	
	CPPUNIT_ASSERT(b.size() == 0);
	CPPUNIT_ASSERT(b.max_size() == 1);
	
	#ifdef VERBOSE
	std::cout << "test_clear: Add elements to the vector and clear them" << std::endl;
	#endif
	
	for (int i = b.size(); i < 20; i++)
	{
		b.push_back( i );
	}
	CPPUNIT_ASSERT(b.size() == 20);
	b.clear();
	CPPUNIT_ASSERT(b.size() == 0);
	CPPUNIT_ASSERT(b.max_size() == 1);
}
