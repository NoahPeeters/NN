//
// Created by Noah Peeters on 11/22/16.
//

#include <cfloat>
#include <iostream>
#include <numeric>
#include "trainer.h"


template <typename T>
std::vector<size_t> get_sort_indexes(const std::vector<T> &v) {

    // initialize original index locations
    std::vector<size_t> idx(v.size());
    std::iota(idx.begin(), idx.end(), 0);

    // sort indexes based on comparing values in v
    sort(idx.begin(), idx.end(),
         [&v](size_t i1, size_t i2) {return v[i1] > v[i2];});

    return idx;
}

Trainer::Trainer(Network network, size_t population_size_factor, double (*new_rate_function)(Network*)) {

    size_t population_size = population_size_factor * 2;

    this->networks.reserve(population_size);

    this->networks.push_back(network);
    for (int i = 0; i < population_size - 1; ++i) {
        Network tmp_network = network;
        tmp_network.modify();
        this->networks.push_back(tmp_network);
    }

    this->rate_function = new_rate_function;
}

Network Trainer::get_best_network() {
    return this->get_best_networks(1)[0];
}

std::vector<Network> Trainer::get_best_networks(size_t n) {
    std::vector<double > scores (this->networks.size());
    std::vector<Network> networks;
    networks.reserve(n);

    //collect scores
    for (int i = 0; i < this->networks.size(); ++i) {
        double score = this->rate_function(&this->networks[i]);
        scores[i] = score;
    }

    std::vector<size_t> sorted_indexes = get_sort_indexes(scores);


    for (int j = 0; j < n; ++j) {
        networks.push_back(this->networks[sorted_indexes[j]]);
    }

    return networks;
}

void Trainer::single_train() {

    std::vector<Network> networks;
    networks.reserve(this->networks.size());

    std::vector<Network> best_networks = this->get_best_networks(this->networks.size() / 2);

    for (int j = 0; j < best_networks.size(); ++j) {
        Network tmp_network = best_networks[j];
        networks.push_back(tmp_network);
        tmp_network.modify();
        networks.push_back(tmp_network);
    }

    this->networks = networks;
}


void Trainer::train(int n) {
    for (int i = 0; i < n; ++i) {
        this->single_train();
//        if (((int)((double)i/50.0)) * 50 == i) {
//                std::cout << i << ".: " <<this->last_score << std::endl;
//        }
    }
}

