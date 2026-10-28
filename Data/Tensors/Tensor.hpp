#pragma once

#include <stdexcept>
#include <algorithm>

using namespace NeuralNetwork::Data::Tensors;

template<typename T>
Tensor<T>::Tensor(std::initializer_list<int> shape) {
    ValidateShape(shape);

    _shape = std::vector<int>(shape);
    _strides = std::vector<int>(shape.size());

    length = 1;
    for (int i = 0; i < _strides.size(); i++) {
        _strides[i] = length;
        length *= _shape[i];
    }
}

template<typename T>
int Tensor<T>::GetRank() const {
    return _shape.size();
}

template<typename T>
int Tensor<T>::GetLength() const {
    return length;
}

template<typename T>
std::span<const int> Tensor<T>::GetShape() const {
    return _shape;
}

template<typename T>
std::span<const int> Tensor<T>::GetStrides() const {
    return _strides;
}

template<typename T>
int Tensor<T>::GetFlatIndex(const std::span<const int> indices) const {
    if (indices.size() != GetRank()) {
        throw std::invalid_argument("Expected " + std::to_string(GetRank()) + " indices, got " + std::to_string(indices.size()) + " instead.");
    }

    int index = 0;

    for (int i = 0; i < _shape.size(); i++) {
        const int value = _strides[i];

        if (static_cast<unsigned int>(value) >= static_cast<unsigned int>(_shape[i])) {
            throw std::invalid_argument("Index " + std::to_string(value) + " is out of dimension " + std::to_string(i) + " with size " + std::to_string(_shape[i]) + ".");
        }

        index += value * _strides[i];
    }

    return index;
}

template<typename T>
void Tensor<T>::ValidateShape(std::span<const int> shape) {
    if (shape.empty()) {
        throw std::invalid_argument("Tensor must have at least one dimension.");
    }

    if (std::ranges::any_of(shape, [](const int x) { return x <= 0; })) {
        throw std::invalid_argument("Tensor dimension must be greater than zero.");
    }
}