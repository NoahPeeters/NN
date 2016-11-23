//
// Created by Noah Peeters on 11/22/16.
//

#ifndef NN_LAYER_H
#define NN_LAYER_H


#include "../neuron/neuron.h"

class Layer {
    std::vector<Neuron> neurons;
public:
    Layer(size_t layer_size, std::vector<double*> inputs);
    std::vector<double*> get_outputs();

    void update_inputs(std::vector<double*> inputs);
    void modify();
    void revert();
    void calculate();
    void print();
};


#endif //NN_LAYER_H
