//
// Created by Noah Peeters on 11/22/16.
//

#ifndef NN_TRAINER_H
#define NN_TRAINER_H


#include "../network/network.h"

class Trainer {
    Network* network;
    double last_score;

    double (*rate_function)(Network*, std::vector<double*>, std::vector<double*>);
    void single_train();
public:
    Trainer(Network* network, double (*new_rate_function)(Network*, std::vector<double*>, std::vector<double*>));
    void train(int n);
    Network* get_network();
};


#endif //NN_TRAINER_H
