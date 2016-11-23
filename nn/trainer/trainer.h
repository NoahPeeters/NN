//
// Created by Noah Peeters on 11/22/16.
//

#ifndef NN_TRAINER_H
#define NN_TRAINER_H

#include "../network/network.h"


class Trainer {
    std::vector<Network> networks;
    double (*rate_function)(Network*);
    void single_train();
public:
    Trainer(Network network, size_t population_size_factor, double (*new_rate_function)(Network*));
    void train(int n);

    std::vector<Network> get_best_networks(size_t n);

    Network get_best_network();
};


#endif //NN_TRAINER_H
