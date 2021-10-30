//////////////////////////////////////////////////////////////////////
/// @file exception.h
/// @author Michael Busby CS153 1B
/// @brief Declarations and definitions for exception class
////////////////////////////////////////////////////////////////////// 
#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>


//////////////////////////////////////////////////////////////////////
/// @class exception
/// @brief This class stores exceptions with a string for use with
/// throw/catch
////////////////////////////////////////////////////////////////////// 

//////////////////////////////////////////////////////////////////////
/// @fn exception::exception( std::string )
/// @brief This constructor initializes the class and message variable
/// @param msg holds a std::string of the exception description
////////////////////////////////////////////////////////////////////// 

//////////////////////////////////////////////////////////////////////
/// @fn exception::~exception()
/// @brief This function deinitializes exception variables
////////////////////////////////////////////////////////////////////// 

//////////////////////////////////////////////////////////////////////
/// @fn exception::get_message()
/// @brief This function returns the exception message
/// @return std::string of exception message
////////////////////////////////////////////////////////////////////// 

class exception
{
    private:
        std::string m_msg; ///< holds exception message
    
    public:
        exception( const std::string &msg ) : m_msg(msg) {}
        ~exception() {}
        std::string get_message() const { return m_msg; }    
};

#include "exception.hpp"

#endif
