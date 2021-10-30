#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include "test_dequeue.h"

CPPUNIT_TEST_SUITE_REGISTRATION( Test_dequeue );

void Test_dequeue::test_push_back ()
{
    cout << endl << "////////////////////////////////////////////////" << endl;
	cout << "Testing the Dequeue class" << endl;
	cout << "////////////////////////////////////////////////" << endl;
    Dequeue<int> d;
	
	cout << endl << "Checking push_back for the first block" << endl;
	for (unsigned int i = 0; i < 3; i++)
	{
	    d.push_back (i);
		CPPUNIT_ASSERT (d[i] == i);
		CPPUNIT_ASSERT (d.size() == i + 1);
	}
	
	cout << "Checking push_back for multiple blocks" << endl;
	for (unsigned int i = 3; i < 200; i++)
	{
	    d.push_back (i);
		CPPUNIT_ASSERT (d[i] == i);
		CPPUNIT_ASSERT (d.size() == i + 1);
	}
}

void Test_dequeue::test_push_front ()
{
    Dequeue<int> d;
	
	cout << endl << "Checking push_front for the first block" << endl;
	for (unsigned int i = 0; i < 3; i++)
	{
	    d.push_front (i);
		CPPUNIT_ASSERT (d[0] == i);
		CPPUNIT_ASSERT (d.size() == i + 1);
	}

	cout << "Checking push_front for multiple blocks" << endl;
	for (unsigned int i = 3; i < 200; i++)
	{
	    d.push_front (i);
		CPPUNIT_ASSERT (d[0] == i);
		CPPUNIT_ASSERT (d.size() == i + 1);
	}
	
	cout << endl << "Checking clear" << endl;
	d.clear();
	CPPUNIT_ASSERT (d.size() == 0);
	
	cout << "Checking push from both ends" << endl;
	int blah;
	for (unsigned int i = 100; i > 0; i--)
	{
	    d.push_front (i);
	}
	
	d.push_front (0);
	
	for (unsigned int i = 101; i < 200; i++)
	{
	    d.push_back (i);
	}
	
	for (unsigned int i = 0; i < 200; i++)
	{
	    CPPUNIT_ASSERT (d[i] == i);
	}
}

void Test_dequeue::test_pop_back ()
{
    Dequeue<int> d;
	
	cout << endl << "Checking pop_back" << endl;
	for (unsigned int i = 0; i < 200; i++)
	{
	    d.push_back (i);
	}
	
	for (unsigned int i = 199; i > 0; i--)
	{
	    CPPUNIT_ASSERT (d[i] == i);
		CPPUNIT_ASSERT (d.size() == i + 1);
	    d.pop_back();
	}
	
	d.pop_back();
	
	cout << "Checking pop_back exception" << endl;
	try
	{
	    d.pop_back();
		CPPUNIT_ASSERT (false);
	}
	catch (Exception & e)
	{
	    CPPUNIT_ASSERT (e.error_code () == CONTAINER_EMPTY);
	}
}

void Test_dequeue::test_pop_front ()
{
    Dequeue<int> d;
	
	cout << endl << "Checking pop_front exception" << endl;
	try
	{
	    d.pop_front();
		CPPUNIT_ASSERT (false);
	}
	catch (Exception & e)
	{
	    CPPUNIT_ASSERT (e.error_code () == CONTAINER_EMPTY);
	}
	
	cout << "Checking pop_front" << endl;
	for (unsigned int i = 0; i < 200; i++)
	{
	    d.push_front (i);
	}
	
	for (unsigned int i = 199; i > 0; i--)
	{
	    CPPUNIT_ASSERT (d[0] == i);
		CPPUNIT_ASSERT (d.size() == i + 1);
	    d.pop_front();
	}
	
	cout << "Checking push and pop from both ends" << endl;
	int blah;
	for (unsigned int i = 199; i > 0; i--)
	{
	    d.push_front (i);
	}
	
	d.push_front (0);

	for (unsigned int i = 0; i < 101; i++)
	{
	    d.pop_back ();
	}
	
	for (unsigned int i = 100; i < 300; i++)
	{
	    d.push_back (i);
	}

	for (unsigned int i = 0; i < 100; i++)
	{
	    d.pop_front ();
	}
	
	for (unsigned int i = 0; i < 200; i++)
	{
	    CPPUNIT_ASSERT (d[i] == i + 100);
	}
}

void Test_dequeue::test_copy_constructor ()
{
    Dequeue<int> d;
	
	cout << endl << "Checking copy_constructor" << endl;
	for (unsigned int i = 0; i < 200; i++)
	{
	    d.push_front (i);
	}
	
	Dequeue<int> dd (d);
    CPPUNIT_ASSERT (dd.size() == d.size());
			
	for (unsigned int i = 0; i < 200; i++)
	{
		CPPUNIT_ASSERT (dd[i] == d[i]);
	}
	
	cout << "Checking out of bounds exception" << endl;
	try
	{
	    dd[200] = 5;
		CPPUNIT_ASSERT (false);
	}
	catch (Exception & e)
	{
	    CPPUNIT_ASSERT (e.error_code () == OUT_OF_BOUNDS);
	}
}
