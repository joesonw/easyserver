/* 
 * File:   Client.cpp
 * Author: joesonw
 * 
 * Created on March 10, 2015, 6:27 PM
 */

#include "./Client.hpp"
#include <assert.h>

net::Client::Client(uv_tcp_t* connection,client_callback callback,void* ptr):_connection(connection),_callback(callback) {
    
    connection->data=this;
    uv_read_start((uv_stream_t*)_connection,on_allocation,on_message);
}

net::Client::~Client() {
    close();
}
void net::Client::close() {
    uv_read_stop((uv_stream_t*)_connection);
    uv_close((uv_handle_t*)_connection,NULL);
}
void net::Client::on_allocation(uv_handle_t* handle, size_t size, uv_buf_t* buf) {
    *buf=uv_buf_init((char*)malloc(size),size);
    assert(buf->base != NULL);
}

void net::Client::on_message(uv_stream_t* client,ssize_t size,const uv_buf_t* buf) {
    Client* d=(Client*)client->data;
    if (size==UV_EOF) {
        uv_close((uv_handle_t*)client,NULL);
        d->_callback(d->_index,EVENT::CLIENT::LOST_CONNECTION,d->_server);
    } else if (size>0) {
        std::cout<<buf->base<<std::endl;
        
    }
    if (size==0) delete buf->base;
}

void net::Client::send(char* msg,int len) {
    uv_buf_t buf={.base=msg,.len=static_cast<size_t>(len)};
    uv_write_t req;
    uv_write(&req,(uv_stream_t*)_connection,&buf,1,on_write_compelete);
}
void net::Client::on_write_compelete(uv_write_t* req, int status) {
    delete req;
    
}
