# Start with a minimal base image
FROM ubuntu:20.04

# Set environment variables to avoid interactive prompts during package installation
ENV DEBIAN_FRONTEND=noninteractive

# Install required packages for building the library
RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    git \
    cmake \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

RUN git clone --depth 1 https://github.com/fmtlib/fmt.git

# Build the library
WORKDIR /app/fmt
RUN mkdir build && cd build && \
    cmake .. && \
    make && \
    make install && \
    cd ../.. && \
    rm -rf fmt

RUN apt-get purge -y --auto-remove \
    build-essential \
    git \
    cmake \
    && rm -rf /var/lib/apt/lists/*

CMD ["bash"]
