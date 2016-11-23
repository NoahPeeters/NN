//
// Created by Noah Peeters on 11/22/16.
//

#ifndef NN_NETWORK_H
#define NN_NETWORK_H


#include "../layer/layer.h"

class Network {
    std::vector<Layer> layers;
    size_t input_size;
public:
    Network(size_t input_size);

    std::vector<double> get_last_outputs();

    void add_layer(size_t layer_size);
    void modify();
    std::vector<double> calculate(std::vector<double> inputs);
    void print();
};


#endif //NN_NETWORK_H
