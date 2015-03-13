/* 
 * File:   Client.hpp
 * Author: joesonw
 *
 * Created on March 10, 2015, 6:27 PM
 */

#include <include/uv.h>
#include <mutex>
#include <iostream>
#include <string>
#ifndef NET_CLIENT_HPP
#define	NET_CLIENT_HPP

#include <net/util.hpp>
namespace net {
    typedef void(*client_callback)(int,EVENT::CLIENT::CALLBACK,void* ptr);
    class TCPServer;
    class Client {
        friend class TCPServer;
      public:
        Client(uv_tcp_t*,client_callback, void* ptr);
        virtual ~Client();
        
        void close();
        void send(char*,int);
        void send(const std::string);
      private:
        uv_tcp_t* _connection;
        int _index;
        void *_server;
        client_callback _callback;
        static void on_allocation(uv_handle_t*,size_t,uv_buf_t*);
        static void on_message(uv_stream_t*,ssize_t,const uv_buf_t*);
        static void on_write_compelete(uv_write_t*,int);
    };
};

#endif	/* NET_CLIENT_HPP */

