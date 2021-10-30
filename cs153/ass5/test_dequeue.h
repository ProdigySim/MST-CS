#ifndef TEST_DEQUEUE_H
#define TEST_DEQUEUE_H

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/config/SourcePrefix.h>

#include "dequeue.h"
#include "exception.h"

class Test_dequeue : public CPPUNIT_NS::TestFixture
{
  private:
    CPPUNIT_TEST_SUITE (Test_dequeue);
      CPPUNIT_TEST (test_push_back);
	  CPPUNIT_TEST (test_push_front);
      CPPUNIT_TEST (test_pop_back);
	  CPPUNIT_TEST (test_pop_front);
	  CPPUNIT_TEST (test_copy_constructor);
    CPPUNIT_TEST_SUITE_END();
    
  protected:
    void test_push_back ();
    void test_push_front ();
    void test_pop_back ();
    void test_pop_front ();
	void test_copy_constructor ();
};

#endif
