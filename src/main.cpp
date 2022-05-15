#include <include/Net.hpp>


int main(const int argc, const char** argv){
    
    std::vector<unsigned int> topology{3, 2, 1};
    Net myNet(topology);

    std::vector<double> inputs{3, 2, 1};
    myNet.feedForward(inputs);

    std::vector<double> targets;
    myNet.backPropgation(targets);

    std::vector<double> results;
    myNet.getResults(results);

    return 0;
}