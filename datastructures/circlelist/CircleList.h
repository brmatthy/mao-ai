//
// Created by brent on 2/10/22.
//

#ifndef MAO_AI_CIRCLELIST_H
#define MAO_AI_CIRCLELIST_H


#include <vector>

template<class T>
class CircleList : public std::vector<T>{
private:
    int root = 0;
    int direction = 1;
public:
    void switchDirection();
    void nextRoot();
    T& getRoot();
};


#endif //MAO_AI_CIRCLELIST_H
