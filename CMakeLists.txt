cmake_minimum_required(VERSION 4.3)
project("Neural Network C++")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(
    Neural_Network+C++ main.cpp

    NetworkFormat/Layers/BaseLayer.cpp
    NetworkFormat/Layers/BaseLayer.h

    Backend/Backend.cpp
    Backend/Backend.h

        Data/Tensors/Tensor.h
        Data/Tensors/Tensor.hpp

        Data/Tensors/CpuTensor.hpp
        Data/Tensors/CpuTensor.h
        Data/DataStructs.h
        Data/DataStructs.cpp
        Data/DataStructs.hpp
        Data/Random.cpp
        Data/Random.h
)