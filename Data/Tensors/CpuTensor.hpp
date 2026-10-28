#pragma once

#include <stdexcept>

using namespace NeuralNetwork::Data::Tensors;

template <typename T>
CpuTensor<T>::CpuTensor(std::initializer_list<int> shape) : Tensor<T>(shape) {
    _data = std::vector<T>(Tensor<T>::GetLength());
}

template <typename T>
CpuTensor<T>::CpuTensor(std::vector<T> data, std::initializer_list<int> shape) : Tensor<T>(shape) {
    if (data.size() != Tensor<T>::GetLength()) {
        throw std::runtime_error("Given data size does not match tensor length.");
    }

    _data = data;
}

template <typename T>
CpuTensor<T>::CpuTensor(T value, std::initializer_list<int> shape) : Tensor<T>(shape) {
    _data = std::vector<T>(Tensor<T>::GetLength(), value);
}

template <typename T>
std::span<const T> CpuTensor<T>::GetData() const {
    return _data;
}