// Created by mats on 19/10/22.

#pragma once

class Algorithm {
public:
    virtual ~Algorithm() = default;
    /**
     * Simulate n iterations of the network
     * @param iterations number of iterations
     */
    virtual void execute(int iterations) = 0;
};
