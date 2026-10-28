#ifndef NEURAL_NETWORK_C_BASELAYER_H
#define NEURAL_NETWORK_C_BASELAYER_H

#include "../../Data/Tensors/Tensor.h"

namespace NeuralNetwork::Format::Layers {

    using namespace NeuralNetwork::Data::Tensors;

    class BaseLayer {
        int neuron_count;
        BaseLayer* next_layer;
    public:
        BaseLayer(int size);

        virtual void Forward(Tensor<float> input, Tensor<float> valuesOut, Tensor<float> activationOut);

        virtual void Backward(Tensor<float> values, Tensor<float> delta, Tensor<float> deltaOut);

        virtual void BackPropagation(Tensor<float> delta, Tensor<float> activations, Tensor<float> weightDelta, Tensor<float> biasDelta);

        virtual void Adjust(Tensor<float> weightDelta, Tensor<float> biasDelta, float scale);
    };
}

#endif