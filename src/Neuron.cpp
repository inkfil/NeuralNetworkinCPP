#include <include/Neuron.hpp>

Neuron::Neuron(const unsigned int connections, const unsigned int _thisNeuronIndex){
    thisNeuronIndex = _thisNeuronIndex;
    for(int connection = 0; connection < connections; connection++){
        std::cout<<"\t\tConnection Num: "<<connection<<std::endl;
        std::cout<<"\t\t........"<<std::endl;

        outputWeights.push_back(Connection());
        outputWeights.at(connection).weight = randomWeight();
    }
}

double Neuron::randomWeight(){
    srand(rand());
    return rand() / double(RAND_MAX);
}

void Neuron::setOutputValue(double _output){
    output = _output;
}

double Neuron::getOutputValue() const {
    return output;
}

void Neuron::feedForward(const Layer& prevLayer){
    double sum = 0.0;
    for(unsigned int i = 0; i < prevLayer.size(); i++){
        sum += prevLayer.at(i).getOutputValue() * 
            prevLayer.at(i).outputWeights.at(thisNeuronIndex).weight;
    }

    output = activationFunction(sum);
}

double Neuron::activationFunction(double x){
    return std::tanh(x);
}

double Neuron::activationFunctionDerivation(double x){
    return 1.0 - x * x;
}