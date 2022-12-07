// Created by mats on 19/10/22.

#pragma once

#include "vector"

class Algorithm {
protected:
    std::vector<double> _faultHist;
public:
    virtual ~Algorithm() = default;
    /**
     * Simulate n training iterations
     * @param iterations number of iterations
     */
    virtual void execute(int iterations) = 0;
};


