/* 
 * File:   Exception.hpp
 * Author: joesonw
 *
 * Created on March 10, 2015, 9:00 AM
 */
#include <exception>
#include <iostream>
#ifndef EXCEPTION_HPP
#define	EXCEPTION_HPP

class Exception:public std::exception {
public:
    Exception(char*);
    virtual const char* what() const throw();
private:
    char* msg;
};

#endif	/* EXCEPTION_HPP */

