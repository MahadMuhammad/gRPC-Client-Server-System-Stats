## Steps for setting up the project

1. Download the grpc repo, as suggested in the documentation [here](https://grpc.io/docs/languages/cpp/quickstart/#clone-the-grpc-repo).

   Use the following command to clone the repository with submodules:

```bash
git clone --recurse-submodules -b v1.73.0 --depth 1 --shallow-submodules https://github.com/grpc/grpc
```

2. For building the docker image, use the following command:

```bash
docker build -t ss .
```

- Using cpp20, you can specify the C++ standard in the Dockerfile as follows:

```dockerfile
docker build -t ss-cpp20 containers/cpp20
```

3. Run the docker image, with `pwd` mounted to `/workspace`:

```bash
docker run -it -v $(pwd):/workspace ss
```
