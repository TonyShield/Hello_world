#include "gen-cpp/BookServlet.h"
 
#include <thrift/protocol/TBinaryProtocol.h>
 
#include <thrift/server/TSimpleServer.h>
 
#include <thrift/transport/TServerSocket.h>
 
#include <thrift/transport/TBufferTransports.h>
 
using namespace ::apache::thrift;
 
using namespace ::apache::thrift::protocol;
 
using namespace ::apache::thrift::transport;
 
using namespace ::apache::thrift::server;
 
using boost::shared_ptr;
 
using namespace example;
 
class BookServletHandler : virtual public BookServletIf {
 
public:
 
BookServletHandler() {
 
// Your initialization goes here
 
}
 
//用户需实现这个接口
 
bool Sender(const std::vector<example::Book_Info> & books) {
 
  // Your implementation goes here
 
  printf("Sender\n");
 
}
 
//用户需实现这个接口
 
void Sender2(const std::vector<example::Book_Info> & books) {
 
  // Your implementation goes here
 
  printf("Sender2\n");
 
}
 
};
 
int main(int argc, char **argv) {
 
  int port = 9090;
 
  shared_ptr<BookServletHandler> handler(new BookServletHandler());
 
  shared_ptr<TProcessor> processor(new BookServletProcessor(handler));
 
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
 
  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
 
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());
 
  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
 
  server.serve();
 
  return 0;
 
}