/* 
 * File:   Entry.cpp
 * Author: joesonw
 * 
 * Created on March 11, 2015, 9:24 PM
 */

#include "Entry.hpp"
#include <string>
#include <fstream>
using namespace std;
using namespace v8;
/*
script::Entry::Entry() {
    V8::InitializeICU();
    platform = platform::CreateDefaultPlatform();
    V8::InitializePlatform(platform);
    V8::Initialize();

    // Create a new Isolate and make it the current one.
    isolate = Isolate::New();
    isolate_scope(isolate);

    // Create a stack-allocated handle scope.
    HandleScope handle_scope(isolate);
    Handle<ObjectTemplate> globalTemplate=ObjectTemplate::New(isolate);
    // Create a new context.
    //globalTemplate->Set(String::NewFromUtf8(isolate,"print"),FunctionTemplate::New(isolate,printMessage));
    Local<Context> context = Context::New(isolate,NULL,globalTemplate);
    // Enter the context for compiling and running the hello world script.
    context_scope(context);


}

Local<Value> script::Entry::loadAndRun(const char * filename) {
    
    string line;
    string scripts;
    ifstream f(filename);
    if (f.is_open()) {
        while (getline(f,line)) {
            scripts+=line;
        }
    }
    
    // Create a string containing the JavaScript source code.
    Local<String> source = String::NewFromUtf8(isolate, scripts.c_str());

    // Compile the source code.
    Local<Script> script = Script::Compile(source);

    // Run the script to get the result.
    Local<Value> result = script->Run();
    f.close();
}


script::Entry::~Entry() {
    isolate->Dispose();
    V8::Dispose();
    V8::ShutdownPlatform();
    delete platform;
}
*/
