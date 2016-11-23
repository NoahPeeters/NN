//
// Created by Noah Peeters on 11/22/16.
//

#include <iostream>
#include <cmath>
#include "neuron.h"
#include "../helpers.h"


Neuron::Neuron(std::vector<double*> inputs) {
    this->theta = rand_double() * 4.0 - 2.0;
#ifdef SINUS
    this->omega = rand_double() * 4.0 - 2.0;
#endif //SINUS
    this->inputs = inputs;
    this->weights.reserve(inputs.size());


    for (int i = 0; i < inputs.size(); ++i) {
        this->weights.push_back(rand_double() * 4.0 - 2.0);
    }
}

void Neuron::modify() {
    this->backup_theta = this->theta;
    this->backup_weights = this->weights;

    this->theta += rand_double() * 0.5 - 0.25;
    for (int i = 0; i < weights.size(); ++i) {
        this->weights[i] += rand_double() * 0.5 - 0.25;
    }
};

void Neuron::revert() {
    this->theta = this->backup_theta;
    this->weights = this->backup_weights;

}

void Neuron::calculate() {
    double sum = 0.0;

    for (int i = 0; i < inputs.size(); ++i) {
        sum += this->weights[i] * *this->inputs[i];
    }

//    this->value = sum > theta ? 1.0 : 0.0;

//    this->value = 1.0/(1+exp(-10.0 * (sum-theta)));
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

    for (int i = 0; i < this->weights.size(); ++i) {
        std::cout << this->inputs[i] << "|";
    }

    std::cout << "|" << &this->value << std::endl;
}

void Neuron::update_inputs(std::vector<double *> inputs) {
    this->inputs = inputs;
}
