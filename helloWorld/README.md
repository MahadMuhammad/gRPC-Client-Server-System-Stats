```bash
# Compile proto
protoc -I . helloworld.proto \
  --cpp_out=. \
  --grpc_out=. \
  --plugin=protoc-gen-grpc=$(which grpc_cpp_plugin)

# Build the app
mkdir build && cd build
cmake ..
make

# In terminal A
./greeter_server

# In terminal B (new docker run)
./greeter_client Mahad
```
