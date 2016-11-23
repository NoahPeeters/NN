//
// Created by Noah Peeters on 11/22/16.
//

#include <iostream>
#include "network.h"

Network::Network(size_t input_size) {
    this->input_size = input_size;
}

void Network::add_layer(size_t layer_size) {

    size_t input_size = this->layers.size() == 0 ? this->input_size : this->layers.back().get_output_size();

    this->layers.reserve(this->layers.size() + 1);

    this->layers.push_back(Layer(layer_size, input_size));
}

std::vector<double> Network::get_last_outputs() {
    return this->layers.back().get_outputs();
}


std::vector<double> Network::calculate(std::vector<double> inputs) {
    for (int i = 0; i < this->layers.size(); ++i) {
        layers[i].calculate(inputs);
    }
    return this->get_last_outputs();
}

void Network::print() {
    for (int i = 0; i < this->layers.size(); ++i) {
        std::cout << i + 1 << ". Layer" << std::endl;
        layers[i].print();
    }
}

void Network::modify() {
    for (int i = 0; i < this->layers.size(); ++i) {
        layers[i].modify();
    }
}