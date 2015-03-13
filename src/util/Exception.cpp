/* 
 * File:   Exception.cpp
 * Author: joesonw
 * 
 * Created on March 10, 2015, 9:00 AM
 */

#include "Exception.hpp"
Exception::Exception(char * m) {
    msg=m;
}

const char* Exception::what() const throw() {
    return msg;
}