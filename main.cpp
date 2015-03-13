
/*
void read_cb(uv_stream_t *client, ssize_t nread, const uv_buf_t *buf) {
  if (nread == UV_EOF) {
    // XXX: this is actually a bug, since client writes could back up (see ./test-client.sh) and therefore
    // some chunks to be written be left in the pipe.
    // Closing in that case results in: [ECANCELED: operation canceled]
    // Not closing here avoids that error and a few more chunks get written.
    // But even then not ALL of them make it through and things get stuck.
    uv_close((uv_handle_t*) client, NULL);

    fprintf(stderr, "closed client connection\n");
    fprintf(stderr, "Total read:    %d\n", total_read);
    fprintf(stderr, "Total written: %d\n", total_written);
    total_read = total_written = 0;
  } else if (nread > 0) {
    fprintf(stderr, "%ld bytes read\n", nread);
    total_read += nread;

    write_req_t *wr = (write_req_t*) malloc(sizeof(write_req_t));
    wr->buf =  uv_buf_init(buf->base, nread);
    uv_write(&wr->req, client, &wr->buf, 1, write_cb);
    //fprintf(stderr, "writing %ld bytes\n", req->bufs[0].len);
  }
  if (nread == 0) free(buf->base);
}
void write_cb(uv_write_t *req, int status) {
  write_req_t* wr;
  wr = (write_req_t*) req;

  int written = wr->buf.len;
  if (status) ERROR("async write", status);
  assert(wr->req.type == UV_WRITE);
  fprintf(stderr, "%d bytes written\n", written);
  total_written += written;

 * 
  free(wr->buf.base);
  free(wr);
}
*/

#include <net/TCPServer.hpp>

int main(int argc,char* argv[]) {
    net::TCPServer *server=new net::TCPServer("0.0.0.0",3001);
    server->start();
    
}