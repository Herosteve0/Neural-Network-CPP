#include <iostream>

#include "Data/Tensors/CpuTensor.h"

using namespace NeuralNetwork::Data;
using namespace NeuralNetwork::Data::Tensors;

int main() {

    CpuTensor<float> cpuTensor = CpuTensor<float>({2, 3});

    std::cout << cpuTensor[3] << std::endl;

    cpuTensor[3] = 3;

    std::cout << cpuTensor[3] << std::endl;

    return 0;
}