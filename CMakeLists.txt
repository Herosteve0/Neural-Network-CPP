cmake_minimum_required(VERSION 4.3)
project("Neural Network C++")

add_executable(
    Neural_Network+C++ main.cpp
    NetworkFormat/Network.cpp
    NetworkFormat/Network.h
    NetworkFormat/Layers/BaseLayer.cpp
    NetworkFormat/Layers/BaseLayer.h
    Data/Tensors/Tensor.cpp
    Data/Tensors/Tensor.h
)