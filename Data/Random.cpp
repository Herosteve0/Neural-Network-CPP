#include "Random.h"

#include <chrono>

namespace NeuralNetwork::Data {
    Random::Random() {
        std::random_device rd;
        generator.seed(rd());
    }
    Random::Random(unsigned int seed) {
        generator.seed(seed);
    }

    float Random::Next() {
        std::uniform_real_distribution<float> distribution(0.0, 1.0);
        return distribution(generator);
    }

    double Random::NextDouble() {
        std::uniform_real_distribution<double> distribution(0.0, 1.0);
        return distribution(generator);
    }

    int Random::NextInt(const int min, const int max) {
        if (min >= max - 1) return min;
        std::uniform_int_distribution<int> distribution(min, max - 1);
        return distribution(generator);
    }

    int Random::NextInt(const int range) {
        if (range <= 0) return 0;
        std::uniform_int_distribution<int> distribution(0, range - 1);
        return distribution(generator);
    }
}
