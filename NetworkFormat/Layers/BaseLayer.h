#ifndef NEURAL_NETWORK_C_BASELAYER_H
#define NEURAL_NETWORK_C_BASELAYER_H

class BaseLayer {
    int neuron_count;
    BaseLayer* next_layer;
public:
    BaseLayer(int size);
    ~BaseLayer();

};

#endif