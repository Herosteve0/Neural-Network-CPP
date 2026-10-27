#include "Tensor.h"

template<typename T>
void Tensor<T>::ValidateShape(const std::vector<int>& shape) {
    if (shape.empty()) {
        throw std::invalid_argument("Tensor must have at least one dimension.");
    }

    if (std::ranges::any_of(shape, [](const int dimension) { return dimension <= 0; })) {
        throw std::invalid_argument("Tensor dimension must be greater than zero.");
    }
}
