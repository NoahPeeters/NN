//
// Created by Noah Peeters on 11/22/16.
//

#include <cfloat>
#include <iostream>
#include "trainer.h"

Trainer::Trainer(Network* network, double (*new_rate_function)(Network*, std::vector<double*>, std::vector<double*>)) : network(network) {
    this->network = network;
    this->rate_function = new_rate_function;
    this->last_score = this->rate_function(this->network, this->network->get_inputs(), this->network->get_outputs());
}

void Trainer::single_train() {
    this->network->modify();

     double score = this->rate_function(this->network, this->network->get_inputs(), this->network->get_outputs());

    if (last_score < score) {
        this->last_score = score;
    } else {
        this->network->revert();
    }
}


void Trainer::train(int n) {
    for (int i = 0; i < n; ++i) {
        this->single_train();
//        if (((int)((double)i/50.0)) * 50 == i) {
//                std::cout << i << ".: " <<this->last_score << std::endl;
//        }
    }
}

Network* Trainer::get_network() {
    return this->network;
}
