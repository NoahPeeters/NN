cmake_minimum_required(VERSION 3.6)
project(NN)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp nn/neuron/neuron.cpp nn/neuron/neuron.h nn/helpers.h nn/network/network.cpp nn/network/network.h nn/layer/layer.cpp nn/layer/layer.h nn/trainer/trainer.cpp nn/trainer/trainer.h)
add_executable(NN ${SOURCE_FILES})