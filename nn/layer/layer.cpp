//
// Created by Noah Peeters on 11/22/16.
//

#include <iostream>
#include "layer.h"

Layer::Layer(size_t layer_size, std::vector<double*> inputs) {
    this->neurons.reserve(layer_size);


    for (int i = 0; i < layer_size; ++i) {
        this->neurons.push_back(Neuron(inputs));
    }
}

std::vector<double *> Layer::get_outputs() {
    std::vector<double *> outputs;

    outputs.reserve(this->neurons.size());

    for (int i = 0; i < this->neurons.size(); ++i) {
        outputs.push_back(&this->neurons[i].value);
    }

    return outputs;
}

void Layer::calculate() {
    for (int i = 0; i < this->neurons.size(); ++i) {
        neurons[i].calculate();
    }
}

void Layer::print() {
    for (int i = 0; i < this->neurons.size(); ++i) {
        std::cout << "  " << i + 1 << ". Neuron: ";
        neurons[i].print();
    }
}

void Layer::modify() {
    for (int i = 0; i < this->neurons.size(); ++i) {
        neurons[i].modify();
    }
}

void Layer::revert() {
    for (int i = 0; i < this->neurons.size(); ++i) {
        neurons[i].revert();
    }
}

void Layer::update_inputs(std::vector<double *> inputs) {
    for (int i = 0; i < this->neurons.size(); ++i) {
        neurons[i].update_inputs(inputs);
    }
}
