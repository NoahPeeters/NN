//
// Created by Noah Peeters on 11/22/16.
//

#ifndef NN_LAYER_H
#define NN_LAYER_H


#include "../neuron/neuron.h"

class Layer {
    std::vector<Neuron> neurons;
public:
    Layer(size_t layer_size, size_t input_size);
    std::vector<double> get_outputs();
    size_t get_output_size();

    void modify();
    void calculate(std::vector<double> inputs);
    void print();

};


#endif //NN_LAYER_H
