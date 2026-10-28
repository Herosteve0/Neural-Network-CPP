#ifndef NEURAL_NETWORK_C_TENSOR_H
#define NEURAL_NETWORK_C_TENSOR_H

#include <span>
#include <vector>

namespace NeuralNetwork::Data::Tensors {
    template <typename T>
    class Tensor {
        std::vector<int> _shape;
        std::vector<int> _strides;
        int length;

        static void ValidateShape(std::span<const int> shape);
    protected:
        Tensor(std::initializer_list<int> shape);

        int GetFlatIndex(std::span<const int> indices) const;
    public:

        /**
         * Returns the dimensions of the tensor.
         */
        int GetRank() const;

        /**
         * Returns the elements of the tensor.
         */
        int GetLength() const;

        /**
         * The size of each dimension.
         */
        std::span<const int> GetShape() const;

        /**
        * Stride of each dimension.
        * Essentially, the offset each dimension needs to go to the index in the array.
        */
        std::span<const int> GetStrides() const;
    };
}

#include "Tensor.hpp"

#endif