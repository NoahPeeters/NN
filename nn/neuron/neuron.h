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

    double backup_theta;
    std::vector<double> weights;
    std::vector<double> backup_weights;
    std::vector<double*> inputs;
public:
    Neuron(std::vector<double*> inputs);

    double value;


    void update_inputs(std::vector<double*> inputs);
    void modify();
    void revert();
    void calculate();
    void print();
};


#endif //NN_NEURON_H
