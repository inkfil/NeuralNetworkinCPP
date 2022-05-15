#include <iostream>
#include <string>
#include <vector>

#include <include/Neuron.hpp>

class Net{
    public:
        Net(const std::vector<unsigned int> topology);
        void feedForward(const std::vector<double>& inputs);
        void backPropgation(const std::vector<double>& outputs);
        void getResults(const std::vector<double> results) const ;
    private:
        std::vector<Layer> network;
        double error = 0.0;
};