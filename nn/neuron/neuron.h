//
// Created by Noah Peeters on 11/22/16.
//

#ifndef NN_NEURON_H
#define NN_NEURON_H


#include <vector>


#define SINUS

class Neuron {
    double theta;

#ifdef SINUS
    double omega;
#endif //SINUS
    std::vector<double> weights;
public:
    Neuron(size_t input_size);

    double value;

    void modify();
    void calculate(std::vector<double> inputs);
    void print();
};


#endif //NN_NEURON_H
