//
// Created by Noah Peeters on 11/22/16.
//

#include <iostream>
#include <cmath>
#include "neuron.h"
#include "../helpers.h"


Neuron::Neuron(size_t input_size) {
    this->theta = rand_double() * 4.0 - 2.0;
#ifdef SINUS
    this->omega = rand_double() * 4.0 - 2.0;
#endif //SINUS
    this->weights.reserve(input_size);


    for (int i = 0; i < input_size; ++i) {
        this->weights.push_back(rand_double() * 4.0 - 2.0);
    }
}

void Neuron::modify() {
    this->theta += rand_double() * 0.5 - 0.25;
    for (int i = 0; i < weights.size(); ++i) {
        this->weights[i] += rand_double() * 0.5 - 0.25;
    }
};

void Neuron::calculate(std::vector<double> inputs) {
    double sum = 0.0;

    for (int i = 0; i < inputs.size(); ++i) {
        sum += this->weights[i] * inputs[i];
    }

//    this->value = sum > theta ? 1.0 : 0.0;
#ifdef SINUS
    this->value = sin(this->omega*sum-theta);
#else
    this->value = 1.0/(1+exp(-10.0 * (sum-theta)));
#endif
}


void Neuron::print() {
    for (int i = 0; i < this->weights.size(); ++i) {
        std::cout << this->weights[i] << "|";
    }

    std::cout << "|" << this->theta << std::endl << "        " ;
}