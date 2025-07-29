FROM ubuntu:24.04

# without building from scratch
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
RUN apt-get install -y libgrpc++-dev libprotobuf-dev protobuf-compiler protobuf-compiler-grpc

# Install shell : personal preference
RUN apt-get install -y zsh


# CLEAN UP APT GET CACHE
RUN apt-get clean purge autoremove \
    && rm -rf /var/lib/apt/lists/*