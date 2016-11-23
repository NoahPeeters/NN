#include <iostream>
#include <cmath>
#include "nn/network/network.h"
#include "nn/trainer/trainer.h"


double get_correct(double a0, double a1) {
    return (double) ((int) a0 + (int) (a1));
}

double rate_function(Network *network) {
    double result = 0;
    for (double a0 = 0; a0 < 3; a0++) {
        for (double a1 = 0; a1 < 3; a1++) {


            std::vector<double> outputs = network->calculate({a0, a1});

            double correct_result = get_correct(a0, a1);

            double diff = correct_result - outputs[0] * 10;

            result += diff * diff;
        }
    }
    return 0 - result;
}


void test(Network network) {
    for (double a0 = 0; a0 < 5; a0++) {
        for (double a1 = 0; a1 < 5; a1++) {

            std::vector<double> outputs = network.calculate({a0, a1});

            std::cout << a0 << "|" << a1 << std::endl;
            for (int i = 0; i < outputs.size(); ++i) {
                std::cout << "  " << outputs[i] << " (" << round(outputs[i] * 10) << ", " << get_correct(a0, a1) << "," << a0 << "+" << a1<< ")"
                          << std::endl;
            }
        }
    }
}


int main() {
    std::srand((unsigned int) std::time(0));

    double a0 = 0.0;
    double a1 = 0.0;
    std::vector<double *> inputs = {&a0, &a1};


    Network network(2);

//    network.add_layer(3);
    network.add_layer(1);
    network.print();
    test(network);

    Trainer trainer(network, 15, rate_function);
    trainer.train(100);

    network = trainer.get_best_network();
    network.print();
    test(network);

    return 0;
}