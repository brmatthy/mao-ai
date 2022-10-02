//
// Created by brent on 2/10/22.
//

#include "CircleList.h"

template<class T>
void CircleList<T>::switchDirection() {
    switch(this->direction){
        case 1: this->direction = -1;
        default: this->direction = 1;
    }
}

template<class T>
void CircleList<T>::nextRoot() {
    this->root += this->direction;
    if(this->root < 0){
        this->root = std::vector<T>::size() - 1;
    }else if(this->root >= std::vector<T>::size()){
        this->root = 0;
    }
}

template<class T>
T &CircleList<T>::getRoot() {
    return std::vector<T>::at(root);
}

