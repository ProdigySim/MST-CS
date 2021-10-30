#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>
using std::string;

enum Error_Type { FRONT_FULL, FRONT_EMPTY, BACK_FULL, BACK_EMPTY, OUT_OF_BOUNDS, CONTAINER_EMPTY };

class Exception
{
  public:
    Exception (Error_Type, string);
    Error_Type error_code ();
    string error_message ();
  private:
    Error_Type m_error_code;
    string m_error_message;
};

#endif
