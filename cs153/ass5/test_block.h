#ifndef TEST_BLOCK_H
#define TEST_BLOCK_H

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/config/SourcePrefix.h>

#include "block.h"
#include "exception.h"

class Test_block : public CPPUNIT_NS::TestFixture
{
  private:
    CPPUNIT_TEST_SUITE (Test_block);
      CPPUNIT_TEST (test_push_back);
	  CPPUNIT_TEST (test_push_front);
      CPPUNIT_TEST (test_pop_back);
	  CPPUNIT_TEST (test_pop_front);
    CPPUNIT_TEST_SUITE_END();
    
  protected:
    void test_push_back ();
    void test_push_front ();
    void test_pop_back ();
    void test_pop_front ();
};

#endif
