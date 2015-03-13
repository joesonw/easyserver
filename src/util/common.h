/* 
 * File:   common.h
 * Author: joesonw
 *
 * Created on March 12, 2015, 12:06 AM
 */


#include <assert.h>
#include <iostream>
#ifndef COMMON_H
#define	COMMON_H

#define ERROR(msg, code) do {                                                         \
      fprintf(stderr, "%s: [%s: %s]\n", msg, uv_err_name((code)), uv_strerror((code)));   \
      assert(0);                                                                          \
    } while(0);
using namespace std;

 #define LOGERROR(msg) do {cerr<<msg<<endl;break;}while(0);  


#endif	/* COMMON_H */

