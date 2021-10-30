#include <iostream>
using std::cout;
using std::endl;

#include "test_block.h"

CPPUNIT_TEST_SUITE_REGISTRATION( Test_block );

void Test_block::test_push_back ()
{
    cout << endl << "////////////////////////////////////////////////" << endl;
	cout << "Testing the Block class" << endl;
	cout << "////////////////////////////////////////////////" << endl;
    Block<int> b;
	cout << endl << "test_push_back: constructor check" << endl;
    CPPUNIT_ASSERT (b.max_size() == 3);
	CPPUNIT_ASSERT (b.size () == 0);
	
	cout << "test_push_back: push check" << endl;
	b.push_back (1);
	CPPUNIT_ASSERT (b[0] == 1);
	CPPUNIT_ASSERT (b.size () == 1);
	
	b.push_back (2);
	CPPUNIT_ASSERT (b[0] == 1);
	CPPUNIT_ASSERT (b[1] == 2);
	CPPUNIT_ASSERT (b.size () == 2);
	
	b.push_back (3);
	CPPUNIT_ASSERT (b[0] == 1);
	CPPUNIT_ASSERT (b[1] == 2);
	CPPUNIT_ASSERT (b[2] == 3);
	CPPUNIT_ASSERT (b.size () == 3);
	
	cout << "test_push_back: back_full exception check" << endl;
	try
	{
	    b.push_back (4);
		CPPUNIT_ASSERT (false);
	}
	catch (Exception & e)
	{
	    CPPUNIT_ASSERT (e.error_code() == BACK_FULL);
	}
	
	cout << "test_push_back: destructor check" << endl;
}

void Test_block::test_push_front ()
{
    Block<int> b;
	
	cout << endl << "test_push_front: push check" << endl;
	b.push_front (1);
	CPPUNIT_ASSERT (b[0] == 1);
	CPPUNIT_ASSERT (b.size () == 1);
	
	b.push_front (2);
	CPPUNIT_ASSERT (b[0] == 2);
	CPPUNIT_ASSERT (b[1] == 1);
	CPPUNIT_ASSERT (b.size () == 2);
	
	b.push_front (3);
	CPPUNIT_ASSERT (b[0] == 3);
	CPPUNIT_ASSERT (b[1] == 2);
	CPPUNIT_ASSERT (b[2] == 1);
	CPPUNIT_ASSERT (b.size () == 3);
	
	cout << "test_push_front: front_full exception check" << endl;
	try
	{
	    b.push_front (4);
		CPPUNIT_ASSERT (false);
	}
	catch (Exception & e)
	{
	    CPPUNIT_ASSERT (e.error_code() == FRONT_FULL);
	}
	
	cout << "test_push_front: back_full when block_full exception check" << endl;
	try
	{
	    b.push_back (4);
		CPPUNIT_ASSERT (false);
	}
	catch (Exception & e)
	{
	    CPPUNIT_ASSERT (e.error_code() == BACK_FULL);
	}

	cout << "test_push_front: clear check" << endl;
	b.clear();
    CPPUNIT_ASSERT (b.max_size() == 3);
	CPPUNIT_ASSERT (b.size () == 0);
	
	cout << "test_push_front: back_full exception check" << endl;
	b.push_front (1);
	CPPUNIT_ASSERT (b[0] == 1);
	CPPUNIT_ASSERT (b.size () == 1);
	
	try
	{
	    b.push_back (2);
		CPPUNIT_ASSERT (false);
	}
	catch (Exception & e)
	{
	    CPPUNIT_ASSERT (e.error_code() == BACK_FULL);
	}
}

void Test_block::test_pop_back ()
{
    Block<int> b;
	
	cout << endl << "test_pop_back: pop check" << endl;
	b.push_back (1);
	b.push_back (2);
	b.push_back (3);
	CPPUNIT_ASSERT (b[0] == 1);
	CPPUNIT_ASSERT (b[1] == 2);
	CPPUNIT_ASSERT (b[2] == 3);
	CPPUNIT_ASSERT (b.size () == 3);
	
	b.pop_back();
	CPPUNIT_ASSERT (b[0] == 1);
	CPPUNIT_ASSERT (b[1] == 2);
	CPPUNIT_ASSERT (b.size () == 2);
	
	try
	{
	    b[2] = 3;
		CPPUNIT_ASSERT (false);
	}
	catch (Exception & e)
	{
	    CPPUNIT_ASSERT (e.error_code() == OUT_OF_BOUNDS);
	}
	
	b.pop_back();
	CPPUNIT_ASSERT (b[0] == 1);
	CPPUNIT_ASSERT (b.size () == 1);
	
	try
	{
	    b[1] = 2;
		CPPUNIT_ASSERT (false);
	}
	catch (Exception & e)
	{
	    CPPUNIT_ASSERT (e.error_code() == OUT_OF_BOUNDS);
	}
	
	b.pop_back();
	CPPUNIT_ASSERT (b.size () == 0);
	
	try
	{
	    b[0] = 1;
		CPPUNIT_ASSERT (false);
	}
	catch (Exception & e)
	{
	    CPPUNIT_ASSERT (e.error_code() == OUT_OF_BOUNDS);
	}
	
	cout << "test_pop_back: back_empty exception check" << endl;
	try
	{
	    b.pop_back();
		CPPUNIT_ASSERT (false);
	}
	catch (Exception & e)
	{
	    CPPUNIT_ASSERT (e.error_code() == BACK_EMPTY);
	}
}

