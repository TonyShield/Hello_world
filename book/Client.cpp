#include "gen-cpp/BookServlet.h" //一定要包含该头文件
 
//其头文件，其他using namespace …….
 
int main(int argc, char** argv) {
 
  shared_ptr<TTransport> socket(new TSocket("localhost", 9090));
 
  shared_ptr<TTransport> transport(new TBufferedTransport(socket));
 
  shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
 
  example::BookServletClient client(protocol);
 
try {
 
  transport->open();
 
  vector<example::Book_Info> books;
 

 
  client.Sender(books);//RPC函数，调用serve端的该函数
 
  transport->close();
 
} catch (TException &tx) {
 
  printf("ERROR: %s\n", tx.what());
 
}
 