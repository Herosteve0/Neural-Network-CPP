#ifndef NEURAL_NETWORK_C_RANDOM_H
#define NEURAL_NETWORK_C_RANDOM_H
#include <chrono>
#include <random>

namespace NeuralNetwork::Data {
    class Random {
        std::mt19937 generator;
    public:
        Random();
        Random(unsigned int seed);

        float Next();
        double NextDouble();

        int NextInt(int range);
        int NextInt(int min, int max);
    };
}

#endif
