#include <iostream>
#include <cmath>
#include "nn/network/network.h"
#include "nn/trainer/trainer.h"


//std::vector<double*> generate_inputs(unsigned long n) {
//    std::vector<double *> outputs (n);
//
//    for (int i = 0; i < n; ++i) {
//        outputs.push_back(new double);
//    }
//
//    return outputs;
//}


double abs(double n) {
    return n < 0 ? -n : n;
}


double get_correct(double a0, double a1) {
    return (double)((int)a0 ^ (int)(a1));
}


double rate_function (Network* network, std::vector<double*> inputs, std::vector<double*> outputs) {
    double result = 0;
    for (double a0 = 0; a0 < 2; a0++) {
        for (double a1 = 0; a1 < 2; a1++) {

            *inputs[0] = a0;
            *inputs[1] = a1;

            network->calculate();

            double correct_result = get_correct(a0, a1);

            double diff = abs(correct_result - *outputs[0]);

            result += diff * diff;
        }
    }
    return 0-result;
}


void test(Network &network) {
    std::vector<double*> outputs = network.get_outputs();
    std::vector<double*> inputs = network.get_inputs();

    for (int a0 = 0; a0 < 2; a0++) {
        for (int a1 = 0; a1 < 2; a1++) {

            *inputs[0] = a0;
            *inputs[1] = a1;

            network.calculate();

            std::cout << a0 << "|" << a1 << std::endl;
            for (int i = 0; i < outputs.size(); ++i) {
                std::cout << "  " << *outputs[i] << " (" << round(*outputs[i]) <<", " << get_correct(a0, a1) << ")" << std::endl;
            }
        }
    }
}


int main() {
    std::srand((unsigned int) std::time(0));

    double a1 = 0.0;
    double a2 = 0.0;
    std::vector<double*> inputs = {&a1, &a2};

    Network network(inputs);
    network.add_layer(3);
    network.add_layer(1);
    network.print();
    test(network);

    Trainer trainer (&network, rate_function);
    trainer.train(100000);

    network.print();
    test(network);


    std::cout << "Hello, World!" << std::endl;
    return 0;
}