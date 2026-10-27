#ifndef NEURAL_NETWORK_C_TENSOR_H
#define NEURAL_NETWORK_C_TENSOR_H
#include <stdexcept>
#include <vector>

template <typename T>
class Tensor {
private:
    static void ValidateShape(const int* shape);

protected:
    explicit Tensor(const std::vector<int>& shape);
public:

    /**
     * Returns the rank of the tensor.
     */
    int get_rank();


};

#endif