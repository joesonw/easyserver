/* 
 * File:   TCPServer.cpp
 * Author: joesonw
 * 
 * Created on March 10, 2015, 8:28 AM
 */

#include <net/TCPServer.hpp>
#include <iostream>
#include <stdio.h>
#include <util/common.h>

#include <net/util.hpp>
using namespace std;
void net::TCPServer::init_server() {
    int r=0;
    _loop=uv_default_loop();
    uv_tcp_init(_loop,&_server);
    r=uv_ip4_addr(_addr,_port,&_bind_addr);
    assert(!r);
    uv_tcp_bind(&_server,(sockaddr*)&_bind_addr,0);
    _server.data=this;
    r=uv_listen((uv_stream_t*)&_server,128,on_connection);
    if (r) ERROR("unable to listen",r);
    cout<<"server created"<<endl;
    
}
void net::TCPServer::start() {
    cout<<"starting server"<<endl;
    uv_run(_loop,UV_RUN_DEFAULT);
}

net::TCPServer::TCPServer(char* addr,int port):_addr(addr),_port(port) {
    init_server();
}


net::TCPServer::~TCPServer() {
    
}
void net::TCPServer::on_connection(uv_stream_t* server, int status) {
    if (status) ERROR("failed on async connect",status)
    TCPServer *d=(TCPServer*)server->data;
    uv_tcp_t* conn= (uv_tcp_t *)new uv_tcp_t();
    uv_tcp_init(d->_loop,conn);
    
    int r=uv_accept(server,(uv_stream_t*)conn);
    if (r) {
        uv_close((uv_handle_t*) conn,NULL);
        LOGERROR("error accepting connection "<<r);
    } else {
        Client* client=new Client(conn,d->on_client_callback,d);
        client->send("hello",5);
        d->_clients.push_back(client);
    }
}

void net::TCPServer::on_client_callback(int index, EVENT::CLIENT::CALLBACK event,void* ptr) {
    TCPServer *d=(TCPServer*)ptr;
    if (event==EVENT::CLIENT::LOST_CONNECTION) {
        d->_clients.erase(d->_clients.begin()+index-1);
    }
}