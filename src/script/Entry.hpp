/* 
 * File:   Entry.hpp
 * Author: joesonw
 *
 * Created on March 11, 2015, 9:24 PM
 */

#include <include/v8.h>
#include <include/libplatform/libplatform.h>
#ifndef ENTRY_HPP
#define	ENTRY_HPP
namespace script {
    using namespace v8;
    class Entry {
    public:
        Entry();
        virtual ~Entry();
        //Local<Value> loadAndRun(const char *);
        //void bindFunction(Handle<Name>,Handle<Data>,PropertyAttributes);
    private:
        //Isolate* isolate;
        //Isolate::Scope isolate_scope;
        //Context::Scope context_scope;
        //Platform* platform;
    };
}

#endif	/* ENTRY_HPP */

