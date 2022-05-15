#include <include/NeuralNetwork.hpp>

Net::Net(const std::vector<unsigned int> topology){
    unsigned int numLayers = topology.size();
    for(unsigned int layerNum = 0; layerNum < numLayers; layerNum++){
        std::cout<<"..................................................."<<std::endl;
        std::cout<<"Layer Num: "<<layerNum<<std::endl;
        std::cout<<"........"<<std::endl;

        unsigned int connections = layerNum == topology.size() - 1 ? 0 : topology.at(layerNum+1);
        network.push_back(Layer());
        for(unsigned int neuronNum = 0; neuronNum <= topology.at(layerNum); neuronNum++){

            std::cout<<"\tNeuron Num: "<<neuronNum<<std::endl;
            std::cout<<"\t........"<<std::endl;
            network.at(layerNum).push_back(Neuron(connections, neuronNum));
        }

        std::cout<<"..................................................."<<std::endl;
    }
}

void Net::feedForward(const std::vector<double>& inputs){
    if(inputs.size() + 1 != network.at(0).size()){
        std::cerr<<"ERROR: invalid number of inputs."<<std::endl;
    }

    // setting the neuron values of input layer.
    for(unsigned int input = 0; input < inputs.size(); input++){
        network.at(0).at(input).setOutputValue(inputs.at(input)); 
    }

    // setting neuron values for other layers.
    for(unsigned int layerNum = 1; layerNum < network.size(); layerNum++){
        Layer& prevLayer = network.at(layerNum-1);
        for(unsigned int neuronNum = 0; neuronNum < network.at(layerNum).size() - 1; neuronNum++){
            network.at(layerNum).at(neuronNum).feedForward(prevLayer);
        }
    }

}

void Net::backPropgation(const std::vector<double>& outputs){
    // calculate loss - RMS [Root Mean Squared Error].
    Layer& outputLayer = network.back();
    error = 0.0;
    
    // calculate output layer gradients.
    // calculate hidden layer gradients.
    // for all layers [from output to first hidden layer] calculate and update connection weight.

}

void Net::getResults(const std::vector<double> results) const {

}
