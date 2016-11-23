//
// Created by Noah Peeters on 11/22/16.
//

#include <iostream>
#include "network.h"

Network::Network(std::vector<double *> inputs) {
    this->inputs = inputs;
}

void Network::add_layer(size_t layer_size) {
    std::vector<double *> inputs = this->layers.size() == 0 ? this->inputs : this->layers.back().get_outputs();

    this->layers.reserve(this->layers.size() + 1);

    this->layers.push_back(Layer(layer_size, inputs));
}

std::vector<double *> Network::get_outputs() {
    return this->layers.back().get_outputs();
}

void Network::calculate() {
    for (int i = 0; i < this->layers.size(); ++i) {
        layers[i].calculate();
    }
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

std::vector<double *> Network::get_inputs() {
    return this->inputs;
}

void Network::revert() {
    for (int i = 0; i < this->layers.size(); ++i) {
        layers[i].revert();
    }
}

void Network::update_inputs() {
    for (int i = 1; i < this->layers.size(); ++i) {
        this->layers[i].update_inputs(this->layers[i-1].get_outputs());
    }
}
