//
// Created by brent on 1/10/22.
//



#include <iostream>
#include "datastructures/circlelist/CircleList.h"

int main(){
    CircleList<int> cijfers;
    cijfers.push_back(0);
    cijfers.push_back(1);
    cijfers.push_back(2);
    cijfers.push_back(3);
    for(int c: cijfers){
        std::cout << c << "\n ";
    }
    std::cout << cijfers.getRoot();
}