/* 
 * File:   TCPServer.hpp
 * Author: joesonw
 *
 * Created on March 10, 2015, 8:28 AM
 */


#include <vector>
#include <include/uv.h>
#include <netinet/in.h>
#include <assert.h>
#include <net/Client.hpp>
#include <util/Exception.hpp>

#ifndef NET_TCPSERVER_HPP
#define NET_TCPSERVER_HPP
namespace net {
    
    class TCPServer {
         
       public:
        TCPServer(char*,int);
        ~TCPServer();
        void start();
        void close();
      private:
        char* _addr;
        int _port;
        uv_loop_t* _loop;
        uv_tcp_t _server;
        sockaddr_in _bind_addr;
        std::vector<Client*> _clients;
        
        void init_server();
        static void on_connection(uv_stream_t*,int);
        static void on_client_callback(int, EVENT::CLIENT::CALLBACK,void* ptr);
    };
};

#endif	/* TCPSERVER_HPP */

