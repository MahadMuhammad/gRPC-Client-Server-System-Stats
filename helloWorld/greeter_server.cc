#include "helloworld.grpc.pb.h"
#include <grpcpp/grpcpp.h>

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using helloworld::Greeter;
using helloworld::HelloReply;
using helloworld::HelloRequest;

class GreeterServiceImpl final : public Greeter::Service {
  Status SayHello(ServerContext *context, const HelloRequest *request,
                  HelloReply *reply) override {
    reply->set_message("Hello " + request->name());
    return Status::OK;
  }
};

int main() {
  std::string address("0.0.0.0:50051");
  GreeterServiceImpl service;
  ServerBuilder builder;
  builder.AddListeningPort(address, grpc::InsecureServerCredentials());
  builder.RegisterService(&service);
  std::unique_ptr<Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << address << std::endl;
  server->Wait();
}
