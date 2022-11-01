//
// Created by brent on 1/10/22.
//


#include "bench/SimpleBench.h"
#include "ai/q_learning/states/AllStatesFactory.h"


int main(){
    auto states = getAllNCards(3);
    for(NCards state: states){
        std::cout << state << std::endl;
    }
    std::cout << states.size();
}