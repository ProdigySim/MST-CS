#include "exception.h"

Exception::Exception (Error_Type _error_code, string _error_message)
{
    m_error_code = _error_code;
    m_error_message = _error_message;
}

Error_Type Exception::error_code ()
{
    return m_error_code;
}

string Exception::error_message ()
{
    return m_error_message;
}

