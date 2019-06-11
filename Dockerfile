FROM ubuntu:latest

# Install the c++ compile tools
RUN apt-get update
RUN apt-get install -y g++
RUN apt-get install -y libncurses5-dev libncursesw5-dev

# Copy over the application src files
RUN mkdir -p home/workspace/monitor
COPY . /home/workspace/monitor
WORKDIR /home/workspace/monitor

# Build the application
RUN g++ main.cpp -std=c++17 -lncurses

# Run the application
# RUN ./a.out
CMD ["/bin/bash"]