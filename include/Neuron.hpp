#include <vector>
#include <cstdlib>
#include <iostream>
#include <cmath>

#ifndef NEURON_HPP
#define NEURON_HPP
class Neuron;
typedef std::vector<Neuron> Layer;

class Connection{
    public:
        double weight;
        double deltaWeight;
};

class Neuron{
    public:
        Neuron(const unsigned int connections, const unsigned int _thisNeuronIndex);
        double randomWeight();
        void setOutputValue(double _output);
        double getOutputValue() const ;
        void feedForward(const Layer& prevLayer);
        double activationFunction(double sum);
        double activationFunctionDerivation(double x);
    private:
        double output;
        unsigned int thisNeuronIndex = 0;
        std::vector<Connection> outputWeights;
};

#endif