FROM ubuntu:24.04

# Folllowing the guidelines, from this: https://grpc.io/docs/languages/cpp/quickstart/
# TODO: if i have to build from scratch, then I can use this: https://github.com/grpc/grpc/blob/v1.73.0/src/cpp/README.md

# Set timezone (important for some packages) 
ARG TZ=Asia/Karachi
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

# Set up working directory
WORKDIR /workspace

# Mount the current directory to /workspace
VOLUME ["/workspace"]

# Install dependencies
RUN apt-get update && \
    apt-get install -y build-essential cmake git autoconf libtool pkg-config wget curl unzip g++ clangd


# If I am on my main system, then I should build the grpc library from source, but I am in container, so I can use the pre-built binaries

# Install gRPC and Protocol Buffers
# https://grpc.io/docs/protoc-installation/
# https://protobuf.dev/installation/

# we are building from source, so we don't need these pre-built packages
# RUN apt-get install -y libgrpc++-dev libprotobuf-dev protobuf-compiler

# Install shell : personal preference
RUN apt-get install -y zsh


# CLEAN UP APT GET CACHE
RUN apt-get clean purge autoremove \
    && rm -rf /var/lib/apt/lists/*

RUN useradd --create-home --home-dir /home/workspace --user-group workspace && echo workspace:workspace | chpasswd \
    && chsh -s /bin/zsh workspace && echo "workspace ALL=(ALL) NOPASSWD: ALL" >> /etc/sudoers

# Clone gRPC repo
RUN git clone --recurse-submodules -b v1.74.0 --depth 1 --shallow-submodules https://github.com/grpc/grpc ~/grpc

# Set up environment variables for gRPC and Protocol Buffers
ENV MY_INSTALL_DIR=~/.local

# Set up the directory structure
RUN mkdir -p $MY_INSTALL_DIR && \
    cd ~/grpc && \
    mkdir -p cmake/build && \
    cd cmake/build && \
    cmake -DgRPC_INSTALL=ON \
    -DgRPC_BUILD_TESTS=OFF \
    -DCMAKE_CXX_STANDARD=20 \
    -DCMAKE_INSTALL_PREFIX=$MY_INSTALL_DIR \
    ../.. && \
    # no of process - 2
    make -j 6 && \
    make install

# Add to PATH
ENV PATH="$MY_INSTALL_DIR/bin:$PATH"

# Build and install gRPC and Protocol Buffers
# RUN mkdir -p grpc/cmake/build && \
#     cd grpc/cmake/build && \
#     cmake -DgRPC_INSTALL=ON \
#           -DgRPC_BUILD_TESTS=OFF \
#           -DCMAKE_CXX_STANDARD=17 \
#           -DCMAKE_INSTALL_PREFIX=/usr/local \
#           ../.. && \
#     make -j 4 && \
#     make install

# Add your source code here (client, server, proto files)
# COPY . /workspace

# Build your application (example, adjust as needed)
# RUN mkdir -p build && cd build && cmake .. && make -j 4

# Default command (adjust to run server or client)
# CMD ["./server"]

