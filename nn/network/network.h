//
// Created by Noah Peeters on 11/22/16.
//

#ifndef NN_NETWORK_H
#define NN_NETWORK_H


#include "../layer/layer.h"

class Network {
    std::vector<Layer> layers;
    std::vector<double*> inputs;
public:
    Network(std::vector<double*> inputs);

    std::vector<double*> get_inputs();
    std::vector<double*> get_outputs();

    void update_inputs();
    void add_layer(size_t layer_size);
    void modify();
    void revert();
    void calculate();
    void print();
};


#endif //NN_NETWORK_H