void Test_block::test_pop_front ()
{
    Block<int> b;
	
	cout << endl << "test_pop_back: pop check" << endl;
	b.push_back (1);
	b.push_back (2);
	b.push_back (3);
	CPPUNIT_ASSERT (b[0] == 1);
	CPPUNIT_ASSERT (b[1] == 2);
	CPPUNIT_ASSERT (b[2] == 3);
	CPPUNIT_ASSERT (b.size () == 3);
	
	b.pop_front();
	CPPUNIT_ASSERT (b[0] == 2);
	CPPUNIT_ASSERT (b[1] == 3);
	CPPUNIT_ASSERT (b.size () == 2);
	
	try
	{
	    b[2] = 1;
		CPPUNIT_ASSERT (false);
	}
	catch (Exception & e)
	{
	    CPPUNIT_ASSERT (e.error_code() == OUT_OF_BOUNDS);
	}
	
	b.pop_front();
	CPPUNIT_ASSERT (b[0] == 3);
	CPPUNIT_ASSERT (b.size () == 1);
	
	try
	{
	    b[1] = 2;
		CPPUNIT_ASSERT (false);
	}
	catch (Exception & e)
	{
	    CPPUNIT_ASSERT (e.error_code() == OUT_OF_BOUNDS);
	}
	
	b.pop_back();
	CPPUNIT_ASSERT (b.size () == 0);
	
	try
	{
	    b[0] = 3;
		CPPUNIT_ASSERT (false);
	}
	catch (Exception & e)
	{
	    CPPUNIT_ASSERT (e.error_code() == OUT_OF_BOUNDS);
	}
	
	cout << "test_pop_front: back_empty exception check" << endl;
	try
	{
	    b.pop_front();
		CPPUNIT_ASSERT (false);
	}
	catch (Exception & e)
	{
	    CPPUNIT_ASSERT (e.error_code() == FRONT_EMPTY);
	}
	
    cout << "test_pop_front: pop from both sides" << endl;
	b.clear();
	
	b.push_back (1);
	b.push_back (2);
	b.push_back (3);
	
	b.pop_front();
	b.pop_back();
	CPPUNIT_ASSERT (b[0] == 2);
	CPPUNIT_ASSERT (b.size () == 1);
	
	b.push_back (3);
	CPPUNIT_ASSERT (b[0] == 2);
	CPPUNIT_ASSERT (b[1] == 3);
	CPPUNIT_ASSERT (b.size () == 2);
	
	b.push_front (1);
	CPPUNIT_ASSERT (b[0] == 1);
	CPPUNIT_ASSERT (b[1] == 2);
	CPPUNIT_ASSERT (b[2] == 3);
	CPPUNIT_ASSERT (b.size () == 3);
	
	b.pop_front();
	b.pop_back();
	b.push_back (3);
	
	try
	{
	    b.push_back (3);
		CPPUNIT_ASSERT (false);
	}
	catch (Exception & e)
	{
	    CPPUNIT_ASSERT (e.error_code() == BACK_FULL);
	}
	
	b.pop_back();
	b.push_front (1);
		
	try
	{
	    b.push_front (0);
		CPPUNIT_ASSERT (false);
	}
	catch (Exception & e)
	{
	    CPPUNIT_ASSERT (e.error_code() == FRONT_FULL);
	}
	
	cout << "test_pop_front: copy constructor" << endl;
	b.push_back (3);
	
	Block<int> bb(b);
	CPPUNIT_ASSERT (b.size () == bb.size ());
	CPPUNIT_ASSERT (b.max_size () == bb.max_size ());
	
	for (unsigned int i = 0; i < b.size (); i++)
	{
	    CPPUNIT_ASSERT (b[i] == bb[i]);
	}
}
