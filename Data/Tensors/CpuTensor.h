#ifndef NEURAL_NETWORK_C_CPUTENSOR_H
#define NEURAL_NETWORK_C_CPUTENSOR_H

#include "Tensor.h"

namespace NeuralNetwork::Data::Tensors {
    template <typename T>
    class CpuTensor : public Tensor<T> {
        std::vector<T> _data;
    public:
        CpuTensor(std::initializer_list<int> shape);

        CpuTensor(std::vector<T> data, std::initializer_list<int> shape);

        CpuTensor(T value, std::initializer_list<int> shape);

        T& operator[](int index) {
            return _data[index];
        }
        T& operator[](int row, int col) {
            return _data[Tensor<T>::GetFlatIndex(row, col)];
        }
        T& operator[](std::vector<int> indices) {
            return _data[Tensor<T>::GetFlatIndex(indices)];
        }

        std::span<const T> GetData() const;
    };
}

#include "CpuTensor.hpp"

#endif